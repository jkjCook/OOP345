//Justin Cook
#include <iostream>
#include <fstream>
#include "Grades.h"

using namespace std;

Grades::Grades(const char* filename) {
   fstream file;
   string temp;
   int count = 0;
   file.open(filename, ios::in);
   if (file.is_open()) {
      do {
         getline(file, temp, '\n');
         int delim = temp.find(' ');
         m_studentNumbers.push_back(temp.substr(0, delim));
         m_grades.push_back(stof(temp.substr(delim, temp.length())));
      } while (!file.eof());
      file.close();
   }

   else throw("File was not opened!");
}
void Grades::displayGrades(std::ostream& os, std::function<std::string(float)>& letter) const {
   for (int i = 0; i < m_grades.size(); i++)
      os << m_studentNumbers[i] << " " << m_grades[i] << " " << letter(m_grades[i]) << endl;
}