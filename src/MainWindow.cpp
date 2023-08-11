#include "include/MainWindow.h"
#include "include/AddDialog.h"
#include "include/Model.h"

#include <fstream>


#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QTableView>
#include <QHeaderView>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QAction>
#include <QMenu>
#include <QFileDialog>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_mapper(new QDataWidgetMapper(this))

{
    m_model = new Model(this);
    m_dialog = new AddDialog (this);
    createActions();
    createGui();
    connectSignals();
}


void MainWindow::createGui()
{
    m_dialog->hide();
    m_btn_add = new QPushButton();
        m_btn_add->setIcon(QIcon(":/icons/icons/positive.svg"));
        m_btn_add->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_btn_rem = new QPushButton();
        m_btn_rem->setIcon(QIcon(":/icons/icons/negative.svg"));
        m_btn_rem->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_btn_clr = new QPushButton();
        m_btn_clr->setIcon(QIcon(":/icons/icons/cross.svg"));
        m_btn_clr->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_btn_save = new QPushButton();
        m_btn_save->setIcon(QIcon(":/icons/icons/save.svg"));
        m_btn_save->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_btn_load = new QPushButton();
        m_btn_load->setIcon(QIcon(":/icons/icons/load.svg"));
        m_btn_save->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


    m_line_srch = new QLineEdit();
        m_line_srch->setPlaceholderText(tr("Поиск"));
        m_line_srch->addAction(QIcon(":/icons/icons/search.svg"), QLineEdit::TrailingPosition);

    m_TableView = new QTableView;
        m_TableView->setEditTriggers(QAbstractItemView::DoubleClicked);
        m_TableView->setContextMenuPolicy(Qt::CustomContextMenu);
        m_TableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_filter = new QSortFilterProxyModel();

    m_filter->setSourceModel(m_model);
        m_filter->setFilterKeyColumn(-1);
        m_filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
    m_TableView->setModel(m_filter);


    auto hh = m_TableView->horizontalHeader();
        hh->setSectionResizeMode(Model::OPTS_NAME,   QHeaderView::ResizeMode::Stretch);
        hh->setSectionResizeMode(Model::OPTS_NUMBER, QHeaderView::ResizeMode::ResizeToContents);
        hh->setSectionResizeMode(Model::OPTS_FIRM,   QHeaderView::ResizeMode::ResizeToContents);
        hh->setSectionResizeMode(Model::OPTS_JOB,    QHeaderView::ResizeMode::ResizeToContents);

    auto button_layout = new QHBoxLayout;
        button_layout->addWidget(m_btn_add);
        button_layout->addWidget(m_btn_rem);
        button_layout->addWidget(m_btn_clr);
        button_layout->addStretch();
        button_layout->addWidget(m_btn_save);
        button_layout->addWidget(m_btn_load);

    auto searh_layout = new QHBoxLayout;
        searh_layout->addWidget(m_line_srch);
        searh_layout->addStretch();

    auto m_layout = new QGridLayout;
        m_layout->addLayout(button_layout, 0, 0);
        m_layout->addWidget(m_TableView,   1, 0);
        m_layout->addLayout(searh_layout,  2, 0);

    m_menu = new QMenu;

        m_menu->addAction(m_add_act);
        m_menu->addSeparator();
        m_menu->addAction(m_rm_act);




        setLayout(m_layout);
}


void MainWindow::connectSignals()
{
    connect(m_btn_add, &QPushButton::clicked, this, &MainWindow::buttonHandlerAdd);

    connect(m_btn_rem, &QPushButton::clicked, this, &MainWindow::buttonHandlerRemove);

    connect(m_btn_clr, &QPushButton::clicked, this, &MainWindow::buttonHandlerClear);

    connect(m_btn_save,&QPushButton::clicked, this, &MainWindow::buttonHandlerSave);

    connect(m_btn_load,&QPushButton::clicked, this, &MainWindow::buttonHandlerLoad);


    connect(m_dialog,  &QDialog::accepted,    this, &MainWindow::dialogAssepted);

    connect(m_line_srch, &QLineEdit::returnPressed, this, [this]() {
        m_filter->setFilterFixedString(m_line_srch->text());
    });


    connect(m_rm_act, &QAction::triggered, this, &MainWindow::buttonHandlerRemove);

    connect(m_add_act, &QAction::triggered, this, &MainWindow::buttonHandlerAdd);


    connect(m_TableView, &QTableView::customContextMenuRequested, this, [this](const QPoint &pos){
       auto index = m_filter->mapToSource(m_TableView->indexAt(pos));
       if (index.row() >= 0){
           m_menu ->popup(m_TableView->viewport()->mapToGlobal(pos));
       }
    });

    //connect(m_mapper, &QDataWidgetMapper::currentIndexChanged, m_model, &QTableView::selectRow);
}

void MainWindow::setMainWindowModel()
{

}

void MainWindow::createActions()
{
    m_rm_act = new QAction(QIcon(":/icons/icons/negative.svg"),tr("&Удалить"),this);
    m_add_act = new QAction(QIcon(":/icons/icons/positive.svg"),tr("&Добавить"),this);
}




void MainWindow::buttonHandlerAdd()
{

    m_dialog->show();

}

void MainWindow::buttonHandlerClear()
{
    QMessageBox msgbox;
    {
        msgbox.setText( tr("Вы уверены, что хотите удалить таблицу?") );
        msgbox.setWindowTitle(tr("ОШИБКА"));
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
        msgbox.setDefaultButton(QMessageBox::Yes);
        msgbox.setIcon(QMessageBox::Icon::Warning);
        msgbox.setFixedSize( QSize(480, 240) );
    }
    if (msgbox.exec() == QMessageBox::Yes)
        m_model->removeRows(0, m_model->rowCount());
}



void MainWindow::buttonHandlerRemove()
{
    QMessageBox msgbox;
    {
        msgbox.setText( tr("Вы уверены, что хотите удалить выделеные строки") );
        msgbox.setWindowTitle(tr("ПРЕДУПРЕЖДЕНИЕ"));
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
        msgbox.setDefaultButton(QMessageBox::Yes);
        msgbox.setIcon(QMessageBox::Icon::Warning);
        msgbox.setFixedSize( QSize(480, 240) );
    }
    if (msgbox.exec() == QMessageBox::Yes) {


            auto sel = m_TableView->selectionModel()->selectedRows();
            if (!sel.empty())
            {
                auto idx = m_filter->mapToSource(m_filter->index(sel.at(0).row(), 0));
                m_model->removeRows(idx.row(),sel.size());
            }

    }
}

void MainWindow::buttonHandlerSave()
{

    QString fname = QFileDialog::getSaveFileName(this, tr("Сохранить телефонную книгу"), "" , tr("*.json")); 
    m_model->toJson(fname);

}

void MainWindow::buttonHandlerLoad()
{
    QString fname = QFileDialog::getOpenFileName(this, tr("Загрузить телефонную книгу"), "" , tr("*.json"));
    m_model->fromJson(fname);
    return;
}


void MainWindow::dialogAssepted()
{
    ModelData data;
        m_dialog->getData(data);

        auto sel = m_TableView->selectionModel()->selectedRows();
        if (!sel.empty()){
            auto idx = m_filter->mapToSource(m_filter->index(sel.at(0).row(), 0));
            m_model->addData(idx.row(),1,data);
        }
        else
            m_model->addData(0,1,data);



}




