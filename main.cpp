#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.setWidth(800);
    w.setHeight(800);
    w.show();
    w.start();
    return a.exec();
}
