#include "VerticalLine.h"

#include <QPainter>

VerticalLine::VerticalLine(QWidget *parent) :
    QWidget(parent),
    mLineWidth(1),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinWidth(mLineWidth);
}

VerticalLine::VerticalLine(int lineWidth, QWidget *parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinWidth(mLineWidth);
}

VerticalLine::VerticalLine(int lineWidth, int lineLength, QWidget* parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(lineLength),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinWidth(mLineWidth);
}

VerticalLine::~VerticalLine()
{

}

void VerticalLine::setMinWidth(int val)
{
    setMinimumWidth(val);
    setMaximumWidth(val);
}

void VerticalLine::setWidth(int width)
{
    mLineWidth = width;
    update();
}

void VerticalLine::setLength(int length)
{
    mLineLength = length;
    update();
}

void VerticalLine::setBlended(bool blended)
{
    mIsBlended = blended;
}

void VerticalLine::setColor(QColor color)
{
    mColor = color;
    update();
}

QSize VerticalLine::sizeHint() const
{
    int lineLength = 0;

    if(mLineLength == -1)
    {
        lineLength = parentWidget()->height();
    }
    else
    {
        lineLength = mLineLength;
    }

    return QSize(mLineWidth, lineLength);
}

void VerticalLine::paintEvent(QPaintEvent *event)
{
    int lineLength = 0;
    int lineWidth = mLineWidth;
    if(mLineLength == -1)
    {
        lineLength = height();
    }
    else
    {
        lineLength = mLineLength;
    }

    /* Start painting */
    QPainter painter(this);
    QPen pen(mColor, mLineWidth);

    /* Start and end point. */
    QPointF start(width()/2.0 - lineWidth/2.0, 0);
    QPointF end(width()/2.0 - lineWidth/2.0, lineLength);

    if(mIsBlended) {
        /* Make the Gradient for the line. */
        QLinearGradient gradient(start, end);
        gradient.setColorAt(0, Qt::transparent);
        gradient.setColorAt(0.5, mColor);
        gradient.setColorAt(1, Qt::transparent );

        pen.setBrush(QBrush(gradient));
    }

    /* Set the line's pen. */
    painter.setPen(pen);

    /* Draw the line. */
    painter.drawLine(start, end);
}
