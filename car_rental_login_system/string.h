#pragma once
#include "access.h"

std::string stringLower(std::string &str) {
    std::string lower("");
    for (char &c : str) {
        lower += c;
    }
    return lower;
}
