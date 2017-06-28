#ifndef CSTRING_H
#define CSTRING_H
#include <iostream>
#define MAX 3

namespace w1 {
   static int count = 0;
	class CString {
      char m_str[MAX + 1];
	public:
		CString(char *x);
		void display(std::ostream& ostr)const;

	};
	std::ostream& operator<<(std::ostream& ostr, CString str);
}
#endif