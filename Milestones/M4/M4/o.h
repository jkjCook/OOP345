#pragma once
//Justin Cook 
//Milestone 2
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "util.h"

using namespace std;


class Order {
   string custName;
   string prodName;
   vector<string> items;

public:
   Order(vector<string> init);

   void orderPrint();
   void orderGraph(ofstream& of);
};


class OrderManager {
   vector<Order> orderList;

public:
   OrderManager(vector<vector<string>> & data);

   void orderManagerPrint();
   void orderManagerGraph(const char* filename);
};