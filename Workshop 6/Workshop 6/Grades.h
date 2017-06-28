#pragma once
#include <functional>
#include <vector>
#include <string>
class Grades {
   std::vector<std::string> m_studentNumbers;
   std::vector<float> m_grades;
   
public:
   //Prohibited functions
   Grades(const Grades&) = delete;
   Grades(Grades&&) = delete;
   Grades& operator=(const Grades&) = delete;
   Grades& operator=(Grades&&) = delete;

   Grades(const char*);
   void displayGrades(std::ostream&, std::function<std::string(float)>& letter) const;

};
