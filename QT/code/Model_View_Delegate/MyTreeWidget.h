#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QtWidgets/QWidget>

class QPushButton;
class QTreeView;
class MyTestModel;

class MyTreeWidget : public QWidget
{
    Q_OBJECT
public:
    MyTreeWidget(QWidget* pParent = nullptr);
    ~MyTreeWidget();

protected:
    void initUI();
    void buildConnect();

protected slots:
    void onInsert();
    void onDel();

signals:
    void sigInsertBtnClick();
    void sigDelBtnClick();

protected:
    QPushButton* m_pInsertBtn;
    QPushButton* m_pDelBtn;
    QTreeView* m_pTreeView;
    MyTestModel* m_pDataModel;
};
#endif