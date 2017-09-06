//Justin Cook 
//Milestone 2
#include "o.h"
#include "i.h"
#include "util.h"
using namespace std;



   Order::Order(vector<string> init) {
      if (init.size() < 3) {
         throw string("Expecting at least 3 fields, got " + init.size());
      }
      if (custNameValid(init[0]))
         custName = init[0];
      else
         throw string(init[0] + " is not a valid order name");
      if (prodNameValid(init[1]))
         prodName = init[1];
      else
         throw string(init[1] + " is not a valid order name");

      for (int i = 2; i < init.size(); i++) {
         if (prodNameValid(init[i]))
            items.push_back(init[i]);
         else
            throw string(init[i] + " is not a valid item name");
      }
   }

   void Order::orderPrint() {
      cout << "<" << custName << ">" << "<" << prodName << ">";
      for (auto i : items) {
         cout << "<" << i << ">";
      }
      cout << endl;
   }
   void Order::orderGraph(ofstream& of) {
      of << "\"" << custName << "\"->" << "\"" << prodName << "\"";
      for (int i = 0; i < items.size(); i++) {
         of << "->" << "\"" << items[i] << "\"";
      }
      of << " [color=green];\n";

   }




   OrderManager::OrderManager(vector<vector<string>> & data) {

      for (int i = 0; i < data.size(); i++) {
         try {
            orderList.push_back(Order(data[i]));
         }
         catch (string& error) {
            cout << error << endl;
         }
      }
   }

   void OrderManager::orderManagerPrint() {
      for (auto it : orderList) {
         it.orderPrint();
      }
   }
   void OrderManager::orderManagerGraph(const char* filename) {
      ofstream file;
      string holder = filename;
      holder += ".gv";
      cout << "opening " << holder << "..." << endl;
      file.open(holder, ios::out | ios::trunc);
      if (file.is_open()) {
         file << "digraph order {\n";
         for (auto it : orderList) {
            it.orderGraph(file);
         }
         file << "}";
      }
      else {
         cout << "file not opened" << endl;
      }
      file.close();
   }
   void OrderManager::validate(ItemManager& im) {
      bool flag = false;
      int trueCount = 0;

      for (int i = 0; i < orderList.size(); i++) {
         for (int p = 0; p < orderList[i].size(); p++) {
            for (int j = 0; j < im.size(); j++) {
               if (orderList[i].item(p) == im.name(j))
                  flag = true;
            }
            if (flag == false) {
               cout << "Order reference error on item " << p << " of order " << i << ": " << orderList[i].item(p) << endl;
               orderList[i].eraseItem(p);
            }
            flag = false;
         }
      }
   }