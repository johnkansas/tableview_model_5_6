#include "tableviewmodel.h"

#include <QDebug>

TableViewModel::TableViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}


TableViewModel::~TableViewModel( void )
{

}

QHash<int, QByteArray> TableViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    //이름이 동일해야 넣을수 있다.
    roles[NumsRole] = "no";
    roles[DatesRole] = "date";
    roles[TextsnsRole] = "textsn";
    return roles;
//    roles[Role_0] = "title";
//    roles[Role_1] = "cpu 1";
//    roles[Role_2] = "cpu 2";
//    roles[Role_3] = "cpu 3";
//    roles[Role_4] = "cpu 4";
//    roles[Role_5] = "cpu 5";
//    roles[Role_6] = "cpu 6";
//    roles[Role_7] = "cpu 7";
//    roles[Role_8] = "cpu 8";
//    roles[Role_9] = "cpu 9";
//    roles[Role_10] = "cpu 10";
//    roles[Role_11] = "cpu 11";
//    roles[Role_12] = "cpu 12";
//    roles[Role_13] = "cpu 13";
//    roles[Role_14] = "cpu 14";
//    roles[Role_15] = "cpu 15";
//    roles[Role_16] = "cpu 16";
}

QString TableViewModel::keyAt(int offset) const
{
    return (m_map.begin() + offset).key();
}

void TableViewModel::setFileIO( FileIO* file_io )
{
    m_file_io = file_io;

}


void TableViewModel::setFileSystemWatcher( QFileSystemWatcher* fileWatcher )
{
    m_fileWatcher = fileWatcher;
}

void TableViewModel::setFilePath( QString filePath )
{
    m_filePath = filePath;
}

int TableViewModel::rowCount(const QModelIndex& parent ) const
{
    return m_map.count();
}

int TableViewModel::columnCount(const QModelIndex& parent ) const
{
    return m_roleNames.size();
}


QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role ) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if( orientation == Qt::Vertical )
        return QVariant( section );

    if( orientation == Qt::Horizontal )
        return QVariant( keyAt(section) );
}



//void CppModelItem::setData(const QVariant &value, int role)
//{
//if( role == NameRole )
//{
//m_name = value.toString();

//    this->model()->dataChanged(this->index(), this->index());
//}
//}


//setter
bool TableViewModel::setData(const QModelIndex &index, const QVariant &value, int role )
{
    qDebug()<<index<<"<<index"<<value<<"<<value"<<role<<"role";
    QString str = QString ("%1").arg(value.toInt());
    //const 에 의한 discards qualifiers 라서 이거 override 해야하는데 어떻게 해야함?
     if (data(index, role) != value)
     {
         int row = index.row();
         int column = index.column();
         QString var="1,2,3";
         QStringList varlist = var.split( "," );
         QVariant a="1";
//        varlist.insert(4,"hello");
//         for(int i=0;i<varlist.size();i++)
//         {
//             m_map.insert(QString::number(i), varlist );
//         }
//         QStringList ss = m_map.value( keyAt( row ) );
//         qDebug() << ss.size();
//         ss.insert(0,varlist);
         switch(role)
         {
             case NumsRole:
                 m_map[keyAt(row)].replace(0,value.toString());//Qvariant는 타입을 모를때 쓰는것
             case DatesRole:
//                 m_map.value( keyAt( row ) ).insert(1,value);
                m_map[keyAt(row)].replace(1,value.toString());
             case TextsnsRole:
//                 m_map.value( keyAt( row ) ).insert(2,value);
                m_map[keyAt(row)].replace(2,value.toString());
         }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}



//getter
QVariant TableViewModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();


    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    } else { //if (role == Qt::DisplayRole) {
        qDebug()<<index<<"where is this comming from";
        int row = index.row();
        int column = index.column();
        switch(role)
        {
            case NumsRole:
//                qDebug()<<m_map.value( keyAt( row ) ).at(0);
                return QVariant( m_map.value( keyAt( row ) ).at(0) );
            case DatesRole:
//                qDebug()<<m_map.value( keyAt( row ) ).at(1);
                return QVariant( m_map.value( keyAt( row ) ).at(1) );
            case TextsnsRole:
//                qDebug()<<m_map.value( keyAt( row ) ).at(2);
                return QVariant( m_map.value( keyAt( row ) ).at(2) );
        }



//        switch(role)
//        {
//            case Role_0:
//                return QVariant( keyAt( row ) );
//            case Role_1:
//                return QVariant( m_map.value( keyAt( row ) ).at(0) );
//            case Role_2:
//                return QVariant( m_map.value( keyAt( row ) ).at(1) );
//            case Role_3:
//                return QVariant( m_map.value( keyAt( row ) ).at(2) );
//            case Role_4:
//                return QVariant( m_map.value( keyAt( row ) ).at(3) );
//            case Role_5:
//                return QVariant( m_map.value( keyAt( row ) ).at(4) );
//            case Role_6:
//                return QVariant( m_map.value( keyAt( row ) ).at(5) );
//            case Role_7:
//                return QVariant( m_map.value( keyAt( row ) ).at(6) );
//            case Role_8:
//                return QVariant( m_map.value( keyAt( row ) ).at(7) );
//            case Role_9:
//                return QVariant( m_map.value( keyAt( row ) ).at(8) );
//            case Role_10:
//                return QVariant( m_map.value( keyAt( row ) ).at(9) );
//            case Role_11:
//                return QVariant( m_map.value( keyAt( row ) ).at(10) );
//            case Role_12:
//                return QVariant( m_map.value( keyAt( row ) ).at(11) );
//            case Role_13:
//                return QVariant( m_map.value( keyAt( row ) ).at(12) );
//            case Role_14:
//                return QVariant( m_map.value( keyAt( row ) ).at(13) );
//            case Role_15:
//                return QVariant( m_map.value( keyAt( row ) ).at(14) );
//            case Role_16:
//                return QVariant( m_map.value( keyAt( row ) ).at(15) );
//            }
    }

    return QVariant();
}

