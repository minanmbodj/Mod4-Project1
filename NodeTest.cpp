#include <iostream>
#include <string>
#include "Node.h"
#include "Stock.h"

using namespace std;

int main(){

	Node<int> *intNode = new Node<int>;
	intNode->setValue(3);
	cout << "intNode's value is " << intNode->getValue() << endl;
	cout << "intNode's next pointer is " << intNode->getNext() << endl;
	cout << endl;

	Node<string> *stringNode = new Node<string>;
	stringNode->setValue("ABC");
	cout << "stringNode's value is " << stringNode->getValue() << endl;
	cout << "stringNode's next pointer is " << stringNode->getNext() << endl;
	cout << endl;

	Node<Stock*> *StockNode = new Node<Stock *>;
	StockNode->setValue(new Stock( "3M Corporation", "MMM", 100, 25.33));
	cout << "Node's value is " << *(StockNode->getValue()) << endl;
	cout << "Node's next pointer is " << StockNode->getNext() << endl;
	cout << endl;

	return 0;
}

