
#ifndef SPELLCHECKER__TEXT_H_
#define SPELLCHECKER__TEXT_H_
#include <vector>
#include <string>
#include <fstream>
class Text {
 private:
  std::vector<std::string> words;
 public:
  void readText(std::string &filename);
  std::vector<std::string> getText();
};

#endif //SPELLCHECKER__TEXT_H_
