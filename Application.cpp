#include <iostream>
#include "Application.h"

void Application::start(const std::string &filename) {
  std::cerr << "If you want choose N or word count write 'set N' or 'set word count'" << '\n';
  std::cerr << "If you want check your text write 'check'" << '\n';
  std::cerr << "If you want view the list of commands write 'help'" << '\n';
  std::string line;
  SpellChecker checker;
  checker.ngrams.setNgrams(filename);
  checker.calculateWordsIndexes(checker.ngrams.getTrigrams(),
                                checker.ngrams.getDigramCount(),
                                checker.ngrams.getTrigramCount());
  while (true) {
    std::getline(std::cin, line);
    if (std::cin.eof() || !m_command.execute(line, checker)) {
      break;
    }
  }
}