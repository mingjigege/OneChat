#include "Config.h"
#include "Global.h"

namespace ConfigData {
extern std::string                                  mLimit;
extern std::unordered_map<std::string, std::string> mBan;
} // namespace ConfigData

namespace {
GMLIB::Files::JsonConfig* Config = nullptr;
}

void initConfig() {
    Config = new GMLIB::Files::JsonConfig("./plugins/OneChat/config/config.json", defaultConfig);
    Config->init();
    ConfigData::mLimit = Config->getValue<std::string>({"NumberLimit"}, "15");
    ConfigData::mBan   = Config->getValue<std::unordered_map<std::string, std::string>>(
        {
            "Ban"
    },
        {{"卡", "操"}}
    );
}

void initPlugin() { initConfig(); }