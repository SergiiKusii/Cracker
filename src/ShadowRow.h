#pragma ones
#include <string>

enum class eHashType
{
    md5, // $1$ is MD5
    blowfish_a, // $2a$ is Blowfish
    blowfish_y, // $2y$ is Blowfish
    sha256, // $5$ is SHA-256
    sha512, // $6$ is SHA-512
};

struct ShadowPassword
{
    eHashType type;
    std::string hash;
};

class ShadowRow
{
public:
    explicit ShadowRow(const std::string& row);

private:
    std::string m_username;
    ShadowPassword m_password;
};