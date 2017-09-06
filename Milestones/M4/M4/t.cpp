//Justin Cook 
//Milestone 4
#include "t.h"
#include "util.h"
using namespace std;


   Task::Task(vector<string> init) {
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

   void Task::taskPrint() {
      cout << taskName << " " << taskSlot << " " << taskPass << " " << taskFail << endl;
   }
   void Task::taskGraph(ofstream& of) {
      if (taskPass != "")
         of << "\"" << taskName << "\"" << "->" << "\"" << taskPass << "\" [color=green];\n";
      if (taskFail != "")
         of << "\"" << taskName << "\"" << "->" << "\"" << taskFail << "\" [color=red];\n";
      if (taskPass == "" && taskFail == "")
         of << "\"" << taskName << "\" [shape=box];\n";
   }




   TaskManager::TaskManager(vector<vector<string>> & data) {

      for (int i = 0; i < data.size(); i++) {
         try {
            taskList.push_back(Task(data[i]));
         }
         catch (string& error) {
            cout << error << endl;
         }
      }
   }

   void TaskManager::taskManagerPrint() {
      for (auto it : taskList) {
         it.taskPrint();
      }
   }
   void TaskManager::taskManagerGraph(char* filename) {
      ofstream file;
      string holder = filename;
      holder += ".gv";
      file.open(holder, ios::out | ios::trunc);
      if (file.is_open()) {
         file << "digraph task {\n";
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
   void TaskManager::validate() {
      bool flagPass = false;
      bool flagFail = false;
      for (int i = 0; i < taskList.size(); i++) {
         for (int j = 0; j < taskList.size(); j++) {
            if (taskList[i].pass() == "")
               flagPass = true;
            if (taskList[i].pass() == taskList[j].name())
               flagPass = true;
            if (taskList[i].fail() != "") {
               if (taskList[i].fail() == taskList[j].name())
                  flagFail = true;
            }
         }
         if (taskList[i].fail() != "") {
            if (flagPass == false || flagFail == false) {
               cout << "Task: " << taskList[i].fail() << " - Fail" << endl;
               taskList.erase(taskList.begin() + i);
               flagPass = true; flagFail = true;   //Set the flags to true so there isn't two deletions
            }
         }
         if (flagPass == false) {
            cout << "Task: " << taskList[i].pass() << " - Pass" << endl;
            taskList.erase(taskList.begin() + i);
         }

         flagPass = false; flagFail = false;       //Reset the flags for the beginning of the loop
      }
   }



   