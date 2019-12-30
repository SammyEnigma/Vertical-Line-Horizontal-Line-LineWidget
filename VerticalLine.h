#ifndef VERTICAL_LINE
#define VERTICAL_LINE

#include <QWidget>

class VerticalLine : public QWidget
{
    Q_OBJECT

public:
    VerticalLine(QWidget* parent = nullptr);
    VerticalLine(int lineWidth, QWidget* parent = nullptr);
    VerticalLine(int lineWidth, int lineLength, QWidget* parent = nullptr);

    ~VerticalLine();

public:
    void setWidth(int width);
    void setLength(int length);
    void setBlended(bool blended);
    void setColor(QColor color);

protected:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

private:
    int mLineWidth;
    int mLineLength;
    bool mIsBlended;
    QColor mColor;

private:
    void setMinWidth(int val);
};

#endif // VERTICAL_LINE
