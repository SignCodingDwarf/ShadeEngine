#ifndef CREATE_SPRITE_LIST_H
#define CREATE_SPRITE_LIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <QObject>
#include <QTimer>

namespace ShadeEngine
{
    class CreateSpriteList : public QObject
    {
        Q_OBJECT
    public:
        CreateSpriteList();
        ~CreateSpriteList() = default;

    public slots:
        void generateList();

    signals:
        void spriteListUpdated(std::vector< std::vector<sf::Sprite> > sprite_layers);

    protected:
        unsigned int m_mode;
        std::vector<sf::Texture> m_textures_list;
        QTimer m_update_timer;
        std::vector< std::vector<sf::Sprite> > m_sprite_layers;

        void loadTextures();

        void mode1();
        void mode2();
        void mode3();
        void mode4();
    };
}

#endif
