#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other)
    _data = other._data;
  return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Helpers
double BitcoinExchange::search(int date) {
  std::map<int, double>::iterator it = _data.begin();
  for (; it != _data.end(); it++) {
    if (it->first == date)
      return (it->second);
  }
  it = _data.lower_bound(date);
  if (it != _data.begin())
    it--;
  return (it->second);
}

void BitcoinExchange::get_inputs(const std::string& file_name) {
  std::string date_str;
  std::string val_str;
  std::ifstream file(file_name.c_str());
  if (file.is_open()) {
    std::string line;
    getline(file, line, '\n');
    // int test = 2;
    while (getline(file, line, '\n')) {

      if (pipeCount(line) > 1) {
        std::cout << "Error: Multiple | in the entry! " << std::endl;
        continue;
      }
      std::string out_date_str;
      std::string out_val_str;
      std::stringstream ss_line(line);
      std::string str_line;
      while (getline(ss_line, str_line, '|')) {
        ft_trim(str_line);
        out_date_str = str_line;
        std::stringstream ss_date(str_line);
        std::string str_date;
        while (getline(ss_date, str_date, '-'))
          date_str += str_date;

        if (getline(ss_line, str_line))
          val_str = str_line;
      }
      // std::cout << test << " ";
      // test++;
      ft_trim(date_str);
      ft_trim(val_str);
      if (date_str.empty() && val_str.size()) {
        std::cout << "Error: No date entry! " << std::endl;
        continue;
      } else if (date_str.empty()) {
        std::cout << "Error: Completely empty entry! " << std::endl;
        continue;
      }
      if (val_str.empty()) {
        std::cout << out_date_str << " ";
        std::cout << "Error: No value entry! " << std::endl;
        continue;
      }

      std::cout << out_date_str << " ";
      if (date_check(date_str)) {
        std::cout << "=> " << val_str << " ";

        if (value_check(val_str)) {
          double coin_result =
              stringToDouble(val_str) * search(stringToInt(date_str));
          std::cout << "= " << std::fixed << std::setprecision(2) << coin_result
                    << std::endl;
        }
      }
      date_str.clear();
      val_str.clear();
    }
  }
}

void BitcoinExchange::store_data() {
  std::string date;
  std::string val;
  std::ifstream file("data.csv");
  if (file.is_open()) {
    std::string line;
    getline(file, line, '\n');
    while (getline(file, line, '\n')) {

      std::stringstream ss_line(line);
      std::string str_line;
      if (getline(ss_line, str_line, ',')) {

        std::stringstream ss_date(str_line);
        std::string str_date;
        while (getline(ss_date, str_date, '-'))
          date += str_date;

        if (getline(ss_line, str_line))
          val = str_line;
      }
      _data.insert(
          std::pair<int, double>(stringToInt(date), stringToDouble(val)));
      date.clear();
      val.clear();
    }
  }
  // std::map<int, double>::iterator it = _data.begin();
  // for (; it != _data.end(); ++it) {
  //   std::cout << it->first << " " << std::fixed << std::setprecision(2)
  //             << it->second << std::endl;
  // }
}

// Exceptions
const char* BitcoinExchange::InvalidValueException::what() const throw() {
  return ("Error: Invalid number!");
}

const char* BitcoinExchange::OutoftheBoundsException::what() const throw() {
  return ("Error: Number is out of the bounds!");
}
