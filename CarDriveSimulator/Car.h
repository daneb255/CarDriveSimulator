/*************************************************************************
*
* Daniel Bitzer
* d@bitzer.io
* https://bitzer.io
* __________________
* Car.h
* [2017]
*  
*
*/

#pragma once
#include <string>

class Car {
private:
	std::string _brand;
	std::string _model;
	float _siceOfTank;
	float _maxRange;
	double _averageWastage;
	float _currentFluidLevel;
	float _mileage;
	bool _ecomodus;

public:
	Car(std::string _brand, std::string _model, float _siceOfTank, double _averageWastage, float _maxRange);
	void drive(float distance);
	void refuel(float amount);
	void print();
};