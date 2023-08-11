#include "include/AddDialog.h"
#include "include/Model.h"

#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>


AddDialog::AddDialog(QWidget* parent) : QDialog(parent)
{
    creatGui();
    connectSignals();
}

AddDialog::~AddDialog()
{

}

void AddDialog::getData(ModelData &data) const
{
    data.firm   = m_firm->text();
    data.name   = m_name->text();
    data.number = m_num->text();
    data.job    = m_job->text();
}


void AddDialog::connectSignals()
{
    connect( btn_ok, &QPushButton::clicked, this, &AddDialog::buttonHandlerOk );
    connect( btn_cnl, &QPushButton::clicked,this, &AddDialog::buttonHandlerCancel );
}

void AddDialog::buttonHandlerOk()
{
    if(m_name->displayText().isEmpty() || m_num->displayText().isEmpty() || m_firm->displayText().isEmpty() || m_job->displayText().isEmpty()){
        QMessageBox msgbox;
        {
            msgbox.setText( tr("Введены неполные данные") );
            msgbox.setWindowTitle(tr("ОШИБКА"));
            msgbox.setStandardButtons(QMessageBox::Ok );
            msgbox.setDefaultButton(QMessageBox::Ok);
            msgbox.setIcon(QMessageBox::Icon::Warning);
            msgbox.setFixedSize( QSize(480, 240) );
        }
        msgbox.exec();
        return;
    }
    else if(m_num->displayText()[0]!="+" && m_num->displayText().size() < 11){

        QMessageBox msgbox;
        {
            msgbox.setText( tr("Неверный формат номера телефона (+x-ххх-хх-хх)") );
            msgbox.setWindowTitle(tr("ОШИБКА"));
            msgbox.setStandardButtons(QMessageBox::Ok );
            msgbox.setDefaultButton(QMessageBox::Ok);
            msgbox.setIcon(QMessageBox::Icon::Warning);
            msgbox.setFixedSize( QSize(480, 240) );
        }
        msgbox.exec();
        return;
     auto x = m_num->displayText();
    }
    else {

    }
    AddDialog::hide();
    emit accepted();
}

void AddDialog::buttonHandlerCancel()
{
    clearLine();
    AddDialog::hide();
}

void AddDialog::clearLine()
{
    m_name->clear();
    m_num->clear();
    m_firm->clear();
    m_job->clear();
}

void AddDialog::creatGui()
{
    layout =  new QGridLayout;
    layout->setMargin(5);
    layout->setSpacing(0);

    /*HEAD*/
    m_Headname = new QLabel("ФИО");
        m_Headname->setStyleSheet("background-color: white");
        layout->addWidget(m_Headname,0,0,1,1);
    m_Headnum = new QLabel("Номер");
    m_Headnum->setStyleSheet("background-color: white");
        layout->addWidget(m_Headnum,0,1,1,1);
    m_Headfirm= new QLabel("Фирма");
    m_Headfirm->setStyleSheet("background-color: white");
        layout->addWidget(m_Headfirm,0,2,1,1);
    m_Headjob = new QLabel("Должность");
    m_Headjob->setStyleSheet("background-color: white");
        layout->addWidget(m_Headjob,0,3,1,1);

    m_name = new QLineEdit;
        layout->addWidget(m_name,1,0,1,1);
    m_num = new QLineEdit;
        layout->addWidget(m_num,1,1,1,1);
    m_firm = new QLineEdit;
        layout->addWidget(m_firm,1,2,1,1);
    m_job = new QLineEdit;
        layout->addWidget(m_job,1,3,1,1);

    btn_ok = new QPushButton("Ok");

        layout->addWidget(btn_ok,2,0,1,2);
    btn_cnl = new QPushButton("Cancel");

        layout->addWidget(btn_cnl,2,2,1,2);
    setLayout(layout);
}



