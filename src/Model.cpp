#include "Model.h"
#include "utils.h"
#include <nlohmann/json.hpp>

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
        m_data.emplace(m_data.begin()+ row,table);
        endInsertRows();
}

void Model::toJson(QString path) const
{
    nlohmann::json json;
    for (const auto& data :qAsConst(m_data)){
        nlohmann::json fields;
            fields["name"]   = data.name.toStdString();
            fields["number"] = data.number.toStdString();
            fields["firm"]   = data.firm.toStdString();
            fields["job"]    = data.job.toStdString();
        json.push_back(fields);
    }
    writeToFile(path +".json", json);
}

void Model::fromJson(QString path)
{

    nlohmann::json json;
    readFromFile(path, json);

   std::vector <ModelData>  vec;
    if ( !json.is_array() )
        return;

    for(const auto& it: json){
        if(!it.is_object())
            continue;

        ModelData s;

        if(it.contains("name"))
            if(it["name"].is_string())
                s.setName(it.value("name", QString()));

        if(it.contains("number"))
            if(it["number"].is_string())
                s.setNum(it.value("number", QString()));

        if(it.contains("firm"))
            if(it["firm"].is_string())
                s.setFirm(it.value("firm", QString()));

        if(it.contains("job"))
            if(it["job"].is_string())
                s.setJob(it.value("job", QString()));

        vec.push_back(s);
    }

    m_data.clear();
    beginInsertRows(QModelIndex(), 0, vec.size()-1);
        m_data = vec;
    endInsertRows();
}


int Model::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
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
        m_data.push_back({"1","1","1","1"});
    endInsertRows();
    return true;
}

bool Model::removeRows(int row, int count, const QModelIndex &parent)
{
       beginRemoveRows(QModelIndex(),row,row+count-1);

       if(row == 0 && count == m_data.size())
           m_data.clear();
       else
           m_data.erase(m_data.begin() + row , m_data.begin() + row + count);
       endRemoveRows();

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

        auto& vt = m_data[row];
        QString tmp;
        if (role == Qt::EditRole)
        {
            switch (index.column())
            {
                case OPTS_NAME:
                    tmp = vt.name;
                    value.toString() == ""? vt.setName(tmp):vt.setName(value.toString());
                    break;
                case OPTS_NUMBER:
                    tmp = vt.number;
                    value.toString() == ""? vt.setNum(tmp):vt.setNum(value.toString());
                    break;
                case OPTS_FIRM:
                    tmp = vt.firm;
                    value.toString() == ""? vt.setFirm(tmp):vt.setFirm(value.toString());
                    break;
                case OPTS_JOB:
                    tmp = vt.job;
                    value.toString() == ""? vt.setJob(tmp):vt.setJob(value.toString());
                    break;

                default:
                    break;
            }
            emit dataChanged(index, index);
        }
    }
    return ret;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    int row[[maybe_unused]] = index.row();
    int col = index.column();

    Qt::ItemFlags flags = QAbstractTableModel::flags(index) | Qt::ItemIsDragEnabled;

    if (index.isValid()) {
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}


QVariant Model::data(const QModelIndex &index, int role) const
{
    QString unswer;
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case (OPTS_NAME):
            unswer = m_data[index.row()].name;
            break;
        case (OPTS_NUMBER):
            unswer = m_data[index.row()].number;
            break;
        case (OPTS_FIRM):
            unswer = m_data[index.row()].firm;
            break;
        case (OPTS_JOB):
            unswer = m_data[index.row()].job;
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

    /*
    m_data.push_back({"Иванов Иван Иванович","+7-911-233-22-00","Петрович","Начальник"});
    m_data.push_back({"Сидоров Николай Васильевич","+7-921-118-29-99","ГазПром","Уборщик"});
    m_data.push_back({"Петров  Василий Юрьевич","+7-911-233-38-44","ГазПром","Уборщик"});
    m_data.push_back({"Васечкин Петр Михайлович","+7-921-344-27-12","ГазПром","Рабочий"});
    m_data.push_back({"Равшан Аскерович","+7-800-555-35-35","СтройКа","Гастарбайтер"});
    m_data.push_back({"Джамшут Фарухович","+7-921-234-14-04","СтройКа","Гастарбайтер"});
    m_data.push_back({"Дулин Иван Олегович","+7-921-139-29-99","ЧЗМ","Фрезеровщик"});
    */
}

