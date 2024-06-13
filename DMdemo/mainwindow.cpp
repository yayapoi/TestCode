#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&waitFight,&QTimer::timeout,this,[this](){
        if(checkFightEnd())
        {
            waitFight.stop();
            //战斗结束
            fightEnd();
        }
    });
    connect(&startFight,&QTimer::timeout,this,[this](){
        startFight.stop();
        on_pushButton_2_clicked();
    });
    steamInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));
    loop.exec();
}

bool MainWindow::youqingzhiyuan(int &intX, int &intY)
{
    //1163,293,1200,328,宽高(37,35)
    INFO youqingzhiyuan=mapList.value("youqingzhiyuan");
    int backint=dm.FindPic(youqingzhiyuan.x,youqingzhiyuan.y,youqingzhiyuan.w,youqingzhiyuan.h,
                             youqingzhiyuan.color,"000000",0.9,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
        return true;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--youqingzhiyuan 查找错误");
        return false;
    }
}

void MainWindow::fightEnd()
{
    delay(WAIT_DELAY);
    dm.MoveTo(100, 100);
    dm.LeftClick();
    delay(MOUSE_DELAY);

    int intX,intY;
    //1292,763,1322,797,宽高(30,34)
    INFO jieshu=mapList.value("jieshu");
jieshu:    int backint=dm.FindPic(jieshu.x,jieshu.y,jieshu.w,jieshu.h,
                             jieshu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--jieshu 查找错误");
        delay(CHECK_DELAY);
        goto jieshu;
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX, intY);
    dm.LeftClick();
    delay(MOUSE_DELAY);
    startFight.start(FIGHT_DELAY);
}

bool MainWindow::checkFightEnd()
{
    int intX,intY;
    //212,293,250,329,宽高(38,36)
    INFO zhandoujieshu=mapList.value("zhandoujieshu");
    int backint=dm.FindPic(zhandoujieshu.x,zhandoujieshu.y,zhandoujieshu.w,zhandoujieshu.h,
                             zhandoujieshu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
        delay(5000);
        return true;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--zhandoujieshu 战斗未结束");
        return false;
    }
}

void MainWindow::mumuInit()
{
    mapList.clear();
    INFO youqingzhiyuan;
    youqingzhiyuan.x=1100;
    youqingzhiyuan.y=260;
    youqingzhiyuan.w=1220;
    youqingzhiyuan.h=350;
    youqingzhiyuan.color="youqingzhiyuan.bmp";
    mapList.insert("youqingzhiyuan",youqingzhiyuan);

    INFO jieshu;
    jieshu.x=1260;
    jieshu.y=750;
    jieshu.w=1340;
    jieshu.h=800;
    jieshu.color="jieshu.bmp";
    mapList.insert("jieshu",jieshu);


    INFO zhandoujieshu;
    zhandoujieshu.x=200;
    zhandoujieshu.y=260;
    zhandoujieshu.w=290;
    zhandoujieshu.h=350;
    zhandoujieshu.color="zhandoujieshu.bmp";
    mapList.insert("zhandoujieshu",zhandoujieshu);

    INFO guanqia5;
    guanqia5.x=1300;
    guanqia5.y=450;
    guanqia5.w=1390;
    guanqia5.h=490;
    guanqia5.color="guanqia5.bmp";
    mapList.insert("guanqia5",guanqia5);

    INFO jixu;
    jixu.x=1200;
    jixu.y=700;
    jixu.w=1270;
    jixu.h=770;
    jixu.color="jixu.bmp";
    mapList.insert("jixu",jixu);

    INFO buyongzhiyuan;
    buyongzhiyuan.x=1100;
    buyongzhiyuan.y=30;
    buyongzhiyuan.w=1190;
    buyongzhiyuan.h=90;
    buyongzhiyuan.color="buyongzhiyuan.bmp";
    mapList.insert("buyongzhiyuan",buyongzhiyuan);


    INFO zhandoukaishi;
    zhandoukaishi.x=1100;
    zhandoukaishi.y=700;
    zhandoukaishi.w=1240;
    zhandoukaishi.h=790;
    zhandoukaishi.color="zhandoukaishi.bmp";
    mapList.insert("zhandoukaishi",zhandoukaishi);

    INFO apbuzu;
    apbuzu.x=1300;
    apbuzu.y=30;
    apbuzu.w=1340;
    apbuzu.h=70;
    apbuzu.color="apbuzu.bmp";
    mapList.insert("apbuzu",apbuzu);
}

