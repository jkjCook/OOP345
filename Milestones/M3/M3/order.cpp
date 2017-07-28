//Justin Cook 
//Milestone 2
#include "util.h"

using namespace std;


class Order {
   string custName;
   string prodName;
   vector<string> items;

public:
   Order(vector<string> init) {
      if ( init.size() < 3 ) {
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

   void orderPrint() {
      cout << "<" << custName << ">" << "<" << prodName << ">";
      for (auto i : items) {
         cout << "<" << i << ">";
      }
      cout << endl;
   }
   void orderGraph(ofstream& of) {
      of << "\"" << custName << "\"->" << "\"" << prodName << "\"";
      for (int i = 0; i < items.size(); i++) {
         of << "->" << "\"" << items[i] << "\"";
      }
      of << " [color=green];\n";

   }
};


class OrderManager {
   vector<Order> orderList;

public:
   OrderManager(vector<vector<string>> & data) {

      for (int i = 0; i < data.size(); i++) {
         try {
            orderList.push_back(Order(data[i]));
         }
         catch (string& error) {
            cout << error << endl;
         }
      }
   }

   void orderManagerPrint() {
      for (auto it : orderList) {
         it.orderPrint();
      }
   }
   void orderManagerGraph(const char* filename) {
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
};