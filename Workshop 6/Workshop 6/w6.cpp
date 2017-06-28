//Justin Cook
// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
   if (argc != 2) {
      std::cerr << argv[0] <<
         ": incorrect number of arguments\n";
      std::cerr << "Usage: " << argv[0] << " file_name\n";
      return 1;
   }


   Grades grades(argv[1]);
   // define the lambda expression for letter
   
   std::function<std::string(float)>letter = [](float grade) { //Needed to do it like this to avoid using template
      std::string letterGrade;
      if (grade < 50)
         letterGrade = "F";
      else if (grade < 55)
         letterGrade = "D";
      else if (grade < 60)
         letterGrade = "D+";
      else if (grade < 65)
         letterGrade = "C";
      else if (grade < 70)
         letterGrade = "C+";
      else if (grade < 75)
         letterGrade = "B";
      else if (grade < 80)
         letterGrade = "B+";
      else if (grade < 90)
         letterGrade = "A";
      else if (grade <= 100)
         letterGrade = "A+";

      return letterGrade;
   };

   grades.displayGrades(std::cout, letter);

   std::cout << "Press any key to continue ... ";
   std::cin.get();
}