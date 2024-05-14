// modelreset.cpp
#include "modelreset.h"
#include <filesystem>
#include <fstream>
#include <iostream>

// std::filesystem namespace kısaltması için bir alias
namespace fs = std::filesystem;

ModelReset::ModelReset(const std::string& modelsDirectory)
: modelsDirectory(modelsDirectory) {
    // Constructor
}

ModelReset::~ModelReset() {
    // Destructor
}

std::vector<std::string> ModelReset::getDefaultModelFilenames() const {
    // Burası varsayılan modellerin isimlerini döndürmek için placeholder.
    // Gerçek isimleri oyunun klasör yapısına göre ayarlamanız gerekecek.
    return {"v_ak47.mdl", "v_m4a1.mdl", /* ... diğer modeller ... */};
}

bool ModelReset::resetModelsToDefault() const {
    try {
        auto defaultModels = getDefaultModelFilenames();
        bool allCopied = true;
        for (const auto& modelName : defaultModels) {
            fs::path sourcePath = fs::current_path() / "default_models" / modelName;
            fs::path destinationPath = fs::path(modelsDirectory) / modelName;

            if (!fs::exists(sourcePath)) {
                std::cerr << "Default model file not found: " << sourcePath << std::endl;
                allCopied = false;
                continue;
            }

            // Model dosyasını resetle
            fs::copy(sourcePath, destinationPath, fs::copy_options::overwrite_existing);
        }
        return allCopied;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
        return false;
    }
}

bool ModelReset::copyModel(const std::string& source, const std::string& destination) const {
    // Bu fonksiyon artık kullanılmıyor, doğrudan resetModelsToDefault içinde işlem yapıyoruz.
    return false;
}