/****************************************************************************
** Meta object code from reading C++ file 'filebrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "filebrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filebrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileBrowser_t {
    QByteArrayData data[12];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileBrowser_t qt_meta_stringdata_FileBrowser = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileBrowser"
QT_MOC_LITERAL(1, 12, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_homeButton_clicked"
QT_MOC_LITERAL(4, 57, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(5, 82, 23), // "on_createButton_clicked"
QT_MOC_LITERAL(6, 106, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(7, 130, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(8, 153, 21), // "updateSystemResources"
QT_MOC_LITERAL(9, 175, 19), // "onFileDoubleClicked"
QT_MOC_LITERAL(10, 195, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 212, 4) // "item"

    },
    "FileBrowser\0on_backButton_clicked\0\0"
    "on_homeButton_clicked\0on_refreshButton_clicked\0"
    "on_createButton_clicked\0on_deleteButton_clicked\0"
    "on_closeButton_clicked\0updateSystemResources\0"
    "onFileDoubleClicked\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileBrowser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void FileBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileBrowser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_backButton_clicked(); break;
        case 1: _t->on_homeButton_clicked(); break;
        case 2: _t->on_refreshButton_clicked(); break;
        case 3: _t->on_createButton_clicked(); break;
        case 4: _t->on_deleteButton_clicked(); break;
        case 5: _t->on_closeButton_clicked(); break;
        case 6: _t->updateSystemResources(); break;
        case 7: _t->onFileDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FileBrowser.data,
    qt_meta_data_FileBrowser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileBrowser.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FileBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
