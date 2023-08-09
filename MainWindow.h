#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class AddDialog;
class Model;
class QAction;
class QTableView;
class QPushButton;
class QDataWidgetMapper;
class QLineEdit;
class QMenu;
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
    void createActions();

private slots:
    void buttonHandlerAdd();
    void buttonHandlerClear();
    void buttonHandlerRemove();
    void buttonHandlerSave();
    void buttonHandlerLoad();
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

    QMenu* m_menu;

    QAction* m_rm_act;
    QAction* m_cp_act;
    QAction* m_add_act;

    QLineEdit* m_line_srch;

    QDataWidgetMapper* m_mapper;

};
#endif // MAINWINDOW_H
