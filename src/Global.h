#pragma once
#include <include_all.h>

#define PLUGIN_NAME "OneChat"

extern ll::Logger                logger;
extern GMLIB::Files::JsonConfig* Config;

namespace ConfigData {
extern int                      mChatLimit;
extern std::string              mPlaceholder;
extern bool                     mReplaceAll;
extern std::vector<std::string> mBlackList;
} // namespace ConfigData

extern void initPlugin();
extern void listenEvent();