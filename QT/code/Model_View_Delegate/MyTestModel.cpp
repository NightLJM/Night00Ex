#include "MyTestModel.h"

DataNode::DataNode(Data* pData, DataNode* pParent)
: m_pData(pData), m_eNodeType(eBranchNode), m_pParent(pParent) { }

DataNode::~DataNode()
{
    for(auto pChild : m_childVec)
    {
        freeAndNil(m_pData);
    }
    freeAndNil(m_pData);
}

Data* DataNode::getData()
{
    return m_pData;
}

void DataNode::addChild(DataNode* pNode)
{
    m_childVec.append(pNode);
}

void DataNode::removeChild(int nRow)
{
    if (nRow < 0 || nRow >= m_childVec.size())
    {
        return;
    }
    DataNode* pNode = m_childVec[nRow];
    freeAndNil(pNode);
    m_childVec.remove(nRow);
}

int DataNode::row()
{
    if (nullptr == m_pParent)
    {
        return 0;
    }

    return m_pParent->m_childVec.indexOf(this);
}

int DataNode::rowCount()
{
    return m_childVec.size();
}

int DataNode::columnCount()
{
    return Data::memberCount();
}

DataNode* DataNode::child(int nRow)
{
    if (nRow < 0 || nRow >= m_childVec.size())
    {
        return nullptr;
    }
    return m_childVec[nRow];
}

DataNode* DataNode::parent()
{
    return m_pParent;
}

bool DataNode::insertNode(int nRow, DataNode* pNode)
{   
    if (nRow < 0 || nRow > m_childVec.size())
    {
        return false;
    }
    m_childVec.insert(nRow, pNode);
    return true;
}

int DataNode::getLevel()
{
    int nLevel = 1;
    DataNode* pParent = m_pParent;
    while(pParent)
    {
        ++nLevel;
        pParent = pParent->m_pParent;
    }
    return nLevel;
}

bool DataNode::isChildNode(DataNode* pNode)
{
    int nRow = m_childVec.indexOf(pNode);
    return nRow != -1;
}

void DataNode::setNodeType(NodeType eNodeType)
{
    m_eNodeType = eNodeType;
}

NodeType DataNode::getNodeType()
{
    return m_eNodeType;
}

MyTestModel::MyTestModel(QObject* pParent)
: QAbstractItemModel(pParent), m_pDataSource(nullptr)
{
    initModel();
}

MyTestModel::~MyTestModel()
{
    freeAndNil(m_pDataSource);
}

int MyTestModel::rowCount(const QModelIndex& parent) const
{
    if (!parent.isValid())
    {
        return 1;
    }

    DataNode* pNode = static_cast<DataNode*>(parent.internalPointer());
    return pNode? pNode->rowCount() : 0;
}

int MyTestModel::columnCount(const QModelIndex& parent) const
{
    return DataNode::columnCount();
}

QModelIndex MyTestModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!parent.isValid())
    {
        return createIndex(0, column, m_pDataSource);
    }

    DataNode* pParentNode = static_cast<DataNode*>(parent.internalPointer());
    DataNode* pNode = pParentNode? pParentNode->child(row) : nullptr;
    return createIndex(row, column, pNode);
}

QModelIndex MyTestModel::parent(const QModelIndex& child) const
{
    if (!child.isValid())
    {
        return QModelIndex();
    }

    DataNode* pChildNode = static_cast<DataNode*>(child.internalPointer());
    DataNode* pParentNode = pChildNode? pChildNode->parent() : m_pDataSource;
    return pParentNode? createIndex(pParentNode->row(), 0, pParentNode) : QModelIndex();
}

QVariant MyTestModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    DataNode* pNode = static_cast<DataNode*>(index.internalPointer());
    if (nullptr == pNode)
    {
        return QVariant();
    }

    Data* pData = pNode->getData();
    if (nullptr == pNode)
    {
        return QVariant();
    }

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch(index.column())
        {
        case 0:
            return QVariant::fromValue(pData->c1);
        case 1:
            return QVariant::fromValue(pData->c2);
        case 2:
            return QVariant::fromValue(pData->c3);
        default:
            return QVariant();
        }
    case Qt::CheckStateRole:
        if (index.column() == 0)
        {
            return getCheckState(pNode);
        }
        break;
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignCenter);
    default:
        break;
    }
    return QVariant();
}

