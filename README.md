# How to run
compile main.cpp and run the resulting excutable
```
g++ ./main.cpp
./a.exe
```
# OOP-Cart
in this project I have made an OOP cart that has four types of products:
  - Expirable product
  - Shippable product
  - Regular product
  - Special product (both shippable and expireable)
these classes are derived from a common interface called Product
# Clarifications:
my choice for using inhertiance rather than a adding a flag to the class product was to demonstrate my understanding of inhertiance and polymorphism.
  -  I have faced the diamond problem intentionally to demonstrate how I can solve it.
  -  I used upcasting in the Cusotmer class so I can put items in one vector.
  -  I casted product* to Shippable* when applicable so I can send it the shipping service as requested.
  -  I have not sperated the interface from the Implementation (by c++ terms) because the classes are very simple, Bjarne Stroustrup advices that in "The C++ Programming Language".

# Design:
![design](https://github.com/MostafaEwis/OOP-Cart/blob/master/design.jpg)

# Screenshots:
| code | result | 
| ---- | ---- |
|![code](./code.png) | ![result](./result.png) |
