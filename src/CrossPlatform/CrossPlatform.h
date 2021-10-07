#include <string>
#include <QString>

class CrossPlatform {
    public:
        std::string xString(QString text);
        void importRecoveryCredentials(QString recoveryPath, QString workDir);
};