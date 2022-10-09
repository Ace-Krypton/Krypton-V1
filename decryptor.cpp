#include <iostream>
#include <fstream>
#include "header.hpp"

auto Decryptor::decryptor() -> void {
    for (auto &entry : Encryptor::files) {
        std::cout << "[*] File(s) decrypted successfully\n" << std::endl;
        std::ifstream read(entry.first);

        if (!read.is_open()) std::cerr << "[-] Could not open the file - '" << entry.first << "'" << std::endl;
        else std::cout << "[*] File opened" << std::endl;

        auto decrypt = std::fstream(entry.first, std::ios::out | std::ios::app);

        for (auto &element : Encryptor::storage) {
            for (auto &encryptions : Encryptor::encryption) {
                if (element == encryptions.second) {
                    decrypt << encryptions.first;
                }
            }

            std::ofstream ofs;
            ofs.open(entry.first, std::ofstream::out | std::ofstream::trunc);
            ofs.close();
        }
        decrypt << '\n';
        std::cout << "[*] File(s) decrypted successfully\n" << std::endl;
    }
}
