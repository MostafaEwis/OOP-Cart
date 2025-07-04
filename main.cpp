#include <iostream>
#include <vector>
#include "product.h"
#include "shippable.h"
#include "regularproduct.h"
#include "expireable.h"
#include "specialproduct.h"
using namespace std;

int main(int argc, char** argv){
	vector<Product*> products;
	products.push_back(new Shippable("mohab", 10, 10, 55));
	products.push_back(new RegularProduct("mostafa", 20, 10));
	products.push_back(new Expireable("maya", 20, 50, "may2025"));	
	products.push_back(new SpecialProduct("sahar", 30, 60, 50, "may2025"));	
	for(Product* prod : products){
		for(float thing : prod -> checkout()){
			cout << prod -> getName() << ": " << thing << endl;
		}
	}
	return 0;
}
