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
    return {};
}

void Model::init()
{
    dataset();

}

void Model::dataset()
{
    model_table table;

    table = {"ФИО", "Номер", "Фирма", "Должность"};
    vector_table.push_back(table);
    table = {"1", "1","1","1"};
    vector_table.push_back(table);
    vector_table.push_back(table);
    vector_table.size();
}

