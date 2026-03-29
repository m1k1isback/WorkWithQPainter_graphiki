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
}
