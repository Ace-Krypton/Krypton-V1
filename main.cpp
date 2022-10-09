#include "header.hpp"

auto main() -> int {
    bool main_loop = true;
    int user_input;

    while (main_loop) {
        main_menu();
        std::cout << "\n> ";
        std::cin >> user_input;

        switch (user_input) {
            case 1:
                Encryptor::encryptor();
                break;

            case 2:
                Decryptor::decryptor();
                break;

            case 0:
                main_loop = false;
                break;

            default:
                std::cout << "[-] Invalid command, Please try again" << std::endl;
        }
    }
}

auto main_menu() -> void {
    std::cout << "[1] Encrypt" << std::endl;
    std::cout << "[2] Decrypt" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}
