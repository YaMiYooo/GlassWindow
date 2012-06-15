/****************************************************************************
** Meta object code from reading C++ file 'bwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   19, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,

 // enums: name, flags, count, data
      27, 0x0,    3,   23,

 // enum data: key, value
      38, uint(BWidget::Normal),
      45, uint(BWidget::Dialog),
      52, uint(BWidget::Popup),

       0        // eod
};

static const char qt_meta_stringdata_BWidget[] = {
    "BWidget\0\0MaxOrNormalSlot()\0WindowType\0"
    "Normal\0Dialog\0Popup\0"
};

void BWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BWidget *_t = static_cast<BWidget *>(_o);
        switch (_id) {
        case 0: _t->MaxOrNormalSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BWidget,
      qt_meta_data_BWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BWidget))
        return static_cast<void*>(const_cast< BWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
