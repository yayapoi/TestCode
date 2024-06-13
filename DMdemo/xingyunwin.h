#ifndef XINGYUNWIN_H
#define XINGYUNWIN_H

#include <QMainWindow>
#include <dmobject.h>
#include "qtimer.h"
#include "globalobject.h"
#include <QMap>

namespace Ui {
class XingyunWin;
}

struct INFO1
{
    int x;
    int y;
    int w;
    int h;
    QString color;
};

class XingyunWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit XingyunWin(QWidget *parent = nullptr);
    ~XingyunWin();
    void delay(int ms);
    bool juesepanduan();
    bool jibanpanduan();
    bool juesesi();
    bool jibansi();

    void list900();
    void list1600();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::XingyunWin *ui;
    DmObject dm;
    QMap<QString,INFO1> mapList;
};

#endif // XINGYUNWIN_H
