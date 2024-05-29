#include "Global.h"

bool replaceIlligalWords(std::string& message, std::string word) {
    if (message.find(word) != std::string::npos) {
        ll::string_utils::replaceAll(message, word, OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.Placeholder);
        return true;
    }
    return false;
}
//OneChat::Entry::getInstance()->getConfig().ChatFormat
void checkMessage(std::string& message) {
    for (auto& word : OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.Blacklist) {
        auto result = replaceIlligalWords(message, word);
        if (result && OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.ReplaceAll) {
            message = OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.Placeholder;
            return;
        }
    }
}

void listenEvent() {
    ll::event::EventBus::getInstance().emplaceListener<ll::event::player::PlayerChatEvent>(
        [](ll::event::player::PlayerChatEvent& ev) {
            if (OneChat::Entry::getInstance()->getConfig().SpamCheck.MaxChatLength) {
                if (ev.message().size() > OneChat::Entry::getInstance()->getConfig().SpamCheck.Enabled) {
                    ev.cancel();
                    ev.message() = OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.Placeholder;
                    return ev.self().sendMessage(OneChat::Entry::getInstance()->getConfig().SpamCheck.Message);
                }
            }
            if (OneChat::Entry::getInstance()->getConfig().IlligalWordsCheck.Enabled == true) {
                return checkMessage(ev.message());
            }
        },
        ll::event::EventPriority::Highest
    );
}
