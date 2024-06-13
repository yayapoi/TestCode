#include "clickform.h"
#include "ui_clickform.h"
#include <QTimer>
#include <QDebug>
#include <encodeing/encodeobject.h>
#include <encodeing/XXTeaHelper.h>
#include <QMessageBox>
#include <QDateTime>

ClickForm::ClickForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClickForm)
{
    ui->setupUi(this);
    //QString setter=QStringLiteral("本软件为免费软件");
    //std::string tesetset=XXTeaHelper::XXTeaEncryptToHex(setter.toStdString(),"123");
    //qDebug()<<"teset Encode----"<<QString::fromStdString(tesetset);
    std::string encodedoe="5622ebcf0632f0393b4eb69f14357c85fc3f0bcd74badb4d0d14765e";
    std::string backstr;
    bool flag=XXTeaHelper::XXTeaDecryptHex(&backstr,encodedoe,"123");
    setWindowTitle(QString::fromStdString(backstr));
    //qDebug()<<"teset Encode----"<<QString::fromStdString(backstr);

    ui->pushButton_3->setVisible(false);
    ui->pushButton_5->setVisible(false);

    exePath = QCoreApplication::applicationDirPath();//获取程序运行路径

    checkPathStr=exePath+checkPathStr;
    fangqiPathStr=exePath+fangqiPathStr;
    wupinPathStr=exePath+wupinPathStr;
    zidongzhandouPathStr=exePath+zidongzhandouPathStr;
}

ClickForm::~ClickForm()
{
    stopBOOL=true;
    delete dm;
    delete ui;
}

void ClickForm::huodongCheck()
{
    qDebug()<<"huodongCheck";
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" 活动选关"));
    //进入活动页面，选择关卡等级
    INFO huodongguanqia;//1267,538,1304,586,宽高(37,48);huodongguanqia
    huodongguanqia.x=1260;
    huodongguanqia.y=530;
    huodongguanqia.w=1310;
    huodongguanqia.h=590;
    huodongguanqia.color="huodongguanqia.bmp";
    huodongguanqia.path=checkPathStr;
    function(huodongguanqia);

    //选择关卡等级
    INFO shangji;//767,687,828,706,宽高(61,19);shangji
    shangji.x=760;
    shangji.y=680;
    shangji.w=830;
    shangji.h=710;
    shangji.color="shangji.bmp";
    shangji.path=checkPathStr;
    function(shangji);

    //确认选择
    INFO kaishi;//936,578,965,610,宽高(29,32);kaishi
    kaishi.x=930;
    kaishi.y=570;
    kaishi.w=970;
    kaishi.h=615;
    kaishi.color="kaishi.bmp";
    kaishi.path=checkPathStr;
    function(kaishi);

    //选择支援
    INFO buyongzhiyuan;//1213,45,1234,68,宽高(21,23);buyongzhiyuan
    buyongzhiyuan.x=1210;
    buyongzhiyuan.y=40;
    buyongzhiyuan.w=1240;
    buyongzhiyuan.h=70;
    buyongzhiyuan.color="buyongzhiyuan.bmp";
    buyongzhiyuan.path=checkPathStr;
    buyongzhiyuan.cilckBool=true;
    buyongzhiyuan.clickx=800;
    buyongzhiyuan.clicky=583;
    function(buyongzhiyuan);

