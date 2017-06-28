//Justin Cook
#include <iostream>
#include "Station.h"

using namespace std;

Station::Station() {
   m_stationName = "";
   m_noSPass = 0;
   m_noAPass = 0;
}
void Station::set(const std::string& name, unsigned sPass, unsigned aPass) {
   m_stationName = name;
   m_noAPass = aPass;
   m_noSPass = sPass;
}
void Station::update(PassType x, int exp) {
   (x == 0) ? m_noSPass += exp : m_noAPass += exp;
}
unsigned Station::inStock(PassType x) const {
   return (x == 0) ? m_noSPass : m_noAPass;
}
const std::string& Station::getName() const {
   return m_stationName;
}
