/* 
   stdHelpers.h
*/

#ifndef __STDHELPERS_H__
#define __STDHELPERS_H__

#include <string>

std::string ReplaceInStr(const std::string& in, const std::string& search_for, const std::string& replace_with);

void ToUpper(std::string& s);
void ToLower(std::string& s);

#endif


