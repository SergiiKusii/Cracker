#include <crypto++/sha.h>
#include <crypto++/config.h>
#include <crypto++/hex.h>
#include <crypto++/base64.h>

#include "UnhesherExternal.h"

using t_byte_container = std::vector<byte>;

std::string EncodeToBase64(t_byte_container& digest)
{
    std::string encoded;

    CryptoPP::Base64Encoder encoder;
    encoder.Put(digest.data(), digest.size());
    encoder.MessageEnd();

    CryptoPP::word64 size = encoder.MaxRetrievable();
    if(size)
    {
        encoded.resize(size);		
        encoder.Get((byte*)&encoded[0], encoded.size());
    }

    return encoded;
}

std::string EncodeToHex(t_byte_container& digest)
{
    std::string encoded;
    CryptoPP::HexEncoder encoder;
    encoder.Attach( new CryptoPP::StringSink( encoded ) );
    encoder.Put( digest.data(), digest.size() );
    encoder.MessageEnd();
    
    return encoded;
}

t_byte_container EncryptSHA512(const std::string& plain)
{
    t_byte_container digest(CryptoPP::SHA512::DIGESTSIZE, 0);

    CryptoPP::SHA512().CalculateDigest(digest.data(), (const byte *)plain.data(), plain.size());

    return digest;
}

std::string UnhesherExternal::Crypt(const HashType, const std::string& salt, const std::string& saltPrefix, const std::string& data)
{
    auto fullSalt = saltPrefix + salt;
    auto digest = EncryptSHA512(fullSalt + data);

    std::string result = EncodeToBase64(digest);

    return result;
}