#ifndef KRYPTON_RANSOMWARE_HEADER_HPP
#define KRYPTON_RANSOMWARE_HEADER_HPP
#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

struct Encryptor {
public:
    static auto encryptor(std::unordered_map<std::string, int> &files, std::map<char, int> &encryption, char &byte) -> void;
};

#endif
