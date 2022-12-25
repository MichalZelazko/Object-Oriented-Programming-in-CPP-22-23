#pragma once
#include <iostream>
#include <string>

using namespace std;

class BookInfo {
public:
  string author;
  string category;
  int numberOfPages;
  bool isAvailable;
  BookInfo();
  BookInfo(string author, string category, int numberOfPages, bool isAvailable);
  BookInfo(const BookInfo& bookInfo);
  BookInfo& operator=(const BookInfo& bookInfo);
  ~BookInfo();
  friend ostream& operator<<(ostream& os, const BookInfo& bookInfo);
};