#include "functions.hpp"

#include <map>
#include <string>

std::string Database(std::vector<std::string>& database, std::string seq) {
  unsigned int i = 0;
  std::map<std::string, std::vector<unsigned int>> people;
  std::vector<std::string> head = utilities::GetSubstrs(database.at(i), ',');
  std::vector<unsigned int> str_counts;
  std::string result;

  for (unsigned int i = 1; i < database.size(); ++i) {
    std::vector<std::string> table = utilities::GetSubstrs(database.at(i), ',');
    std::string name = table.at(0);
    std::vector<unsigned int> counts;
    for (unsigned int i = 1; i < table.size(); ++i) {
      counts.push_back(std::stoi(table.at(i)));
    }
    people.insert({name, counts});
  }

  for (unsigned int i = 1; i < head.size(); ++i) {
    unsigned int str_num = LongestOccurence(seq, head.at(i));
    str_counts.push_back(str_num);
  }

  result = Identity(people, str_counts);
  return result;
}

unsigned int Max(unsigned int& longest, unsigned int& count) {
  unsigned int num = 0;
  if (longest < count) {
    num = count;
  } else {
    num = longest;
  }
  return num;
}

unsigned int LongestOccurence(std::string& seq, std::string& substr) {
  unsigned int longest = 0;
  unsigned int length = substr.size();
  for (unsigned int i = 0; i < seq.size() - length + 1; ++i) {
    unsigned int count = 0;
    while (true) {
      unsigned int start = i + (length * count);
      if (seq.substr(start, length) == substr) {
        count += 1;
      } else {
        break;
      }
    }
    longest = Max(longest, count);
  }
  return longest;
}

std::string Identity(
    std::map<std::string, std::vector<unsigned int>>& datatable,
    std::vector<unsigned int>& str_count) {
  std::map<std::string, std::vector<unsigned int>> copy(datatable);
  std::string identity = "No match";
  int count = 0;

  for (auto& p : datatable) {
    std::string key = p.first;
    std::vector<unsigned int> value = p.second;

    if (str_count == value) {
      if (count == 0) {
        count += 1;
        identity = key;
      } else {
        identity = "No match"; 
      }
    }
  }
  return identity;
}
