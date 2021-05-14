#ifndef SPELLCHECKER__SPELLCHECKER_H_
#define SPELLCHECKER__SPELLCHECKER_H_
#include <cmath>
#include <algorithm>
#include "Ngrams.h"
class SpellChecker {
 public:
  std::vector<std::pair<double, std::string>> check(const double &N);
  void calculateWordsIndexes(const std::map<std::string, std::set<std::string>> &trigrams,
                             std::map<std::string, int> &diagramCount,
                             std::map<std::string, int> &trigramCount);
  Ngrams ngrams;
 private:
  std::map<std::string, double> m_wordIndexes;
};

#endif
