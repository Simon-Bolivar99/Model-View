#pragma once

#include <QComboBox>

class ComboLineBox : public QComboBox {
    Q_OBJECT
public:
    ComboLineBox(QWidget *parent = nullptr);
    ~ComboLineBox() = default;

protected:
    void paintEvent(QPaintEvent *event);
};
