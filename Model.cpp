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

void Model::addData(model_table table, model_table *tmp_table)
{
    tmp_table->name     = table.name;
    tmp_table->number   = table.number;
    tmp_table->firm     = table.firm;
    tmp_table->job      = table.job;
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

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool ret = false;

    int row = index.row();
    int col = index.column();

    if(checkIndex(index))
    {
        ret = true;

        if (role == Qt::EditRole)
        {
            switch (col)
            {
                case OPTS_NAME:
                    vector_table[row].name =value.toString();
                    break;
                case OPTS_NUMBER:
                    vector_table[row].number =value.toString();
                    break;
                case OPTS_FIRM:
                    vector_table[row].firm =value.toString();
                    break;
                case OPTS_JOB:
                    vector_table[row].job =value.toString();
                    break;
            }
            emit dataChanged(index,index);
        }
    }

    return ret;

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

