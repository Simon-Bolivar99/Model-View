#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Model;
class QTableView;
class QPushButton;
class AddDialog;
class QDataWidgetMapper;
class QLineEdit;
class QSortFilterProxyModel;

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
    void setMainWindowModel();

private slots:
    void buttonHandlerAdd();
    void buttonHandlerClear();
    void buttonHandlerRemove();
    void buttonHandlerFilter();
    void dialogAssepted();


private:
    Model* m_model;

    AddDialog* m_dialog;
    QSortFilterProxyModel* m_filter;

    QTableView* m_TableView;

    QPushButton* m_btn_add;
    QPushButton* m_btn_rem;
    QPushButton* m_btn_clr;
    QPushButton* m_btn_save;
    QPushButton* m_btn_load;
    QPushButton* m_btn_srch;

    QLineEdit* m_line_srch;

    QDataWidgetMapper* m_mapper;

};
#endif // MAINWINDOW_H
