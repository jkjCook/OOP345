#include "i.h"
#include "t.h"
#include "o.h"
#include "util.h"

using namespace std;

int main(int argc, char** argv) {

   char* task = argv[1];
   char* order = argv[2];
   char* item = argv[3];
   char delim = argv[4][0];
   vector<vector<string>> csvData;

   csvData = csvRead(task, delim);
   TaskManager T(csvData);
   T.validate();
   T.taskManagerPrint();
   T.taskManagerGraph(task);
   
   csvData = csvRead(item, delim);
   ItemManager I(csvData);
   I.validate(T);
   I.itemManagerPrint();
   I.itemManagerGraph(item);
   
   csvData = csvRead(order, delim);
   OrderManager O(csvData);
   O.validate(I);
   O.orderManagerPrint();
   O.orderManagerGraph(order);
  
#ifdef __unix
   string dot = "dot"
#else 
   string dot = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe";
#endif

   string file(task);
   string cmd = dot + " -Tpng " + file + ".gv > " + file + ".gv.png";
   cout << "Running command --->'" << cmd << "'\n";
   cout << "The operating system says dot returned '"
      << system(cmd.c_str())
      << "' (0 is good --> dot executed successfully)\n";

   file = order;
   cmd = dot + " -Tpng " + file + ".gv > " + file + ".gv.png";
   cout << "Running command --->'" << cmd << "'\n";
   cout << "The operating system says dot returned '"
      << system(cmd.c_str())
      << "' (0 is good --> dot executed successfully)\n";

   file = item;
   cmd = dot + " -Tpng " + file + ".gv > " + file + ".gv.png";
   cout << "Running command --->'" << cmd << "'\n";
   cout << "The operating system says dot returned '"
      << system(cmd.c_str())
      << "' (0 is good --> dot executed successfully)\n";

   cin.get();
}