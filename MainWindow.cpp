#include "MainWindow.h"
#include "Model.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_model = new Model(this);
    createGui();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createGui()
{

    m_TableView = new QTableView;

    m_TableView->setModel(m_model);

    auto m_layout = new QGridLayout;
        m_layout -> addWidget(m_TableView);


    setLayout(m_layout);
}


