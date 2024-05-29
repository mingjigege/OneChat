#include "Entry.h"
#include "Global.h"

ll::Logger logger(PLUGIN_NAME);

namespace OneChat {

std::unique_ptr<Entry>& Entry::getInstance() {
    static std::unique_ptr<Entry> instance;
    return instance;
}

bool Entry::load() { return true; }

bool Entry::enable() {
    mConfig.emplace();
    if (!ll::config::loadConfig(*mConfig, getSelf().getConfigDir() / u8"config.json")) {
        ll::config::saveConfig(*mConfig, getSelf().getConfigDir() / u8"config.json");
    }
    listenEvent();
    logger.info("OneChat Loaded!");
    logger.info("Author: 铭记mingji");
    logger.info("Repository: https://github.com/mingjigege/OneChat");
    return true;
}
Config& Entry::getConfig() { return mConfig.value(); }

bool Entry::disable() { return true; }

bool Entry::unload() { return true; }

} // namespace OneChat

LL_REGISTER_PLUGIN(OneChat::Entry, OneChat::Entry::getInstance());