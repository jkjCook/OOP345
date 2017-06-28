//Justin Cook
#include "Notifications.h"
#include "Message.h"
#include <iostream>
using namespace std;

namespace w5 {
   Notifications::Notifications(const Notifications& cpy) {
      m_messages = new Message[cpy.m_size];
      for (int i = 0; i < cpy.m_size; i++) {
         m_messages[i] = cpy.m_messages[i];
         m_size++;
      }
   }
   Notifications& Notifications::operator=(const Notifications& cpy) {
      m_messages = new Message[cpy.m_size];
      if (this != &cpy) {
         for (int i = 0; i < cpy.m_size; i++) {
            m_messages[i] = cpy.m_messages[i];
            m_size++;
         }
      }
      return *this;
   }
   Notifications::Notifications(Notifications&& cpy) : m_messages(cpy.m_messages), m_size(cpy.m_size){
      cpy.m_messages = nullptr;
      cpy.m_size = 0;
   }
   Notifications&& Notifications::operator=(Notifications&& cpy) {
      if (this != &cpy) {
         m_messages = cpy.m_messages;
         m_size = cpy.m_size;

         cpy.m_messages = nullptr;
         cpy.m_size = 0;
      }
      return move(*this);

   }
   Notifications::~Notifications() {
      delete[] m_messages;

   }
   void Notifications::operator+=(const Message& msg) {
      if (m_size < MAX_SIZE) {
         Notifications holder;

         holder.m_messages = new Message[m_size];
         for (int i = 0; i < m_size; i++) {
            holder.m_messages[i] = m_messages[i];
         }
         holder.m_size = m_size;
         holder.m_size++;

         if (m_size == 0) {
            m_messages = new Message[holder.m_size];
            m_size = holder.m_size;
            m_messages[m_size - 1] = msg;
         }
         else {
            m_messages = new Message[holder.m_size];
            m_size = holder.m_size;
            for (int i = 0; i < m_size - 1; i++) {
               m_messages[i] = holder.m_messages[i];
            }
            m_messages[m_size - 1] = msg;
         }
        
      }
   }
   void Notifications::display(std::ostream& os) const {
      for (int i = 0; i < m_size; i++)
         m_messages[i].display(os);
   }
}