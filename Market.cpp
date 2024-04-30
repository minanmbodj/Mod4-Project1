#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string.h>
#include "Node.h"
#include "Stock.h"
#include "List.h"
#include "Market.h"
#include <random>

using namespace std;
//template <typename T>
Market::Market() : name_("Default"), current_day_(0) {}

Market::Market(string name) : name_(name), current_day_(0) {}

Market::Market(string name, int current_day) : name_(name), current_day_(current_day) {}

// Method to read file
void Market::readStockFile(int dayNum){
    // File name
    string fileName = name_ + "." + to_string(dayNum) + ".txt";

    /// Open the file
    ifstream stockFile(fileName);

	//check that we're able to open
	if (!stockFile){
		cout << "Error opening: " << fileName << endl;
		exit(EXIT_FAILURE);
	}

	string ticker;
	string name;
	double price;
	int quantity;

    //List<Stock> *stockList = new List<Stock>();
		stocks_ = new List<Stock>();
	// temp variable to hold one line of text from the file
	string line;

	// temp variable to hold one character version of price & quantity
	string temp_word;

	// read one line at time from the file of stock info
	while (getline(stockFile, line)){
		if (line.size() > 1){

			//treat the string containing line as a stream named words
			istringstream words(line);

			//read from words into ticker until we see a comma
			getline(words, ticker, ',');

			//continuing reading, now into name, until we see a comma
			getline(words, name, ',');

			//continuing reading, now into temp_word, until we see a comma
			// and assign to price
			getline(words, temp_word, ',');
			price = stod(temp_word);

			//continuing reading, now into temp_word, until we see a comma
			// and assign to quantity
			getline(words, temp_word, '\n');
			quantity = stoi(temp_word);
	
			Stock *s = new Stock(name, ticker, quantity, price);

            stocks_->insert(*s);

        }

    // Close the file
    stockFile.close();
    }
}
void Market::readStockFile() {
  readStockFile(current_day_);
}

void Market::writeStockFile(int day_num) {
  string file_name = name_ + "." + to_string(day_num) + ".txt";
  ofstream output_file(file_name);
  if (!output_file.is_open()) {
    cout << "Error opening file: " << file_name << endl;
    return;
  }
	stocks_ = new List<Stock>();
  Node<Stock>* current = stocks_->getHead();
  while (current != nullptr) {
    output_file << current->getValue() << endl;
    current = current->getNext();
  }
  output_file.close();
}

void Market::writeStockFile() {
  writeStockFile(current_day_);
}

//void Market::showStocks() {
//  cout << "Current day: " << current_day_ << endl;
 // cout << "Stocks in " << name_ << " market:" << endl;
 // stocks_->display();

void Market::showStocks() {
   cout << "Current day: " << current_day_ << endl;
   cout << "Stocks in " << name_ << " market:" << endl;
   Node<Stock>* current = stocks_->getHead();
   while (current != nullptr) {
      Stock& stock = current->getValue();
      cout << std::setw(5) << std::left << stock.getTicker() << ":"
           << std::setw(5) << std::right << stock.getQuantity()
           << " @ $ " << std::setw(7) << std::right << stock.getPrice()
           << " (" << stock.getName() << ")" << "\n";
      current = current->getNext();
   }
}

//std::setw(5) << std::left << st.getTicker() << ":" << std::setw(5) << std::right << st.getQuantity()
 
//    << " @ $ " << std::setw(7) << std::right << st.getPrice() << " (" << st.getName() << ")" << "\n";


void Market::step() {
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(-0.05, 0.05);
  Node<Stock>* current = stocks_->getHead();
  while (current != nullptr) {
    Stock& stock = current->getValue();
    double new_price = stock.getPrice() * (1 + dis(gen));
    stock.setPrice(new_price);
    current = current->getNext();
  }
}

int Market::nextDay() {
  return ++current_day_;
}

int Market::getDay() {
  return current_day_;
}

void Market::addStock(Stock s) {
  stocks_->insert(s);
}

void Market::removeStock(string t) {
  stocks_->remove(t);
}

Stock& Market::getStockBySymbol(string t) {
  Node<Stock>* stock_node = stocks_->find(t);
  return stock_node->getValue();
}
