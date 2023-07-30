#include "Model.h"
#include <QVariant>
#include <QString>
#include <vector>

Model::Model(QObject*parent)
    : QAbstractTableModel(parent)
{
    init();
}

Model::~Model()
{
}

int Model::rowCount(const QModelIndex &parent) const
{
    return vector_table.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    QString unswer;
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case (OPTS_NAME):
            unswer = vector_table[index.row()].name;
            break;
        case (OPTS_NUMBER):
            unswer = vector_table[index.row()].number;
            break;
        case (OPTS_FIRM):
            unswer = vector_table[index.row()].firm;
            break;
        case (OPTS_JOB):
            unswer = vector_table[index.row()].job;
            break;
        }
        return QVariant(unswer);
    }
    return QVariant();
}

void Model::init()
{
    dataset();

}

void Model::dataset()
{
    vector_table.push_back({"ФИО", "Номер", "Фирма", "Должность"});
    vector_table.push_back({"Иванов Иван Иванович","+7-911-233-22-00","Петрович","Начальник"});
    vector_table.push_back({"34","ewe","ewew","343"});
    vector_table.size();
}

