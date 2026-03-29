#include "graphwidget.h"

#include <QPainter>

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget (parent)
{

    setMinimumSize(400, 300);
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    // === ОСИ КООРДИНАТ ===

    int w = width();
    int h = height();

    int centerX = w / 2;
    int centerY = h / 2;

    QPen axisPen(Qt::black, 2);
    painter.setPen(axisPen);

    painter.drawLine(0, centerY, w - 15, centerY);
    painter.drawLine(centerX, 15, centerX, h);


    // === СТРЕЛКИ НА ОСЯХ ===
    QPolygonF arrowX;
    arrowX << QPointF(w - 10, centerY)
           << QPointF(w - 20, centerY - 5)
           << QPointF(w - 20, centerY + 5);

    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    painter.drawPolygon(arrowX);

    QPolygonF arrowY;
    arrowY << QPointF(centerX, 10)
           << QPointF(centerX - 5, 20)
           << QPointF(centerX + 5, 20);

    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);
    painter.drawPolygon(arrowY);
}
