#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtCore/QStringList>
#include <QtCore/QDebug>

/*
 * g++ 007.QFileDialog_Test.cpp -o a.out -L$QTDIR/lib -lQt5Core -lQt5Widgets -fPIC
*/

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    // 获取文件路径
    {
        QString sFilter = "Image Files(*.jpg *.bmp *.png *.jpeg *.jpe)";
        QStringList fileNames = QFileDialog::getOpenFileNames(nullptr, "Import Image", "", sFilter);
        for (auto str : fileNames)
        {
            qDebug() << str;
        }
    } 


    return a.exec();
}