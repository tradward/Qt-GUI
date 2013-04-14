/****************************************************************************
** Meta object code from reading C++ file 'result.h'
**
** Created: Sat Apr 13 20:59:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "result.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'result.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Result[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      25,    7,    7,    7, 0x08,
      48,    7,    7,    7, 0x08,
      71,    7,    7,    7, 0x08,
      94,    7,    7,    7, 0x08,
     117,    7,    7,    7, 0x08,
     140,    7,    7,    7, 0x08,
     163,    7,    7,    7, 0x08,
     186,    7,    7,    7, 0x08,
     209,    7,    7,    7, 0x08,
     232,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Result[] = {
    "Result\0\0handleButton_5()\0"
    "handleButton_5_pic_1()\0handleButton_5_pic_2()\0"
    "handleButton_5_pic_3()\0handleButton_5_pic_4()\0"
    "handleButton_5_pic_5()\0handleButton_5_pic_6()\0"
    "handleButton_5_pic_7()\0handleButton_5_pic_8()\0"
    "handleButton_5_pic_9()\0handleButton_5_pic_10()\0"
};

void Result::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Result *_t = static_cast<Result *>(_o);
        switch (_id) {
        case 0: _t->handleButton_5(); break;
        case 1: _t->handleButton_5_pic_1(); break;
        case 2: _t->handleButton_5_pic_2(); break;
        case 3: _t->handleButton_5_pic_3(); break;
        case 4: _t->handleButton_5_pic_4(); break;
        case 5: _t->handleButton_5_pic_5(); break;
        case 6: _t->handleButton_5_pic_6(); break;
        case 7: _t->handleButton_5_pic_7(); break;
        case 8: _t->handleButton_5_pic_8(); break;
        case 9: _t->handleButton_5_pic_9(); break;
        case 10: _t->handleButton_5_pic_10(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Result::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Result::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Result,
      qt_meta_data_Result, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Result::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Result::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Result::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Result))
        return static_cast<void*>(const_cast< Result*>(this));
    return QDialog::qt_metacast(_clname);
}

int Result::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
