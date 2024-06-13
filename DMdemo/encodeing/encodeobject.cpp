#include "encodeobject.h"

EncodeObject::EncodeObject(QObject *parent)
    : QObject{parent}
{

}

QByteArray EncodeObject::Encode(QString str)
{
    QByteArray byteArray = str.toUtf8();
    byteArray = byteArray.toBase64();
    return  byteArray;
}

QByteArray EncodeObject::Decode(QString str)
{
    QByteArray byteArray = str.toUtf8();
    byteArray = QByteArray::fromBase64(str.toUtf8());
    return byteArray;
}
