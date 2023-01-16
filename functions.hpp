#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <map>
#include <vector>

#include "utilities.hpp"

std::string Database(std::vector<std::string>& database, std::string seq);
unsigned int LongestOccurence(std::string& seq, std::string& substr);
unsigned int Max(unsigned int& longest, unsigned int& count);
std::string Identity(
    std::map<std::string, std::vector<unsigned int>>& datatable,
    std::vector<unsigned int>& str_count);

#endif
