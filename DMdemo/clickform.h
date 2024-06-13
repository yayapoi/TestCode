#ifndef CLICKFORM_H
#define CLICKFORM_H

#include <QWidget>
#include <dmobject.h>
#include "globalobject.h"
#include <QMap>

namespace Ui {
class ClickForm;
}

class ClickForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClickForm(QWidget *parent = nullptr);
    ~ClickForm();

    //进入活动页面，选择关卡等
    void huodongCheck();

    //放弃战斗
    void fangqiba();

    //七个物品判断
    bool checkWupin();

    //成功后自动开始
    void successAgine();

    //弹出ap不足的窗口
    bool apbuzu(bool eatyao, int &x, int &y);

    //正常识图的函数
    void function(INFO &doInfo);
    //检测格子有指定东西木有，true代表有这玩意
    bool checkWupin(INFO &doInfo);


    void closeEvent(QCloseEvent *e);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_setEnd_clicked();

    void on_stopBT_clicked();

private:
    Ui::ClickForm *ui;
    DmObject* dm=nullptr;
    QMap<QString,INFO> mapList;
    bool stopBOOL=false;
    QString checkPathStr="/data/taimanin/taimanin_shuatiaoqi/huodongToLevel/";
    QString fangqiPathStr="/data/taimanin/taimanin_shuatiaoqi/fangqi/";
    QString wupinPathStr="/data/taimanin/taimanin_shuatiaoqi/wupin/";
    QString zidongzhandouPathStr="/data/taimanin/taimanin_wuxianying/";
    QString exePath;
};

#endif // CLICKFORM_H
