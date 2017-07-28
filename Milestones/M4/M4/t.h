#pragma once
//Justin Cook 
//Milestone 4
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "util.h"
using namespace std;


class Task {
   string taskName;
   string taskSlot = "1";
   string taskPass;
   string taskFail;

public:
   Task(vector<string> init);

   void taskPrint();
   void taskGraph(ofstream& of);
};


class TaskManager {
   vector<Task> taskList;

public:
   TaskManager(vector<vector<string>> & data);

   void taskManagerPrint();
   void taskManagerGraph(char* filename);
};