void TableViewModel::processData( void )
{
//    QStringList dataList = m_file_io->read();
//    dataList.removeAll( QString( "    " ) );

    // Clear all
    m_roleNames.clear();
    m_map.clear();

    // Get number of processors
    m_processorNumber = 0;
//    int cnt = dataList.count();


//    for( int i=0; i < cnt; i++ )
//        if( dataList.at(i).contains("processor") )
//            ++m_processorNumber;



    m_roleNames.append( "no" );// 제목 추가하는 방법.
    m_roleNames.append( "date" );
    m_roleNames.append( "textsn" );
    QString var="1,2,3";
    QStringList varlist = var.split( "," );
    foreach(QString v,varlist)
    {
        m_map[v]= varlist;
    }


//    for (int i = 1; i <= m_processorNumber; i++ )//title을 입력하는 곳임.
//    {
//        m_roleNames.append( QString( "cpu " ) + QString::number(i));
//    }

//    QString var;

//    foreach( var, dataList )//foreach문으로 datalist 값을 var값에 투여
//    {
//        var.remove("\t");
//        QStringList tmp = var.split( ":" );

//        if( m_map.contains(tmp.at(0) ))//정제된 tmp처음 값을 m_map이 가지고 있냐?
//        {
//            QStringList strList = m_map.value( tmp.at(0) );//가지고 있으면 키에
//                                                            해당하는 값을strlist에 넣는다.

//            if( tmp.count() == 2 )
//                strList.append( tmp.at(1) );
//            if( tmp.count() == 1 )
//                strList.append("");

//            m_map[ tmp.at(0) ] = strList;
//        }
//        else
//        {
//            if( tmp.count() == 2 )
//            {
//                QStringList lst;
//                lst.append( tmp.at(1) );
//                m_map.insert( tmp.at(0), lst );
//            }

//            if( tmp.count() == 1 )
//            {
//                QStringList lst;
//                lst.append( "" );
//                m_map.insert( tmp.at(0), lst );
//            }
//        }
//    }
}


QStringList TableViewModel::userRoleNames()
{
    return m_roleNames;
}


void TableViewModel::updateModel()
{
//    qDebug() << "updateModel";
//    QString var="1,2,3";
//    QStringList varlist = var.split( "," );
//    for(int i=0;i<varlist.size();i++)
//    {
//        m_map.insert(QString::number(i), varlist );
//    }
//    qDebug() << m_map.values().at(0);
//    QStringList test;
//    test.append("4");
//    test.append("5");
//    test.append("6");
//    m_map.insert("4",test);
//    qDebug() << m_map.value("4");
//    QStringList test2;
//    test2.append("7");
//    test2.append("8");
//    test2.append("9");
//    m_map["4"] = test2;
//    qDebug() << m_map.value("4");
//    m_map.insert("")


    emit dataChanged( QModelIndex(), QModelIndex());
}

