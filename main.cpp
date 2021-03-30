#include "Application.h"

int main(int argc, char **argv) {
  if (argc != 1) {
    std::string filename = argv[1];
    Application application = {};
    application.start(filename);
  } else{
    std::cout << "Wrong file\n";
  }
  return 0;

}
