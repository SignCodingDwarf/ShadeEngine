#include <QApplication>

#include "include/Test/TestShadeWidget.h"
#include "include/Graphics/SpriteLayersWidget.h"
#include "include/Test/CreateSpriteList.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShadeEngine::TestShadeWidget w(QPoint(0,0), QSize(400,600));
    w.show();

    ShadeEngine::SpriteLayersWidget w2(QPoint(500,0), QSize(450,450));
    w2.show();

    ShadeEngine::CreateSpriteList list;
    QObject::connect(&list, SIGNAL(spriteListUpdated(std::vector<std::vector<sf::Sprite> >)), &w2, SLOT(updateLayersArray(std::vector<std::vector<sf::Sprite> >)));

    return a.exec();
}
