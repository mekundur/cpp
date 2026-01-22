#pragma once

#include <map>
#include <string>

class BitcoinExchange {

 private:
  std::map<int, double> _data;

 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  void store_data();
  void get_inputs(const std::string& file_name);
  double search(int date);

  double stringToDouble(const std::string& str) const;
  int stringToInt(const std::string& str) const;
  void ft_trim(std::string& str);
  std::string get_current_date_time() const;
  bool value_check(std::string& value_str) const;
  bool date_check(std::string& date_str) const;
  void print_date(std::string& date_str);
  size_t pipeCount(std::string& str) const;

  class InvalidValueException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class OutoftheBoundsException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};