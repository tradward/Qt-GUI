/****************************************************************************
** Meta object code from reading C++ file 'favorite.h'
**
** Created: Sun Apr 14 11:21:47 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "favorite.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'favorite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Favorite[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      29,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      67,    9,    9,    9, 0x08,
      86,    9,    9,    9, 0x08,
     109,    9,    9,    9, 0x08,
     132,    9,    9,    9, 0x08,
     155,    9,    9,    9, 0x08,
     178,    9,    9,    9, 0x08,
     201,    9,    9,    9, 0x08,
     224,    9,    9,    9, 0x08,
     247,    9,    9,    9, 0x08,
     270,    9,    9,    9, 0x08,
     293,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Favorite[] = {
    "Favorite\0\0handleButton_6_1()\0"
    "handleButton_6_2()\0handleButton_6_3()\0"
    "handleButton_6_4()\0handleButton_6_pic_1()\0"
    "handleButton_6_pic_2()\0handleButton_6_pic_3()\0"
    "handleButton_6_pic_4()\0handleButton_6_pic_5()\0"
    "handleButton_6_pic_6()\0handleButton_6_pic_7()\0"
    "handleButton_6_pic_8()\0handleButton_6_pic_9()\0"
    "handleButton_6_pic_10()\0"
};

void Favorite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Favorite *_t = static_cast<Favorite *>(_o);
        switch (_id) {
        case 0: _t->handleButton_6_1(); break;
        case 1: _t->handleButton_6_2(); break;
        case 2: _t->handleButton_6_3(); break;
        case 3: _t->handleButton_6_4(); break;
        case 4: _t->handleButton_6_pic_1(); break;
        case 5: _t->handleButton_6_pic_2(); break;
        case 6: _t->handleButton_6_pic_3(); break;
        case 7: _t->handleButton_6_pic_4(); break;
        case 8: _t->handleButton_6_pic_5(); break;
        case 9: _t->handleButton_6_pic_6(); break;
        case 10: _t->handleButton_6_pic_7(); break;
        case 11: _t->handleButton_6_pic_8(); break;
        case 12: _t->handleButton_6_pic_9(); break;
        case 13: _t->handleButton_6_pic_10(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Favorite::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Favorite::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Favorite,
      qt_meta_data_Favorite, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Favorite::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Favorite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Favorite::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Favorite))
        return static_cast<void*>(const_cast< Favorite*>(this));
    return QDialog::qt_metacast(_clname);
}

int Favorite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
