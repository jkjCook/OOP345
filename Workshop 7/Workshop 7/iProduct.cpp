#include "iProduct.h"

using namespace std;

namespace w7 {

   std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
      prod.display(os);
      return os;
   }
   iProduct* readProduct(std::ifstream& file) {
      iProduct* prod;
      if (file.is_open()) {
         string line;
         getline(file, line);
         if (line.find('H') != string::npos) {
            prod = new TaxableProduct(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), line.find(' '))), 'H');
         }
         else if (line.find('P') != string::npos) {
            prod = new TaxableProduct(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), line.find(' '))), 'P');
         }
         else {
            prod = new Product(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), 256)));
         }

      }
      return prod;
   }

   TaxableProduct::TaxableProduct(int num, double price, char status){
      this->status(status);
      this->price(price);
      this->prodNum(num);
   }
   Product::Product(int num, double price) {
      this->prodNum(num);
      this->price(price);
   }

   double Product::getCharge()const {
      return m_price;
   }
   void Product::display(std::ostream& os)const {
      os << setw(10) << m_prodNum << " " << fixed << setw(10) << setprecision(2) << m_price;
   }
   int Product::getProdNum() {
      return m_prodNum;
   }
   void Product::prodNum(int num) {
      m_prodNum = num;
   }
   void Product::price(double price) {
      m_price = price;
   }

   double TaxableProduct::getCharge() {
      double total = 0;
      if (this->getStatus() == 'H')
         total =  Product::getCharge() * 1.13;
      if (this->getStatus() == 'P')
         total = Product::getCharge() * 1.08;

      return total;
   }
   void TaxableProduct::display(std::ostream& os)const {
      this->Product::display(os);
      os << " " << (m_status == 'H' ? "HST" : "PST");
   }
   char TaxableProduct::getStatus() {
      return m_status;
   }
   void TaxableProduct::status(char c) {
      m_status = c;
   }

}
