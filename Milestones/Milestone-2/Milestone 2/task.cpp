//Justin Cook 
//Milestone 2
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
   Task(vector<string> init) {
      switch (init.size()) {
      case 4:
         if (taskNameValid(init[3]) && init[3] != " ")
            taskFail = init[3];
         else
            throw string(init[3] + " is not a valid task name");
      case 3:
         if (taskNameValid(init[2]) && init[2] != " ")
            taskPass = init[2];
         else
            throw string(init[2] + " is not a valid task name");
      case 2:
         if (taskSlotsValid(init[1]) && init[1] != " ")
            taskSlot = init[1];
         else
            throw string(init[1] + " is not a valid slots number");
      case 1:
         if (taskNameValid(init[0]) && init[0] != " ")
            taskName = init[0];
         else
            throw string(init[0] + " is not a valid task name");
         break;
      default:
         if (init.size() > 4) {
            throw string("expected 1,2,3 or 4 fields, got ") + to_string(init.size());
         }
         break;
      }
   }

   void taskPrint(){
      cout << taskName << " " << taskSlot << " " << taskPass << " " << taskFail << endl;
   }
   void taskGraph(ofstream& of){
      if (taskPass != "")
         of << "\"" << taskName << "\"" << "->" << "\"" << taskPass << "\" [color=green];\n";
      if (taskFail != "")
         of << "\"" << taskName << "\"" << "->" << "\"" << taskFail << "\" [color=red];\n";
      if(taskPass == "" && taskFail == "")
         of << "\"" << taskName << "\" [shape=box];\n";
   }
};


class TaskManager {
   vector<Task> taskList;
   
public:
   TaskManager(vector<vector<string>> & data) {
      
      for (int i = 0; i < data.size(); i++) {
         try {
            taskList.push_back(Task(data[i]));
         }
         catch (string& error) {
            cout << error << endl;
         }
      }  
   }

   void taskManagerPrint() {
      for (auto it : taskList) {
         it.taskPrint();
      }
   }
   void taskManagerGraph(char* filename) {
      ofstream file;
      
      file.open(strcat(filename, ".gv"), ios::out | ios::trunc);
      if (file.is_open()) {
         file << "digraph DG {";
         for (auto it : taskList) {
            it.taskGraph(file);
         }
         file << "}";
      }
      else {
         cout << "file not opened" << endl;
      }
      file.close();
   }
};



int main(int argc, char** argv) {

   vector<vector<string>> csvData;
   csvData = csvRead(argv[1], argv[2][0]);

   TaskManager T(csvData);

   T.taskManagerPrint();
   T.taskManagerGraph(argv[1]);

#ifdef __unix
   string dot = "dot"
#else 
   string dot = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe";
#endif

      string file(argv[1]);
      string cmd = dot + " -Tpng " + file + " > " + file + ".png";
      cout << "Running command --->'" << cmd << "'\n";
      cout << "The operating system says dot returned '"
         << system(cmd.c_str())
         << "' (0 is good --> dot executed successfully)\n";

   cin.get();
}