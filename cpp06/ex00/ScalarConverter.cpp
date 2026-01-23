#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
  return (*this);
}
ScalarConverter::~ScalarConverter() {}

static void ft_trim(std::string& str) {
  while (str.size() &&
         ((str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t' ||
           str[str.size() - 1] == '\'') ||
          str[str.size() - 1] == '\"'))
    str.erase(str.size() - 1);
  while (str.size() && ((str[0] == ' ' || str[0] == '\t') || str[0] == '\'' ||
                        str[0] == '\"'))
    str.erase(0, 1);
}

static bool is_displayable(char c) {
  if (33 <= c && c <= 126)
    return true;
  return false;
}

static bool char_literal_check(std::string& str, char& c) {
  if (str.size() == 3 && ((str[0] == '\'' && str[2] == '\'') ||
                          (str[0] == '\"' && str[2] == '\"'))) {
    c = str[1];
    ft_trim(str);
    return true;
  } else if (str.size() == 1 && ((33 <= str[0] && str[0] < 48) ||
                                 (58 <= str[0] && str[0] < 127))) {
    c = str[0];
    return true;
  }
  return false;
}

static void float_literal_check(std::string& str) {
  if (str.size() && str[str.size() - 1] == 'f')
    str.erase(str.size() - 1);
}

static void convert_char(std::string& str, char& c, std::string& msg) {

  try {
    c = strToType<char>(str);
    std::ostringstream out;
    if (c < 0)
      msg += "impossible";
    else if (!is_displayable(c))
      msg += "Non displayable";
    else {
      out << c;
      msg += "\'" + out.str() + "\'";
    }
  } catch (std::exception& e) {
    msg += "impossible";
  }
}

static void convert_float(std::string& str, float& n, std::string& msg) {
  try {
    n = strToType<float>(str);
    std::ostringstream out;
    if ((n - static_cast<int>(n) == 0))
      out << std::fixed << std::setprecision(1) << n << "f";
    else
      out << n << "f";
    msg += out.str();
  } catch (std::exception& e) {
    msg += "impossible";
  }
}

static void convert_double(std::string& str, double& n, std::string& msg) {
  try {
    n = strToType<double>(str);
    std::ostringstream out;
    if ((n - static_cast<int>(n) == 0))
      out << std::fixed << std::setprecision(1) << n;
    else
      out << n;
    msg += out.str();
  } catch (std::exception& e) {
    msg += "impossible";
  }
}

static void convert_int(std::string& str, int& n, std::string& msg) {
  try {
    n = strToType<int>(str);
    std::ostringstream out;
    out << n;
    msg += out.str();
  } catch (std::exception& e) {
    msg += "impossible";
  }
}

void ScalarConverter::convert(std::string str) {
  char c = 0;
  int i = 0;
  float f = 0;
  double d = 0;
  std::string msg_c, msg_i, msg_f, msg_d;

  if (char_literal_check(str, c)) {
    std::ostringstream out;
    out << static_cast<int>(c);
    str = out.str();
  }
  float_literal_check(str);

  convert_char(str, c, msg_c);
  convert_int(str, i, msg_i);
  convert_float(str, f, msg_f);
  convert_double(str, d, msg_d);

  std::cout << "char: " << msg_c << std::endl;
  std::cout << "int: " << msg_i << std::endl;
  std::cout << "float: " << msg_f << std::endl;
  std::cout << "double: " << msg_d << std::endl;
}

const char* OutoftheBoundsException::what() const throw() {
  return ("Error: Number is out of the bounds!");
}

const char* ConversionFailException::what() const throw() {
  return ("Error: Conversion is failed!");
}

// bool convert_char(std::string& str, char& c, std::string& msg) {

// try {
//   if (str.size() == 3 && str[0] == '\'' && str[2] == '\'' &&
//       is_displayable(str[1]))
//     c = strToType<char>(str, msg);
//   else if (str.size() == 1 &&
//            ((33 <= str[0] && str[0] < 48) || (58 <= str[0] && str[0] < 127)))
//     c = strToType<char>(str, msg);
//   std::cout << "c: " << c << std::endl;
//   return true;
// } catch (std::exception& e) {
//   msg += "impossible ";
//   return false;
// }

// msg += c;

// return false;
// }