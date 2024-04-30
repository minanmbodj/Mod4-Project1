#include <iostream>
#include "List.h"

int main(){
	List stocks;

	// test inserting and displaying one element
	cout << "test inserting one element: " << endl;
	stocks.insert(5);
	stocks.display();			
	cout << endl;

	// test inserting and displaying an element before head
	cout << "test inserting an element before head: " << endl;
	stocks.insert(3);
	stocks.display();			
	cout << endl;

	// test inserting and displaying a new element at the end of the list 
	cout << "test inserting a new element at the end of the list " << endl;
	stocks.insert(6);
	stocks.display();			
	cout << endl;

	// try a few more
	cout << "try a few more " << endl;
	stocks.insert(4);
	stocks.insert(1);
	stocks.insert(2);
	stocks.display();			
	cout << endl;

	//test the contains method
	cout << "test the contains method: " << endl;
	if (stocks.contains(3))
		cout << "3 is in stocks" << endl;
	else
		cout << "3 is NOT in stocks" << endl;


	if (stocks.contains(7))
		cout << "7 is in stocks" << endl;
	else
		cout << "7 is NOT in stocks" << endl;
	cout << endl;	

	// test inserting repeated elements
	// Do we allow repeat elements?  Generally, yes.
   // But we'd like this to be a list implementation 
   // list to have some set properties (no repeats).
	// How can you adapt your code to handle this?
	cout << "test inserting a repeat element: " << endl;
	stocks.insert(4);
	stocks.display();			
	cout << endl;	

	//test removing the first element 
	cout << "test removing the first element: " << endl;
	stocks.remove(1);
	stocks.display();			
	cout << endl;	

	//test removing the element at the tail of the list
	cout << "test removing the element at the tail: " << endl;
	stocks.remove(6);
	stocks.display();			
	cout << endl;	


	// try removing an element not in the list
	// should do nothing
   // do you need to adapt your code to handle this?
	// how??
	cout << "test removing an element not in the list: (8) " << endl;
	stocks.remove(8);
	stocks.display();			
	cout << endl;	

	cout << "test removing a few more (3, 2, 5) : " << endl;
	stocks.remove(3);
	stocks.remove(2);
	stocks.remove(5);
	stocks.display();			

	// test removing the last element to create an empty list 
	cout << "test removing the last element to create an empty list " << endl;
	stocks.remove(4);
	stocks.display();			

/*
	stocks.add("MMM");
	stocks.add("ABB");
	stocks.add("ABBV");
	stocks.add("ANET");
	stocks.add("ADI");
	stocks.add("T");
	stocks.add("AZO");
	stocks.add("AVB");
	stocks.add("GOOG");
*/
	

}
