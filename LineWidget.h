#ifndef LINEWIDGET_H
#define LINEWIDGET_H

#include <QWidget>

class LineWidget : public QWidget
{
    Q_OBJECT

public:
    enum LineType {
        Horizontal,
        Vertical
    };

    LineWidget(LineType lineType, QWidget* parent = nullptr);
    LineWidget(int lineWidth, QWidget* parent = nullptr);
    LineWidget(int lineWidth, int lineLength, QWidget* parent = nullptr);

    ~LineWidget();

public:
    void setWidth(int width);
    void setLength(int length);
    void setBlended(bool blended);
    void setColor(QColor color);

protected:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

private:
    LineType mLineType;
    int mLineWidth;
    int mLineLength;
    bool mIsBlended;
    QColor mColor;

private:
    void setup(int val);
};

#endif // LINEWIDGET_H
