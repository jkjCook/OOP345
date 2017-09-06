#include "Sale.h"

using namespace std;

namespace w7 {

   Sale::Sale(char * filename) {
      ifstream file;
      file.open(filename, ios::in);
      while (!file.eof()) {
         m_products.push_back(std::move(readProduct(file)));
      }
      file.close();
   }
   void Sale::display(std::ostream& os) const {

      double sum = 0.0;

      os << setw(10) << "Product No" << setw(10) << "Cost" << " Taxable" << endl;

      for (auto prod : m_products)
      {
         prod->display(os);
         sum += prod->getCharge();
         cout << endl;
      }
      
      cout << setw(10) << "Total" << fixed << setprecision(2) << setw(10) << sum << endl;
   }

}