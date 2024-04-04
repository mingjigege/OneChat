#include "Global.h"

std::string formatMessage(std::string_view author, std::string_view message) {
    std::string Limit          = ConfigData::mLimit;
    std::string forbiddenWords = ConfigData::mBan;
    auto        result         = message;


    for (const auto& word : forbiddenWords) {
        if (result.find(word) != std::string::npos) {
            std::string replacement(word.length(), '*');
            ll::utils::string_utils::replaceAll(result, word, replacement);
        }
    }

    return result;
}

void listenEvent() {
    auto& eventBus = ll::event::EventBus::getInstance();
    eventBus.emplaceListener<GMLIB::Event::PacketEvent::TextPacketWriteBeforeEvent>(
        [](GMLIB::Event::PacketEvent::TextPacketWriteBeforeEvent& ev) {
            auto& pkt = ev.getPacket();
            if (pkt.mType == TextPacketType::Chat) {
                auto pl      = ll::service::getLevel()->getPlayer(pkt.mAuthor);
                pkt.mMessage = formatMessage(pkt.mAuthor, pkt.mMessage);
                pkt.mAuthor.clear();
            }
        }
    );
}

void removeListener() {
    auto& eventBus = ll::event::EventBus::getInstance();
    eventBus.removePluginListeners("OneChat");
}