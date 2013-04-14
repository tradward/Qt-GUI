/****************************************************************************
** Meta object code from reading C++ file 'series.h'
**
** Created: Sat Apr 13 20:59:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "series.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'series.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Series[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      27,    7,    7,    7, 0x08,
      46,    7,    7,    7, 0x08,
      65,    7,    7,    7, 0x08,
      84,    7,    7,    7, 0x08,
     104,    7,    7,    7, 0x08,
     124,    7,    7,    7, 0x08,
     144,    7,    7,    7, 0x08,
     164,    7,    7,    7, 0x08,
     184,    7,    7,    7, 0x08,
     204,    7,    7,    7, 0x08,
     229,    7,    7,    7, 0x08,
     257,    7,    7,    7, 0x08,
     284,    7,    7,    7, 0x08,
     308,    7,    7,    7, 0x08,
     333,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x08,
     391,    7,    7,    7, 0x08,
     417,    7,    7,    7, 0x08,
     440,    7,    7,    7, 0x08,
     469,    7,    7,    7, 0x08,
     495,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Series[] = {
    "Series\0\0handleButton_8_1()\0"
    "handleButton_8_2()\0handleButton_8_3()\0"
    "handleButton_8_4()\0handle_a_button_8()\0"
    "handle_b_button_8()\0handle_c_button_8()\0"
    "handle_d_button_8()\0handle_e_button_8()\0"
    "handle_f_button_8()\0handle_action_button_8()\0"
    "handle_biography_button_8()\0"
    "handle_classics_button_8()\0"
    "handle_comic_button_8()\0"
    "handle_comedy_button_8()\0"
    "handle_discovery_button_8()\0"
    "handle_documentary_button_8()\0"
    "handle_history_button_8()\0"
    "handle_kids_button_8()\0"
    "handle_miniseries_button_8()\0"
    "handle_reality_button_8()\0"
    "handle_science_fiction_button_8()\0"
};

void Series::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Series *_t = static_cast<Series *>(_o);
        switch (_id) {
        case 0: _t->handleButton_8_1(); break;
        case 1: _t->handleButton_8_2(); break;
        case 2: _t->handleButton_8_3(); break;
        case 3: _t->handleButton_8_4(); break;
        case 4: _t->handle_a_button_8(); break;
        case 5: _t->handle_b_button_8(); break;
        case 6: _t->handle_c_button_8(); break;
        case 7: _t->handle_d_button_8(); break;
        case 8: _t->handle_e_button_8(); break;
        case 9: _t->handle_f_button_8(); break;
        case 10: _t->handle_action_button_8(); break;
        case 11: _t->handle_biography_button_8(); break;
        case 12: _t->handle_classics_button_8(); break;
        case 13: _t->handle_comic_button_8(); break;
        case 14: _t->handle_comedy_button_8(); break;
        case 15: _t->handle_discovery_button_8(); break;
        case 16: _t->handle_documentary_button_8(); break;
        case 17: _t->handle_history_button_8(); break;
        case 18: _t->handle_kids_button_8(); break;
        case 19: _t->handle_miniseries_button_8(); break;
        case 20: _t->handle_reality_button_8(); break;
        case 21: _t->handle_science_fiction_button_8(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Series::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Series::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Series,
      qt_meta_data_Series, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Series::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Series::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Series::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Series))
        return static_cast<void*>(const_cast< Series*>(this));
    return QDialog::qt_metacast(_clname);
}

int Series::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
