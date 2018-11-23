#include "Cryper.h"
#include "Logger.h"

#include <crypto++/sha.h>
#include <crypto++/config.h>
#include <crypto++/hex.h>

Cryper::Cryper(const HashType& type)
: m_type(type)
{

}

void Cryper::Encrypt(const std::string& plain)
{
    Logger::Get()->Info("start encrypt plain=" + plain);
    byte digest[CryptoPP::SHA512::DIGESTSIZE];

    CryptoPP::SHA512().CalculateDigest(digest, (const byte *)plain.data(), plain.size());

    CryptoPP::HexEncoder encoder;
    std::string output;

    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    Logger::Get()->Info("end encrypt hex digest=" + output);
}