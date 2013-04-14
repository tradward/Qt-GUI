/****************************************************************************
** Meta object code from reading C++ file 'entry.h'
**
** Created: Sat Apr 13 20:59:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "entry.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'entry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Entry[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      26,    6,    6,    6, 0x08,
      45,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Entry[] = {
    "Entry\0\0handleButton_4_1()\0handleButton_4_2()\0"
    "handleButton_4_3()\0"
};

void Entry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Entry *_t = static_cast<Entry *>(_o);
        switch (_id) {
        case 0: _t->handleButton_4_1(); break;
        case 1: _t->handleButton_4_2(); break;
        case 2: _t->handleButton_4_3(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Entry::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Entry::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Entry,
      qt_meta_data_Entry, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Entry::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Entry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Entry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Entry))
        return static_cast<void*>(const_cast< Entry*>(this));
    return QDialog::qt_metacast(_clname);
}

int Entry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
