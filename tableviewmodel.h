#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QStringList>
#include <QFileSystemWatcher>

#include <fileio.h>

class TableViewModel : public QAbstractTableModel
{
    Q_OBJECT

    Q_PROPERTY(QStringList userRoleNames READ userRoleNames NOTIFY userRoleNamesChanged )

    enum Roles{
        NumsRole = Qt::UserRole + 1,
        DatesRole,
        TextsnsRole
    };

public:
    explicit TableViewModel( QObject *parent = 0 );
    ~TableViewModel( void );


    // Standart, MUST be here
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex& parent ) const;
    int columnCount(const QModelIndex& parent ) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole ) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;

    // User created
    QString keyAt(int offset) const;
    void setFileIO( FileIO* file_io );
    void setFileSystemWatcher( QFileSystemWatcher* fileWatcher );
    void setFilePath( QString filePath );
    void processData( void );
    QStringList userRoleNames( void );
    //void updateModel1( );


signals:
    QStringList userRoleNamesChanged();

public slots:
    Q_INVOKABLE void updateModel();

private:
    //QMap<QString, QString> m_map;
    QMap<QString, QStringList> m_map;
    QStringList m_roleNames;
    int m_processorNumber;
    FileIO* m_file_io;
    QString m_filePath;
    QFileSystemWatcher* m_fileWatcher;
};

#endif // TABLEVIEWMODEL_H