//战斗开始
beginAgin:
    if(stopBOOL)
        return;
    INFO zidongzaizhan;//1001,679,1028,695,宽高(27,16);zidongzaizhan
    zidongzaizhan.x=1000;
    zidongzaizhan.y=670;
    zidongzaizhan.w=1030;
    zidongzaizhan.h=700;
    zidongzaizhan.color="zidongzaizhan.bmp";
    zidongzaizhan.path=checkPathStr;
    zidongzaizhan.cilckBool=true;
    zidongzaizhan.clickx=1210;
    zidongzaizhan.clicky=730;
    function(zidongzaizhan);

    //自动再战确认
    INFO zhandoukaishi;//967,725,1002,762,宽高(35,37);zhandoukaishi
    zhandoukaishi.x=960;
    zhandoukaishi.y=720;
    zhandoukaishi.w=1010;
    zhandoukaishi.h=770;
    zhandoukaishi.color="zhandoukaishi.bmp";
    zhandoukaishi.path=checkPathStr;
    function(zhandoukaishi);

    //ap不足弹窗检测
    //返回false即有ap
    //返回true没有ap，输入值true表示吃药，输入false表示不吃药
    //同时返回的xy是吃药 不吃药时候点击的点
    int clickx,clicky;
    if(apbuzu(EAT_AP_YAO,clickx,clicky))//没体力了
    {
        GlobalObject::delayMS(WAIT_DELAY);
        dm->MoveTo(clickx, clicky);
        dm->LeftClick();
        GlobalObject::delayMS(MOUSE_DELAY);

        if(EAT_AP_YAO)
        {
            //吃药确认
            //924,638,954,671,宽高(30,33)shiyongqueren.bmp
            INFO shiyongqueren;//955,726,979,762
            shiyongqueren.x=920;
            shiyongqueren.y=630;
            shiyongqueren.w=960;
            shiyongqueren.h=680;
            shiyongqueren.color="shiyongqueren.bmp";
            shiyongqueren.path=zidongzhandouPathStr;
            function(shiyongqueren);

            //600,496,635,525,宽高(35,29)apyiyong.bmp
            INFO apyiyong;//955,726,979,762
            apyiyong.x=600;
            apyiyong.y=490;
            apyiyong.w=640;
            apyiyong.h=530;
            apyiyong.color="apyiyong.bmp";
            apyiyong.path=zidongzhandouPathStr;
            apyiyong.cilckBool=true;
            apyiyong.clickx=100;
            apyiyong.clicky=100;
            function(apyiyong);
        }

        goto beginAgin;
    }
    else//成功战斗
    {
        return;
    }
}

void ClickForm::fangqiba()
{
    qDebug()<<"fangqiba";
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" 放弃战斗"));
    //放弃战斗
    INFO tuichuanniu;//1486,25,1522,63,宽高(36,38);tuichuanniu
    tuichuanniu.x=1480;
    tuichuanniu.y=20;
    tuichuanniu.w=1530;
    tuichuanniu.h=70;
    tuichuanniu.color="tuichuanniu.bmp";
    tuichuanniu.path=fangqiPathStr;
    function(tuichuanniu);

    //放弃
    INFO fangqi;//1166,44,1185,68,宽高(19,24);fangqi
    fangqi.x=1160;
    fangqi.y=40;
    fangqi.w=1190;
    fangqi.h=70;
    fangqi.color="fangqi.bmp";
    fangqi.path=fangqiPathStr;
    function(fangqi);

    //放弃确认
    INFO fangqiqueren;//973,624,998,655,宽高(25,31);fangqiqueren
    fangqiqueren.x=970;
    fangqiqueren.y=620;
    fangqiqueren.w=1000;
    fangqiqueren.h=660;
    fangqiqueren.color="fangqiqueren.bmp";
    fangqiqueren.path=fangqiPathStr;
    function(fangqiqueren);
}

