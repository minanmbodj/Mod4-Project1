#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

using namespace std;
// delete out the std in further argument
class Stock {
 public:
  // No-argument constructor
  Stock();
  // Constructor with arguments
  Stock(string name, string ticker, int quantity, double price);
  // Copy constructor
  Stock(const Stock& other);

  // Getters
  string getName() const;
  string getTicker() const;
  int getQuantity() const;
  double getPrice() const;

  // Setters
  void setName(string name);
  void setTicker(string ticker);
  void setQuantity(int quantity);
  void setPrice(double price);

  // Get key (identical to getTicker)
  string getKey() const;

  // Comparison operators
  bool operator<(const Stock& other) const;
  bool operator>(const Stock& other) const;
  bool operator==(const Stock& other) const;
  bool operator>=(const Stock& other) const;
  bool operator<=(const Stock& other) const;
  bool operator==(string ticker) const;
bool operator!=(const Stock& other) const;
  

	// Output operator
  friend ostream& operator<<(ostream& out, const Stock& stock);

 private:
  string name_;
  string ticker_;
  int quantity_;
  double price_;
};



#endif 
