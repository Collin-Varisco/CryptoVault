#include "Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Global/Global.h"
#include <iostream>

/* encryptString(const QString &information)
 * Encrypt with AES
 * const QString &information - plain text that will be encrypted
 *
*/
std::string Crypto::encryptString(QString information, bool loginChanged)
{
    // AES Encryption Key
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CBC);
    QString key(QString::fromStdString(global.global_key));
    QString iv(QString::fromStdString(global.global_iv));
    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(iv.toUtf8(), QCryptographicHash::Md5);

    QByteArray encodeInfo = encryption.encode(information.toUtf8(), hashKey, hashIV);
    QString encoded = QString(encodeInfo.toBase64());
    CrossPlatform x;
    std::string encoded_str = x.xString(encoded);
    return encoded_str;
}

/* decryptValue(const QString &info)
 * Decrypt AES encrypted credentials
 * const QString &info - AES encrypted information that will be decrypted
 *
*/
std::string Crypto::decryptValue(QString info)
{
    // AES Encryption Key
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CBC);
    QString key(QString::fromStdString(global.global_key));
    QString iv(QString::fromStdString(global.global_iv));
    QByteArray temp = QByteArray::fromBase64(info.toUtf8());

    QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(iv.toUtf8(), QCryptographicHash::Md5);

    QByteArray decodeCred = encryption.decode(temp, hashKey, hashIV);
    QString decodedString = encryption.removePadding(decodeCred);
    CrossPlatform x;
    return x.xString(decodedString);
}

/* hash256(QString value)
 * Hash Username and Password with SHA-256
 * Qtring value - either username or password
 *
 * Returns: hashed_value - value of parameter after being hashed with SHA-256
*/
QString Crypto::hash256(QString value){
    QByteArray value_qByte = QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Sha256);
    QString hashed_Value = value_qByte.toBase64();
    return hashed_Value;
}
