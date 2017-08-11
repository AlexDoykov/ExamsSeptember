#include <iostream>
#include <cstring>
#include "Product.h"
#include <fstream>

void Product::setName(const char* _name){
	if(strlen(_name) > 4194304){
		"Name too big\n";
	}else{
		delete name;
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
}

const char* Product::getName() const{
	return name;
}

int Product::getNumber() const{
	return number;
}

void Product::setNumber(int _number){
	int br = 0;
	int temp = _number;
	while(temp > 0){
		br++;
		temp /= 10;
	}
	if(br <= 6){
		number = _number;
	}else{
		std::cout<<"number must contain no more than 6 digits\n";
	}
}

double Product::getPrice() const{
	return price;
}

void Product::setPrice(double _price){
	price = _price;
}

Product::Product(int _number){
	price = 0.0;
	name = new char[2];
	strcpy(name, "");
	setNumber(_number);
}

Product::Product(){
	price = 0.0;
	number = 0;
	name = new char[2];
}

Product::Product(const Product& other){
	name = new char[strlen(other.name)];
	strcpy(name, other.name);
	price = other.price;
	number = other.number;
}

Product& Product::operator = (const Product& other){
	if(strlen(other.name) > strlen(name)){
		delete name;
		name = new char[strlen(other.name)];
	}

	strcpy(name, other.name);
	price = other.price;
	number = other.number;
	return *this;
}

std::istream& operator >> (std::ifstream& in, Product& product){
	in>>product.name;
	in.get();
	in.get();
	in>>product.number;
	in.get();
	in>>product.price;
	in.get();
	return in;
}

std::ostream& operator << (std::ostream& out, const Product& product){
	out<<product.name<<" ,"<<product.number<<","<<product.price<<"\n";
}

Product::~Product(){
	delete name;
}
