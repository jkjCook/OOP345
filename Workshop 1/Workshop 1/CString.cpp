//Justin Cook
#include <iostream>
#include <cstring>
#include "CString.h"

using namespace std;

namespace w1 {
   const int n = 3;
	CString::CString(char *x) {
      if (x == nullptr)
         m_str[0] = '\0';
      else 
         strncpy(m_str, x, n);
      m_str[MAX] = '\0';
	}
	void CString::display(std::ostream& ostr)const {
      ostr << m_str;
	}
	std::ostream& operator<< (std::ostream& ostr, CString str) {
      ostr << count << ": ";
      str.display(ostr);
      count++;
      return ostr;
	}

}