#include "Config.h"
#include "Global.h"

namespace ConfigData {
int                      mChatLimit   = 20;
std::string              mPlaceholder = "*";
bool                     mReplaceAll  = false;
std::vector<std::string> mBlackList   = {};
} // namespace ConfigData

GMLIB::Files::JsonConfig* Config = nullptr;

void initConfig() {
    Config = new GMLIB::Files::JsonConfig("./plugins/OneChat/config/config.json", defaultConfig);
    Config->init();
    ConfigData::mChatLimit   = Config->getValue<int>({"SpamCheck", "MaxChatLength"}, 60);
    ConfigData::mPlaceholder = Config->getValue<std::string>({"IlligalWordsCheck", "Placeholder"}, "*");
    ConfigData::mReplaceAll  = Config->getValue<bool>({"IlligalWordsCheck", "ReplaceAll"}, true);
    ConfigData::mBlackList   = Config->getValue<std::vector<std::string>>({"IlligalWordsCheck", "Blacklist"}, {});
}

void initPlugin() { initConfig(); }