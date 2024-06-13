#include "xingyunwin.h"
#include "ui_xingyunwin.h"
#include "qdebug.h"
#include <QTimer>
#include <QDateTime>

XingyunWin::XingyunWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XingyunWin)
{
    ui->setupUi(this);
    list900();
}

XingyunWin::~XingyunWin()
{
    delete ui;
}

void XingyunWin::delay(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));
    loop.exec();
}

bool XingyunWin::juesepanduan()
{
    //角色四星第四星
    //150,163,161,173,宽高(11,10)
    //角色四星第一星
    //77,163,88,172,宽高(11,9)
    //角色详情
    //79,203,88,229,宽高(9,26)
    INFO1 juesexiangqing=mapList.value("juesexiangqing");
    int backint=dm.GetColorNum(juesexiangqing.x,juesexiangqing.y,juesexiangqing.w,juesexiangqing.h,
                                 juesexiangqing.color,0.8);
    qDebug()<<QStringLiteral("角色详情--")<<backint;
        if(backint>80){
        //79,205,90,231,宽高(11,26)
            INFO1 juesediyixing=mapList.value("juesediyixing");
            int backint=dm.GetColorNum(juesediyixing.x,juesediyixing.y,juesediyixing.w,juesediyixing.h,
                                         juesediyixing.color,0.8);
        qDebug()<<QStringLiteral("角色第一星--")<<backint;
            if(backint>80){
            return true;
        }
        else
        {
            qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("角色查找错误");
            return false;
        }
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("角色 查找错误");
        return false;
    }
}

bool XingyunWin::jibanpanduan()
{
    //羁绊四星第四星
    //140,167,150,178,宽高(10,11)
    //羁绊四星第一星
    //67,167,78,178,宽高(11,11)
    //羁绊详情
    //72,244,82,271,宽高(10,27)
    INFO1 jibanxiangqing=mapList.value("jibanxiangqing");
    int backint=dm.GetColorNum(jibanxiangqing.x,jibanxiangqing.y,jibanxiangqing.w,jibanxiangqing.h,
                                 jibanxiangqing.color,0.8);
    qDebug()<<QStringLiteral("羁绊详情--")<<backint;
        if(backint>80){
        INFO1 jibandiyixing=mapList.value("jibandiyixing");
        int backint=dm.GetColorNum(jibandiyixing.x,jibandiyixing.y,jibandiyixing.w,jibandiyixing.h,
                                     jibandiyixing.color,0.8);
        qDebug()<<QStringLiteral("羁绊第一星--")<<backint;
            if(backint>80){
            return true;
        }
        else
        {
            qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("羁绊 查找错误");
            return false;
        }
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("羁绊 查找错误");
        return false;
    }
}

bool XingyunWin::juesesi()
{
    //角色四星第四星
    //150,163,161,173,宽高(11,10)
    INFO1 juesedisixing=mapList.value("juesedisixing");
    int backint=dm.GetColorNum(juesedisixing.x,juesedisixing.y,juesedisixing.w,juesedisixing.h,
                                 juesedisixing.color,0.8);
    qDebug()<<QStringLiteral("角色第四星--")<<backint;
        if(backint>80){
        return true;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("角色查找错误");
        return false;
    }
}

bool XingyunWin::jibansi()
{
    //羁绊四星第四星
    //140,167,150,178,宽高(10,11)
    INFO1 jibandisixing=mapList.value("jibandisixing");
    int backint=dm.GetColorNum(jibandisixing.x,jibandisixing.y,jibandisixing.w,jibandisixing.h,
                                 jibandisixing.color,0.8);
    qDebug()<<QStringLiteral("角色第四星--")<<backint;
        if(backint>80){
        return true;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("角色查找错误");
        return false;
    }
}

void XingyunWin::list900()
{
    mapList.clear();
    INFO1 juesexiangqing;
    juesexiangqing.x=79;
    juesexiangqing.y=203;
    juesexiangqing.w=88;
    juesexiangqing.h=229;
    juesexiangqing.color="212129-000000";
    mapList.insert("juesexiangqing",juesexiangqing);

    INFO1 juesediyixing;
    juesediyixing.x=77;
    juesediyixing.y=163;
    juesediyixing.w=88;
    juesediyixing.h=172;
    juesediyixing.color="FFFFFF-000000";
    mapList.insert("juesediyixing",juesediyixing);


    INFO1 jibanxiangqing;
    jibanxiangqing.x=72;
    jibanxiangqing.y=244;
    jibanxiangqing.w=82;
    jibanxiangqing.h=271;
    jibanxiangqing.color="22222A-000000";
    mapList.insert("jibanxiangqing",jibanxiangqing);

    INFO1 jibandiyixing;
    jibandiyixing.x=67;
    jibandiyixing.y=167;
    jibandiyixing.w=78;
    jibandiyixing.h=178;
    jibandiyixing.color="F8F8F8-000000";
    mapList.insert("jibandiyixing",jibandiyixing);

    INFO1 juesedisixing;
    juesedisixing.x=150;
    juesedisixing.y=163;
    juesedisixing.w=161;
    juesedisixing.h=173;
    juesedisixing.color="F8F8F8-000000";
    mapList.insert("juesedisixing",juesedisixing);

    INFO1 jibandisixing;
    jibandisixing.x=140;
    jibandisixing.y=167;
    jibandisixing.w=150;
    jibandisixing.h=178;
    jibandisixing.color="FAFAFA-000000";
    mapList.insert("jibandisixing",jibandisixing);


    INFO1 chongxinzhaomu;
    chongxinzhaomu.x=700;
    chongxinzhaomu.y=470;
    chongxinzhaomu.w=780;
    chongxinzhaomu.h=490;
    chongxinzhaomu.color="chongxinzhaomu.bmp";
    mapList.insert("chongxinzhaomu",chongxinzhaomu);

    INFO1 queren;
    queren.x=580;
    queren.y=310;
    queren.w=620;
    queren.h=340;
    queren.color="queren.bmp";
    mapList.insert("queren",queren);
}

