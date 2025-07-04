#ifndef customer_h
#define customer_h
#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "shippingservice.h"
#include "shippable.h"
class Customer{
public:
	Customer(float balance_):balance(balance_){}
	void addToCart(Product* product, int quantity){
		try{
			if(product -> getQuantity() < quantity){
				throw std::runtime_error("sorry, no enough " + product -> getName());
			}
			//res will contain price, quantity, weight
			std::vector<float> res = product -> checkout();
			if(res.size() > 1){
				Shippable* ptr = dynamic_cast<Shippable*>(product);
				shippableItems.push_back({ptr, quantity});
			}
			res.insert(res.begin() + 1, quantity);
			product -> changeQuantity(quantity);
			items.push_back({product, res});
		}catch(const std::runtime_error& e){
			std::cout << e.what() << std::endl;
		}
	}
	void checkout(){
		try{
			if(items.size() == 0){
				throw std::runtime_error("sorry, the cart is empty");	
			}
			float subTotal = 0;
			float totalWeight = 0;
			float shippingFees = 0;
			float amount = 0;
			for(auto item : items){
				subTotal += item.second[0] * item.second[1];
				//this equavliant to creating a flag in the product to say if it's shippable
				if(item.second.size() > 2){
					//every kilo costs 3
					totalWeight+=item.second[2] / 1000.f;
					shippingFees+= (item.second[2] / 1000.f) * 3;
				}
			}
			amount = subTotal + shippingFees;
			if(amount > balance){
				throw std::runtime_error("balance insufficent");
			}
			if(shippableItems.size() > 0){
				ShippingService::service(shippableItems);	
				std::cout << "Total package weight " << totalWeight << "kg" << std::endl; 
			}
			std::cout << "** checkout reciept **" << std::endl;
			for(auto item : items){
					std::cout << std::left
						<<item.second[1] << "x " <<
						std::setw(20) <<
						item.first -> getName() <<
						item.second[1] * item.second[0]<<
						std::endl;
			}	
			std::cout << "--------------------" << std::endl;
			std::cout << "subtotal: " << subTotal << std::endl;
			std::cout << "shippingg fees: " << shippingFees << std::endl;
			std::cout << "amount: " <<amount<< std::endl;
			balance-=amount;
			items.clear();
		} catch(const std::runtime_error& e){
			std::cout << e.what() << std::endl;
		}
	}
private:
	std::vector<std::pair<Shippable*, int>> shippableItems;
	std::vector<std::pair<Product*, std::vector<float>>> items;
	float balance;
};

#endif
