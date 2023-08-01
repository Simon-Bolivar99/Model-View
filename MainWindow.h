#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>

class Model;
class QTableView;
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();
    void connectSignals();
    void buttonHandlerAdd();
    void buttonHandlerClear();
    void buttonHandlerRemove();

private:
    Model *m_model;
    QTableView* m_TableView;
    QPushButton *m_btn_add , *m_btn_rem, *m_btn_clr;

};
#endif // MAINWINDOW_H