bool ClickForm::checkWupin()
{
    /*
     *
     * 37,25,114,103,宽高(77,78)
     * 144,28,218,99,宽高(74,71)
     * 250,29,326,98,宽高(76,69)
     * 354,27,434,101,宽高(80,74)
     * 462,26,540,103,宽高(78,77)
     * 567,24,646,102,宽高(79,78)
     * 673,26,752,102,宽高(79,76)
     *
     * 693,46,735,83,宽高(42,37)tempwupin
     *
     * 365,37,421,95,宽高(56,58)smallAP
     * 582,41,631,91,宽高(49,50)midleAP
     * 49,40,96,89,宽高(47,49)bigAP
     * 33,21,757,110//第一到七格子
*/

    qDebug()<<"checkWupin";
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" 物品判断"));
    INFO onewupin;
    onewupin.x=35;
    onewupin.y=23;
    onewupin.w=117;
    onewupin.h=108;
    onewupin.color="smallAP.bmp";
    onewupin.path=wupinPathStr;

    INFO tuwupin;
    tuwupin.x=139;
    tuwupin.y=22;
    tuwupin.w=223;
    tuwupin.h=106;
    tuwupin.color="smallAP.bmp";
    tuwupin.path=wupinPathStr;

    INFO siruipin;
    siruipin.x=246;
    siruipin.y=23;
    siruipin.w=330;
    siruipin.h=106;
    siruipin.color="smallAP.bmp";
    siruipin.path=wupinPathStr;

    INFO forpin;
    forpin.x=354;
    forpin.y=23;
    forpin.w=435;
    forpin.h=106;
    forpin.color="smallAP.bmp";
    forpin.path=wupinPathStr;

    INFO fivepin;
    fivepin.x=459;
    fivepin.y=23;
    fivepin.w=540;
    fivepin.h=105;
    fivepin.color="smallAP.bmp";
    fivepin.path=wupinPathStr;

    INFO sixpin;
    sixpin.x=565;
    sixpin.y=22;
    sixpin.w=647;
    sixpin.h=106;
    sixpin.color="smallAP.bmp";
    sixpin.path=wupinPathStr;

    INFO sevenpin;
    sevenpin.x=670;
    sevenpin.y=22;
    sevenpin.w=751;
    sevenpin.h=105;
    sevenpin.color="smallAP.bmp";
    sevenpin.path=wupinPathStr;


    //第七格子是否有物品
    sevenpin.color="tempwupin.bmp";
checkeagine:
    if(stopBOOL)
        return false;
    if(checkWupin(sevenpin))
    {
        //第七格子空物品，继续检测
        GlobalObject::delayMS(CHECK_DELAY);
        goto checkeagine;
    }

    onewupin.color="smallAP.bmp";
    if(checkWupin(onewupin))
    {
        goto chenggong;
    }
    onewupin.color="midleAP.bmp";
    if(checkWupin(onewupin))
    {
        goto chenggong;
    }
    onewupin.color="bigAP.bmp";
    if(checkWupin(onewupin))
    {
        goto chenggong;
    }
    onewupin.color="piao.bmp";
    if(checkWupin(onewupin))
    {
        goto chenggong;
    }

    tuwupin.color="smallAP.bmp";
    if(checkWupin(tuwupin))
    {
        goto chenggong;
    }
    tuwupin.color="midleAP.bmp";
    if(checkWupin(tuwupin))
    {
        goto chenggong;
    }
    tuwupin.color="bigAP.bmp";
    if(checkWupin(tuwupin))
    {
        goto chenggong;
    }
    tuwupin.color="piao.bmp";
    if(checkWupin(tuwupin))
    {
        goto chenggong;
    }

    siruipin.color="smallAP.bmp";
    if(checkWupin(siruipin))
    {
        goto chenggong;
    }
    siruipin.color="midleAP.bmp";
    if(checkWupin(siruipin))
    {
        goto chenggong;
    }
    siruipin.color="bigAP.bmp";
    if(checkWupin(siruipin))
    {
        goto chenggong;
    }
    siruipin.color="piao.bmp";
    if(checkWupin(siruipin))
    {
        goto chenggong;
    }

    forpin.color="smallAP.bmp";
    if(checkWupin(forpin))
    {
        goto chenggong;
    }
    forpin.color="midleAP.bmp";
    if(checkWupin(forpin))
    {
        goto chenggong;
    }
    forpin.color="bigAP.bmp";
    if(checkWupin(forpin))
    {
        goto chenggong;
    }
    forpin.color="piao.bmp";
    if(checkWupin(forpin))
    {
        goto chenggong;
    }

    fivepin.color="smallAP.bmp";
    if(checkWupin(fivepin))
    {
        goto chenggong;
    }
    fivepin.color="midleAP.bmp";
    if(checkWupin(fivepin))
    {
        goto chenggong;
    }
    fivepin.color="bigAP.bmp";
    if(checkWupin(fivepin))
    {
        goto chenggong;
    }
    fivepin.color="piao.bmp";
    if(checkWupin(fivepin))
    {
        goto chenggong;
    }

    sixpin.color="smallAP.bmp";
    if(checkWupin(sixpin))
    {
        goto chenggong;
    }
    sixpin.color="midleAP.bmp";
    if(checkWupin(sixpin))
    {
        goto chenggong;
    }
    sixpin.color="bigAP.bmp";
    if(checkWupin(sixpin))
    {
        goto chenggong;
    }
    sixpin.color="piao.bmp";
    if(checkWupin(sixpin))
    {
        goto chenggong;
    }

    sevenpin.color="smallAP.bmp";
    if(checkWupin(sevenpin))
    {
        goto chenggong;
    }
    sevenpin.color="midleAP.bmp";
    if(checkWupin(sevenpin))
    {
        goto chenggong;
    }
    sevenpin.color="bigAP.bmp";
    if(checkWupin(sevenpin))
    {
        goto chenggong;
    }
    sevenpin.color="piao.bmp";
    if(checkWupin(sevenpin))
    {
        goto chenggong;
    }

    //都跑完了，没检测到，放弃
    qDebug()<<"checkWupin fail";
    dm->MoveTo(100, 100);
    dm->LeftClick();
    return false;
