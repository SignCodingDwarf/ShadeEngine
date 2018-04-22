#ifndef TEST_SHADE_WIDGET_H
#define TEST_SHADE_WIDGET_H

#include "include/Graphics/AbstractShadeWidget.h"

namespace ShadeEngine
{
    class TestShadeWidget : public AbstractShadeWidget
    {
    public:
        TestShadeWidget(const QPoint& position, const QSize& size, unsigned int refresh_rate_ms = 60, QWidget* parent = NULL);

        virtual ~TestShadeWidget() = default;

    protected:
        int m_radius;
        int m_direction;
        sf::CircleShape m_shape;

        virtual void onInit() final;

        virtual void onUpdate() final;
    };
}

#endif
