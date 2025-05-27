/****************************************************************************
** Meta object code from reading C++ file 'maindashboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "maindashboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindashboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDashboard_t {
    QByteArrayData data[13];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainDashboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainDashboard_t qt_meta_stringdata_MainDashboard = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainDashboard"
QT_MOC_LITERAL(1, 14, 27), // "on_textEditorButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 27), // "on_calculatorButton_clicked"
QT_MOC_LITERAL(4, 71, 26), // "on_resourcesButton_clicked"
QT_MOC_LITERAL(5, 98, 22), // "on_gamesButton_clicked"
QT_MOC_LITERAL(6, 121, 17), // "updateMemoryLabel"
QT_MOC_LITERAL(7, 139, 25), // "on_calendarButton_clicked"
QT_MOC_LITERAL(8, 165, 22), // "on_clockButton_clicked"
QT_MOC_LITERAL(9, 188, 27), // "on_systeminfoButton_clicked"
QT_MOC_LITERAL(10, 216, 25), // "on_pcbtableButton_clicked"
QT_MOC_LITERAL(11, 242, 28), // "on_filebrowserButton_clicked"
QT_MOC_LITERAL(12, 271, 11) // "onAppClosed"

    },
    "MainDashboard\0on_textEditorButton_clicked\0"
    "\0on_calculatorButton_clicked\0"
    "on_resourcesButton_clicked\0"
    "on_gamesButton_clicked\0updateMemoryLabel\0"
    "on_calendarButton_clicked\0"
    "on_clockButton_clicked\0"
    "on_systeminfoButton_clicked\0"
    "on_pcbtableButton_clicked\0"
    "on_filebrowserButton_clicked\0onAppClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDashboard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainDashboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDashboard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_textEditorButton_clicked(); break;
        case 1: _t->on_calculatorButton_clicked(); break;
        case 2: _t->on_resourcesButton_clicked(); break;
        case 3: _t->on_gamesButton_clicked(); break;
        case 4: _t->updateMemoryLabel(); break;
        case 5: _t->on_calendarButton_clicked(); break;
        case 6: _t->on_clockButton_clicked(); break;
        case 7: _t->on_systeminfoButton_clicked(); break;
        case 8: _t->on_pcbtableButton_clicked(); break;
        case 9: _t->on_filebrowserButton_clicked(); break;
        case 10: _t->onAppClosed(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MainDashboard::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainDashboard.data,
    qt_meta_data_MainDashboard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainDashboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDashboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDashboard.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainDashboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
