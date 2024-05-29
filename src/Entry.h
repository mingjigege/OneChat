#pragma once
#include "Config.h"
#include <ll/api/plugin/NativePlugin.h>

namespace OneChat {

class Entry {

public:
    static std::unique_ptr<Entry>& getInstance();

    Entry(ll::plugin::NativePlugin& self) : mSelf(self) {}

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const { return mSelf; }

    /// @return True if the plugin is loaded successfully.
    bool load();

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

    // /// @return True if the plugin is unloaded successfully.
    bool unload();

    Config& getConfig();

private:
    ll::plugin::NativePlugin& mSelf;
    std::optional<Config> mConfig;
};

} // namespace OneChat