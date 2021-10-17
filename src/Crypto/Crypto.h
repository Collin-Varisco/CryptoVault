#include <string>
#include <QString>
#include <QCryptographicHash>
#include <qaesencryption.h>
#include <vector>
#include <QStringList>
class Crypto {
    public:
        std::string decryptValue(QString val);
        std::string encryptString(QString val);
        QString hash256(QString value);
};
