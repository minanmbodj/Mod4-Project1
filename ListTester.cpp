#include <iostream>
#include "List.h"
#include "Stock.h"

int main(){
	// create a list of nodes that contain a Stock as the value portion of the node
	List<Stock> *stockList = new List<Stock>();
	// dynamically create some example stock objects
	Stock *a = new Stock("AbbVie", "ABBV", 1000, 116.35);
	Stock *b = new Stock("Abbott Laboratories", "ABB", 200, 35.17);
	Stock *c = new Stock("Accenture", "ACN", 1000, 309.15);
	Stock *d = new Stock("3M Corp.", "MMM", 1000, 198.27);
	Stock *e = new Stock("AES Corp", "AES", 1000, 25.73);
	Stock *f = new Stock("Alliant Energy", "LNT", 1000, 56.67);
 
	// test inserting and displaying one element
	cout << "test inserting one element: " << endl;
	stockList->insert(*a);
	stockList->display();			
	cout << endl;

	// test inserting and displaying an element before head
	cout << "test inserting an element before head: " << endl;
	stockList->insert(*b);
	stockList->display();			
	cout << endl;

	// test inserting and displaying a new element at the end of the list 
	cout << "test inserting a new element at the end of the list " << endl;
	stockList->insert(*c);
	stockList->display();			
	cout << endl;

	// try a few more
	cout << "try a few more " << endl;
	stockList->insert(*e);
	stockList->insert(*d);
	stockList->display();			
	cout << endl;

	//test the contains method
	cout << "test the contains method: " << endl;
	if (stockList->contains("MMM"))
		cout << "MMM is in the stockList" << endl;
	else
		cout << "MMM is NOT in the stockList" << endl;


	if (stockList->contains("AMD"))
		cout << "AMD is in the stockList" << endl;
	else
		cout << "AMD is NOT in the stockList" << endl;
	cout << endl;	

	// test inserting repeated elements
	// Do we allow repeat elements?  Generally, yes.
   // But we'd like this to be a list implementation 
   // list to have some set properties (no repeats).
	// How can you adapt your code to handle this?
	cout << "test inserting a repeat element: (MMM again) " << endl;
	stockList->insert(*d);
	stockList->display();			
	cout << endl;	

	// test finding the node containing the ticker symbol T
	Node<Stock> * foundPtr = stockList->find("MMM");
	if (foundPtr == nullptr){
		cout << "MMM not found" << endl;
	}
	else{
		cout << "found: " << foundPtr->getValue() << endl;
	}
	cout << endl;

	//test removing the first element 
	cout << "test removing the first element, by Stock object: (ABB) " << endl;
	stockList->remove(*b);
	stockList->display();			
	cout << endl;	

	//test removing the first element 
	cout << "test removing the first element, by key value (ABBV ) : " << endl;
	stockList->remove("ABBV");
	stockList->display();			
	cout << endl;
	
	//test removing the element at the tail of the list
	cout << "test removing the tail element, by Stock object (MMM)  " << endl;
	stockList->remove(*d);
	stockList->display();			
	cout << endl;	

	//test removing the element at the tail of the list
	cout << "test removing the tail element, by ticker symbol (AES): " << endl;
	stockList->remove(*e);
	stockList->display();			
	cout << endl;	

	// try removing an element not in the list
	// should do nothing
   // do you need to adapt your code to handle this?
	// how??
	cout << "test removing an element not in the list: (LNT) " << endl;
	stockList->remove(*f);
	stockList->display();			
	cout << endl;	

	// test removing the last element to create an empty list 
	cout << "test removing the last element (ACN) to create an empty list " << endl;
	stockList->remove("ACN");
	stockList->display();			


	foundPtr = stockList->find("T");
	if (foundPtr == nullptr){
		cout << "T not found" << endl;
	}
	else{
		cout << "found: " << foundPtr->getValue() << endl;
	}
	cout << endl;
 
	return 0;	

}
