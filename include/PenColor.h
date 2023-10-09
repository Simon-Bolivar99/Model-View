#pragma once

#include "libs/ColorToolButton.h"

#include <QList>
#include <QWidget>


class ComboLineBox;
class QSpinBox;
class ColorToolButton;
class QHBoxLayout;
class QPen;
class QPushButton;
class CustomDelegate;


class PenColor : public QWidget{
    Q_OBJECT
public:
    PenColor(QWidget *parent);
    ~PenColor() = default;

    QColor getColor();
    int getLine();
    int getThick();

private:
    void initTools();
    void createGui();
    void createItems();
    void paintLine();


private:

    ComboLineBox    *LineBox;
    QSpinBox        *ThickBox;
    ColorToolButton *ColorButton;
    QHBoxLayout     *Layout;
    CustomDelegate  *Delegate;

};
