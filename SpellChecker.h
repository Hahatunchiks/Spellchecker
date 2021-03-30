#ifndef SPELLCHECKER__SPELLCHECKER_H_
#define SPELLCHECKER__SPELLCHECKER_H_
#include <vector>
#include <string>
#include <cmath>
#include "Ngrams.h"
class SpellChecker {
 public:
  std::vector<std::string> check(const std::vector<std::string> &text, double N);
 private:
  std::map<std::string, double> wordIndexes;
  Ngrams ngrams = {};
};

#endif
