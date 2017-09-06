//Justin Cook
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>

namespace w8 {
   template<class T>
   class DataTable {
      std::vector<T> x;
      std::vector<T> y;
      int w;
      int d;

   public:
      DataTable(std::ifstream& file, int width, int dec) {
         w = width;
         d = dec;
         if (file.is_open()) {
            while (!file.eof()) {

               std::string line;
               std::stringstream s;
               std::getline(file, line);
               s.str(line);
               T localx;
               T localy;
               s >> localx >> localy;

               x.push_back(localx);
               y.push_back(localy);

            }
         }
         else
            throw std::string("File could not be opened for table creation!");
      }

      T mean() const {
         T total = std::accumulate(y.begin(), y.end(), 0.0);
         total /= y.size();
         
         return total;
      }

      T sigma() const{
         T m = mean();
         T dev = 0.0;
         T s = 0;

         for (int i = 0; i < y.size(); ++i)
            dev += (y[i] - m) * (y[i] - m);

         s = std::sqrt(dev / y.size());

         return s;
      }

      T median() const{
         std::vector<T> c = y;

         std::sort(c.begin(), c.end());
         
         T med = c[c.size() / 2];

         return med;
      }

      void regression(T& slope, T& y_intercept) const{

         T ax = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
         T ay = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
         T num = 0.0, dnom = 0.0;

         for (int i = 0; i < x.size(); ++i){
            num += ((x[i] - ax) * (y[i] - ay));
            dnom += ((x[i] - ax) * (x[i] - ay));
         }
         slope = num / dnom;
         y_intercept = ay - (slope * ax);
      }

      void display(std::ostream& os) const{
         os << std::setw(w) << "x" << std::setw(w) << "y" << std::endl;

         for (int i = 0; i < x.size(); i++){
            os << std::setw(w) << std::fixed << std::setprecision(d) << x[i] << std::setw(w) <<std::fixed
               << std::setprecision(d) << y[i] << std::endl;
         }
      }
   };

   template<class T>
   std::ostream& operator<<(std::ostream& os, DataTable<T>& data){
      data.display(os);
      return os;
   }
}


