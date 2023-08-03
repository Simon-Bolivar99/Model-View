#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Model;
class QTableView;
class QPushButton;
class AddDialog;

struct ModelData;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();
    void connectSignals();    

private slots:
    void buttonHandlerAdd();
    void buttonHandlerClear();
    void buttonHandlerRemove();
    void dialogAssepted();


private:
    Model *m_model;
    AddDialog *m_dialog;
    QTableView* m_TableView;
    QPushButton *m_btn_add , *m_btn_rem, *m_btn_clr;

};
#endif // MAINWINDOW_H