chenggong: //成功有物品啦
    qDebug()<<"checkWupin success";
    return true;
}

void ClickForm::successAgine()
{
    //自动再战 zidongzaizhan 点击它 //988,817,1020,849
    //自动再战确认 zidongzaizhanqueren 点击它//955,726,979,762
    //有体力 没体力
    //ap不足 apbuzu 点击它//1118,406,1145,432
    //使用确认 shiyongqueren 点击它//922,641,955,669
    //ap已用 apyiyong  点击100,100//601,497,634,522
    //回到自动再战

    //有体力 等十几秒判断有没体力
    //等待结束
    /*INFO zidongzaizhan;//988,817,1020,849
    zidongzaizhan.x=980;
    zidongzaizhan.y=810;
    zidongzaizhan.w=1030;
    zidongzaizhan.h=850;
    zidongzaizhan.color="zidongzaizhan.bmp";
    zidongzaizhan.path=zidongzhandouPathStr;
    function(zidongzaizhan);

    INFO zidongzaizhanqueren;//955,726,979,762
    zidongzaizhanqueren.x=950;
    zidongzaizhanqueren.y=720;
    zidongzaizhanqueren.w=980;
    zidongzaizhanqueren.h=770;
    zidongzaizhanqueren.color="zidongzaizhanqueren.bmp";
    zidongzaizhanqueren.path=zidongzhandouPathStr;
    function(zidongzaizhanqueren);


    INFO apbuzu;//1118,406,1145,432
    apbuzu.x=1110;
    apbuzu.y=400;
    apbuzu.w=1150;
    apbuzu.h=440;
    apbuzu.color="apbuzu.bmp";
    apbuzu.path=zidongzhandouPathStr;
    function(apbuzu);

    INFO shiyongqueren;//922,641,955,669
    shiyongqueren.x=920;
    shiyongqueren.y=640;
    shiyongqueren.w=960;
    shiyongqueren.h=670;
    shiyongqueren.color="shiyongqueren.bmp";
    shiyongqueren.path=zidongzhandouPathStr;
    function(shiyongqueren);

    INFO apyiyong;//601,497,634,522
    apyiyong.x=600;
    apyiyong.y=490;
    apyiyong.w=640;
    apyiyong.h=530;
    apyiyong.color="apyiyong.bmp";
    apyiyong.path=zidongzhandouPathStr;
    function(apyiyong);

    INFO buyaoap;//1307,32,1340,68
    buyaoap.x=1300;
    buyaoap.y=30;
    buyaoap.w=1350;
    buyaoap.h=70;
    buyaoap.color="buyaoap.bmp";
    buyaoap.path=zidongzhandouPathStr;
    function(buyaoap);*/


//自动再战 zidongzaizhan 点击它 //988,817,1020,849
//自动再战确认 zidongzaizhanqueren 点击它//955,726,979,762
//有体力 没体力
//ap不足 apbuzu 点击它//1118,406,1145,432
//使用确认 shiyongqueren 点击它//922,641,955,669
//ap已用 apyiyong  点击100,100//601,497,634,522
//回到自动再战

//有体力 等十几秒判断有没体力
//等待结束
beginAgin:
    if(stopBOOL)
        return;
    qDebug()<<"successAgine";
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" 自动继续"));
    INFO zidongzaizhan;//988,817,1020,849
    zidongzaizhan.x=980;
    zidongzaizhan.y=810;
    zidongzaizhan.w=1030;
    zidongzaizhan.h=850;
    zidongzaizhan.color="zidongzaizhan.bmp";
    zidongzaizhan.path=zidongzhandouPathStr;
    function(zidongzaizhan);

    INFO zidongzaizhanqueren;//955,726,979,762
    zidongzaizhanqueren.x=950;
    zidongzaizhanqueren.y=720;
    zidongzaizhanqueren.w=980;
    zidongzaizhanqueren.h=770;
    zidongzaizhanqueren.color="zidongzaizhanqueren.bmp";
    zidongzaizhanqueren.path=zidongzhandouPathStr;
    function(zidongzaizhanqueren);


    //ap不足弹窗检测
    //返回false即有ap
    //返回true没有ap，输入值true表示吃药，输入false表示不吃药
    //同时返回的xy是吃药 不吃药时候点击的点
    int clickx,clicky;
    if(apbuzu(EAT_AP_YAO,clickx,clicky))//没体力了
    {
        GlobalObject::delayMS(WAIT_DELAY);
        dm->MoveTo(clickx, clicky);
        dm->LeftClick();
        GlobalObject::delayMS(MOUSE_DELAY);

        if(EAT_AP_YAO)
        {
            //吃药确认
            //924,638,954,671,宽高(30,33)shiyongqueren.bmp
            INFO shiyongqueren;//955,726,979,762
            shiyongqueren.x=920;
            shiyongqueren.y=630;
            shiyongqueren.w=960;
            shiyongqueren.h=680;
            shiyongqueren.color="shiyongqueren.bmp";
            shiyongqueren.path=zidongzhandouPathStr;
            function(shiyongqueren);

            //600,496,635,525,宽高(35,29)apyiyong.bmp
            INFO apyiyong;//955,726,979,762
            apyiyong.x=600;
            apyiyong.y=490;
            apyiyong.w=640;
            apyiyong.h=530;
            apyiyong.color="apyiyong.bmp";
            apyiyong.path=zidongzhandouPathStr;
            apyiyong.cilckBool=true;
            apyiyong.clickx=100;
            apyiyong.clicky=100;
            function(apyiyong);
        }
        goto beginAgin;
    }
    else//成功战斗
    {
        return;
    }
}

