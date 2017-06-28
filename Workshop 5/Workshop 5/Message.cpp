//Justin Cook
#include "Message.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace w5 {
   Message::Message(std::ifstream& in, char c) {
      string temp;
      int rstart = 0, rend = 0, uend = 0, mstart = 0, mend = 0;   //Start and end point variables
      getline(in, temp, c);                                       //Get full line
      if (temp != "") {                                           //Loop to find the end of username
         mend = temp.length(); 
         for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == ' ') {
               uend = i;
               i = temp.length();
            }
         }
         rstart = temp.find('@') + 1;                             //Finding the start of the reply
         if (rstart > 0) {
            for (int i = rstart; i < temp.length(); i++) {        //Loop to find end of reply
               if (temp[i] == ' ') {
                  rend = i;
                  i = temp.length();
               }
            }
            rend = rend - rstart;
            m_reply = temp.substr(rstart, rend);                              //Substring for reply
         }
         else { m_reply = ""; }

         (rend == 0) ? mstart = (uend + 1) : mstart = ((rend + rstart) + 1);  //Start of message is 1 space more than reply end
         m_user = temp.substr(0, uend);                                       //Substring for username
         m_message = temp.substr(mstart, mend);                               //Substring for message
      }

   }

   void Message::display(std::ostream& os) const {
      os << "Message" << endl
         << "User  : " << m_user << endl;
      if (m_reply != "")
         os << "Reply : " << m_reply << endl;
      os << "Tweet : " << m_message << endl;
      os << endl;
   }
}