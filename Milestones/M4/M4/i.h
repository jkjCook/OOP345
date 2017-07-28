#pragma once
//Justin Cook 
//Milestone 3
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

class Item {
   std::string itemName;
   std::string installerTask;
   std::string removerTask;
   std::string code;
   std::string desc;

public:
   Item(std::vector<std::string> init);

   void itemPrint();
   void itemGraph(std::ofstream& of);
};


class ItemManager {
   std::vector<Item> itemList;

public:
   ItemManager(std::vector<std::vector<std::string>> & data);

   void itemManagerPrint();
   void itemManagerGraph(const char* filename);
};
