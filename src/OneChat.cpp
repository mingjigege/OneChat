#include "Global.h"

bool replaceIlligalWords(std::string& message, std::string word) {
    if (message.find(word) != std::string::npos) {
        ll::string_utils::replaceAll(message, word, ConfigData::mPlaceholder);
        return true;
    }
    return false;
}

void checkMessage(std::string& message) {
    for (auto& word : ConfigData::mBlackList) {
        auto result = replaceIlligalWords(message, word);
        if (result && ConfigData::mReplaceAll) {
            message = ConfigData::mPlaceholder;
            return;
        }
    }
}

void listenEvent() {
    ll::event::EventBus::getInstance().emplaceListener<ll::event::player::PlayerChatEvent>(
        [](ll::event::player::PlayerChatEvent& ev) {
            if (Config->getValue<bool>({"SpamCheck", "Enabled"}, true)) {
                if (ev.message().size() > ConfigData::mChatLimit) {
                    ev.cancel();
                    ev.message() = ConfigData::mPlaceholder;
                    return ev.self().sendMessage(Config->getValue<std::string>({"SpamCheck", "Message"}, ""));
                }
            }
            if (Config->getValue<bool>({"IlligalWordsCheck", "Enabled"}, true)) {
                return checkMessage(ev.message());
            }
        },
        ll::event::EventPriority::Highest
    );
}
