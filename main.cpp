#include "Application.h"
int main(int argc, char **argv) {
  if (argc == 2) {
    std::string filename = argv[1];
    Application application;
    application.start(filename);
  } else{
    std::cerr << "Usage: ./Program [filepath]\n";
    std::exit(-1);
  }
  return 0;

}