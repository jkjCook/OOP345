#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

std::string trimString(std::string);
std::vector<std::vector<std::string>> csvRead(char*, const char);
bool taskNameValid(std::string&);
bool taskSlotsValid(std::string&);