/* 
   stdHelpers.cpp
*/
#include "stdafx.h"
#include "stdHelpers.h"
#include <algorithm>
#include <cctype>

std::string ReplaceInStr(const std::string& in, const std::string& search_for, const std::string& replace_with) {

  std::string ret = in;

  std::string::size_type pos = ret.find(search_for);

  while (pos != std::string::npos) {
    ret = ret.replace(pos, search_for.size(), replace_with);

    pos =  pos - search_for.size() + replace_with.size() + 1;

    pos = ret.find(search_for, pos);
  }

  return ret;
}

void ToUpper(std::string& s) {
  std::transform(s.begin(), s.end(), s.begin(), toupper);
}

void ToLower(std::string& s) {
  std::transform(s.begin(), s.end(), s.begin(), tolower);
}
