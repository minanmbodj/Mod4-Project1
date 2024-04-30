#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include "Node.h"
#include "Stock.h"
#include "List.h"


using namespace std;

class Market
{


public:
		
	Market();
	Market(string);
	Market(string, int);
	//~Market();
	void readStockFile(int);
	void readStockFile();
	void writeStockFile(int);
	void writeStockFile();
	void showStocks();
	void addStock(Stock s);
	void removeStock(string);
	void step();
	int nextDay();
	int getDay();
	Stock &getStockBySymbol(string);
	


private:
	List<Stock>* stocks_; // unsure about this || a list of stocks in this market (using the templated list class
	const string name_;
	int current_day_;


};

#endif
