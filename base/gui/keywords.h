#pragma once
#include <windows.h>
#include <string>
#include <vector>

struct KeyWordInfo {
    std::string String;
    int pageID;
    int categoryID;
    bool initiateSequence = false;

    int timer = 0;
    float targeta;
    float a = 0;
    float dya;
    float aeasing;
};

std::vector<KeyWordInfo> keywordList = {};


