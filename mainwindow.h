#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<windows.h>
#include <QMouseEvent>
#include <QDebug>
#include <QKeyEvent>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QByteArray>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void mousePressEvent(QMouseEvent *e);
     void keyPressEvent(QKeyEvent *event);

    void sleep(unsigned int msec);
    void zhixing();
    void setreadonly(bool flag);

    POINT Point[6];
    int yanshi[6];

    int time_flag;
    int start_flag;

    QString moshi[6];

    QSystemTrayIcon *systray;
    QString file;


private slots:
    void on_pushButton_clicked();
    void timerUpDate();

    void on_pushButton_2_clicked();

  //  void on_pushButton_6_clicked();

    void on_bu1_clicked();

    void on_start_clicked();

    void on_bu2_clicked();

    void on_moshi1_activated(const QString &arg1);

    void on_moshi2_activated(const QString &arg1);
    void showmain();

    void on_bu3_clicked();

    void on_bu4_clicked();

    void on_bu5_clicked();

    void on_moshi3_activated(const QString &arg1);

    void on_moshi4_activated(const QString &arg1);

    void on_moshi5_activated(const QString &arg1);

    void on_test_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
