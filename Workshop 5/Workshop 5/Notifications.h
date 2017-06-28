//Justin Cook
#pragma once
#include "Message.h"
#define MAX_SIZE 10
namespace w5 {

   class Notifications {
      Message* m_messages;
      size_t m_size;
      
   public:
      Notifications() { m_size = 0; m_messages = nullptr; };
      Notifications(const Notifications&);   
      Notifications& operator=(const Notifications&);
      Notifications(Notifications&&); //move constructor
      Notifications&& operator=(Notifications&&); //move assignment operator
      ~Notifications(); //- destructor
      void operator+=(const Message& msg); // adds msg to the set
      void display(std::ostream& os) const; //inserts the Message objects to the os output stream
   };

}