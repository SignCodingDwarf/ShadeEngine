/*!
 * @file SpriteLayersWidget.h
 * @brief Class used to render ovelapping layers of sprites.
 * @author SignC0dingDw@rf
 * @date 26 May 2018
 *
 * Definition of a Qt Widget allowing to render overlapping layers of sprites. <br>
 * It is particularly designed for rendering of 2D gameboy-like or 2D point'n click games. <br>
 * The sprites to render are organized as layers. The first layer is the first rendered, the second one is rendered over it and so on. <br>
 * Inherits from AbstractShadeWidget.
 *
 */

/*
Copyright (c) 2018 SignC0dingDw@rf. All rights reserved

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Copywrong (w) 2018 SignC0dingDw@rf. All profits reserved.

This program is dwarven software: you can redistribute it and/or modify
it provided that the following conditions are met:

   * Redistributions of source code must retain the above copywrong
     notice and this list of conditions and the following disclaimer
     or you will be chopped to pieces AND eaten alive by a Bolrag.

   * Redistributions in binary form must reproduce the above copywrong
     notice, this list of conditions and the following disclaimer in
     the documentation and other materials provided with it or they
     will be axe-printed on your stupid-looking face.

   * Any commercial use of this program is allowed provided you offer
     99% of all your benefits to the Dwarven Tax Collection Guild.

   * This software is provided "as is" without any warranty and especially
     the implied warranty of merchantability or fitness to purport.
     In the event of any direct, indirect, incidental, special, examplary
     or consequential damages (including, but not limited to, loss of use;
     loss of data; beer-drowning; business interruption; goblin invasion;
     procurement of substitute goods or services; beheading; or loss of profits),
     the author and all dwarves are not liable of such damages even
     the ones they inflicted you on purpose.

   * If this program "does not work", that means you are an elf
     and are therefore too stupid to use this program.

   * If you try to copy this program without respecting the
     aforementionned conditions, then you're wrong.

You should have received a good beat down along with this program.
If not, see <http://www.dwarfvesaregonnabeatyoutodeath.com>.
*/

#ifndef SPRITE_LAYERS_WIDGET_H
#define SPRITE_LAYERS_WIDGET_H

#include <atomic>
#include <mutex>
#include <vector>
#include <SFML/Graphics.hpp>

#include "AbstractShadeWidget.h"

/*!
* @namespace ShadeEngine
* @brief A namespace used to regroup all classes associated with ShadeEngine library
*/
namespace ShadeEngine
{
    /*! \class SpriteLayersWidget
    * \brief Class allowing to manage SFML window update and periodic SFML rendering.
    *
    * Definition of a class used to render SFML sprites as overlapping layers and integrate them into Qt windows. <br>
    * Inherits from AbstractShadeWidget.
    *
    */
    class SpriteLayersWidget : public AbstractShadeWidget
    {
        Q_OBJECT
    public:
        /*!
        * @brief Constructor of the SpriteLayersWidget class
        * @param position : Position of widget (into the desktop rendering or parent window).
        * @param size : Rendering area size.
        * @param refresh_rate_ms : Rate at which the paint Event is triggered in milliseconds. Default is 60.
        * @param parent : Parent widget. Default is NULL.
        *
        * Constructor of the SpriteLayersWidget class allowing to configure rendering area and setup repaint timer.
        *
        */
        SpriteLayersWidget(const QPoint& position, const QSize& size, unsigned int refresh_rate_ms = 60, QWidget* parent = NULL);

        /*!
        * @brief Destructor of the SpriteLayersWidget class
        *
        * Virtual method. Does nothing.
        *
        */
        virtual ~SpriteLayersWidget() = default;

    public slots:
        /*!
        * @brief Update the layer arrays of sprites.
        * @param sprite_layers : Array of sprite vectors to render.
        *
        * Set the array of sprite vectors.Each vector corresponds to a rendering layer. <br>
        * The first layer is the first rendered, the second is rendered on top of it and so on. If sprites overlap on a same layer, the one with the higher inex is rendered on top of the other. <br>
        * Slot.
        *
        */
        void updateLayersArray(std::vector< std::vector<sf::Sprite> > sprite_layers);

    protected:
        std::atomic<bool> m_updated; /*!< Flag indicating if list of sprites to render has been updated. */
        std::mutex m_layers_mutex; /*!< Mutex protecting the access to the layers vector. */
        std::vector< std::vector<sf::Sprite> > m_sprite_layers; /*!< List of overlapping layers containing sprites to render. */

        /*!
        * @brief User specific rendering initialization
        *
        * Application specific operations performed the first time widget is shown.
        * Covers rendering area with background color. <br>
        * Virtual final method.
        *
        */
        virtual void onInit() final;

        /*!
        * @brief User specific rendering operations
        *
        * Fills the background with background color then display sprite layers one after another. <br>
        * Virtual final method.
        *
        */
        virtual void onUpdate() final;
    };
}

#endif

//  ______________________________
// |                              |
// |    ______________________    |
// |   |                      |   |
// |   |         Sign         |   |
// |   |        C0ding        |   |
// |   |        Dw@rf         |   |
// |   |         1.0          |   |
// |   |______________________|   |
// |                              |
// |______________________________|
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |__|
