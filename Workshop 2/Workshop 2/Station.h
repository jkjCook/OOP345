//Justin Cook
#pragma once
#include <string>
#include <string.h>

enum PassType {STUD=0, ADLT};

class Station {
   std::string m_stationName;
   unsigned int m_noSPass;
   unsigned int m_noAPass;

public:
   Station();
   void set(const std::string&, unsigned, unsigned);
   void update(PassType, int);
   unsigned inStock(PassType) const;
   const std::string& getName() const;

};
