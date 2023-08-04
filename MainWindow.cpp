#include "MainWindow.h"
#include "AddDialog.h"
#include "Model.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_mapper(new QDataWidgetMapper(this))

{
    m_model = new Model(this);
    m_dialog = new AddDialog (this);
    createGui();
    //connectSignals();
}

MainWindow::~MainWindow()
{
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

    m_btn_srch = new QPushButton();
        m_btn_srch->setIcon(QIcon(":/icons/icons/search.svg"));
        m_btn_srch->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_line_srch = new QLineEdit();

    m_TableView = new QTableView;
        m_TableView->setEditTriggers(QAbstractItemView::DoubleClicked);

    m_TableView->setModel(m_model);
    m_filter = new QSortFilterProxyModel();
    m_filter->setSourceModel(m_model);

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
        searh_layout->addWidget(m_btn_srch);
        searh_layout->addWidget(m_line_srch);
        searh_layout->addStretch();

    auto m_layout = new QGridLayout;
        m_layout->addLayout(button_layout, 0, 0);
        m_layout->addWidget(m_TableView,   1, 0);
        m_layout->addLayout(searh_layout,  2, 0);



        setLayout(m_layout);
}

void MainWindow::connectSignals()
{
    /*           BUTTONS                  */
    connect(m_btn_add, &QPushButton::clicked, this, &MainWindow::buttonHandlerAdd);

    connect(m_btn_rem, &QPushButton::clicked, this, &MainWindow::buttonHandlerRemove);

    connect(m_btn_clr, &QPushButton::clicked, this, &MainWindow::buttonHandlerClear);

    connect(m_btn_srch, &QPushButton::clicked, this, &MainWindow::buttonHandlerFilter);

    /*           DIALOG                   */
    connect(m_dialog,  &QDialog::accepted,    this, &MainWindow::dialogAssepted);

    /*           FILTER                   */
    connect(m_filter, &QSortFilterProxyModel::filterCaseSensitivityChanged, this, &MainWindow::buttonHandlerFilter);

    /*           MAPPER                   */
    //connect(m_mapper, &QDataWidgetMapper::currentIndexChanged, m_model, &QTableView::selectRow);
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
        msgbox.setText( tr("Вы уверены, что хотите удалить последнюю строку?") );
        msgbox.setWindowTitle(tr("ОШИБКА"));
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
        msgbox.setDefaultButton(QMessageBox::Yes);
        msgbox.setIcon(QMessageBox::Icon::Warning);
        msgbox.setFixedSize( QSize(480, 240) );
    }
    if (msgbox.exec() == QMessageBox::Yes)
        m_model->removeRows(0, 1);
}

void MainWindow::buttonHandlerFilter()
{

}



void MainWindow::dialogAssepted()
{
    ModelData data;
        m_dialog->getData(data);
        m_model->addData(0,1,data);
}


