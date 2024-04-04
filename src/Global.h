#pragma once
#include <include_all.h>

#define PLUGIN_NAME "OneChat"

extern ll::Logger logger;

namespace ConfigData {
extern std::string                     mLimit;
extern std::unordered_map<std::string> mBan;
} // namespace ConfigData

extern void initPlugin();
extern void listenEvent();
extern void removeListener();