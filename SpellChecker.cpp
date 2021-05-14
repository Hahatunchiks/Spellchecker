#include "SpellChecker.h"

void SpellChecker::calculateWordsIndexes(const std::map<std::string, std::set<std::string>> &trigrams,
                                         std::map<std::string, int> &diagramCount,
                                         std::map<std::string, int> &trigramCount) {
  for (const auto &[word, trigram] : trigrams) {
    double wordIdx = 0;
    std::vector<double> trigramsIndexes;
    for (const auto &j : trigram) {
      std::string left = j.substr(0, 2);
      std::string right = j.substr(1, 2);
      double leftCount = (diagramCount[left] - 1) != 0 ? log(diagramCount[left] - 1) : 10;
      double rightCount = (diagramCount[right] - 1) != 0 ? log(diagramCount[right] - 1) : 10;
      double trigramWordCount = (trigramCount[j] - 1) != 0 ? log(trigramCount[j] - 1) : 10;
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
  std::sort(unusualWords.begin(), unusualWords.end(), [](std::pair<double, std::string> &l, std::pair<double, std::string> &r) {
              return l.first > r.first;
            });
  return unusualWords;
}