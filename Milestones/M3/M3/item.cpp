//Justin Cook 
//Milestone 3
#include "util.h"

using namespace std;


class Item {
   string itemName;
   string installerTask;
   string removerTask;
   string code;
   string desc;

public:
   Item(vector<string> init) {
      if (init.size() <= 5) {
         itemName = init[0];
         installerTask = init[1];
         removerTask = init[2];
         code = init[3];
         if (init.size() == 5)
            desc = init[4];
         else
            desc = "";
      }
      else {
         throw string("Expecting a maximum of 5 fields, got ") + to_string(init.size());
      }
   }

   void itemPrint() {
      cout << "<" << itemName << ">" << "<" << installerTask << ">" << "<" << removerTask << ">" << "<" << code << ">";
      if (desc != "")
         cout << "<" << desc << ">";
      cout << endl;
   }
   void itemGraph(ofstream& of) {
      of << "\"" << itemName << "\"->" << "\"" << installerTask << "\"->" << "\"" << removerTask << "\"->" << "\"" << code << "\"";
      if (desc != "")
         of << "->\"" << desc << "\"";
      of << " [color=green];\n";

   }
};


class ItemManager {
   vector<Item> itemList;

public:
   ItemManager(vector<vector<string>> & data) {

      for (int i = 0; i < data.size(); i++) {
         try {
            itemList.push_back(Item(data[i]));
         }
         catch (string& error) {
            cout << error << endl;
         }
      }
   }

   void itemManagerPrint() {
      for (auto it : itemList) {
         it.itemPrint();
      }
   }
   void itemManagerGraph(const char* filename) {
      ofstream file;
      string holder = filename;
      holder += ".gv";
      cout << "opening " << holder << "..." << endl;
      file.open(holder, ios::out | ios::trunc);
      if (file.is_open()) {
         file << "digraph item {\n";
         for (auto it : itemList) {
            it.itemGraph(file);
         }
         file << "}";
      }
      else {
         cout << "file not opened" << endl;
      }
      file.close();
   }
};