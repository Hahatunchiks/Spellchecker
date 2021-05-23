#include "Client.h"
#include <algorithm>

void printNgrams(const std::map<std::string, std::set<std::string>> &words) {
  for (const auto &[word, ngrams] : words) {
    std::cout << word.substr(1, word.size() - 2) << ":\n";
    for (const auto &j : ngrams) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
}

void printUnusualWords(const std::vector<std::pair<double, std::string>> &words, const int &wordCount) {
  int counter = 0;
  for (const auto &i : words) {
    std::cout << i.second << " ";
    ++counter;
    if (counter == wordCount) {
      break;
    }
  }
  std::cout << '\n';
}

bool Client::execute(const std::string &line, SpellChecker &checker) {
  std::string value;
  if (line == "check") {
    std::vector<std::pair<double, std::string>> unusualWords = checker.check(m_N);
    printUnusualWords(unusualWords, m_wordCount);
  } else if (line == "help") {
    printCommandDescription();
  } else if (line == "exit") {
    return false;
  } else if (line == "print digrams") {
    printNgrams(checker.ngrams.getDigrams());
  } else if (line == "print trigrams") {
    printNgrams(checker.ngrams.getTrigrams());
  } else if (line == "set N") {
    std::cerr << "write N\n";
    std::getline(std::cin, value);
    try {
      m_N = std::stod(value);
      std::cerr << "your number: " << m_N << '\n';
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input: number expected\n";
    } catch (const std::out_of_range &e) {
      std::cerr << "Invalid input: overflow\n";
    }
  } else if (line == "set word count") {
    std::cerr << "write word count\n";
    std::getline(std::cin, value);
    try {
      m_wordCount = std::stoi(value);
      std::cerr << "your number: " << m_wordCount << '\n';
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input: integer expected\n";
    } catch (const std::out_of_range &e) {
      std::cerr << "Invalid input: overflow\n";
    }
  } else {
    std::cerr << "Unknown command\n";
  }
  return true;
}