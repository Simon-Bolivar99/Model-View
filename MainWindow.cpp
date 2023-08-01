#include "MainWindow.h"
#include "Model.h"
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_model = new Model(this);
    createGui();
    connectSignals();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createGui()
{
    m_btn_add = new QPushButton("+");
        m_btn_add->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_rem = new QPushButton("-");
        m_btn_rem->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_clr = new QPushButton("C");
        m_btn_clr->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_TableView = new QTableView;

    m_TableView->setModel(m_model);

    auto m_layout = new QGridLayout;
        m_layout->setMargin(5);
        m_layout->addWidget(m_btn_add,         0, 0, 1, 1);
        m_layout->addWidget(m_btn_rem,         0, 1, 1, 1);
        m_layout->addWidget(m_btn_clr,         0, 2, 1, 1);
        m_layout->addWidget(m_TableView,       1, 0, 1, 4);



        setLayout(m_layout);
}

void MainWindow::connectSignals()
{
    connect(m_btn_add, &QPushButton::clicked, this, &MainWindow::buttonHandlerAdd);
    connect(m_btn_rem, &QPushButton::clicked, this, &MainWindow::buttonHandlerRemove);
    connect(m_btn_clr, &QPushButton::clicked, this, &MainWindow::buttonHandlerClear);
}

void MainWindow::buttonHandlerAdd()
{
    Model::model_table mod = {"1231","1332","313","31312"};
    m_model->insertRow(m_model->rowCount());

}

void MainWindow::buttonHandlerClear()
{
    m_model->removeRows(0, m_model->rowCount());
}

void MainWindow::buttonHandlerRemove()
{
    m_model->removeRows(0, 1);
}


