//Justin Cook
#pragma once
#include "Station.h"

namespace w2 {
   class Stations {
      Station* m_stations;
      char *m_filename;
      unsigned m_noOfStations; 
      char m_delim;

   public:
      Stations(char*);
      ~Stations();
      void update() const;
      void restock() const;
      void report() const;

   };
}