bool MyTestModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid())
    {
        return false;
    }

    DataNode* pNode = static_cast<DataNode*>(index.internalPointer());
    if (nullptr == pNode)
    {
        return false;
    }

    Data* pData = pNode->getData();
    if (nullptr == pData)
    {
        return false;
    }
    
    int nLevel = pNode->getLevel();
    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch(index.column())
        {
        case 0:
            pData->c1 = value.toString();
            break;
        case 1:
            pData->c2 = value.toString();
            break;
        case 2:
            pData->c3 = value.toString();
            break;
        default:
            return false;
        }
        break;
    case Qt::CheckStateRole:
        if (index.column() != 0)
        {
            break;
        }
        switch(nLevel)
        {
        case 1: //一级节点一直是禁用状态
            break;
        case 2:
            if (value == Qt::Unchecked)
            {   //二级节点
                m_choosenL2Nodes.remove(pNode);
            }
            else
            {
                m_choosenL2Nodes.insert(pNode, Qt::Checked);
            }
            break;
        case 3:
            if (value == Qt::Unchecked)
            {   //三级节点
                m_choosenL3Nodes.remove(pNode);
            }
            else
            {
                m_choosenL3Nodes.insert(pNode, Qt::Checked);
            }
            break;
        };
        break;
    default:
        break;
    }
    {   //可能存在CheckState的变化，需要刷新model
        if (Qt::CheckStateRole == role)
        {
            emit dataChanged(createIndex(0, 0, m_pDataSource), createIndex(rowCount() - 1, columnCount() - 1, m_pDataSource));
        }
    }
    
    emit dataChanged(index, index);
    return QAbstractItemModel::setData(index, value, role);
}

QVariant MyTestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (Qt::Horizontal == orientation && Qt::DisplayRole == role)
    {
        switch(section)
        {
        case 0:
            return QString("c1");
        case 1:
            return QString("c2");
        case 2:
            return QString("c3");
        default:
            break;
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

Qt::ItemFlags MyTestModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    DataNode* pNode = static_cast<DataNode*>(index.internalPointer());

    bool bEnable = isEnable(pNode);

    flags = bEnable? (flags | Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsUserCheckable) : (flags & ~Qt::ItemIsEnabled & ~Qt::ItemIsEditable & ~Qt::ItemIsUserCheckable);

    return flags;
}

bool MyTestModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count);

    DataNode* pParent = m_pDataSource;
    if (parent.isValid())
    {
        pParent = static_cast<DataNode*>(parent.internalPointer());
    }
    if (nullptr == pParent)
    {
        return false;
    }

    insertNodes(row, count, pParent);

    endInsertRows();
    return true;
}

bool MyTestModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginResetModel();

    DataNode* pParent = m_pDataSource;
    if (parent.isValid())
    {
        pParent = static_cast<DataNode*>(parent.internalPointer());
    }
    if (nullptr == pParent)
    {
        return false;
    }

    removeNodes(row, count, pParent);
    endResetModel();
    return true;
}

void MyTestModel::initModel()
{
    Data* pRootData = new Data();
    {
        pRootData->c1 = "Root";
    }
    m_pDataSource = new DataNode(pRootData, nullptr);

    for (int iL2 = 0; iL2 < 10; ++iL2)
    {
        Data* pL2Data = new Data();
        {
            pL2Data->c1 = "L2_c1_" + QVariant(iL2).toString();
            pL2Data->c2 = "L2_c2_" + QVariant(iL2).toString();
            pL2Data->c3 = "L2_c3_" + QVariant(iL2).toString();
        }
        DataNode* pL2Node = new DataNode(pL2Data, m_pDataSource);
        m_pDataSource->addChild(pL2Node);

        for (int iL3 = 0; iL3 < 2; ++iL3)
        {
            Data* pL3Data = new Data();
            {
                pL3Data->c1 = "L3_c1_" + QVariant(iL3).toString();
                pL3Data->c2 = "L3_c2_" + QVariant(iL3).toString();
                pL3Data->c3 = "L3_c3_" + QVariant(iL3).toString();
            }
            DataNode* pL3Node = new DataNode(pL3Data, pL2Node);
            pL3Node->setNodeType(NodeType(iL3));
            pL2Node->addChild(pL3Node);
        }
    }
}

