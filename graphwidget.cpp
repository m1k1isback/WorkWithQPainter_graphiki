#include "graphwidget.h"

#include <QPainter>
#include <QPainterPath>

#include <cmath>

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget (parent)
{

    setMinimumSize(400, 300);
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    int w = width();
    int h = height();

    int centerX = w / 2;
    int centerY = h / 2;


    // === СЕТКА ===
    QPen gridPen(QColor(200, 200, 200), 1);
    painter.setPen(gridPen);

    for (int x = 0; x <= w; x += 50) {
        //if(x == centerX) continue;
        painter.drawLine(x, 0, x, h);
    }

    for (int y = 0; y <= h; y += 50) {
        //if(y == centerY) break;
        painter.drawLine(0, y, w, y);
    }


    // === ОСИ КООРДИНАТ ===
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


    // === ГРАФИК sin(x) ===
    painter.setBrush(Qt::NoBrush);
    QPen graphPen(Qt::blue, 2);
    painter.setPen(graphPen);
    QPainterPath path;

    double xStart = 0;
    double yStart = std::sin(xStart);

    // Преобразовать в экранные координаты
    int scale = 20;
    int startX = centerX + xStart * scale;
    int startY = centerY - yStart * scale;

    path.moveTo(startX, startY);

    for (double x = 0; x <= w; x += 0.1) {
        double y = std::sin(x);

        int screenX = centerX + x * scale;
        int screenY = centerY - y * scale;

        path.lineTo(screenX, screenY);
    }
    painter.drawPath(path);
}
