#include "Application.h"

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      int c = 0;
      c++;
      std::string filename = argv[1];
      Application application;
      application.start(filename);
    } catch (const std::exception &e) {
      std::cerr << "Error while execution: " << e.what() << std::endl;
      return -1;
    }
  } else {
    std::cerr << "Usage: ./Program [filepath]\n";
    return -1;
  }
  return 0;
}