bool MyTestModel::isEnable(DataNode* pNode) const
{
    auto areChoosenNodeAllChildsOf = [](DataNode* pL2Node, const QMap<DataNode*, Qt::CheckState>& choosenL3Nodes) -> bool
    {
        for (auto iter = choosenL3Nodes.begin(); iter != choosenL3Nodes.end(); ++iter)
        {
            if (iter.key()->parent() != pL2Node)
            {
                return false;
            }
        }
        return true;
    };
    auto isNodeChoosen = [](DataNode* pL3Node, const QMap<DataNode*, Qt::CheckState>& choosenL3Nodes) -> bool
    {
        for (auto iter = choosenL3Nodes.begin(); iter != choosenL3Nodes.end(); ++iter)
        {
            if (iter.key() == pL3Node)
            {
                return true;
            }
        }
        return false;
    };


    if (nullptr == pNode)
    {
        return false;
    };

    int nLevel = pNode->getLevel();
    switch(nLevel)
    {
    case 1:
        {   //根节点: 一直是禁用状态
            return false;
        }
    case 2:
        {   //二级节点： 如果选中的3级节点存在不是自己孩子的节点，则禁用
            bool bChoosenAllChild = areChoosenNodeAllChildsOf(pNode, m_choosenL3Nodes);
            return bChoosenAllChild;
        }
    case 3:
        {   //三级节点
            int nChoosenL3NodeCount = m_choosenL3Nodes.size();
            if (nChoosenL3NodeCount == 0)           //若三级节点没有选中
            {
                return true;
            }
            else if (nChoosenL3NodeCount == 1)       //若三级节点只被选中一个
            {   //被选中的节点不被禁用
                if (isNodeChoosen(pNode, m_choosenL3Nodes))
                {
                    return true;
                }
                //非同类型的节点不被禁用
                if (pNode->getNodeType() != m_choosenL3Nodes.begin().key()->getNodeType())
                {
                    return true;
                }
                return false;
            }
            else                                       //若三级节点选中两个
            {
                return isNodeChoosen(pNode, m_choosenL3Nodes);
            }
        }
    default:
        break;
    }

    return false;
}

void MyTestModel::insertNodes(int row, int count, DataNode* pParent)
{
    if (nullptr == pParent)
    {
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        Data* pData = new Data();
        DataNode* pNode = new DataNode(pData, pParent);
        pParent->insertNode(row, pNode);
    }
}

void MyTestModel::removeNodes(int row, int count, DataNode* pParent)
{
    if (nullptr == pParent)
    {
        return;
    }
    count = std::min(count, pParent->rowCount() - row);
    for (int i = 0; i < count; ++i)
    {
        pParent->removeChild(row);
    }
}

Qt::CheckState MyTestModel::getCheckState(DataNode* pNode) const
{
    if (nullptr == pNode)
    {
        return Qt::Unchecked;
    }

    int nLevel = pNode->getLevel();
    switch(nLevel)
    {
    case 1:
        {
            auto iter = m_choosenL1Nodes.find(pNode);
            return iter == m_choosenL1Nodes.end() ? Qt::Unchecked : *iter;
        }
    case 2:
        {
            auto iter = m_choosenL2Nodes.find(pNode);
            return iter == m_choosenL2Nodes.end() ? Qt::Unchecked : *iter;
        }
    case 3:
        {
            auto iter = m_choosenL3Nodes.find(pNode);
            return iter == m_choosenL3Nodes.end() ? Qt::Unchecked : *iter;
        }
    default:
        break;
    }
    return Qt::Unchecked;
}




