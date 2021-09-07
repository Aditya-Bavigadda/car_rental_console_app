#pragma once
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
#ifndef STRING_H
#define STRING_H
#include <string>
#endif
#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <algorithm>
#endif
#include "string.h"
#ifndef LIMITS_H
#define LIMITS_H
#include <limits>
#endif
void returning_process(std::vector<std::string> user_details);

void registration_process(std::vector<char> unnacceptable_words);

void login_process();
#include "access.cpp"
