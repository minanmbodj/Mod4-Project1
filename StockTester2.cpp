#include "Stock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

	Stock *s1 = new Stock("Enphase Energy Inc.", "ENPH", 10000, 184.52);
	cout << "Stock 1 is " << endl << *s1 << endl << endl;	

	Stock *s2 = new Stock();
	cout << "At first, stock 2 is " << endl << *s2 << endl << endl;	

	s2->setName("UNITY Biotechnology Inc.");
	s2->setTicker("UBX");
	s2->setPrice (1.15);
	s2->setQuantity(10000);
	cout << "Later, stock 2 is " << endl << *s2 << endl << endl;	

	Stock *s3 = new Stock(*s1);
	cout << "Stock 3 is a copy of Stock 1 " << endl << *s3 << endl;	

	cout << "Now looking at stock 3 element by element: " << endl;
	cout << "Name: " <<s3->getName() << endl;
	cout << "Ticker: " <<s3->getTicker() << endl;
	cout << "Price: " <<s3->getPrice() << endl;
	cout << "Quantity: " <<s3->getQuantity() << endl;
	cout << "Key: " <<s3->getKey() << endl;
	

	return 0;



}
