/*!
 * @file SpriteLayersWidget.cpp
 * @brief Class used to render ovelapping layers of sprites.
 * @author SignC0dingDw@rf
 * @date 26 May 2018
 *
 * Implementation of a Qt Widget allowing to render overlapping layers of sprites. <br>
 * It is particularly designed for rendering of 2D gameboy-like or 2D point'n click games. <br>
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

#include "include/Graphics/SpriteLayersWidget.h"

#include <utility>
#include <iostream>

namespace ShadeEngine
{
    SpriteLayersWidget::SpriteLayersWidget(const QPoint &position, const QSize &size, unsigned int refresh_rate_ms, QWidget *parent) : AbstractShadeWidget(position, size, refresh_rate_ms, parent)
    {
    }

    void SpriteLayersWidget::updateLayersArray(std::vector<std::vector<sf::Sprite> > sprite_layers)
    {
        std::unique_lock<std::mutex>  __attribute__((unused))mutex_lock(m_layers_mutex); // Lock mutex to prevent updating when layers are rendered
        m_sprite_layers = std::move(sprite_layers);
    }

    void SpriteLayersWidget::onInit()
    {
        fillBackground();
    }

    void SpriteLayersWidget::onUpdate()
    {
        std::unique_lock<std::mutex>  __attribute__((unused))mutex_lock(m_layers_mutex); // Lock mutex to prevent rendering when layers are updated
        fillBackground();

        // Draw
        for(std::vector< std::vector<sf::Sprite> >::iterator layer_it = m_sprite_layers.begin(); layer_it != m_sprite_layers.end(); ++layer_it ) // Iterate over layers
        {
            for(std::vector<sf::Sprite>::iterator sprite_it = layer_it->begin(); sprite_it != layer_it->end(); ++sprite_it) // Iterate on sprites in each layer
            {
                draw(*sprite_it); // Draw current sprite
            }
        }
    }
}

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
