#include "Client.h"
void printNgrams(const std::map<std::string, std::vector<std::string>> &words) {
  for (const auto &i : words) {
    std::cout << i.first.substr(1, i.first.size() - 2) << ":\n";
    for (const auto &j : i.second) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
}

void printUnusualWords(const std::vector<std::string> &words, int wordCount) {
  int counter = 0;
  for (const auto &i : words) {
    std::cout << i << " ";
    ++counter;
    if (counter == wordCount) {
      break;
    }
  }
  std::cout << '\n';
}

bool checkNumber(const std::string &N) {
  for (const auto &i : N) {
    if (!isdigit(i)) {
      std::cout << "Incorrect value for N\n";
      return false;
    }
  }
  return true;
}
bool Client::execute(const std::string &line, std::string &filename) {
  std::string value;
  SpellChecker checker = {};
  Ngrams ngrams = {};
  this->text.readText(filename);
  std::vector<std::string> words = this->text.getText();
  if (line == "check") {
    std::vector<std::string> unusualWords = checker.check(words, this->N);
    printUnusualWords(unusualWords, this->wordCount);

  } else if (line == "help") {
    HelpCommand helpCommand = {};
    helpCommand.printCommandsDescription();

  } else if (line == "exit") {
    return false;

  } else if (line == "print diagrams") {
    ngrams.setDiagrams(words);
    printNgrams(ngrams.getDiagrams());

  } else if (line == "print trigrams") {
    ngrams.setTrigrams(words);
    printNgrams(ngrams.getTrigrams());

  } else if (line == "set N") {
    std::cout << "write N\n";
    std::getline(std::cin, value);
    if (checkNumber(value)) {
      this->N = std::stod(value);
    }

  } else if (line == "set word count") {
    std::cout << "write word count\n";
    std::getline(std::cin, value);
    if (checkNumber(value)) {
      this->wordCount = std::stoi(value);
    }

  } else {
    std::cout << "Wrong command\n";

  }
  return true;
}