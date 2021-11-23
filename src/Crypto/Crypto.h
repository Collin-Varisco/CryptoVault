#include <string>
#include <QString>
#include <QCryptographicHash>
#include <qaesencryption.h>
#include <vector>
#include <QStringList>
class Crypto {
    public:
        std::string decryptValue(QString val);
        std::string decryptFileValue(QString val);
        std::string encryptString(QString val, bool loginChanged);
        QString hash256(QString value);
};
