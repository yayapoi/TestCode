#ifndef DMOBJECT_H
#define DMOBJECT_H

#include <QObject>
#include <QProcess>
//#include "dm/dm.h"
#include "dm/dm.tlh"

class DmObject : public QObject
{
    Q_OBJECT
public:
    explicit DmObject(QObject *parent = nullptr);
    ~DmObject();

    bool initDm();

    int GetMousePointWindow();

    int screenSize(int& x, int& y, int& w, int& h);

    int MoveTo(int x, int y);

    int LeftClick();

    int GetColorNum(int x1, int y1, int x2, int y2, const QString& color, double sim);

    int FindPic(int x1, int y1, int x2, int y2, const QString& pic_name, const QString& delta_color, double sim, int dir, int& x, int& y);
    int FindPicWithoutPath(int x1, int y1, int x2, int y2, const QString& pic_name, const QString& delta_color, double sim, int dir, int& x, int& y);
    int FindPic(int x1, int y1, int x2, int y2, const QString& pic_name, const QString& path, const QString& delta_color, double sim, int dir, int& x, int& y);

    int KeyDown(int vk);

    int KeyUp(int vk);
signals:

private:
    Idmsoft* dm=nullptr;
    int hwnd;
    QString dirStr="C:/Users/-/Desktop/warframe/taimanin/taimanin_wuxianying/";
};
#endif // DMOBJECT_H
