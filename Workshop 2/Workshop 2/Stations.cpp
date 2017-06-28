//Justin Cook
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "Stations.h"

using namespace std;

namespace w2 {
   Stations::Stations(char* filename) {
      m_filename = filename;

      fstream file;
    
      file.open(filename, ios::in);

      if (file.is_open()) {
         string saveLine;
         int index = 0;
 
         getline(file, saveLine);

        do { //Reads until it finds a digit and uses that as the number of stations, discards anything but a digit
            m_noOfStations = saveLine[index] - '0';
            index++;
        } while (index < saveLine.size() && !isdigit(saveLine[index - 1]));
         
         m_delim = saveLine[index]; //Making the delimeter so it works with any delimeter that could be in the file
 
         m_stations = new Station[m_noOfStations];

         string tempName = "", tempSPass = "" , tempAPass = "";   //Temporary variables
         unsigned int SPass = 0, APass = 0;

         for (int i = 0; i < m_noOfStations; i++) {

            getline(file, tempName, m_delim);       //Reads into individual strings using delimeters
            getline(file, tempSPass, ' ');
            getline(file, tempAPass);
            
            SPass = atoi(tempSPass.c_str());    //Changing the string into int
            APass = atoi(tempAPass.c_str());

            m_stations[i].set(tempName, SPass, APass);
         }

         //cout << m_stations[2].inStock(STUD) << " " << m_stations[2].inStock(ADLT) << " " << m_stations[2].getName() << endl; 
         //Reading properly
      }
      file.close();
   }
   Stations::~Stations() {
      fstream file;
      file.open(m_filename, ios::out | ios::trunc);
      if (file.is_open()) {
         file << m_noOfStations << m_delim << "\n";
         for (int i = 0; i < m_noOfStations; i++)
            file << m_stations[i].getName() << m_delim << m_stations[i].inStock(STUD) << " " << m_stations[i].inStock(ADLT) << "\n";
      }
      file.close();
      delete[] m_stations;
   }
   void Stations::update() const {
      int input = 0;
      cout << "Passes Sold :" << endl << "-------------" << endl;
      for (int i = 0; i < m_noOfStations; i++) {
         cout << m_stations[i].getName() << endl;
         cout << " Student Passes sold : ";
         cin >> input;
         input -= (input * 2);
         m_stations[i].update(STUD , input);
         cout << " Adult   Passes sold : ";
         cin >> input;
         input -= (input * 2);
         m_stations[i].update(ADLT, input);
         
         //cout << m_stations[i].inStock(STUD) << " " << m_stations[i].inStock(ADLT) << endl;
         //Subtracting properly
      }
      cout << endl;
   }
   void Stations::restock() const {
      int input = 0;
      cout << "Passes Added :" << endl << "-------------" << endl;
      for (int i = 0; i < m_noOfStations; i++) {
         cout << m_stations[i].getName() << endl;
         cout << " Student Passes added : ";
         cin >> input;
         m_stations[i].update(STUD, input);
         cout << " Adult   Passes added : ";
         cin >> input;
         m_stations[i].update(ADLT, input);
      }
      cout << endl;
   }
   void Stations::report() const {
      cout << "Passes in Stock : Student Adult" << endl;
      cout << "-------------------------------" << endl;
      for (int i = 0; i < m_noOfStations; i++) {
         cout << setw(17) << left << m_stations[i].getName() << setw(8) << right << m_stations[i].inStock(STUD)
            << setw(6) << right << m_stations[i].inStock(ADLT) << endl;
      }
   }
   

}
