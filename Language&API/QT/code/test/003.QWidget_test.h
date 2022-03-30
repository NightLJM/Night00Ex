#pragma once
#include <QtWidgets/QWidget>
/*
* g++ 003.QWidget_test.cpp -o a.out -L$QTDIR/lib -lQt5Widgets -lQt5Core  -fPIC
*/

class MyWidget : public QWidget
{
    Q_OBJECT
public slots:
    void test() { }

signals:
    void sig();
};