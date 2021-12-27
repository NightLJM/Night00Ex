/****************************************************************************
** Meta object code from reading C++ file 'MyTreeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyTreeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTreeWidget_t {
    QByteArrayData data[6];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTreeWidget_t qt_meta_stringdata_MyTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyTreeWidget"
QT_MOC_LITERAL(1, 13, 17), // "sigInsertBtnClick"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "sigDelBtnClick"
QT_MOC_LITERAL(4, 47, 8), // "onInsert"
QT_MOC_LITERAL(5, 56, 5) // "onDel"

    },
    "MyTreeWidget\0sigInsertBtnClick\0\0"
    "sigDelBtnClick\0onInsert\0onDel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigInsertBtnClick(); break;
        case 1: _t->sigDelBtnClick(); break;
        case 2: _t->onInsert(); break;
        case 3: _t->onDel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sigInsertBtnClick)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sigDelBtnClick)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyTreeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyTreeWidget.data,
      qt_meta_data_MyTreeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< MyTreeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::sigInsertBtnClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyTreeWidget::sigDelBtnClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
