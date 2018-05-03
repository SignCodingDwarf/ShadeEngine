/*!
 * @file AbstractShadeWidget.h
 * @brief Interface of classes used to integrate SFML rendering into Qt windows.
 * @author SignC0dingDw@rf
 * @date 19 April 2018
 *
 * Implementation of a Qt Widget allowing to render SFML content using a render window. <br>
 * Based on : https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt <br>
 * Abstract class. Must be inherited depending on your rendering requirements in order to be used. <br>
 * Inherits from QWidget and sf::RenderWindow.
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

#include "include/Graphics/AbstractShadeWidget.h"

namespace ShadeEngine
{
    AbstractShadeWidget::AbstractShadeWidget(const QPoint &position, const QSize &size, unsigned int refresh_rate_ms, QWidget *parent) : QWidget(parent), sf::RenderWindow(),
        m_initialized(false), m_background_color(sf::Color::Black)
    {
        // Setup some states to allow direct rendering into the widget
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);

        // Set strong focus to enable keyboard events to be received
        setFocusPolicy(Qt::StrongFocus);

        // Setup the widget geometry
        move(position);
        resize(size);

        // Setup the timer
        m_refresh_timer.setInterval(refresh_rate_ms);
        m_refresh_timer.setSingleShot(false); // Periodic call
    }

    void AbstractShadeWidget::setBackgroundColor(sf::Color color)
    {
        m_background_color = color;
    }

    sf::Color AbstractShadeWidget::getBackgroundColor() const
    {
        return m_background_color;
    }

    QPaintEngine* AbstractShadeWidget::paintEngine() const
    {
        return nullptr; // To stay consistent with WA_PaintOnScreen option, we set the built-in paintEngine to null pointer
    }

    void AbstractShadeWidget::showEvent(QShowEvent*)
    {
        if (!m_initialized)
        {
            // Create the SFML window with the widget handle
            sf::RenderWindow::create((sf::WindowHandle) winId());

            // Let the derived class do its specific stuff
            onInit();

            // Setup the timer to trigger a refresh at specified framerate
            connect(&m_refresh_timer, SIGNAL(timeout()), this, SLOT(repaint()));
            m_refresh_timer.start();

            m_initialized = true;
        }
    }

    void AbstractShadeWidget::paintEvent(QPaintEvent*)
    {
        // Let the derived class do its specific stuff
        onUpdate();

        // Display on screen
        display();
    }

    void AbstractShadeWidget::resizeEvent(QResizeEvent*)
    {
        setSize(sf::Vector2u(QWidget::width(), QWidget::height()));
    }

    void AbstractShadeWidget::fillBackground()
    {
        clear(m_background_color);
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
