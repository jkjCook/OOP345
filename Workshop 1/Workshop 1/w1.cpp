//Justin Cook
#include <iostream>
#include "process.h"
#include "CString.h"

using namespace std;


int main(int argc, char* argv[]) {
	int ret = 0;

   cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i];
	}
   cout << endl;

   if (argc == 1) {
      cout << "Insufficient number of arguments (min 1)" << endl;
      ret = 1;
   }
   else {
      cout << "Maximum number of characters stored : " << MAX << endl;
      for (int args = 1; args < argc-1; args++) {
         process(argv[args]);
      }
   }

	return ret;
}

