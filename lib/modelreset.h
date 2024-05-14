// modelreset.h
#ifndef MODELRESET_H
#define MODELRESET_H

#include <string>
#include <vector>

class ModelReset {
public:
    ModelReset(const std::string& modelsDirectory);
    ~ModelReset();

    bool resetModelsToDefault() const;

private:
    std::string modelsDirectory;
    std::vector<std::string> getDefaultModelFilenames() const;
    bool copyModel(const std::string& source, const std::string& destination) const;
};

#endif // MODELRESET_H