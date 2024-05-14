// main.cpp
#include <iostream>
#include "cmdparser.h"
#include "modelreset.h"

int main(int argc, char* argv[]) {
    // Komut satırı argümanlarını kontrol et
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_CS_model_directory>" << std::endl;
        return 1;
    }

    std::string pathToCSModelDir = argv[1]; // CS model klasörü yolu

    // Kullanıcıdan komut al
    std::string userInput;
    std::cout << "Staple Model Reset CLI" << std::endl;
    std::cout << "> "; // Komut istemi
    getline(std::cin, userInput);

    // Komut satırı argümanlarını ayrıştır
    CmdParser parser;
    parser.parse(userInput);

    // Komutu ve argümanları al
    std::string command = parser.getCommand();
    std::vector<std::string> args = parser.getArgs();

    // ModelReset sınıfının bir örneğini oluştur
    ModelReset modelReset(pathToCSModelDir);

    // Komutları işle
    if (command == "reset") {
        if (modelReset.resetModelsToDefault()) {
            std::cout << "Models have been successfully reset to defaults." << std::endl;
        } else {
            std::cerr << "There was an error resetting the models." << std::endl;
        }
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
    }

    return 0;
}