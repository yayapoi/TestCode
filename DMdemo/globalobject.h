#ifndef GLOBALOBJECT_H
#define GLOBALOBJECT_H

#include <QObject>
#include <QEventLoop>
#include <QTimer>

struct INFO
{
    int x;
    int y;
    int w;
    int h;
    QString color;

    QString path;
    bool cilckBool=false;
    int clickx=0;
    int clicky=0;

    bool gotoBool=true;
};

static int MOUSE_DELAY=200;
static int WAIT_DELAY=2200;
static int CHECK_DELAY=1800;
static int AP_BUZU=7000;
static bool EAT_AP_YAO=false;
static int FIGHT_DELAY=5000;

class GlobalObject : public QObject
{
    Q_OBJECT
public:
    explicit GlobalObject(QObject *parent = nullptr);

    static void delayMS(int ms)
    {
        QEventLoop loop;
        QTimer::singleShot(ms, &loop, SLOT(quit()));
        loop.exec();
    }
signals:

};

#endif // GLOBALOBJECT_H
