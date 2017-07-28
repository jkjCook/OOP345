#pragma once
#include "t.h"
#include "i.h"
#include "o.h"

std::string trimString(std::string);
std::vector<std::vector<std::string>> csvRead(char*, const char);
bool taskNameValid(std::string&);
bool taskSlotsValid(std::string&);
bool custNameValid(std::string&);
bool prodNameValid(std::string&);
//Valide for referential integrety
bool validateTask(const Task&);
bool validateItem(const TaskManager&);
bool validateOrder(const ItemManager&);