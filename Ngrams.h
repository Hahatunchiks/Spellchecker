#ifndef SPELLCHECKER__NGRAMS_H_
#define SPELLCHECKER__NGRAMS_H_
#include <map>
#include <string>
#include <set>

class Ngrams {
 public:
  void setNgrams(const std::string &filename);
  const std::map<std::string, std::set<std::string>> &getDigrams();
  const std::map<std::string, std::set<std::string>> &getTrigrams();
  const std::map<std::string, int> &getDigramCount();
  const std::map<std::string, int> &getTrigramCount();
 private:
  std::map<std::string, std::set<std::string>> m_digrams;
  std::map<std::string, std::set<std::string>> m_trigrams;
  std::map<std::string, int> m_digramCount;
  std::map<std::string, int> m_trigramCount;
};

#endif //SPELLCHECKER__NGRAMS_H_