//Justin Cook
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace w3 {
   class Text {
      std::string* m_str;
      size_t m_lines;
   public:
      Text();
      Text(const std::string);
      Text(const Text&); //Copy constructor
      Text(Text&&); //Move Constructor
      ~Text();
      Text& operator=(const Text&); //Copy assignment operator
      Text&& operator=(Text&&); //Move assignment operator
      /*void display() {
         for (int i = 0; i < 20; i++)
            cout << m_str[i] << endl;
      }*/

      size_t size() const;


   };
}