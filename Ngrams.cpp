#include "Ngrams.h"

std::map<std::string, std::vector<std::string>> Ngrams::getDiagrams() {
  return this->diagrams;
}
std::map<std::string, std::vector<std::string>> Ngrams::getTrigrams() {
  return this->trigrams;
}
std::map<std::string, int> Ngrams::getDiagramCount() {
  return this->diagramCount;
}
std::map<std::string, int> Ngrams::getTrigramCount() {
  return this->trigramCount;
}
void Ngrams::setTrigrams(const std::vector<std::string> &text) {
  for (const auto &i : text) {
    for (int j = 0; j < i.size() - 2; j++) {
      std::string trigramWord = i.substr(j, 3);
      this->trigrams[i].push_back(trigramWord);
      this->trigramCount[trigramWord]++;
    }
  }
}
void Ngrams::setDiagrams(const std::vector<std::string> &text) {
  for (const auto &i : text) {
    for (int j = 0; j < i.size() - 1; j++) {
      std::string substring = i.substr(j, 2);
      this->diagrams[i].push_back(substring);
      this->diagramCount[substring]++;
    }
  }
}