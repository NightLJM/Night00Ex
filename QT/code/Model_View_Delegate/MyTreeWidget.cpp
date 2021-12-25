#include "MyTreeWidget.h"
#include "MyTestModel.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>

MyTreeWidget::MyTreeWidget(QWidget* pParent)
: QWidget(pParent), m_pInsertBtn(nullptr), m_pDelBtn(nullptr), m_pTreeView(nullptr), m_pDataModel(nullptr)
{
    initUI();
    buildConnect();
}

MyTreeWidget::~MyTreeWidget()
{

}

void MyTreeWidget::initUI()
{
    m_pTreeView = new QTreeView(this);
    m_pDataModel = new MyTestModel(m_pTreeView);
    m_pTreeView->setModel(m_pDataModel);
    m_pTreeView->setEditTriggers(QAbstractItemView::DoubleClicked);
    m_pTreeView->header()->setSectionResizeMode(QHeaderView::Stretch);
    m_pInsertBtn = new QPushButton("Insert", this);
    m_pDelBtn = new QPushButton("Delete", this);
    
    QHBoxLayout* pBtnLayout = new QHBoxLayout();
    {
        QLabel* pSpaceLabel = new QLabel("", this);
        pSpaceLabel->setFixedSize(140, 20);
        pBtnLayout->addWidget(pSpaceLabel);
        pBtnLayout->addStretch();
        pBtnLayout->addWidget(m_pInsertBtn);
        pBtnLayout->addStretch();
        pBtnLayout->addWidget(m_pDelBtn);
    }

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    {
        pMainLayout->addWidget(m_pTreeView);
        pMainLayout->addLayout(pBtnLayout);
    }

    this->setLayout(pMainLayout);
    this->setFixedSize(800, 400);
}

void MyTreeWidget::buildConnect()
{
    connect(m_pInsertBtn, &QPushButton::clicked, this, &MyTreeWidget::onInsert);
    connect(m_pDelBtn, &QPushButton::clicked, this, &MyTreeWidget::onDel);
}

void MyTreeWidget::onInsert()
{
    QModelIndex index = m_pTreeView->currentIndex();
    if (!index.isValid())
    {
        return;
    }
    m_pDataModel->insertRows(index.row() + 1, 1, index.parent());
}

void MyTreeWidget::onDel()
{
    QModelIndex index = m_pTreeView->currentIndex();
    if (!index.isValid())
    {
        return;
    }
    m_pDataModel->removeRows(index.row(), 1, index.parent());
}