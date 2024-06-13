#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtimer.h"
#include <QMainWindow>
#include <dmobject.h>
#include "globalobject.h"
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void delay(int ms);

    bool youqingzhiyuan(int& intX,int& intY);

    void fightEnd();

    bool checkFightEnd();

    void mumuInit();

    void steamInit();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    DmObject dm;
    QTimer waitFight;
    QTimer startFight;
    QMap<QString,INFO> mapList;
};
#endif // MAINWINDOW_H
