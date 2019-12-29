/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../funserver/database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_database_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_database_t qt_meta_stringdata_database = {
    {
QT_MOC_LITERAL(0, 0, 8), // "database"
QT_MOC_LITERAL(1, 9, 20), // "authorizationSuccess"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "authorizationException"
QT_MOC_LITERAL(4, 54, 9), // "reg_false"
QT_MOC_LITERAL(5, 64, 8), // "reg_true"
QT_MOC_LITERAL(6, 73, 9), // "checkUser"
QT_MOC_LITERAL(7, 83, 10), // "registrate"
QT_MOC_LITERAL(8, 94, 10), // "newMessage"
QT_MOC_LITERAL(9, 105, 10), // "descriptor"
QT_MOC_LITERAL(10, 116, 7) // "message"

    },
    "database\0authorizationSuccess\0\0"
    "authorizationException\0reg_false\0"
    "reg_true\0checkUser\0registrate\0newMessage\0"
    "descriptor\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_database[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   57,    2, 0x0a /* Public */,
       7,    2,   60,    2, 0x0a /* Public */,
       8,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString,    9,   10,

       0        // eod
};

void database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->authorizationSuccess(); break;
        case 1: _t->authorizationException(); break;
        case 2: _t->reg_false((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->reg_true((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->checkUser((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->registrate((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 6: _t->newMessage((*reinterpret_cast< const qint64(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (database::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&database::authorizationSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (database::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&database::authorizationException)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (database::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&database::reg_false)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (database::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&database::reg_true)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject database::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_database.data,
    qt_meta_data_database,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void database::authorizationSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void database::authorizationException()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void database::reg_false(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void database::reg_true(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
