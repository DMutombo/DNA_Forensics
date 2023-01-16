#include <fstream>
#include <iostream>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }

  std::vector<std::string> database;
  std::ifstream ifs{argv[1]};
  for (std::string line; std::getline(ifs, line); line = "") {
    database.push_back(line);
  }
  std::string result = Database(database, argv[2]);
  std::cout << result << std::endl;

  return 0;
}