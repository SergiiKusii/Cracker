#pragma once

enum class HashType
{
    none,
    md5, // $1$ is MD5
    blowfish_a, // $2a$ is Blowfish
    blowfish_y, // $2y$ is Blowfish
    sha256, // $5$ is SHA-256
    sha512, // $6$ is SHA-512
};