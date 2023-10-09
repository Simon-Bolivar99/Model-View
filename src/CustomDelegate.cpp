#include "include/CustomDelegate.h"
#include <QPainter>

CustomDelegate::CustomDelegate()
{
}

QSize CustomDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int data = index.model()->data(index, Qt::UserRole).toInt();
    QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;

    QPixmap pixmap(5,5);    

    pixmap.fill(Qt::white);
    painter->drawPixmap(myOption.rect.x()+3,myOption.rect.y()+3,myOption.rect.width()-6,myOption.rect.height()-3, pixmap);
    myOption.state = option.state & (~QStyle::State_HasFocus);
    QStyledItemDelegate::paint(painter,myOption,index);
    painter->setPen(QPen(Qt::black, 3, Qt::PenStyle(data)));
    painter->drawLine(myOption.rect.x()+6,myOption.rect.y()+9,myOption.rect.x()+90,myOption.rect.y()+9);

}