void MainWindow::steamInit()
{
    mapList.clear();
    INFO youqingzhiyuan;
    youqingzhiyuan.x=1190;
    youqingzhiyuan.y=30;
    youqingzhiyuan.w=1230;
    youqingzhiyuan.h=69;
    youqingzhiyuan.color="youqingzhiyuan.bmp";
    mapList.insert("youqingzhiyuan",youqingzhiyuan);

    INFO jieshu;
    jieshu.x=1030;
    jieshu.y=600;
    jieshu.w=1060;
    jieshu.h=650;
    jieshu.color="jieshu.bmp";
    mapList.insert("jieshu",jieshu);


    INFO zhandoujieshu;
    zhandoujieshu.x=160;
    zhandoujieshu.y=230;
    zhandoujieshu.w=200;
    zhandoujieshu.h=270;
    zhandoujieshu.color="zhandoujieshu.bmp";
    mapList.insert("zhandoujieshu",zhandoujieshu);

    INFO guanqia5;
    guanqia5.x=1050;
    guanqia5.y=350;
    guanqia5.w=1080;
    guanqia5.h=390;
    guanqia5.color="guanqia5.bmp";
    mapList.insert("guanqia5",guanqia5);

    INFO jixu;
    jixu.x=960;
    jixu.y=580;
    jixu.w=1000;
    jixu.h=620;
    jixu.color="jixu.bmp";
    mapList.insert("jixu",jixu);

    INFO buyongzhiyuan;
    buyongzhiyuan.x=920;
    buyongzhiyuan.y=30;
    buyongzhiyuan.w=950;
    buyongzhiyuan.h=60;
    buyongzhiyuan.color="buyongzhiyuan.bmp";
    mapList.insert("buyongzhiyuan",buyongzhiyuan);


    INFO zhandoukaishi;
    zhandoukaishi.x=920;
    zhandoukaishi.y=560;
    zhandoukaishi.w=970;
    zhandoukaishi.h=620;
    zhandoukaishi.color="zhandoukaishi.bmp";
    mapList.insert("zhandoukaishi",zhandoukaishi);

    INFO apbuzu;
    apbuzu.x=1040;
    apbuzu.y=20;
    apbuzu.w=1080;
    apbuzu.h=60;
    apbuzu.color="apbuzu.bmp";
    mapList.insert("apbuzu",apbuzu);
}

void MainWindow::on_pushButton_clicked()
{
    QEventLoop loop;
    QTimer::singleShot(2000, &loop, SLOT(quit()));
    loop.exec();
    ui->winHWID->setText(QString::number(dm.GetMousePointWindow()));
    int x,y,w,h;
    if(dm.screenSize(x,y,w,h)==1)
    {
        ui->winXLE->setText(QString::number(x));
        ui->winYLE->setText(QString::number(y));
        ui->winWLE->setText(QString::number(w));
        ui->winHLE->setText(QString::number(h));
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    //循环刷单个自动活动
    //1387,697,1466,756,宽高(79,59)
    /*QVariant intX;
    QVariant intY;

//1315,452,1342,483,宽高(27,31)
    INFO guanqia5=mapList.value("guanqia5");
guanqia5:    int backint=dm.FindPic(guanqia5.x,guanqia5.y,guanqia5.w,guanqia5.h,
                             guanqia5.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--guanqia5 查找错误");
        delay(CHECK_DELAY);
        goto guanqia5;
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX.toInt(), intY.toInt());
    dm.LeftClick();
    delay(MOUSE_DELAY);


//1214,732,1245,764,宽高(31,32)
INFO jixu=mapList.value("jixu");
jixu:    backint=dm.FindPic(jixu.x,jixu.y,jixu.w,jixu.h,
                     jixu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--jixu 查找错误");
        delay(CHECK_DELAY);
        goto jixu;
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX.toInt(), intY.toInt());
    dm.LeftClick();
    delay(MOUSE_DELAY);

//1160,45,1184,69,宽高(24,24)
INFO buyongzhiyuan=mapList.value("buyongzhiyuan");
buyongzhiyuan:    backint=dm.FindPic(buyongzhiyuan.x,buyongzhiyuan.y,buyongzhiyuan.w,buyongzhiyuan.h,
                     buyongzhiyuan.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--buyongzhiyuan 查找错误");
        delay(CHECK_DELAY);
        goto buyongzhiyuan;
    }
    delay(WAIT_DELAY);
    //steam dm.MoveTo(660, 480);
    dm.MoveTo(762, 590);
    dm.LeftClick();
    delay(MOUSE_DELAY);


//1158,713,1206,763,宽高(48,50)
INFO zhandoukaishi=mapList.value("zhandoukaishi");
zhandoukaishi:    backint=dm.FindPic(zhandoukaishi.x,zhandoukaishi.y,zhandoukaishi.w,zhandoukaishi.h,
                     zhandoukaishi.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--zhandoukaishi 查找错误");
        delay(CHECK_DELAY);
        goto zhandoukaishi;
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX.toInt(), intY.toInt());
    dm.LeftClick();
    delay(MOUSE_DELAY);


    //1307,33,1339,69,宽高(32,36)
    delay(10000);
    INFO apbuzu=mapList.value("apbuzu");
    backint=dm.FindPic(apbuzu.x,apbuzu.y,apbuzu.w,apbuzu.h,
                         apbuzu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
        delay(WAIT_DELAY);
        dm.MoveTo(intX.toInt(), intY.toInt());
        dm.LeftClick();
        delay(MOUSE_DELAY);
        goto zhandoukaishi;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--apbuzu 查找错误");
    }


    waitFight.start(FIGHT_DELAY);*/
}


void MainWindow::on_pushButton_3_clicked()
{
    dm.MoveTo(100, 100);
    dm.LeftClick();
}

