
#ifndef SPELLCHECKER__NGRAMS_H_
#define SPELLCHECKER__NGRAMS_H_
#include <map>
#include <vector>
#include <string>

class Ngrams {
 public:
  void setDiagrams(const std::vector<std::string> &text);
  void setTrigrams(const std::vector<std::string> &text);
  std::map<std::string, std::vector<std::string>> getDiagrams();
  std::map<std::string, std::vector<std::string>> getTrigrams();
  std::map<std::string, int> getDiagramCount();
  std::map<std::string, int> getTrigramCount();
 private:
  std::map<std::string, std::vector<std::string>> diagrams;
  std::map<std::string, std::vector<std::string>> trigrams;
  std::map<std::string, int> diagramCount;
  std::map<std::string, int> trigramCount;
};

#endif //SPELLCHECKER__NGRAMS_H_
