#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include <QDialog>

class QLineEdit;
class QLabel;
class QGridLayout;
class QPushButton;

struct ModelData;

class AddDialog : public QDialog
{
    Q_OBJECT
public:
    AddDialog(QWidget *parent = 0);
    ~AddDialog();

    void getData(ModelData& data) const;



signals:
    void applied();

private:
    void connectSignals();
    void buttonHandlerOk();
    void buttonHandlerCancel();
    void clearLine();
    void creatGui();

private:
    QLabel *m_Headname;
    QLabel *m_Headnum;
    QLabel *m_Headfirm;
    QLabel *m_Headjob;

    QLineEdit *m_name;
    QLineEdit *m_num;
    QLineEdit *m_firm;
    QLineEdit *m_job;

    QGridLayout *layout;
    QPushButton *btn_ok;
    QPushButton *btn_cnl;

};

#endif // ADDDIALOG_H
