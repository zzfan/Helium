#ifndef __STRING_UTIL_HPP__
#define __STRING_UTIL_HPP__

#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>

class StringUtil {
public:
  static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
  }
  static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
  }
  static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
  }
  static inline std::string trimed(const std::string& s) {
    std::string tmp = s;
    trim(tmp);
    return tmp;
  }

  static bool EndsWith(const std::string &s, const std::string &pattern) {
    if (s.length() >= pattern.length()) {
      return (0 == s.compare (s.length() - pattern.length(), pattern.length(), pattern));
    } else {
      return false;
    }
  }
  static bool StartsWith(const std::string &s, const std::string &pattern) {
    if (s.length() >= pattern.length()) {
      return (0 == s.compare (0, pattern.length(), pattern));
    } else {
      return false;
    }
  }
  // from the begin to the first occurence of c
  static std::string SubStringIfFind(const std::string& s, const char c);
  static std::string SubStringIfFind(const std::string& s, const std::string pattern);

  static std::vector<std::string> &Split(
    const std::string &s,
    char delim,
    std::vector<std::string> &elems
  );
  static std::vector<std::string> Split(const std::string &s, char delim);

  /*
   * This is the split function that use any white space as delimiter
   * Use completely different implementation from the other two
   */
  static std::vector<std::string> Split(const std::string &s);

  // remove all currence of pattern from s
  static void Remove(std::string& s, const std::string& pattern) {
    while (s.find(pattern) != std::string::npos) {
      s.erase(s.find(pattern), pattern.length());
    }
  }
};

#endif
