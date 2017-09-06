#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

std::string trimString(std::string);
std::vector<std::vector<std::string>> csvRead(char*, const char);
bool taskNameValid(std::string&);
bool taskSlotsValid(std::string&);
bool custNameValid(std::string&);
bool prodNameValid(std::string&);