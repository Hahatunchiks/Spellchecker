#include "HelpCommand.h"
void HelpCommand::printCommandsDescription() {
  std::cout << "'check' - check mistakes in the text\n";
  std::cout << "'help' - print commands description\n";
  std::cout << "'exit' - stop the program\n";
  std::cout << "'set N' - write N index\n";
  std::cout << "'set word count' - write word count\n";
}
