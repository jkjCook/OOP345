//Justin Cook
#include "Text.h"

using namespace std;
namespace w3 {
   Text::Text() {
      m_str = nullptr;
      m_lines = 0;
   }
   Text::Text(const std::string filename){
      fstream file;
      int count = 0;
      string record;

      file.open(filename, ios::in); //To count the lines
      if (file.is_open()) {
         while (getline(file, record))
            count++;

         m_str = new string[count]; //Alloc

         file.clear();
         file.seekg(0, ios::beg);


         for (int i = 0; i < count; i++)
            getline(file, m_str[i]);

         m_lines = count;
      }
      file.close();
   }
   Text&& Text::operator=(Text&& rhs) { //Move assignment operator
      if (this != &rhs) {
         delete[] m_str;

         m_lines = rhs.m_lines;
         m_str = rhs.m_str;

         rhs.m_str = nullptr;
         rhs.m_lines = 0;

      }
      return move(*this);
   }
   Text& Text::operator=(const Text& lhs) { // Regular assignment operator
      if (this != &lhs) {
         delete[] this->m_str;
         m_lines = 0; m_str = nullptr;
            
         
         this->m_str = new string[lhs.size()];
         this->m_lines = lhs.m_lines;
         for (int i = 0; i < lhs.size(); i++) {
            this->m_str[i] = lhs.m_str[i];
         }
      }
      return *this;
   }
   Text::Text(const Text& lhs) : m_lines(0), m_str(nullptr) { //Deep copy constructor
      this->m_str = new string[lhs.size()];
      this->m_lines = lhs.m_lines;
      for (int i = 0; i < lhs.size(); i++)
         this->m_str[i] = lhs.m_str[i];
   }
   Text::Text(Text&& rhs) : m_lines(rhs.m_lines), m_str(rhs.m_str) { //Move copy constructor
      rhs.m_lines = 0;
      rhs.m_str = nullptr;
   }
   size_t Text::size() const {
      return m_lines;
   }
   Text::~Text() {
      delete[] m_str;
   }
}