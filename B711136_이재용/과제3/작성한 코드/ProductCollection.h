#pragma once

#include "Product.h"
#include <string>
using namespace std;

#define MAX_PRODUCT 1000

class ProductCollection
{
private:
	Product* productCollection[MAX_PRODUCT];
	int numProd;

public:
	ProductCollection()
		:numProd(0){}

	Product* findFirst();
	//Product* getNext();
	void addProduct(Product* newProd);
	Product* findProduct(string prodName);
};

