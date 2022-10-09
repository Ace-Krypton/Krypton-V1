#ifndef KRYPTON_RANSOMWARE_HEADER_HPP
#define KRYPTON_RANSOMWARE_HEADER_HPP
#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

struct Encryptor {
public:
    static auto encryptor() -> void;
};

struct Decryptor {
public:
    static auto decryptor() -> void;
};

#endif
