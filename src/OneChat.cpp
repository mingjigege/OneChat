#include "Global.h"

ll::event::ListenerId mEventId;

bool mIsEnabled = false;

std::string formatMessage(std::string_view author, std::string_view message) {
    std::string        result         = message;
    const std::string& forbiddenWords = ConfigData::mBan;

    for (const auto& word : forbiddenWords) {
        std::size_t found = result.find(word);
        if (found != std::string::npos) {
            std::string replacement(word.length(), '*');
            result.replace(found, word.length(), replacement);
        }
    }

    return result;
}

void listenEvent() {
    auto listener = ll::event::EventBus::getInstance().emplaceListener<ll::event::player::PlayerChatEvent>(
        [](ll::event::player::PlayerChatEvent& ev) {
            ev.setMessage(formatMessage(ev.getAuthor(), ev.getMessage())); // 过滤违禁词
        },
        ll::event::EventPriority::High
    );
    mEventId   = listener->getId();
    mIsEnabled = true;
}
