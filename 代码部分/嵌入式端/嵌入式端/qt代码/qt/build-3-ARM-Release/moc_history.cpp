/****************************************************************************
** Meta object code from reading C++ file 'history.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../4/history.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'history.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_history[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,
      63,    8,    8,    8, 0x08,
      74,    8,    8,    8, 0x08,
      87,    8,    8,    8, 0x08,
      98,    8,    8,    8, 0x08,
     127,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_history[] = {
    "history\0\0on_pushButton_clicked()\0"
    "on_pushButton_query_clicked()\0showpage()\0"
    "init_table()\0init_sql()\0"
    "on_pushButton_last_clicked()\0"
    "on_pushButton_next_clicked()\0"
};

void history::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        history *_t = static_cast<history *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_query_clicked(); break;
        case 2: _t->showpage(); break;
        case 3: _t->init_table(); break;
        case 4: _t->init_sql(); break;
        case 5: _t->on_pushButton_last_clicked(); break;
        case 6: _t->on_pushButton_next_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData history::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject history::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_history,
      qt_meta_data_history, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &history::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *history::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *history::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_history))
        return static_cast<void*>(const_cast< history*>(this));
    return QDialog::qt_metacast(_clname);
}

int history::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
