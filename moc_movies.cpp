/****************************************************************************
** Meta object code from reading C++ file 'movies.h'
**
** Created: Sat Apr 13 20:59:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "movies.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movies.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Movies[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
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
     282,    7,    7,    7, 0x08,
     312,    7,    7,    7, 0x08,
     336,    7,    7,    7, 0x08,
     366,    7,    7,    7, 0x08,
     392,    7,    7,    7, 0x08,
     417,    7,    7,    7, 0x08,
     445,    7,    7,    7, 0x08,
     480,    7,    7,    7, 0x08,
     506,    7,    7,    7, 0x08,
     540,    7,    7,    7, 0x08,
     565,    7,    7,    7, 0x08,
     587,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Movies[] = {
    "Movies\0\0handleButton_3_1()\0"
    "handleButton_3_2()\0handleButton_3_3()\0"
    "handleButton_3_4()\0handle_a_button_3()\0"
    "handle_b_button_3()\0handle_c_button_3()\0"
    "handle_d_button_3()\0handle_e_button_3()\0"
    "handle_f_button_3()\0handle_action_button_3()\0"
    "handle_animation_button_3()\0"
    "handle_comedy_button_3()\0"
    "handle_documentary_button_3()\0"
    "handle_drama_button_3()\0"
    "handle_family_kids_button_3()\0"
    "handle_foreign_button_3()\0"
    "handle_horror_button_3()\0"
    "handle_music_art_button_3()\0"
    "handle_mystery_suspense_button_3()\0"
    "handle_romance_button_3()\0"
    "handle_science_fiction_button_3()\0"
    "handle_sports_button_3()\0handle_war_button_3()\0"
    "handle_western_button_3()\0"
};

void Movies::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Movies *_t = static_cast<Movies *>(_o);
        switch (_id) {
        case 0: _t->handleButton_3_1(); break;
        case 1: _t->handleButton_3_2(); break;
        case 2: _t->handleButton_3_3(); break;
        case 3: _t->handleButton_3_4(); break;
        case 4: _t->handle_a_button_3(); break;
        case 5: _t->handle_b_button_3(); break;
        case 6: _t->handle_c_button_3(); break;
        case 7: _t->handle_d_button_3(); break;
        case 8: _t->handle_e_button_3(); break;
        case 9: _t->handle_f_button_3(); break;
        case 10: _t->handle_action_button_3(); break;
        case 11: _t->handle_animation_button_3(); break;
        case 12: _t->handle_comedy_button_3(); break;
        case 13: _t->handle_documentary_button_3(); break;
        case 14: _t->handle_drama_button_3(); break;
        case 15: _t->handle_family_kids_button_3(); break;
        case 16: _t->handle_foreign_button_3(); break;
        case 17: _t->handle_horror_button_3(); break;
        case 18: _t->handle_music_art_button_3(); break;
        case 19: _t->handle_mystery_suspense_button_3(); break;
        case 20: _t->handle_romance_button_3(); break;
        case 21: _t->handle_science_fiction_button_3(); break;
        case 22: _t->handle_sports_button_3(); break;
        case 23: _t->handle_war_button_3(); break;
        case 24: _t->handle_western_button_3(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Movies::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Movies::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Movies,
      qt_meta_data_Movies, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Movies::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Movies::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Movies::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Movies))
        return static_cast<void*>(const_cast< Movies*>(this));
    return QDialog::qt_metacast(_clname);
}

int Movies::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
