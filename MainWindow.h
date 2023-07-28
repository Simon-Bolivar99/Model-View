#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
class Model;
class QTableView;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();

private:
    Model *m_model;
    QTableView* m_TableView;

};
#endif // MAINWINDOW_H
