// modelreset.cpp
#include "modelreset.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

ModelReset::ModelReset(const std::string& modelsDir, const std::string& cfgFile)
    : modelsDirectory(modelsDir), cfgFilePath(cfgFile) {
    loadDefaultModelFilenames();
}

void ModelReset::loadDefaultModelFilenames() {
    std::ifstream configFile(cfgFilePath);
    if (!configFile.is_open()) {
        std::cerr << "Unable to open config file: " << cfgFilePath << std::endl;
        throw std::runtime_error("Configuration file could not be opened.");
    }

    std::string line;
    while (std::getline(configFile, line)) {
        if (line.rfind("default_models=", 0) == 0) {
            std::string modelsList = line.substr(15); // Remove the key
            std::istringstream ss(modelsList);
            std::string modelName;
            while (std::getline(ss, modelName, ',')) {
                defaultModelFilenames.push_back(modelName);
            }
            break;
        }
    }
}

bool ModelReset::resetModelsToDefault() const {
    for (const auto& modelName : defaultModelFilenames) {
        fs::path sourcePath = fs::path("res/default_models") / modelName;
        fs::path targetPath = fs::path(modelsDirectory) / modelName;
        try {
            if (fs::exists(sourcePath)) {
                fs::copy(sourcePath, targetPath, fs::copy_options::overwrite_existing);
            } else {
                std::cerr << "Default model file not found: " << sourcePath << std::endl;
                return false;
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Filesystem error: " << e.what() << std::endl;
            return false;
        }
    }
    return true;
}