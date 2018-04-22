#include <QApplication>

#include "include/Test/TestShadeWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShadeEngine::TestShadeWidget w(QPoint(100,200), QSize(400,600));
    w.show();

    return a.exec();
}
