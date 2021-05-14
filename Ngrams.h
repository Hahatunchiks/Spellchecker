
#ifndef SPELLCHECKER__NGRAMS_H_
#define SPELLCHECKER__NGRAMS_H_
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>

class Ngrams {
 public:
  void setNgrams(const std::string &filename);
  const std::map<std::string, std::set<std::string>> &getDiagrams();
  const std::map<std::string, std::set<std::string>> &getTrigrams();
  std::map<std::string, int> &getDiagramCount();
  std::map<std::string, int> &getTrigramCount();
 private:
  std::map<std::string, std::set<std::string>> m_diagrams;
  std::map<std::string, std::set<std::string>> m_trigrams;
  std::map<std::string, int> m_diagramCount;
  std::map<std::string, int> m_trigramCount;
};

#endif //SPELLCHECKER__NGRAMS_H_
