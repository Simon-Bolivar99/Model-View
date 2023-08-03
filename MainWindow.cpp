#include "MainWindow.h"
#include "AddDialog.h"
#include "Model.h"

#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_model = new Model(this);
    m_dialog = new AddDialog (this);
    createGui();
    connectSignals();
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

    m_TableView = new QTableView;

    m_TableView->setModel(m_model);

    auto hh = m_TableView->horizontalHeader();
        hh->setSectionResizeMode(Model::OPTS_NAME,   QHeaderView::ResizeMode::Stretch);
        hh->setSectionResizeMode(Model::OPTS_NUMBER, QHeaderView::ResizeMode::ResizeToContents);
        hh->setSectionResizeMode(Model::OPTS_FIRM,   QHeaderView::ResizeMode::ResizeToContents);
        hh->setSectionResizeMode(Model::OPTS_JOB,    QHeaderView::ResizeMode::ResizeToContents);

    auto button_layout = new QHBoxLayout;
        //button_layout->setMargin(5);
        button_layout->addWidget(m_btn_add);
        button_layout->addWidget(m_btn_rem);
        button_layout->addWidget(m_btn_clr);
        button_layout->addStretch();

    auto m_layout = new QGridLayout;
        m_layout->addLayout(button_layout, 0, 0);
        m_layout->addWidget(m_TableView, 1, 0);



        setLayout(m_layout);
}

void MainWindow::connectSignals()
{
    connect(m_btn_add, &QPushButton::clicked, this, &MainWindow::buttonHandlerAdd);
    connect(m_btn_rem, &QPushButton::clicked, this, &MainWindow::buttonHandlerRemove);
    connect(m_btn_clr, &QPushButton::clicked, this, &MainWindow::buttonHandlerClear);
    connect(m_dialog,  &QDialog::accepted,    this, &MainWindow::dialogAssepted);
}


void MainWindow::buttonHandlerAdd()
{

    m_dialog->show();

}

void MainWindow::buttonHandlerClear()
{
    m_model->removeRows(0, m_model->rowCount());
}

void MainWindow::buttonHandlerRemove()
{
    m_model->removeRows(0, 1);
}



void MainWindow::dialogAssepted()
{
    ModelData data;
        m_dialog->getData(data);
        m_model->addData(0,1,data);
}


