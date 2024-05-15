// main.cpp
#include "modelreset.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <models_directory> <config_file_path>" << std::endl;
        return 1;
    }

    std::string modelsDirectory = argv[1];
    std::string configFilePath = argv[2];

    ModelReset modelReset(modelsDirectory, configFilePath);
    if (modelReset.resetModelsToDefault()) {
        std::cout << "Models have been successfully reset to defaults." << std::endl;
    } else {
        std::cerr << "An error occurred while resetting models." << std::endl;
        return 1;
    }

    return 0;
}