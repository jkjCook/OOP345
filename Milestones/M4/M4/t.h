#pragma once
//Justin Cook 
//Milestone 4
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
   string name() { return taskName; }
   string slot() { return taskSlot; }
   string pass() { return taskPass; }
   string fail() { return taskFail; }
};


class TaskManager {
   vector<Task> taskList;

public:
   TaskManager(vector<vector<string>> & data);

   void taskManagerPrint();
   void taskManagerGraph(char* filename);
   void validate();
   string name(int pos) { return taskList[pos].name(); }
   size_t size() { return taskList.size(); }
};




