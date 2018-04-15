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
