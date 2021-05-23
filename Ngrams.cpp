#include <iostream>
#include "Ngrams.h"
#include <fstream>

const std::map<std::string, std::set<std::string>> &Ngrams::getDigrams() {
  return m_digrams;
}
const std::map<std::string, std::set<std::string>> &Ngrams::getTrigrams() {
  return m_trigrams;
}
const std::map<std::string, int> &Ngrams::getDigramCount() {
  return m_digramCount;
}
const std::map<std::string, int> &Ngrams::getTrigramCount() {
  return m_trigramCount;
}

void saveNgrams(std::string &word,
                std::map<std::string, int> &digramCount,
                std::map<std::string, int> &trigramCount,
                std::map<std::string, std::set<std::string>> &digram,
                std::map<std::string, std::set<std::string>> &trigram) {
  word += '.';
  for (int i = 0; i < word.size() - 2; i++) {
    std::string substring = word.substr(i, 3);
    trigram[word].insert(substring);
    trigramCount[substring]++;
  }
  for (int i = 0; i < word.size() - 1; i++) {
    std::string substring = word.substr(i, 2);
    digram[word].insert(substring);
    digramCount[substring]++;
  }
  word = ".";
}

void Ngrams::setNgrams(const std::string &filename) {
  std::string s;
  char symbol;
  std::string word = ".";
  std::ifstream input(filename);
  if (!input.is_open()) {
    throw std::runtime_error("Wrong filename");
  }
  while (input.get(symbol)) {
    if (!isspace(symbol)) {
      if (isalpha(symbol)) {
        word += tolower(symbol);
      }
    } else if (word != ".") {
      saveNgrams(word, m_digramCount, m_trigramCount, m_digrams, m_trigrams);
    }
  }
  if (word != ".") {
    saveNgrams(word, m_digramCount, m_trigramCount, m_digrams, m_trigrams);
  }
}