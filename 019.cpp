#include <iostream>

enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
typedef int Year;
typedef int Day;

Month &operator++(Month &month) {
  month = static_cast<Month>(static_cast<int>(month) + 1);
  return month;
}

bool isLeap(Year year) { return (year % 4 == 0 && year % 100 != 0); }

int DaysThisMonth(Month month, Year year) {
  if (month == SEP || month == APR || month == JUN || month == NOV) {
    return 30;
  } else if (month == FEB) {
    return isLeap(year) ? 29 : 28;
  } else {
    return 31;
  }
}

struct Date {
  Year year;
  Month month;
  Day day;
  void print() { std::cout << year << "/" << month << "/" << day << std::endl; }
  void operator++() {
    Date yearEnd = {year, DEC, 31};
    Date monthEnd = {year, month, DaysThisMonth(month, year)};
    if (*this == yearEnd) {
      ++year;
      month = JAN;
      day = 1;
      return;
    } else if (*this == monthEnd) {
      ++month;
      day = 1;
    } else {
      ++day;
    }
  }
  bool operator==(const Date &other) {
    return (year == other.year && month == other.month && day == other.day);
  }
};

int main() {
  Date ew = {1900, JAN, 1};
  Date start = {1901, JAN, 1};
  Date end = {2001, JAN, 1};
  int dayInWeek = 1;
  while (!(ew == start)) {
    ++ew;
    ++dayInWeek;
  }
  int sum = 0;
  while (!(start == end)) {
    if (dayInWeek % 7 == 0 && start.day == 1) {
      ++sum;
    }
    ++dayInWeek;
    ++start;
  }
  std::cout << "Amount of sundays that fell on the first of the month is: "
            << sum << std::endl;
}
