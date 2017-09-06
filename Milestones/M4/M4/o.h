#pragma once
//Justin Cook 
//Milestone 2
#include "util.h"
#include "i.h"

using namespace std;

class Order {
   string custName;
   string prodName;
   vector<string> items;

public:
   Order(vector<string> init);

   void orderPrint();
   void orderGraph(ofstream& of);
   size_t size() { return items.size(); }
   string item(int pos) { return items[pos]; }
   void eraseItem(int pos) { items.erase(items.begin() + pos); }
};


class OrderManager {
   vector<Order> orderList;

public:
   OrderManager(vector<vector<string>> & data);

   void orderManagerPrint();
   void orderManagerGraph(const char* filename);
   void validate(ItemManager& im);
};