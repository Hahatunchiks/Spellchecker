#include <iostream>

#include "Application.h"
void Application::start(std::string filename) {
  std::cout << "If you want choose N or word count write 'set N' or 'set word count'" << '\n';
  std::cout << "If you want check your text write 'check'" << '\n';
  std::cout << "If you want view the list of commands write 'help'" << '\n';
  std::string line;
  while (true) {
    std::getline(std::cin, line);
    if(!this->command.execute(line, filename)){
      break;
    }
  }
}