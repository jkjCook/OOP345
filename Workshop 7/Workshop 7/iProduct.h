#pragma once
// Workshop 7 - STL Containers
// iProduct.h
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

namespace w7 {

   class iProduct {
   public:
      virtual double getCharge() const = 0;
      virtual void display(std::ostream&) const = 0;
   };

   std::ostream& operator<<(std::ostream&, const iProduct&);
   iProduct* readProduct(std::ifstream&);


   class Product : public iProduct {
      int m_prodNum;
      double m_price;

   public:
      Product() { m_prodNum = 0; m_price = 0; }; //default
      Product(int, double);
      void prodNum(int);
      void price(double);
      int getProdNum();
      double getCharge()const;
      void display(std::ostream&)const;

   };

   class TaxableProduct : public Product {
      char m_status;

   public:
      TaxableProduct( int, double, char);
      char getStatus();
      void status(char);
      double getCharge();
      void display(std::ostream&)const;

   };

}

