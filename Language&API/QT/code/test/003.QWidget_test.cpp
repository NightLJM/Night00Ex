#include "003.QWidget_test.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QObject>
/*
* moc 003.QWidget_test.h -o  moc_003.QWidget_test.cpp
* g++ 003.QWidget_test.cpp moc_003.QWidget_test.cpp  -o a.out -L$QTDIR/lib -lQt5Widgets -lQt5Core  -fPIC
*/

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    
    MyWidget* pWidget = new MyWidget();
    QHBoxLayout* pMainLayout = new QHBoxLayout();
    QLabel* pLabel = new QLabel("Test");
    pMainLayout->addWidget(pLabel);
    pWidget->setLayout(pMainLayout);
    pWidget->setFixedSize(100, 200);
    pWidget->show();
    return a.exec();
}