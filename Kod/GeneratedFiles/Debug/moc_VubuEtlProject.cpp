/****************************************************************************
** Meta object code from reading C++ file 'VubuEtlProject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VubuEtlProject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VubuEtlProject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VubuEtlProject_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VubuEtlProject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VubuEtlProject_t qt_meta_stringdata_VubuEtlProject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VubuEtlProject"
QT_MOC_LITERAL(1, 15, 7), // "getHTML"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "transformHTML"
QT_MOC_LITERAL(4, 38, 11), // "radioButton"
QT_MOC_LITERAL(5, 50, 16), // "downloadFunction"
QT_MOC_LITERAL(6, 67, 14), // "updateDatabase"
QT_MOC_LITERAL(7, 82, 13), // "clearDatabase"
QT_MOC_LITERAL(8, 96, 13), // "getHTMLThread"
QT_MOC_LITERAL(9, 110, 9), // "buttonETL"
QT_MOC_LITERAL(10, 120, 15), // "ThreadButtonETL"
QT_MOC_LITERAL(11, 136, 12), // "stateProcess"
QT_MOC_LITERAL(12, 149, 12), // "showDatabase"
QT_MOC_LITERAL(13, 162, 7) // "saveCSV"

    },
    "VubuEtlProject\0getHTML\0\0transformHTML\0"
    "radioButton\0downloadFunction\0"
    "updateDatabase\0clearDatabase\0getHTMLThread\0"
    "buttonETL\0ThreadButtonETL\0stateProcess\0"
    "showDatabase\0saveCSV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VubuEtlProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       3,    0,   77,    2, 0x0a /* Public */,
       4,    0,   78,    2, 0x0a /* Public */,
       5,    0,   79,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
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

void VubuEtlProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VubuEtlProject *_t = static_cast<VubuEtlProject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getHTML((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->transformHTML(); break;
        case 2: _t->radioButton(); break;
        case 3: _t->downloadFunction(); break;
        case 4: _t->updateDatabase(); break;
        case 5: _t->clearDatabase(); break;
        case 6: _t->getHTMLThread(); break;
        case 7: _t->buttonETL(); break;
        case 8: _t->ThreadButtonETL(); break;
        case 9: _t->stateProcess(); break;
        case 10: _t->showDatabase(); break;
        case 11: _t->saveCSV(); break;
        default: ;
        }
    }
}

const QMetaObject VubuEtlProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VubuEtlProject.data,
      qt_meta_data_VubuEtlProject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VubuEtlProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VubuEtlProject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VubuEtlProject.stringdata0))
        return static_cast<void*>(const_cast< VubuEtlProject*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VubuEtlProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
