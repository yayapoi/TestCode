#ifndef ENCODEOBJECT_H
#define ENCODEOBJECT_H

#include <QObject>

class EncodeObject : public QObject
{
    Q_OBJECT
public:
    explicit EncodeObject(QObject *parent = nullptr);

    //加密
    static QByteArray Encode(QString str);

    //解密
    static QByteArray Decode(QString str);
signals:

};

#endif // ENCODEOBJECT_H
