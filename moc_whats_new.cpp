/****************************************************************************
** Meta object code from reading C++ file 'whats_new.h'
**
** Created: Sun Apr 14 11:21:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "whats_new.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'whats_new.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WhatsNew[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
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
     106,    9,    9,    9, 0x08,
     126,    9,    9,    9, 0x08,
     146,    9,    9,    9, 0x08,
     166,    9,    9,    9, 0x08,
     186,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,
     226,    9,    9,    9, 0x08,
     246,    9,    9,    9, 0x08,
     266,    9,    9,    9, 0x08,
     286,    9,    9,    9, 0x08,
     306,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WhatsNew[] = {
    "WhatsNew\0\0handleButton_7_1()\0"
    "handleButton_7_2()\0handleButton_7_3()\0"
    "handleButton_7_4()\0handle_a_button_7()\0"
    "handle_b_button_7()\0handle_c_button_7()\0"
    "handle_d_button_7()\0handle_e_button_7()\0"
    "handle_f_button_7()\0handle_g_button_7()\0"
    "handle_h_button_7()\0handle_i_button_7()\0"
    "handle_j_button_7()\0handle_k_button_7()\0"
    "handle_l_button_7()\0"
};

void WhatsNew::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WhatsNew *_t = static_cast<WhatsNew *>(_o);
        switch (_id) {
        case 0: _t->handleButton_7_1(); break;
        case 1: _t->handleButton_7_2(); break;
        case 2: _t->handleButton_7_3(); break;
        case 3: _t->handleButton_7_4(); break;
        case 4: _t->handle_a_button_7(); break;
        case 5: _t->handle_b_button_7(); break;
        case 6: _t->handle_c_button_7(); break;
        case 7: _t->handle_d_button_7(); break;
        case 8: _t->handle_e_button_7(); break;
        case 9: _t->handle_f_button_7(); break;
        case 10: _t->handle_g_button_7(); break;
        case 11: _t->handle_h_button_7(); break;
        case 12: _t->handle_i_button_7(); break;
        case 13: _t->handle_j_button_7(); break;
        case 14: _t->handle_k_button_7(); break;
        case 15: _t->handle_l_button_7(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WhatsNew::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WhatsNew::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WhatsNew,
      qt_meta_data_WhatsNew, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WhatsNew::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WhatsNew::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WhatsNew::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WhatsNew))
        return static_cast<void*>(const_cast< WhatsNew*>(this));
    return QDialog::qt_metacast(_clname);
}

int WhatsNew::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
