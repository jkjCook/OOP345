#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "iProduct.h"


namespace w7 {
   class Sale {
      std::vector<iProduct*> m_products;

   public:
      Sale(char * filename);
      void display(std::ostream& os) const;
   };

}
