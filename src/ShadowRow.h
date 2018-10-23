#pragma ones
#include <string>

enum class HashType
{
    none,
    md5, // $1$ is MD5
    blowfish_a, // $2a$ is Blowfish
    blowfish_y, // $2y$ is Blowfish
    sha256, // $5$ is SHA-256
    sha512, // $6$ is SHA-512
};

struct ShadowPassword
{
    HashType type;
    std::string salt;
    std::string hash;
};

class ShadowRow
{
public:
    explicit ShadowRow(const std::string& row);

private:
    void SetPassword(const std::string& str);

private:
    std::string m_userName;
    ShadowPassword m_password;
    bool m_isLocked = false;
};