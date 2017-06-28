//Justin Cook
#pragma once
#include <string>
namespace w5 {
   class Message {
      std::string m_message;
      std::string m_reply;
      std::string m_user;

   public:
      Message() : m_message(""), m_reply(""), m_user("") {};
      Message(std::ifstream& in, char c);
      bool empty() const { return m_user == ""; }
      void display(std::ostream&) const;
   };
}
