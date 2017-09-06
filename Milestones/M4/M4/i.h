#pragma once
//Justin Cook 
//Milestone 3
#include "util.h"
#include "t.h"

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
   std::string name() { return itemName; };
   std::string installer() { return installerTask; };
   std::string remover() { return removerTask; };

};


class ItemManager {
   std::vector<Item> itemList;

public:
   ItemManager(std::vector<std::vector<std::string>> & data);

   void itemManagerPrint();
   void itemManagerGraph(const char* filename);
   void validate(TaskManager& tm);
   size_t size() { return itemList.size(); }
   std::string name(int pos) { return itemList[pos].name(); }
};
