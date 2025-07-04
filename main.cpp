#include <iostream>
#include <vector>
#include "product.h"
#include "shippable.h"
#include "regularproduct.h"
#include "expireable.h"
#include "specialproduct.h"
#include "customer.h"
using namespace std;

int main(int argc, char** argv){
	//vector<Product*> products;
	//products.push_back(new Shippable("mohab", 10, 10, 55));
	//products.push_back(new RegularProduct("mostafa", 20, 10));
	//products.push_back(new Expireable("maya", 20, 50, "may2025"));	
	//products.push_back(new SpecialProduct("sahar", 30, 60, 50, "may2025"));	
	//for(Product* prod : products){
	//	for(float thing : prod -> checkout()){
	//		cout << prod -> getName() << ": " << thing << endl;
	//	}
	//}
	Customer customer(100);
	SpecialProduct cheese("cottage cheese", 10, 3, 500, "may");
	Shippable tv("tv", 10, 2, 1500);
	RegularProduct card("scratch card", 4, 3);
	Expireable bisciut("biscuts", 2, 3, "may 2025");
	customer.addToCart(&cheese, 1);
	customer.addToCart(&tv, 2);
	customer.addToCart(&card, 1);
	customer.addToCart(&bisciut, 1);
	customer.checkout();
	return 0;
}
