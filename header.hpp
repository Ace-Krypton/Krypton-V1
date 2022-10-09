#ifndef KRYPTON_RANSOMWARE_HEADER_HPP
#define KRYPTON_RANSOMWARE_HEADER_HPP
#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

struct Encryptor {
public:
    static auto encryptor() -> void;
    inline static std::vector<int> storage;
    inline static std::unordered_map<std::string, int> files;
    inline static std::map<char, int> encryption;
};

struct Decryptor {
public:
    static auto decryptor() -> void;
};

#endif
