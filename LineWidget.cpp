#include "LineWidget.h"

#include <QPainter>

LineWidget::LineWidget(LineType lineType, QWidget *parent) :
    QWidget(parent),
    mLineType(lineType),
    mLineWidth(1),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setup(mLineWidth);
}

LineWidget::LineWidget(int lineWidth, QWidget *parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(-1),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setup(mLineWidth);
}

LineWidget::LineWidget(int lineWidth, int lineLength, QWidget* parent) :
    QWidget(parent),
    mLineWidth(lineWidth),
    mLineLength(lineLength),
    mIsBlended(false),
    mColor(QColor(127,127,127))
{
    setup(mLineWidth);
}

LineWidget::~LineWidget()
{

}

void LineWidget::setup(int val)
{
    if(mLineType == LineType::Horizontal) {
        setMinimumHeight(val);
        setMaximumHeight(val);
    }
    else {
        setMinimumWidth(val);
        setMaximumWidth(val);
    }
}

void LineWidget::setWidth(int width)
{
    mLineWidth = width;
    update();
}

void LineWidget::setLength(int length)
{
    mLineLength = length;
    update();
}

void LineWidget::setBlended(bool blended)
{
    mIsBlended = blended;
    update();
}

void LineWidget::setColor(QColor color)
{
    mColor = color;
    update();
}

QSize LineWidget::sizeHint() const
{
    if(mLineType == LineType::Horizontal) {
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
    else {
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
}

void LineWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    int lineLength = 0;
    int lineWidth = mLineWidth;
    if(mLineLength == -1)
    {
        if(mLineType == LineType::Horizontal) {
            lineLength = width();
        }
        else {
            lineLength = height();
        }
    }
    else
    {
        lineLength = mLineLength;
    }

    /* Line's start and end point. */
    QPointF start;
    QPointF end;

    if(mLineType == LineType::Horizontal) {
        start = QPointF(0, height()/2.0 - lineWidth/2.0);
        end = QPointF(lineLength, height()/2.0 - lineWidth/2.0);
    }
    else {
        start = QPointF(width()/2.0 - lineWidth/2.0, 0);
        end = QPointF(width()/2.0 - lineWidth/2.0, lineLength);
    }

    /* Start painting */
    QPainter painter(this);
    QPen pen(QBrush(mColor), mLineWidth);

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
