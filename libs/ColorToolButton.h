#pragma once

#include <QToolButton>
#include <QList>

class QAction;
class QMenu;
class QColorDialog;
class QSize;

class ColorToolButton : public QToolButton{
    Q_OBJECT

public:
    ColorToolButton(QWidget *parent = nullptr);
    ~ColorToolButton();

public:
    QColor getColor() {return IconColor;}

private:
    void createGui();
    void connectSignals();
    void createActions();
    void buttonClick();
    void updateColor();//изменение цветов после работы с диалоговым окном
    void createMenu();//создание QMenu
    void updateMenu();
    void createIcon(QColor color, const QSize& sz);

    void deleteActions();

    void resizeEvent(QResizeEvent *);

private:
    struct action_color_t{
        QAction  *Action;
        QColor    ActionColor;
        bool      Visible;

    };
    QList <action_color_t> action_list;

    QMenu        *Menu   ;
    QColor        IconColor;   //цвет  ColorToolButton
    QColorDialog *ColorDialog;
    QSize         sz;          // размер icon

    int numColors;

};
