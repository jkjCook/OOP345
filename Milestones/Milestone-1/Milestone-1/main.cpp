//Justin Cook
//Milestone 1 CSV Reader

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector <vector<string>> csvLoad(char* filename, const char delim);

int main(int argc, char** argv) {
   if (argc != 3) {
      std::cerr << "*** invalid number of arguments ***\n"
         << "Usage: " << argv[0] << " tasks_file delimiter\n";
      exit(1);
   }
   std::cout << "Command Line Arguments\n----------------------\n";
   std::cout << "Tasks File Specified          = " << argv[1] << "\n";
   std::cout << "File Record Field Delimiter   = " << argv[2][0] << "\n\n";

   cout << "Outputting" << endl;
   cout << "-------------------------------" << endl;
   cout << "Ranged based for loop:" << endl;

   vector <vector<string>> csvData(csvLoad(argv[1], argv[2][0]));

   int index = 0;
   for (auto row : csvData) {
      index++;
      cout << index << ": ";     //Keeping track of line number before printing fields
      for (auto col : row)
         cout << "<" << col << ">"; //Adding delimeters in between since fields have no padded spaces
      cout << endl;
   }
   index = 0;
   cout << endl;

   cout << "Iterator:" << endl;
   vector < vector<string>>::iterator row;
   vector<string>::iterator col;

   for (row = csvData.begin(); row != csvData.end(); row++) {
      index++;
      cout << index << ": ";      //Keeping track of line number before printing fields
      for (col = row->begin(); col != row->end(); col++) {
         cout << "<" << *col << ">"; //Adding delimeters in between since fields have no padded spaces
      }
      cout << endl;
   }

   
   index = 0;
   cout << endl;
   cout << "Regular For Loop:" << endl;
   for (int i = 0; i < csvData.size(); i++) {
      index++;
      cout << index << ": ";
      for (int j = 0; j < csvData[i].size(); j++) {
         cout << "<" << csvData[i][j] << ">"; //Adding delimeters in between since fields have no padded spaces
      }
      cout << endl;
   }

   cin.get();
}



vector <vector<string>> csvLoad(char* filename, const char delim) {
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

            //Right trimming field
            field[i].erase(field[i].find_last_not_of(" \n\r\t") + 1);
            //Left trimming field
            for (int j = 0; j < field[i].length(); j++) {
               if (field[i][j] != ' ') {
                  field[i] = field[i].substr(j, (field[i].length() - j));
                  j = field[i].length();
               }
            }

 
           //To keep track of the correct substring index
            start = stop + 1;
            stop = holder;

            if (line.find(delim) == string::npos) {
               if (field[i] == "Approve" || field[i] == "Repair") {}
               else
                  proper = false;   //Not propper if there is no delimeters and it's not either Approve or Repair
               
            }
         }

         for (int i = 0; i < fields; i++) {
            if (isdigit(field[i][0])) {
               proper = false;
            }
            if (i == 0) i++;
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