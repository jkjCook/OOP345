#include "util.h"

using namespace std;

string trimString(string trim) {
   //Right trimming field
   trim.erase(trim.find_last_not_of(" \n\r\t") + 1);
   //Left trimming field
   for (int i = 0; i < trim.length(); i++) {
      if (trim[i] != ' ') {
         trim = trim.substr(i, (trim.length() - i));
         i = trim.length();
      }
   }
   return trim;
}

vector<vector<string>> csvRead(char* filename, const char delim) {
   fstream file;        //The file
   string line;         //The line pulled from the file
   int lines = 0;       //Used for the length of the vector

   vector<vector<string>>csvData;

   file.open(filename, ios::in);
   if (file.is_open()) {
      while (!file.eof()) {
         getline(file, line);
         bool proper = true;                     //If the string is a good string or not
         int fields = 0, start = 0, stop = 0;    //Used for number of fields, lines and manipulating substr

                                                 //Seperate fields into individual strings
         fields = std::count(line.begin(), line.end(), delim) + 1;

         vector<string> field;                   //The seperate fields in a line

         for (int i = 0; i < fields; i++) {

            stop = line.find(delim, start);      //Shows where to stop in the line at the delim

            int holder = stop - start;           //Sets the amount to go forward the difference between start and stop

            if (fields == 1)
               field.push_back(line.substr(0, 256));        //If it's just one field there's no delimeter
            else
               field.push_back(line.substr(start, holder)); //If it's not then you want to


                                                            //To keep track of the correct substring index
            start = stop + 1;
            stop = holder;

            field[i] = trimString(field[i]);

         }


         if (proper == true) {
            vector<string> col;
            csvData.push_back(col);
            for (int i = 0; i < fields; i++) {
               csvData[lines].push_back(field[i]);
            }
            lines++;
         }

      }
   }
   else {
      cout << "Unable to open file" << endl;
   }
   file.close();
   return csvData;
}

bool taskNameValid(string& task) {
   bool proper = true;
   for (int i = 0; i < task.length(); i++) {
      if (isdigit(task[i]) && task[i] != ' ') {
         proper = false;
      }
      else
         proper = true;
      if (i == 0) i++;
   }
   return proper;
}

bool taskSlotsValid(std::string& slot) {
   bool proper = true;

   for (int i = 0; i < slot.length(); i++) {
      if (!isdigit(slot[i]))
         proper = false;
   }

   return proper;
}

bool custNameValid(std::string& name) {
   bool proper = true;
   for (int i = 0; i < name.length(); i++) {
      if (isdigit(name[i]) && name[i] != ' ') {
         proper = false;
      }
      else
         proper = true;
   }
   return proper;
}
bool prodNameValid(std::string& name) {
   bool proper = true;
   for (int i = 0; i < name.length(); i++) {
      if (name[i] == ' ') {
         proper = false;
      }
      else
         proper = true;
   }
   return proper;
}