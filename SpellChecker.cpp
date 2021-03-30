#include "SpellChecker.h"

std::map<std::string, double> calculateWordsIndexes(const std::vector<std::string> &text,
                                                    std::map<std::string, int> diagramCount,
                                                    std::map<std::string, int> trigramCount) {
  std::map<std::string, double> wordIndexes;
  for (const auto &i : text) {
    double wordIdx = 0;
    std::vector<double> trigramsIndexes;
    for (int j = 0; j < i.size() - 2; j++) {
      std::string trigramWord = i.substr(j, 3);
      std::string left = trigramWord.substr(0, 2);
      std::string right = trigramWord.substr(1, 2);

      double leftCount = (diagramCount[left] - 1) != 0 ? log(diagramCount[left] - 1) : 10;
      double rightCount = (diagramCount[right] - 1) != 0 ? log(diagramCount[right] - 1) : 10;
      double trigramWordCount = (trigramCount[trigramWord] - 1) != 0 ? log(trigramCount[trigramWord] - 1) : 10;
      double c = ((leftCount + rightCount) / 2) - trigramWordCount;
      trigramsIndexes.push_back(c);
    }

    for (const auto &j : trigramsIndexes) {
      wordIdx += pow(j, 2);
    }
    wordIdx = sqrt(wordIdx / trigramsIndexes.size());
    wordIndexes[i] = wordIdx;
  }

  return wordIndexes;
}
std::vector<std::string> findUnusualWords(const std::map<std::string, double> &v, double N) {
  std::vector<std::string> unusualWords;
  for (const auto &i : v) {
    if (i.second > N) {
      unusualWords.push_back(i.first.substr(1, i.first.size() - 2));
    }
  }
  return unusualWords;
}

std::vector<std::string> SpellChecker::check(const std::vector<std::string> &text, double N) {
  this->ngrams.setDiagrams(text);
  this->ngrams.setTrigrams(text);
  this->wordIndexes = calculateWordsIndexes(text, this->ngrams.getDiagramCount(), this->ngrams.getTrigramCount());
  return findUnusualWords(wordIndexes, N);
}