bool ClickForm::apbuzu(bool eatyao, int &x, int &y)
{
    ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" ap不足窗口"));
    INFO apbuzu;//1118,406,1145,432
    apbuzu.x=1110;
    apbuzu.y=400;
    apbuzu.w=1150;
    apbuzu.h=440;
    apbuzu.color="apbuzu.bmp";
    apbuzu.path=zidongzhandouPathStr;

    GlobalObject::delayMS(AP_BUZU);
    int intX,intY;
    int backint=dm->FindPicWithoutPath(apbuzu.x,apbuzu.y,apbuzu.w,apbuzu.h,
                                         apbuzu.path+apbuzu.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
        if(eatyao)//吃药就返回吃药坐标
        {
            x=1133;y=411;
        }
        else//不吃药就返回退出界面坐标
        {
            x=792;y=804;
        }
    }
    else
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("--apbuzu 查找错误");
        GlobalObject::delayMS(CHECK_DELAY);
        return false;
    }
    return true;
}

void ClickForm::function(INFO &doInfo)
{
    int intX,intY;
doInfo:
    if(stopBOOL)
        return;
    int backint=dm->FindPicWithoutPath(doInfo.x,doInfo.y,doInfo.w,doInfo.h,
                                         doInfo.path+doInfo.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        qDebug()<<"intX--"<<intX<<"intY--"<<intY;
    }
    else
    {
        ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+doInfo.color+QStringLiteral("--没查到"));
        GlobalObject::delayMS(CHECK_DELAY);
        if(doInfo.gotoBool)
        {
            goto doInfo;
        }
        else
        {
            return;
        }
    }
    GlobalObject::delayMS(WAIT_DELAY);
    if(doInfo.cilckBool)
    {
        dm->MoveTo(doInfo.clickx, doInfo.clicky);
    }
    else
    {
        dm->MoveTo(intX, intY);
    }
    dm->LeftClick();
    GlobalObject::delayMS(MOUSE_DELAY);
}

