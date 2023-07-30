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

private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    struct model_table{
        QString name    ;
        QString number  ;
        QString firm    ;
        QString job     ;
    };

    enum OPTS{OPTS_NAME, OPTS_NUMBER, OPTS_FIRM, OPTS_JOB};

    std::vector <model_table> vector_table;




private:
   void init();
   void dataset();

public:



};



#endif // MODEL_H
