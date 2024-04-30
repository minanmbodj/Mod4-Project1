#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string.h>
//#include <Node.h>
#include "Stock.h"

using namespace std;

Stock::Stock() : name_("null"), ticker_("nul"), quantity_(0), price_(0.0) {

}

Stock::Stock(string name, string ticker, int quantity, double price)
    : name_(name), ticker_(ticker), quantity_(quantity), price_(price) {}

Stock::Stock(const Stock& other)
    : name_(other.name_), ticker_(other.ticker_), quantity_(other.quantity_), price_(other.price_) {}


string Stock::getName() const {
  return name_;
}

void Stock::setName(string name) {
  name_ = name;
}

string Stock::getTicker() const {
  return ticker_;
}

string Stock::getKey() const {
	return ticker_;
}

void Stock::setTicker(string ticker) {
  ticker_ = ticker;
}

int Stock::getQuantity() const {
  return quantity_;
}

void Stock::setQuantity(int quantity) {
  quantity_ = quantity;
}

double Stock::getPrice() const {
  return price_;
}

void Stock::setPrice(double price) {
  price_ = price;
}


bool Stock::operator<(const Stock& other) const {
  return ticker_ < other.ticker_;
}

bool Stock::operator>(const Stock& other) const {
  return ticker_ > other.ticker_;
}

bool Stock::operator==(const Stock& other) const {
  return ticker_ == other.ticker_;
}

bool Stock::operator>=(const Stock& other) const {
  return ticker_ >= other.ticker_;
}

bool Stock::operator<=(const Stock& other) const {
  return ticker_ <= other.ticker_;
}

bool Stock::operator!=(const Stock& other) const {
  return ticker_ != other.ticker_;
}

bool Stock::operator==(string ticker) const {
  return ticker_ == ticker;
}

ostream& operator<<(ostream& out, const Stock& stock) {
  out << stock.getName() << " " << stock.getTicker() << " " << stock.getQuantity() << " "
      << stock.getPrice();
  return out;
}
