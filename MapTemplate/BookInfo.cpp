#include "BookInfo.h"

using namespace std;

BookInfo::BookInfo() {
  this->author = "";
  this->category = "";
  this->numberOfPages = 0;
  this->isAvailable = false;
}

BookInfo::BookInfo(string author, string category, int numberOfPages, bool isAvailable) {
  this->author = author;
  this->category = category;
  this->numberOfPages = numberOfPages;
  this->isAvailable = isAvailable;
}

BookInfo::BookInfo(const BookInfo& bookInfo) {
  this->author = bookInfo.author;
  this->category = bookInfo.category;
  this->numberOfPages = bookInfo.numberOfPages;
  this->isAvailable = bookInfo.isAvailable;
}

BookInfo& BookInfo::operator=(const BookInfo& bookInfo) {
  this->author = bookInfo.author;
  this->category = bookInfo.category;
  this->numberOfPages = bookInfo.numberOfPages;
  this->isAvailable = bookInfo.isAvailable;
  return *this;
}

BookInfo::~BookInfo() {}

ostream& operator<<(ostream& os, const BookInfo& bookInfo) {
  os << "Author: " << bookInfo.author << ", category: " << bookInfo.category << ", number of pages: " << bookInfo.numberOfPages << ", is available: " << bookInfo.isAvailable << endl;
  return os;
}