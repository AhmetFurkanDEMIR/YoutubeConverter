#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include<stdio.h>

QString dir="";
std::string path=get_current_dir_name();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // dark thema
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;

    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    FILE *file;
    std::string path_temp=path+"/download.py";

    if (file = fopen(path_temp.c_str(), "r")) {
        fclose(file);
    }
    else {
        system("wget https://ahmetfurkandemir.s3.amazonaws.com/download.py");

    }

    path_temp=path+"/yt.png";

    if (file = fopen(path_temp.c_str(), "r")) {
        fclose(file);
    }
    else {
        system("wget https://ahmetfurkandemir.s3.amazonaws.com/yt.png");

    }

    MainWindow w;
    w.show();
    return a.exec();
}
