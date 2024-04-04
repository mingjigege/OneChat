#pragma once
#include "Global.h"

std::string defaultConfig = R"({
    "SpamCheck": {
        "Enabled": true,
        "MaxChatLength": 60,
        "Message": "发言内容过长，请重新输入！"
    },
    "IlligalWordsCheck": {
        "Enabled": true,
        "ReplaceAll": true,
        "Placeholder": "***",
        "Blacklist": [
            "妈",
            "操",  
            "卡"
        ]
    }
})";