all:	StockTester NodeTest ListTester MarketTester

StockTester:	Stock.h Stock.cpp StockTester.cpp
	g++ -ggdb -o StockTester StockTester.cpp Stock.cpp 

ListTester:	List.h ListTester.cpp Stock.h Stock.cpp
	g++ -ggdb -o ListTester ListTester.cpp Stock.cpp

NodeTest:	NodeTest.cpp Node.h Stock.h Stock.cpp
	g++ -o NodeTest NodeTest.cpp Stock.cpp

MarketTester:	Market.h Market.cpp MarketTester.cpp Node.h List.h Stock.h Stock.cpp
	g++ -ggdb -o MarketTester MarketTester.cpp Market.cpp Stock.cpp

clean:
	rm StockTester ListTester MarketTester
