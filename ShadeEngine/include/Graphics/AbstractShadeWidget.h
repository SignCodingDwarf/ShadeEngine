/*!
 * @file AbstractShadeWidget.h
 * @brief Interface of classes used to integrate SFML rendering into Qt windows.
 * @author SignC0dingDw@rf
 * @date 19 April 2018
 *
 * Definition of a Qt Widget allowing to render SFML content using a render window. <br>
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


#ifndef SHADE_WIDGET_H
#define SHADE_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <SFML/Graphics.hpp>

/*!
* @namespace ShadeEngine
* @brief A namespace used to regroup all classes associated with ShadeEngine library
*/
namespace ShadeEngine
{
    /*! \class AbstractShadeWidget
    * \brief Class allowing to manage SFML window update and periodic SFML rendering.
    *
    * Definition of a class used to manage SFML rendering and integrating it into Qt windows. <br>
    * Abstract class. Must be inherited depending on your rendering requirements in order to be used. <br>
    * Inherits from QWidget and sf::RenderWindow.
    *
    */
    class AbstractShadeWidget : public QWidget, public sf::RenderWindow
    {
    public:
        /*!
        * @brief Constructor of the AbstractShadeWidget class
        * @param position : Position of widget (into the desktop rendering or parent window).
        * @param size : Rendering area size.
        * @param refresh_rate_ms : Rate at which the paint Event is triggered in milliseconds. Default is 60.
        * @param parent : Parent widget. Default is NULL.
        *
        * Constructor of the AbstractShadeWidget class allowing to configure rendering area and setup repaint timer.
        *
        */
        AbstractShadeWidget(const QPoint& position, const QSize& size, unsigned int refresh_rate_ms = 60, QWidget* parent = NULL);

        /*!
        * @brief Destructor of the AbstractShadeWidget class
        *
        * Virtual method. Does nothing.
        *
        */
        virtual ~AbstractShadeWidget() = default;

        /*!
        * @brief Allow to update background color
        * @param color : New background color.
        *
        * Allows to control the background color (i.e. color of widget areas that will not be painted otherwise).
        *
        */
        void setBackgroundColor(sf::Color color);

        /*!
        * @brief Get current background color
        * @return Current background color
        *
        * Constant method.
        *
        */
        sf::Color getBackgroundColor() const;

    protected:
        QTimer m_refresh_timer; /*!< Timer used to trigger window repaint. */
        bool m_initialized; /*!< Flag indicating if rendering has been initialized. */
        sf::Color m_background_color; /*!< Color with which the background is repainted. */

        /*!
        * @brief Redefinition of QWidget's paintEngine
        * @return A null paint engine
        *
        * Redefinition of QWidget's paint engine that returns a null engine to transfer rendering to SFML. <br>
        * Constant method. <br>
        * Virtual method cannot be redefined in child classes.
        *
        */
        virtual QPaintEngine* paintEngine() const final;

        /*!
        * @brief Actions performed on a show event
        * @param Unused show event
        *
        * Redefinition of QWidget's show event handler.
        * On first show, creates rendering window, perform user specific actions (via OnInit) and starts periodic refresh.
        * Does nothing after first initialization. <br>
        * Virtual method cannot be redefined in child classes.
        *
        */
        virtual void showEvent(QShowEvent*) final;

        /*!
        * @brief Actions performed on a paint event
        * @param Unused paint event
        *
        * Redefinition of QWidget's paint event handler. Updates display with user action (via onUpdate). <br>
        * Virtual method cannot be redefined in child classes.
        *
        */
        virtual void paintEvent(QPaintEvent*) final;

        /*!
        * @brief Actions performed on a resize event
        * @param Unused resize event
        *
        * Redefinition of QWidget's resize event handler. Resizes renderingWindow so that it always matches Widget's size. <br>
        * Virtual method cannot be redefined in child classes.
        *
        */
        virtual void resizeEvent(QResizeEvent*) final;

        /*!
        * @brief Clears window content and applies background color
        *
        * This method is never called directly by any event handling methods because it is up to the user to handler rendering.
        * Thus this method should be used in onInit and onDisplay to clean window content
        * to avoid visual glitches when updating rendering.
        *
        */
        void fillBackground();

        /*!
        * @brief User specific rendering initialization
        *
        * Application specific operations performed the first time widget is shown.
        * It is highly recommended to first initialize rendering area with background color using fillBackground. <br>
        * Abstract method.
        *
        */
        virtual void onInit() = 0;

        /*!
        * @brief User specific rendering operations
        *
        * Application specific operations performed every time rendering is refreshed.
        * If display is updated, it is highly recommended to first clean up rendering area with background color using fillBackground.
        * This operation is not performed automatically since rendering may not be updated depending on application requirements. <br>
        * Abstract method.
        *
        */
        virtual void onUpdate() = 0;
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
