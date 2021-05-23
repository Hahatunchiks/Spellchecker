#include "SpellChecker.h"
#include <cmath>
#include <algorithm>

void SpellChecker::calculateWordsIndexes(const std::map<std::string, std::set<std::string>> &trigrams,
                                         const std::map<std::string, int> &diagramCount,
                                         const std::map<std::string, int> &trigramCount) {
  for (const auto &[word, trigram] : trigrams) {
    double wordIdx = 0;
    std::vector<double> trigramsIndexes;
    for (const auto &j : trigram) {
      std::string left = j.substr(0, 2);
      std::string right = j.substr(1, 2);
      int x = diagramCount.find(left)->second;
      double leftCount = (x - 1) == 0 ? -10 : log(x - 1);
      int y = diagramCount.find(right)->second;
      double rightCount = (y - 1) == 0 ? -10 : log(y - 1);
      int z = trigramCount.find(j)->second;
      double trigramWordCount = (z - 1) == 0 ? -10 : log(z - 1);
      double c = ((leftCount + rightCount) / 2) - trigramWordCount;
      trigramsIndexes.push_back(c);
      for (const auto &k : trigramsIndexes) {
        wordIdx += pow(k, 2);
      }
      wordIdx = sqrt(wordIdx / (double) trigramsIndexes.size());
      m_wordIndexes[word] = wordIdx;
    }
  }
}

std::vector<std::pair<double, std::string>> SpellChecker::check(const double &N) {
  std::vector<std::pair<double, std::string>> unusualWords;
  for (const auto &[word, val] : m_wordIndexes) {
    if (val >= N) {
      unusualWords.emplace_back(val, word.substr(1, word.size() - 2));
    }
  }
  std::sort(unusualWords.rbegin(), unusualWords.rend());
  return unusualWords;
}