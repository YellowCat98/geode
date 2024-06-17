
#include <Geode/loader/Dirs.hpp>
#include <cocos2d.h>
#include <crashlog.hpp>
#include <filesystem>
#include "LoaderImpl.hpp"

using namespace geode::prelude;

std::filesystem::path dirs::getGeodeDir() {
    return dirs::getGameDir() / "geode";
}

std::filesystem::path dirs::getGeodeSaveDir() {
    return dirs::getSaveDir() / "geode";
}

std::filesystem::path dirs::getGeodeResourcesDir() {
    return dirs::getGeodeDir() / "resources";
}

std::filesystem::path dirs::getGeodeLogDir() {
    return dirs::getGeodeDir() / "logs";
}

std::filesystem::path dirs::getTempDir() {
    return getGeodeDir() / "temp";
}

std::filesystem::path dirs::getModsDir() {
    return getGeodeDir() / "mods";
}

std::filesystem::path dirs::getModsSaveDir() {
    return getGeodeSaveDir() / "mods";
}

std::filesystem::path dirs::getModConfigDir() {
    return dirs::getGeodeDir() / "config";
}

std::filesystem::path dirs::getIndexDir() {
    return dirs::getGeodeDir() / "index";
}

std::filesystem::path dirs::getCrashlogsDir() {
    return crashlog::getCrashLogDirectory();
}
std::filesystem::path dirs::alias(const char* path) {
    std::string str = path;
    if (str.find("game://") != std::string::npos) {
        str.replace(str.find("game://"), std::string("game://").length(), dirs::getGameDir().string() + "\\");
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("mods://") != std::string::npos) {
        str.replace(str.find("mods://"), std::string("mods://").length(), dirs::getModsDir().string() + "\\");
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("mods:save://") != std::string::npos) {
        str.replace(str.find("mods:save://"), std::string("mods:save://").length(), dirs::getModsSaveDir().string() + "\\");
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode://") != std::string::npos) {
        str.replace(str.find("geode://"), std::string("geode://").length(), dirs::getGeodeDir().string() + "\\");
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode:save://") != std::string::npos) {
        str.replace(str.find("geode:save://"), std::string("geode:save://").length(), dirs::getGeodeSaveDir().string() + "\\");
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode:res://") != std::string::npos) {
        str.replace(str.find("geode:res://"), std::string("geode:res://").length(), dirs::getGeodeResourcesDir().string());
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode:log://") != std::string::npos) {
        str.replace(str.find("geode:log://"), std::string("geode:log://").length(), dirs::getGeodeLogDir().string());
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode:temp://") != std::string::npos) {
        str.replace(str.find("geode:temp://"), std::string("geode:temp://").length(), dirs::getTempDir().string());
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("geode:conf://") != std::string::npos) {
        str.replace(str.find("geode:conf://"), std::string("geode:conf://").length(), dirs::getModConfigDir().string());
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else if (str.find("mod:res://") != std::string::npos) {
        Mod* mod = getMod();
        str.replace(str.find("mod:res://"), std::string("mod:res://").length(), mod->getResourcesDir().string());
        size_t pos = 0;
        while ((pos = str.find("\\", pos)) != std::string::npos) {
            str.replace(pos, std::string("\\").length(), "/");
            pos += std::string("/").length();
        }
        std::filesystem::path finalPath(str);
        return finalPath;
    } else {
        throw std::invalid_argument("Invalid alias: " + std::string(str));
    }
}