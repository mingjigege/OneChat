#pragma once
#include <iostream>
#include <vector>

struct Config {
    int version = 1;
struct Spam_Check {
        bool                     Enabled     = true;
        int                      MaxChatLength = 60;
        std::string              Message = "发言内容过长，请重新输入！";
    } SpamCheck;

    struct Words_Check {
        bool                     Enabled     = true;
        bool                     ReplaceAll  = true;
        std::string              Placeholder = "***";
        std::vector<std::string> Blacklist   = {"卡"};
    } IlligalWordsCheck;
}