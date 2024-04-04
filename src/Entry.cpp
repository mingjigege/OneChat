#include "Entry.h"
#include "Global.h"

ll::Logger logger(PLUGIN_NAME);

namespace my_plugin {

std::unique_ptr<MyPlugin>& MyPlugin::getInstance() {
    static std::unique_ptr<MyPlugin> instance;
    return instance;
}

bool MyPlugin::load() {
    initPlugin();
    return true;
}

bool MyPlugin::enable() {
    listenEvent();
    logger.info("OneChat Loaded!");
    logger.info("Author: 铭记mingji");
    logger.info("Repository: https://github.com/mingjigege/OneChat");
    return true;
}

bool MyPlugin::disable() { return true; }

} // namespace my_plugin

LL_REGISTER_PLUGIN(my_plugin::MyPlugin, my_plugin::MyPlugin::getInstance());