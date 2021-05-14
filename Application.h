
#ifndef SPELLCHECKER__APPLICATION_H_
#define SPELLCHECKER__APPLICATION_H_

#include "Client.h"
class Application {
 public:
  void start(const std::string &filename);
 private:
  Client *m_command;
};

#endif //SPELLCHECKER__APPLICATION_H_