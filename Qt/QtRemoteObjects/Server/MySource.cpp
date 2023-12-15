#include "MySource.h"

void MySource::setData(const QString &data)
{
    myData = data;
    emit dataChanged(data);
}

QString MySource::getData()
{
    return myData;
}

void MySource::testEnum(MyEnum t)
{
    Q_UNUSED(t)
}

void MySource::testStruct(MyStruct t)
{
    Q_UNUSED(t)
}
