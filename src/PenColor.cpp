#include "include/PenColor.h"
#include "include/CustomDelegate.h"
#include "include/ComboLineBox.h"

#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPen>
#include <QPainter>
#include <QAction>
#include <QPushButton>

#include <QDebug>

PenColor::PenColor(QWidget* parent) : LineBox(new ComboLineBox(this)), ThickBox(new QSpinBox(this)),
    ColorButton(new ColorToolButton(this)), Layout(new QHBoxLayout(this)), Delegate(new CustomDelegate(this))
{
    initTools();
    createGui();
}

QColor PenColor::getColor()
{
    return ColorButton->getColor();
}

int PenColor::getLine()
{
    return LineBox->currentIndex();
}

int PenColor::getThick()
{
    return ThickBox->value();
}

void PenColor::initTools()
{
    ThickBox->setValue(2);
    createItems();
    LineBox->setItemDelegate(Delegate);
}

void PenColor::createGui()
{
     //LineBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        LineBox->setMinimumSize(QSize(100,25));
        Layout->addWidget(LineBox);
    //ThickBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        Layout->addWidget(ThickBox);
    //ColorButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ColorButton->setMinimumSize(QSize(40,25));
        Layout->addWidget(ColorButton);
    Layout->setSizeConstraint(QLayout::SetFixedSize);

//   auto Button = new QPushButton("Ok");
//    Layout->addWidget(Button);
//    connect(Button, &QPushButton::clicked, this, [this](){
//          qDebug()<<getLine();
//          qDebug()<<getThick();
//          qDebug()<<getColor();
//    });

    setLayout(Layout);
}

void PenColor::createItems()
{
    for (int i = 1; i < 6;i++)
        LineBox->addItem("",i);
}

