#ifndef	Product_h 
#define	Product_h
#include <string>
#include <vector>
class Product{
public:
	friend class Customer;
	Product(std::string name_, float price_, int quantity_): name(name_), price(price_), quantity(quantity_){};
	//not returning a reference because a local variable will be created. this is bad to return a vector but in this case it's maximum of length 2;
	std::string getName(){
		return name;
	}
	float getPrice(){
		return price;
	}
	int getQuantity(){
		return quantity;
	}
	void setPrice(int price_){
		price = price_;
	}

	void setName(std::string name_){
		name = name_;
	}
	void changeQuantity(int diff){
		this -> quantity -= diff;
	}
	virtual ~Product() = default;
protected: 
	virtual std::vector<float> checkout() = 0;
	std::string name;
	float price;
	int quantity;
};

#endif