void XingyunWin::list1600()
{
    mapList.clear();
    INFO1 juesexiangqing;
    juesexiangqing.x=79;
    juesexiangqing.y=203;
    juesexiangqing.w=88;
    juesexiangqing.h=229;
    juesexiangqing.color="212129-000000";
    mapList.insert("juesexiangqing",juesexiangqing);

    INFO1 juesediyixing;
    juesediyixing.x=77;
    juesediyixing.y=163;
    juesediyixing.w=88;
    juesediyixing.h=172;
    juesediyixing.color="FFFFFF-000000";
    mapList.insert("juesediyixing",juesediyixing);


    INFO1 jibanxiangqing;
    jibanxiangqing.x=72;
    jibanxiangqing.y=244;
    jibanxiangqing.w=82;
    jibanxiangqing.h=271;
    jibanxiangqing.color="22222A-000000";
    mapList.insert("jibanxiangqing",jibanxiangqing);

    INFO1 jibandiyixing;
    jibandiyixing.x=67;
    jibandiyixing.y=167;
    jibandiyixing.w=78;
    jibandiyixing.h=178;
    jibandiyixing.color="F8F8F8-000000";
    mapList.insert("jibandiyixing",jibandiyixing);

    INFO1 juesedisixing;
    juesedisixing.x=150;
    juesedisixing.y=163;
    juesedisixing.w=161;
    juesedisixing.h=173;
    juesedisixing.color="F8F8F8-000000";
    mapList.insert("juesedisixing",juesedisixing);

    INFO1 jibandisixing;
    jibandisixing.x=140;
    jibandisixing.y=167;
    jibandisixing.w=150;
    jibandisixing.h=178;
    jibandisixing.color="FAFAFA-000000";
    mapList.insert("jibandisixing",jibandisixing);


    INFO1 chongxinzhaomu;
    chongxinzhaomu.x=700;
    chongxinzhaomu.y=470;
    chongxinzhaomu.w=780;
    chongxinzhaomu.h=490;
    chongxinzhaomu.color="chongxinzhaomu.bmp";
    mapList.insert("chongxinzhaomu",chongxinzhaomu);

    INFO1 queren;
    queren.x=580;
    queren.y=310;
    queren.w=620;
    queren.h=340;
    queren.color="queren.bmp";
    mapList.insert("queren",queren);
}

void XingyunWin::on_pushButton_clicked()
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


void XingyunWin::on_pushButton_2_clicked()
{
    int intX,intY;


    //708,471,770,489,宽高(62,18)
    INFO1 chongxinzhaomu=mapList.value("chongxinzhaomu");
    int backint=dm.FindPic(chongxinzhaomu.x,chongxinzhaomu.y,chongxinzhaomu.w,chongxinzhaomu.h,
                             chongxinzhaomu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--chongxinzhaomu 查找错误");
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX, intY);
    dm.LeftClick();
    delay(MOUSE_DELAY);

//581,317,617,335,宽高(36,18)

        INFO1 queren=mapList.value("queren");
queren: backint=dm.FindPic(queren.x,queren.y,queren.w,queren.h,
                             queren.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--queren 查找错误");
        delay(CHECK_DELAY);
        goto queren;
    }
    delay(WAIT_DELAY);
    dm.MoveTo(intX, intY);
    dm.LeftClick();
    delay(MOUSE_DELAY);

    delay(8000);
    dm.LeftClick();
    delay(MOUSE_DELAY);

    delay(2000);
    int zijuese=0;
    int zijibase=0;
    for(int num=0;num<10;num++)
    {
    //78,161,88,173,宽高(10,12)
    xiayiye: bool backjuese=juesepanduan();
        if(backjuese){
            bool backjuese=juesesi();
            if(backjuese){
                zijuese++;
            }
        }
        else
        {
            backjuese=jibanpanduan();
            if(backjuese)
            {
                bool backjuese=jibansi();
                if(backjuese){
                    zijibase++;
                }
            }
            else
            {
                delay(2000);
                goto xiayiye;
            }
        }
        qDebug()<<"success--";
        delay(WAIT_DELAY);
        dm.MoveTo(818, 468);
        dm.LeftClick();
        delay(1000);
    }

    ui->textEdit->append(QStringLiteral("角色----")+QString::number(zijuese));
    ui->textEdit->append(QStringLiteral("羁绊----")+QString::number(zijibase));
    ui->textEdit->append(QStringLiteral("总体----")+QString::number(zijibase+zijuese));
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("------------------------"));
    if((zijuese+zijibase)<5)
    {
        delay(2000);
        on_pushButton_2_clicked();
    }
}


void XingyunWin::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
    {
        list900();
    }
        break;
    case 1:
    {
        list1600();
    }
    break;
    default:
        break;
    }
}

