#ifndef HORIZONTAL_LINE
#define HORIZONTAL_LINE

#include <QWidget>

class HorizontalLine : public QWidget
{
    Q_OBJECT

public:
    HorizontalLine(QWidget* parent = nullptr);
    HorizontalLine(int lineWidth, QWidget* parent = nullptr);
    HorizontalLine(int lineWidth, int lineLength, QWidget* parent = nullptr);

    ~HorizontalLine();

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
    void setMinHeight(int val);
};

#endif // HORIZONTAL_LINE
