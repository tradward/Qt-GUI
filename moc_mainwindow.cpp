/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Apr 12 16:01:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   28,   28,   28, 0x08,
      29,   28,   28,   28, 0x08,
      46,   28,   28,   28, 0x08,
      63,   28,   28,   28, 0x08,
      80,   28,   28,   28, 0x08,
      97,   28,   28,   28, 0x08,
     114,   28,   28,   28, 0x08,
     125,   28,   28,   28, 0x08,
     145,   28,   28,   28, 0x08,
     165,   28,   28,   28, 0x08,
     185,   28,   28,   28, 0x08,
     205,   28,   28,   28, 0x08,
     225,   28,   28,   28, 0x08,
     245,   28,   28,   28, 0x08,
     265,   28,   28,   28, 0x08,
     285,   28,   28,   28, 0x08,
     305,   28,   28,   28, 0x08,
     325,   28,   28,   28, 0x08,
     345,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0handleButton_2()\0\0"
    "handleButton_3()\0handleButton_4()\0"
    "handleButton_5()\0handleButton_6()\0"
    "handleButton_7()\0search_2()\0"
    "handle_a_button_2()\0handle_b_button_2()\0"
    "handle_c_button_2()\0handle_d_button_2()\0"
    "handle_e_button_2()\0handle_f_button_2()\0"
    "handle_g_button_2()\0handle_h_button_2()\0"
    "handle_i_button_2()\0handle_j_button_2()\0"
    "handle_k_button_2()\0handle_l_button_2()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->handleButton_2(); break;
        case 1: _t->handleButton_3(); break;
        case 2: _t->handleButton_4(); break;
        case 3: _t->handleButton_5(); break;
        case 4: _t->handleButton_6(); break;
        case 5: _t->handleButton_7(); break;
        case 6: _t->search_2(); break;
        case 7: _t->handle_a_button_2(); break;
        case 8: _t->handle_b_button_2(); break;
        case 9: _t->handle_c_button_2(); break;
        case 10: _t->handle_d_button_2(); break;
        case 11: _t->handle_e_button_2(); break;
        case 12: _t->handle_f_button_2(); break;
        case 13: _t->handle_g_button_2(); break;
        case 14: _t->handle_h_button_2(); break;
        case 15: _t->handle_i_button_2(); break;
        case 16: _t->handle_j_button_2(); break;
        case 17: _t->handle_k_button_2(); break;
        case 18: _t->handle_l_button_2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
