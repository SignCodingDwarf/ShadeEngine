#include "include/Test/CreateSpriteList.h"

namespace ShadeEngine
{
    CreateSpriteList::CreateSpriteList() : QObject(), m_mode(0)
    {
        loadTextures();
        connect(&m_update_timer, SIGNAL(timeout()), this, SLOT(generateList()));

        m_update_timer.setInterval(1000);
        m_update_timer.setSingleShot(false);
        m_update_timer.setTimerType(Qt::PreciseTimer);
        m_update_timer.start();
    }

    void CreateSpriteList::generateList()
    {
        m_sprite_layers.clear();
        switch(m_mode)
        {
        case 0:
            m_mode = 1;
            break;
        case 1:
            mode1();
            m_mode = 2;
            break;
        case 2:
            mode2();
            m_mode = 3;
            break;
        case 3:
            mode3();
            m_mode = 4;
            break;
        case 4:
            mode4();
            m_mode = 0;
            break;
        default:
            m_mode = 0;
            break;
        }

        emit spriteListUpdated(m_sprite_layers);
    }

    void CreateSpriteList::loadTextures()
    {
        sf::Texture text1;
        text1.loadFromFile("/home/signcodingdwarf/Documents/git/ShadeEngine/ShadeEngine/resources/ShadowS.png");
        m_textures_list.push_back(text1);

        sf::Texture text2;
        text2.loadFromFile("/home/signcodingdwarf/Documents/git/ShadeEngine/ShadeEngine/resources/Qt.png");
        m_textures_list.push_back(text2);

        sf::Texture text3;
        text3.loadFromFile("/home/signcodingdwarf/Documents/git/ShadeEngine/ShadeEngine/resources/SFML.png");
        m_textures_list.push_back(text3);
    }

    void CreateSpriteList::mode1()
    {
        std::vector<sf::Sprite> layer1;

        sf::Sprite sp1;
        sp1.setTexture(m_textures_list[0]);
        sp1.setPosition(25,10);
        sp1.setScale(sf::Vector2f(0.417,0.417));
        layer1.push_back(sp1);

        m_sprite_layers.push_back(layer1);
    }

    void CreateSpriteList::mode2()
    {
        std::vector<sf::Sprite> layer1;

        sf::Sprite sp1;
        sp1.setTexture(m_textures_list[0]);
        sp1.setPosition(25,10);
        sp1.setScale(sf::Vector2f(0.417,0.417));
        layer1.push_back(sp1);

        sf::Sprite sp2;
        sp2.setTexture(m_textures_list[2]);
        sp2.setPosition(25,300);
        sp2.setScale(sf::Vector2f(0.333,0.333));
        layer1.push_back(sp2);


        m_sprite_layers.push_back(layer1);
    }

    void CreateSpriteList::mode3()
    {
        mode2();

        std::vector<sf::Sprite> layer2;

        sf::Sprite sp1;
        sp1.setTexture(m_textures_list[0]);
        sp1.setPosition(0,100);
        sp1.setScale(sf::Vector2f(0.500,0.500));
        sp1.setColor(sf::Color(255,0,0,180));
        layer2.push_back(sp1);

        m_sprite_layers.push_back(layer2);
    }

    void CreateSpriteList::mode4()
    {
        mode3();

        std::vector<sf::Sprite> layer3;

        sf::Sprite sp1;
        sp1.setTexture(m_textures_list[1]);
        sp1.setPosition(0,340);
        sp1.setScale(sf::Vector2f(0.125,0.125));
        layer3.push_back(sp1);

        sf::Sprite sp2;
        sp2.setTexture(m_textures_list[1]);
        sp2.setPosition(300,0);
        sp2.setScale(sf::Vector2f(0.125,0.125));
        layer3.push_back(sp2);

        sf::Sprite sp3;
        sp3.setTexture(m_textures_list[1]);
        sp3.setPosition(150,170);
        sp3.setScale(sf::Vector2f(0.125,0.125));
        layer3.push_back(sp3);

        m_sprite_layers.push_back(layer3);
    }
}
