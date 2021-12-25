#ifndef MYTREEMODEL_H
#define MYTREEMODEL_H

#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QMap>
#include <QtCore/QAbstractItemModel>
#define freeAndNil(p)   \
{                       \
    if (p)              \
    {                   \
        delete p;       \
        p = nullptr;    \
    }                   \
}  

struct Data
{
    QString c1;
    QString c2;
    QString c3;
    static int memberCount() { return 3; }
};

enum NodeType
{
    eBranchNode = -1,
    eType1 = 0,
    eType2 = 1
};

class DataNode
{
public:
    DataNode(Data* pData, DataNode* pParent = nullptr);
    ~DataNode();

    Data* getData();

    void addChild(DataNode* pNode);
    void removeChild(int nRow);

    int row();
    int rowCount();
    int static columnCount();

    DataNode* child(int nRow);
    DataNode* parent();

    bool insertNode(int nRow, DataNode* pNode);

public:
    int getLevel();
    bool isChildNode(DataNode* pNode);
    void setNodeType(NodeType eNodeType);
    NodeType getNodeType();
protected:
    NodeType m_eNodeType;
    Data* m_pData;
    DataNode* m_pParent;
    QVector<DataNode*> m_childVec;
};

class MyTestModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    MyTestModel(QObject* pParent = nullptr);
    ~MyTestModel();

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex& child) const override;

    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

protected:
    void initModel();
    bool isEnable(DataNode* pNode) const;
    void insertNodes(int row, int count, DataNode* pParent);
    void removeNodes(int row, int count, DataNode* pParent);
    Qt::CheckState getCheckState(DataNode* pNode) const;
protected:
    DataNode* m_pDataSource;

    QMap<DataNode*, Qt::CheckState> m_choosenL1Nodes;
    QMap<DataNode*, Qt::CheckState> m_choosenL2Nodes;
    QMap<DataNode*, Qt::CheckState> m_choosenL3Nodes;
};



#endif