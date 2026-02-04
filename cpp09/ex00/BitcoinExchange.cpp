#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

// OCF: Constructors, Assignemnt Operator, Destructor
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other)
    _data = other._data;
  return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// HELPERS
// O(log n) lookup complexity
double BitcoinExchange::search(int date) {
  std::map<int, double>::iterator it = _data.lower_bound(date);
  if (it != _data.end() && it->first == date)
    return it->second;
  if (it == _data.begin())
    throw NoDataException();
  --it;
  return (it->second);
}

void BitcoinExchange::get_inputs(const std::string& file_name) {
  std::string date_str;
  std::string val_str;
  std::ifstream file(file_name.c_str());
  if (file.fail())
    throw(ReadFailException());
  if (file.peek() == std::ifstream::traits_type::eof())
    throw(EmptyFileException());
  if (file.is_open()) {
    std::string line;
    getline(file, line, '\n');
    while (getline(file, line, '\n')) {
      date_str.clear();
      val_str.clear();
      if (pipeCount(line) > 1 || pipeCount(line) == 0) {
        std::cout << "Error: Multiple or no '|'s or empty entry! " << std::endl;
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
        std::cout << "Error: No value entry! " << std::endl;
        continue;
      } else {
        bool flag = 0;
        for (std::string::iterator it = val_str.begin(); it != val_str.end();
             ++it) {
          if (!(isdigit(*it) || *it == '.'))
            flag = 1;
        }
        if (flag || dotCount(val_str) > 1) {
          std::cout << "Error: Wrong value format! " << std::endl;
          continue;
        }
      }

      if (date_check(date_str)) {
        if (value_check(val_str)) {
          double coin_result;
          try {
            coin_result =
                stringToDouble(val_str) * search(stringToInt(date_str));
          } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
          }
          std::cout << out_date_str << " => " << val_str << " = " << std::fixed
                    << std::setprecision(2) << coin_result << std::endl;
        }
      }
    }
  }
}

void BitcoinExchange::store_data() {
  std::string date;
  std::string val;
  std::ifstream file("data.csv");
  if (file.fail())
    throw(ReadFailException());
  if (file.peek() == std::ifstream::traits_type::eof())
    throw(EmptyFileException());
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

// EXCEPTIONS
const char* BitcoinExchange::InvalidValueException::what() const throw() {
  return ("Error: Invalid number!");
}

const char* BitcoinExchange::OutoftheBoundsException::what() const throw() {
  return ("Error: Number is out of the bounds!");
}

const char* BitcoinExchange::NoDataException::what() const throw() {
  return ("Error: No data for this exact or any earlier date");
}

const char* BitcoinExchange::EmptyFileException::what() const throw() {
  return ("Error: Empty file");
}

const char* BitcoinExchange::ReadFailException::what() const throw() {
  return ("Error: Unable to read from file");
}
