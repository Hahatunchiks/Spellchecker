#ifndef SPELLCHECKER__CLIENT_H_
#define SPELLCHECKER__CLIENT_H_
#include <iostream>
#include "Text.h"
#include "SpellChecker.h"
#include "HelpCommand.h"
class Client {
 public:
  bool execute(const std::string &line, std::string &filename);
 private:
  Text text = {};
  int wordCount = 10'000;
  double N = 0;
};

#endif
