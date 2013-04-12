/****************************************************************************
** Meta object code from reading C++ file 'create_account.h'
**
** Created: Fri Apr 12 16:01:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "create_account.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'create_account.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreateAccount[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   31,   31,   31, 0x08,
      32,   31,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CreateAccount[] = {
    "CreateAccount\0handleButton_a()\0\0"
    "handleButton_a_2()\0"
};

void CreateAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CreateAccount *_t = static_cast<CreateAccount *>(_o);
        switch (_id) {
        case 0: _t->handleButton_a(); break;
        case 1: _t->handleButton_a_2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CreateAccount::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreateAccount::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAccount,
      qt_meta_data_CreateAccount, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreateAccount::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreateAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreateAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAccount))
        return static_cast<void*>(const_cast< CreateAccount*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
