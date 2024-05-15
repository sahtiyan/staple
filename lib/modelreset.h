// modelreset.h
#ifndef MODELRESET_H
#define MODELRESET_H

#include <string>
#include <vector>

class ModelReset {
public:
    ModelReset(const std::string& modelsDirectory, const std::string& cfgFilePath);
    bool resetModelsToDefault() const;

private:
    std::string modelsDirectory;
    std::string cfgFilePath;
    std::vector<std::string> defaultModelFilenames;
    void loadDefaultModelFilenames();
};

#endif // MODELRESET_H