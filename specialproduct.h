#ifndef SpecialProduct_h
#define SpecialProduct_h
#include <string>
#include "expireable.h"
#include "shippable.h"
#include "product.h"
#include "regularproduct.h"

class SpecialProduct: public Expireable, public Shippable{
public:
	SpecialProduct(std::string name, float price, int quantity, float weight, std::string expiry):
		Product(name, price, quantity),
		RegularProduct(name, price, quantity),
		Expireable(name, price, quantity, expiry),
		Shippable(name, price, quantity, weight)
	{}
protected:
	std::vector<float> checkout(){
		return Shippable::checkout();
	}

};

#endif
