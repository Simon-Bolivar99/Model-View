#include "libs/ColorToolButton.h"

#include <QMenu>
#include <QToolButton>
#include <QColorDialog>
#include <QString>
#include <QList>
#include <QPainter>

#include <QDebug>

ColorToolButton::ColorToolButton(QWidget *parent)
    :  ColorDialog (new QColorDialog(this)), Menu(new QMenu(this)), numColors (ColorDialog->customCount()),
      IconColor(ColorDialog->customColor(0)),  sz (size())
{
    createActions();
    createGui();
    connectSignals();

}

ColorToolButton::~ColorToolButton()
{
    deleteActions();
}

void ColorToolButton::createGui()
{
    createIcon(IconColor, {56, 56});
    setPopupMode(QToolButton::DelayedPopup);
    createMenu();
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    for (int i = 0; i <action_list.size(); i++){
         connect(action_list[i].Action, &QAction::triggered, this, [this, i](bool checked) {
             Q_UNUSED(checked)
             IconColor = ColorDialog->customColor(i);
             createIcon(ColorDialog->customColor(i),sz);
         });
    }
}

void ColorToolButton::createActions()
{

    QPixmap pixmap(QSize(56,36));
    for (int i=0;i<numColors;i++){
        pixmap.fill(ColorDialog->customColor(i));
        QPainter p(&pixmap);
        p.drawRect(0,0,55,35);
        action_list.push_back({new QAction(QIcon(pixmap),tr(ColorDialog->customColor(i).name().toUtf8()),this),
                         ColorDialog->customColor(i),
                         false});
    }

}

void ColorToolButton::resizeEvent(QResizeEvent *e)
{
    sz = size();
    createIcon(IconColor, sz);

}

void ColorToolButton::buttonClick()
{
     const QColorDialog::ColorDialogOptions options = QFlag(QColorDialog::DontUseNativeDialog);
     QColor color = ColorDialog->getColor(IconColor,this, "Select Color",options);
     if (color.isValid()){
         IconColor = color;
         createIcon(IconColor, sz);
     }
     updateColor();
     updateMenu();

}

void ColorToolButton::updateColor()
{
    QPixmap pixmap(QSize(56,36));
    for (int i =0;i<action_list.size();i++){
        action_list[i].ActionColor=ColorDialog->customColor(i);
        pixmap.fill(action_list[i].ActionColor);
            QPainter p(&pixmap);
            p.drawRect(0,0,55,35);
            action_list[i].Action->setIcon(QIcon(pixmap));
            action_list[i].Action->setText(tr(action_list[i].ActionColor.name().toUtf8()));
    }
}

void ColorToolButton::createMenu()
{
        for (int i =0;i<action_list.size();i++){
            for (int j = 0; j<i;j++){
                if(action_list[i].ActionColor == action_list[j].ActionColor)
                {
                    action_list[i].Visible = false;
                    break;
                }
                else
                    action_list[i].Visible = true;
            }
            if(action_list[i].Visible == true || i == 0)
                Menu->addAction(action_list[i].Action);
        }
    setMenu(Menu);

}

void ColorToolButton::updateMenu()
{
    Menu->clear();
    createMenu();
}


void ColorToolButton::createIcon(QColor color, const QSize& sz)
{
    QPixmap pixmap(sz);
           pixmap.fill(color);
           QPainter p(&pixmap);
           p.drawRect(0,0, sz.width()-1, sz.height()-1);

       auto icon = QIcon();
           icon.addPixmap(pixmap, QIcon::Mode::Active);
           icon.addPixmap(pixmap, QIcon::Mode::Selected);
           icon.addPixmap(pixmap, QIcon::Mode::Normal);

       setIcon(icon);
       setIconSize({static_cast<int>(sz.width()*0.4),
                    static_cast<int>(sz.height()*0.4)});
}

void ColorToolButton::deleteActions()
{
    for (int i = 0;i<numColors;i++)
      delete  action_list[i].Action;
}

