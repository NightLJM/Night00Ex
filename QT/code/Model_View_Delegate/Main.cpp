#include "MyTreeWidget.h"
#include "MyTestModel.h"

#include <QtWidgets/QApplication>

/*
 * moc MyTreeWidget.h -o moc_MyTreeWidget.cpp
 * moc MyTestModel.h -o moc_MyTestModel.cpp
 * g++ moc_MyTreeWidget.cpp moc_MyTestModel.cpp  MyTestModel.cpp  MyTreeWidget.cpp  Main.cpp -o a.out -L$QTDIR/lib -lQt5Core -lQt5Widgets -lQt5Gui -fPIC
*/

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    MyTreeWidget* pWidget= new MyTreeWidget();
    pWidget->setAttribute(Qt::WA_DeleteOnClose);
    pWidget->show();
    return a.exec();
}