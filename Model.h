#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include <QStringListModel>


class QString;

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    Model(QObject *parent = nullptr );
    ~Model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent= QModelIndex()) const override;
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool setData(const QModelIndex &index, const QVariant& value, int role) override;

public:
    struct model_table{
        QString name    ;
        QString number  ;
        QString firm    ;
        QString job     ;
    };


public:
    void addData(model_table table , model_table *tmp_table);
    void delData();
    void Clear();
    void resetModel();

private:


    QVariant data(const QModelIndex &index, int role) const override;

private:
    enum OPTS{OPTS_NAME, OPTS_NUMBER, OPTS_FIRM, OPTS_JOB};
    std::vector <model_table> vector_table;

private:
   void init();
   void dataset();

public:



};



#endif // MODEL_H
