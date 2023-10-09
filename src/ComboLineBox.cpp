#include "include/ComboLineBox.h"
#include <QStylePainter>

ComboLineBox::ComboLineBox(QWidget *parent)
{

}

void ComboLineBox::paintEvent(QPaintEvent *event)
{

    QStylePainter painter(this);
    QStyleOptionComboBox opt;
    initStyleOption(&opt);
    painter.drawComplexControl(QStyle::CC_ComboBox, opt);
    painter.setPen(QPen(Qt::black,3,Qt::PenStyle(currentIndex()+1)));
    painter.drawLine(7, 13, 75, 13);
    painter.end();
}
