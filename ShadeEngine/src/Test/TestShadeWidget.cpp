#include "include/Test/TestShadeWidget.h"

namespace ShadeEngine
{
    TestShadeWidget::TestShadeWidget(const QPoint &position, const QSize &size, unsigned int refresh_rate_ms, QWidget *parent) : AbstractShadeWidget(position, size, refresh_rate_ms, parent), m_radius(10), m_direction(1)
    {
        setBackgroundColor(sf::Color::Blue);
        m_shape.setPosition(width()/2, height()/2);
    }

    void TestShadeWidget::onInit()
    {
        fillBackground();
    }

    void TestShadeWidget::onUpdate()
    {
        fillBackground();

        m_shape.setRadius(m_radius);
        m_shape.setOrigin(m_radius,m_radius); // Set circle origin to circle center

        draw(m_shape);

        (m_direction > 0 && m_radius + m_direction * 10 > std::min(height()/2, width() / 2)) && (m_direction = -1);
        (m_direction < 0 && m_radius + m_direction * 10 <= 0) && (m_direction = 1);

        m_radius += m_direction * 10;
    }
}
