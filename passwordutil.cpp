#include "passwordutil.h"
#include <QCryptographicHash>

QString PasswordUtil::hashPassword(const QString &password)
{
    QByteArray hash =
        QCryptographicHash::hash(
            password.toUtf8(),
            QCryptographicHash::Sha256
        );

    return hash.toHex();
}
