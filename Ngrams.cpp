#include <iostream>
#include "Ngrams.h"

const std::map<std::string, std::set<std::string>> &Ngrams::getDiagrams() {
  return m_diagrams;
}
const std::map<std::string, std::set<std::string>> &Ngrams::getTrigrams() {
  return m_trigrams;
}
std::map<std::string, int> &Ngrams::getDiagramCount() {
  return m_diagramCount;
}
std::map<std::string, int> &Ngrams::getTrigramCount() {
  return m_trigramCount;
}
void Ngrams::setNgrams(const std::string &filename) {
  std::string s;
  char symbol;
  std::string word = ".";
  std::ifstream input(filename);
  if (!input.is_open()) {
    std::cerr << "Wrong filename\n";
    std::exit(-1);
  }
  while (input.get(symbol)) {
    if (!isspace(symbol)) {
      if (isalpha(symbol)) {
        word += tolower(symbol);
      }
    } else if (word != ".") {
      word += '.';
      for (int i = 0; i < word.size() - 2; i++) {
        std::string substring = word.substr(i, 3);
        m_trigrams[word].insert(substring);
        m_trigramCount[substring]++;
      }
      for (int i = 0; i < word.size() - 1; i++) {
        std::string substring = word.substr(i, 2);
        m_diagrams[word].insert(substring);
        m_diagramCount[substring]++;
      }
      word = ".";
    }
  }
  if (word != ".") {
    word += '.';
    for (int i = 0; i < word.size() - 2; i++) {
      std::string substring = word.substr(i, 3);
      m_trigrams[word].insert(substring);
      m_trigramCount[substring]++;
    }
    for (int i = 0; i < word.size() - 1; i++) {
      std::string substring = word.substr(i, 2);
      m_diagrams[word].insert(substring);
      m_diagramCount[substring]++;
    }
  }
}