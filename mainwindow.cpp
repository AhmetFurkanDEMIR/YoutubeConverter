#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <thread>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(715, 405);
    this->move(382, 134);

    QPixmap pix(QString::fromUtf8(path.c_str())+"/yt.png");
    ui->label_6->setPixmap(pix);
    ui->label_7->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// butondaki animasyon
void MainWindow::buttona(QPushButton *button){

    int i=0;

    while(true){

        if(button->text()=="Downloaded"){
            return;
        }

        else{

            if(i==10){
                button->setText("Downloading ");
                sleep(1);
            }
            else if(i==20){
                button->setText("Downloading .");
                sleep(1);
            }

            else if(i==30){
                button->setText("Downloading ..");
                sleep(1);
            }

            else if(i==40){
                button->setText("Downloading ...");
                sleep(1);
            }

            else if(i==50){
                button->setText("Downloading ....");
                sleep(1);
                i=0;
            }

            i+=1;
        }

    }

}

// python uzerinden videoyu veya sesi indirme islemi
void MainWindow::run(QString a, QPushButton *button, QLineEdit *line){

    int i;

    std::thread runb(buttona, button);
    runb.detach();

    system(qPrintable(a));
    line->setText("");

    for(i=0;i<20;i++){
        button->setText("Downloaded");
    }

}


// video indirme islemi
void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text()!="Downloading ...")
    {
        if(ui->pushButton_2->text()!="Download location"){

            if(ui->lineEdit->text()!=""){

                QString url=ui->lineEdit->text();
                url.replace('&', '*');

                QString fps=ui->comboBox_2->currentText();
                fps.remove('F');
                fps.remove('P');
                fps.remove('S');
                fps.remove(' ');

                QString quality=ui->comboBox->currentText();
                quality.remove('H');
                quality.remove('D');
                quality.remove(' ');

                QString command;
                command = "python3 "+QString::fromUtf8(path.c_str())+"/download.py --url "+url+" --quality "+quality+" --fps "+fps+" --path "+dir+" --flag 0";

                QPushButton *button=ui->pushButton;
                QLineEdit *line=ui->lineEdit;

                ui->pushButton->setText("");
                std::thread runa(run, command, button, line);
                runa.detach();

            }

            else{
                ui->pushButton->setText("Error");
            }

        }

        else{
            ui->pushButton->setText("Error");
        }
    }

}

// indirme yeri
void MainWindow::on_pushButton_2_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->pushButton_2->setText(dir);


}

// indirme yeri
void MainWindow::on_pushButton_4_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->pushButton_4->setText(dir);
}

// ses indirme islemi
void MainWindow::on_pushButton_3_clicked()
{

    if(ui->pushButton_3->text()!="Downloading ..."){

        if(ui->pushButton_4->text()!="Download location"){

            if(ui->lineEdit_2->text()!=""){

                QString url=ui->lineEdit_2->text();
                url.replace('&', '*');

                QString command = "python3 "+QString::fromUtf8(path.c_str())+"/download.py --url "+url+" --quality 0"+" --fps 0"+" --path "+dir+" --flag 1";

                QPushButton *button=ui->pushButton_3;
                QLineEdit *line=ui->lineEdit_2;

                ui->pushButton_3->setText("");
                std::thread runa(run, command, button, line);
                runa.detach();

                ui->pushButton_3->setText("Downloaded");
                ui->lineEdit_2->setText("");
            }

            else{
                ui->pushButton_3->setText("Error");
            }
        }

        else{
            ui->pushButton_3->setText("Error");
        }
    }

    else{
        ui->pushButton_3->setText("Error");
    }

}


