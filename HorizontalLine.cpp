#include "HorizontalLine.h"

#include <QPainter>

HorizontalLine::HorizontalLine(QWidget *parent) :
    QWidget(parent),
    mLineWidth(1),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinHeight(mLineWidth);
}

HorizontalLine::HorizontalLine(int lineWidth, QWidget *parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinHeight(mLineWidth);
}

HorizontalLine::HorizontalLine(int lineWidth, int lineLength, QWidget* parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(lineLength),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setMinHeight(mLineWidth);
}

HorizontalLine::~HorizontalLine()
{

}

void HorizontalLine::setMinHeight(int val)
{
    setMinimumHeight(val);
    setMaximumHeight(val);
}

void HorizontalLine::setWidth(int width)
{
    mLineWidth = width;
    update();
}

void HorizontalLine::setLength(int length)
{
    mLineLength = length;
    update();
}

void HorizontalLine::setBlended(bool blended)
{
    mIsBlended = blended;
    update();
}

void HorizontalLine::setColor(QColor color)
{
    mColor = color;
    update();
}

QSize HorizontalLine::sizeHint() const
{
    int lineLength = 0;

    if(mLineLength == -1)
    {
        lineLength = parentWidget()->width();
    }
    else
    {
        lineLength = mLineLength;
    }

    return QSize(lineLength, mLineWidth);
}

void HorizontalLine::paintEvent(QPaintEvent *event)
{
    int lineLength = 0;
    int lineWidth = mLineWidth;
    if(mLineLength == -1)
    {
        lineLength = width();
    }
    else
    {
        lineLength = mLineLength;
    }

    /* Start painting */
    QPainter painter(this);
    QPen pen(mColor, mLineWidth);

    /* Start and end point. */
    QPointF start(0, height()/2.0 - lineWidth/2.0);
    QPointF end(lineLength, height()/2.0 - lineWidth/2.0);

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
