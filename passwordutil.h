#ifndef PASSWORDUTIL_H
#define PASSWORDUTIL_H

#include <QString>

class PasswordUtil
{
public:
    static QString hashPassword(const QString &password);
};

#endif // PASSWORDUTIL_H
