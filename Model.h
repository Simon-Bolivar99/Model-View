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
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role) const override;

public:
    void addData(int row, int count , const ModelData& table);
    void delData();
    void Clear();
    void resetModel();

private:




private:

    std::vector <ModelData> vector_table;


private:
   void init();
   void dataset();

public:



};



#endif // MODEL_H
