#include <limits.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "BitcoinExchange.hpp"

void BitcoinExchange::ft_trim(std::string& str) {
  while (str.size() &&
         (str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t'))
    str.erase(str.size() - 1);
  while (str.size() && (str[0] == ' ' || str[0] == '\t'))
    str.erase(0, 1);
}

size_t BitcoinExchange::pipeCount(std::string& str) const {
  int pipeCount = 0;
  std::string::size_type pos = 0;

  while ((pos = str.find('|', pos)) != std::string::npos) {
    ++pipeCount;
    ++pos;  // move past the found position
  }
  return (pipeCount);
}

std::string BitcoinExchange::get_current_date_time() const {
  std::time_t now = std::time(NULL);
  struct tm* local_time = std::localtime(&now);

  std::ostringstream oss;
  oss << (1900 + local_time->tm_year) << std::setfill('0') << std::setw(2)
      << (1 + local_time->tm_mon) << std::setfill('0') << std::setw(2)
      << local_time->tm_mday << " " << std::setfill('0');

  return oss.str();
}

double BitcoinExchange::stringToDouble(const std::string& str) const {
  std::stringstream ss(str);
  long double value;
  ss >> value;
  if (ss.fail())
    throw(InvalidValueException());
  if (value > INT_MAX || value < INT_MIN)
    throw(OutoftheBoundsException());
  return static_cast<double>(value);
}

int BitcoinExchange::stringToInt(const std::string& str) const {
  std::stringstream ss(str);
  long long value;
  ss >> value;
  if (ss.fail())
    throw(InvalidValueException());
  if (value > INT_MAX || value < INT_MIN)
    throw(OutoftheBoundsException());
  return static_cast<int>(value);
}

bool BitcoinExchange::value_check(std::string& value_str) const {
  double val;
  try {
    val = stringToDouble(value_str);
  } catch (std::exception& e) {
    return (std::cout << e.what() << std::endl, 0);
  }
  if (val <= 0)
    return (std::cout << "Error: Invalid value entry!" << std::endl, 0);
  if (1000 < val)
    return (std::cout << "Error: Value is too large!" << std::endl, 0);

  return (1);
}

void BitcoinExchange::print_date(std::string& date_str) {
  int date = stringToInt(date_str);
  int year = date / 10000;
  int day = date % 100;
  int month = (date - (year * 10000) - day) / 100;
  std::cout << std::setfill('0') << std::setw(4) << year << "-" << std::setw(2)
            << month << "-" << std::setw(2) << day << " ";
}

bool BitcoinExchange::date_check(std::string& date_str) const {
  if (date_str.size() != 8)
    return (std::cout << "Error: Invalid date format!\n", 0);
  int date = stringToInt(date_str);
  int year = date / 10000;
  int day = date % 100;
  int month = (date - (year * 10000) - day) / 100;
  int today = stringToInt(get_current_date_time());
  //   print_date(date_str);
  if (month < 1 || 12 < month)
    return (std::cout << "Error: Wrong month entry!\n", 0);
  if (day < 1 || 31 < day)
    return (std::cout << "Error: Invalid day entry!\n", 0);
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
    return (std::cout << "Error: Invalid month-day format\n", 0);
  if (month == 2) {
    bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (!leap && day > 28)
      return (std::cout << "Error: Invalid leap year format!\n", 0);
  }
  if (date < 20000101)
    return (std::cout << "Error: No data for Ancient ages!\n", 0);
  if (date >= today)
    return (std::cout << "Error: I can't tell a fortune!\n", 0);
  //   return (std::cout << std::endl, 1);
  return (1);
}
