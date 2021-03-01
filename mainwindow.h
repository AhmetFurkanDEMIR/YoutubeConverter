#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <iostream>
#include <unistd.h>

extern QString dir;
extern std::string path;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
    static void run(QString a, QPushButton *button, QLineEdit *line);
    static void buttona(QPushButton *button_temp);
    static void error(QPushButton *button, QLineEdit *line);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
