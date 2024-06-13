#include "mainwindow.h"
#include <QApplication>
#include <clickform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClickForm w;
    w.show();
    return a.exec();
}
