#ifndef expireable_h
#define expireable_h
#include "regularproduct.h"
#include "product.h"
#include <string>
class Expireable : virtual public RegularProduct{
public: 
	Expireable(std::string name, float price, int quantity, std::string expiry): Product(name, price, quantity), RegularProduct(name, price, quantity), expiry(expiry){};
	std::string getExpiry(){
		return expiry;
	}
	void setExpiry(std::string expiry_){
		expiry = expiry_;
	}
private:
	std::string expiry;

};
#endif
