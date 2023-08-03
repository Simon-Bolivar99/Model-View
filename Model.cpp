#include "Model.h"
#include <algorithm>
#include <iterator>
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

void Model::addData(int row, int count , const ModelData& table)
{

    beginInsertRows(QModelIndex(),row,row+count-1);
        vector_table.push_back(table);
    endInsertRows();
}


int Model::rowCount(const QModelIndex &parent) const
{
    return vector_table.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    return 4;
}

bool Model::insertRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0)
        return false;

    beginInsertRows(QModelIndex(),row,row+count-1);
        vector_table.push_back({"1","1","1","1"});
    endInsertRows();
    return true;
}

bool Model::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row >= 0 && row < vector_table.size()){
       count = ((row + count) > vector_table.size())? vector_table.size() - row : count;
       beginRemoveRows(QModelIndex(),row,row+count-1);

       if(row == 0 && count == vector_table.size())
           vector_table.clear();
       else
           for(int i = 0; i<count ;i++)
               vector_table.pop_back();
       endRemoveRows();
    }
    return true;
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

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case OPTS_NAME: return QString(tr("ФИО"));
                case OPTS_NUMBER: return QString(tr("Номер"));
                case OPTS_FIRM: return QString(tr("Фирма"));
                case OPTS_JOB: return QString(tr("Должность"));
                default: break;
            }
        }
        else {
            return QString::number(section+1);
        }

    }

    return QVariant();
}

void Model::init()
{
    dataset();

}

void Model::dataset()
{
    vector_table.push_back({"Иванов Иван Иванович","+7-911-233-22-00","Петрович","Начальник"});
    vector_table.push_back({"34","ewe","ewew","343"});
    vector_table.size();
}

