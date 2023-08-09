#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include <QStringListModel>


class QString;

struct ModelData{
    QString name;
    QString number;
    QString firm;
    QString job;
    void setName(const QString& a_name){name = a_name;}
    void setNum(const QString& a_num){number = a_num;}
    void setFirm(const QString& a_firm){firm = a_firm;}
    void setJob(const QString& a_job){job = a_job;}

};

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum OPTS{OPTS_NAME, OPTS_NUMBER, OPTS_FIRM, OPTS_JOB};

    Model(QObject *parent = nullptr );
    ~Model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent= QModelIndex()) const override;
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role) const override;

public:
    void addData(int row, int count , const ModelData& table);
    void delData();
    void clear();
    void resetModel();



private:




private:

    std::vector<ModelData> m_data;


private:
   void init();
   void dataset();

public:



};



#endif // MODEL_H
