
#ifndef SPELLCHECKER__APPLICATION_H_
#define SPELLCHECKER__APPLICATION_H_
#include "Text.h"
#include "Client.h"
class Application {
 public:
  void start(std::string filename);
 private:
  Client command = {};
};

#endif //SPELLCHECKER__APPLICATION_H_