bool ClickForm::checkWupin(INFO &doInfo)
{
    int intX,intY;
    int backint=dm->FindPicWithoutPath(doInfo.x,doInfo.y,doInfo.w,doInfo.h,
                                         doInfo.path+doInfo.color,"000000",0.8,0,intX,intY);
    if(backint!=-1){
        ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral(" 物品空的"));
        return true;
    }
    else
    {
        ui->textEdit->append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+QStringLiteral("  物品满了"));
        return false;
    }
}

void ClickForm::closeEvent(QCloseEvent *e)
{
    stopBOOL=true;
}

void ClickForm::on_pushButton_clicked()
{
    if(dm!=nullptr)
    {
        delete dm;
    }
    dm=new DmObject;
    QEventLoop loop;
    QTimer::singleShot(2000, &loop, SLOT(quit()));
    loop.exec();
    ui->winHWID->setText(QString::number(dm->GetMousePointWindow()));
    int x,y,w,h;
    if(dm->screenSize(x,y,w,h)==1)
    {
        ui->winXLE->setText(QString::number(x));
        ui->winYLE->setText(QString::number(y));
        ui->winWLE->setText(QString::number(w));
        ui->winHLE->setText(QString::number(h));
    }
}


void ClickForm::on_pushButton_2_clicked()
{
    if(stopBOOL)
        return;
    huodongCheck();
    if(checkWupin())
    {
        on_pushButton_4_clicked();
    }
    else
    {
        fangqiba();
        on_pushButton_2_clicked();
    }
}


void ClickForm::on_pushButton_3_clicked()
{
    fangqiba();
}


void ClickForm::on_pushButton_4_clicked()
{
    if(stopBOOL)
        return;
    sdfg: successAgine();
    goto sdfg;
    /*if(checkWupin())
    {
        on_pushButton_4_clicked();
    }
    else
    {
        fangqiba();
        on_pushButton_2_clicked();
    }*/
}


void ClickForm::on_pushButton_5_clicked()
{
    checkWupin();
}


void ClickForm::on_pushButton_6_clicked()
{
    if(stopBOOL)
        return;
    if(checkWupin())
    {
        on_pushButton_4_clicked();
    }
    else
    {
        fangqiba();
        on_pushButton_2_clicked();
    }
}


void ClickForm::on_setEnd_clicked()
{
    stopBOOL=false;
    if(ui->checkDely->text().isEmpty() ||
        ui->mouseDely->text().isEmpty() ||
        ui->waitDely->text().isEmpty() ||
        ui->apbuzuLe->text().isEmpty())
    {
        QMessageBox::question(this,"设定","四个设定不能为空");
    }
    else if(ui->winHWID->text().isEmpty())
    {
        QMessageBox::question(this,"设定","窗口句柄不能为空");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        MOUSE_DELAY=ui->mouseDely->text().toInt();
        WAIT_DELAY=ui->waitDely->text().toInt();
        CHECK_DELAY=ui->checkDely->text().toInt();
        AP_BUZU=ui->apbuzuLe->text().toInt();
        EAT_AP_YAO=ui->apCheck->isChecked();
    }
}

void ClickForm::on_stopBT_clicked()
{
    stopBOOL=true;
    ui->stackedWidget->setCurrentIndex(0);
}

