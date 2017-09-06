#include "i.h"
#include "t.h"

using namespace std;

Item::Item(vector<string> init) {
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

void Item::itemPrint() {
   cout << "<" << itemName << ">" << "<" << installerTask << ">" << "<" << removerTask << ">" << "<" << code << ">";
   if (desc != "")
      cout << "<" << desc << ">";
   cout << endl;
}
void Item::itemGraph(ofstream& of) {
   of << "\"" << itemName << "\"->" << "\"" << installerTask << "\"->" << "\"" << removerTask << "\"->" << "\"" << code << "\"";
   if (desc != "")
      of << "->\"" << desc << "\"";
   of << " [color=green];\n";

}




ItemManager::ItemManager(vector<vector<string>> & data) {

   for (int i = 0; i < data.size(); i++) {
      try {
         itemList.push_back(Item(data[i]));
      }
      catch (string& error) {
         cout << error << endl;
      }
   }
}

void ItemManager::itemManagerPrint() {
   for (auto it : itemList) {
      it.itemPrint();
   }
}
void ItemManager::itemManagerGraph(const char* filename) {
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
void ItemManager::validate(TaskManager& tm) {
   bool flagInstall = false;
   bool flagRemove = false;
   for (int index = 0; index < itemList.size(); index++) {
      
      for (int inner = 0; inner < tm.size(); inner++) {
         if (itemList[index].installer() == tm.name(inner)) {
            flagInstall = true;
         }
         if (itemList[index].remover() == tm.name(inner)) {
            flagRemove = true;
         }
      }

      if (flagInstall == false || flagRemove == false) {
         cout << "Item reference error on item " << index << ": " << itemList[index].name() << endl;
         itemList.erase(itemList.begin() + index);
      }

      flagInstall = false; flagRemove = false;
   }
}
