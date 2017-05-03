/*************************************************************************
*
* Daniel Bitzer
* d@bitzer.io
* https://bitzer.io
* __________________
* Car.cpp
* [2017]
*
*
*/

#include "Car.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip> 

Car::Car(std::string brand, std::string model, float siceOfTank, double averageWastage, float maxRange) {
	_brand = brand;
	_model = model;
	_siceOfTank = siceOfTank;
	_averageWastage = averageWastage;
	_maxRange = maxRange;

	// Auto bei Auslieferung 0 Kilometer und 0 liter Tankinhalt
	_mileage = 0;
	_currentFluidLevel = 0;
	_ecomodus = false;
};

void Car::drive(float distance) {
	if (distance <= 0)
		std::cout << "Bitte geben Sie ein positiven Wert ein!" << std::endl;
	else if (_currentFluidLevel == 0)
		std::cout << "Der Tank ist leer, Sie muessen das Auto erst tanken!" << std::endl;
	// Wenn der Füllstand des Tanks nicht für die Distanz ausreichen sollte
	else if ((_averageWastage * distance / 100) > _currentFluidLevel) {
		std::cout << "Das Benzin des Autos reicht fuer die angeforderte Strecke nicht aus." << std::endl;
		std::cout << "Moechten Sie mit dem Eco-Modus fahren?" << std::endl;

		int choiceMenu;
		bool menuOn = true;

		// While Schleife für Menu
		while (menuOn != false) {
			std::cout << "*******************************\n";
			std::cout << " 1 - Yes.\n";
			std::cout << " 2 - No.\n";
			std::cout << " 3 - Exit.\n";
			std::cout << " Enter your choice and press return: ";

			std::cin >> choiceMenu;

			switch (choiceMenu)
			{
			case 1:
				std::cout << "\n";
				_ecomodus = true;
				std::cout << "ECO-Modus aktiviert." << std::endl;
				menuOn = false;
				break;
			case 2:
				std::cout << "\n";
				_ecomodus = false;
				std::cout << "ECO-Modus deaktiviert." << std::endl;
				menuOn = false;
				break;
			case 3:
				std::cout << "End of Program.\n";
				menuOn = false;
				break;
			default:
				std::cout << "Not a Valid Choice. \n";
				std::cout << "Choose again.\n";
				std::cin >> choiceMenu;
				break;
			}
		}
		// Wenn ECO-Modus eingeschaltet wurde
		if (_ecomodus)
		{
			// Temporäre Variable zum abziehen von 2 Liter pro 100km
			float averageWastagetemp = _averageWastage - 2.00;
			// Überprüfe erneut mit Eco-Modus ob das Benzin reicht
			if ((averageWastagetemp * distance / 100) > _currentFluidLevel)
				std::cout << "Das Benzin des Autos reicht auch im ECO-Modus nicht fuer die angeforderte Strecke nicht aus." << std::endl;
			else {
				_currentFluidLevel -= averageWastagetemp * distance / 100;
				_mileage = distance;
				std::cout << "Kilometerstand vorher:  " << _mileage - distance << std::endl;
				std::cout << "Gefahrene Kilometer: " << distance << std::endl;
				std::cout << "Neuer Kilometerstand: " << _mileage << std::endl;
				std::cout << "Aktueller Tankfuellstand: " << _currentFluidLevel << std::endl;
				// Eco-Modus wieder deaktivieren
				_ecomodus = false;
				std::cout << "ECO-Modus wieder deaktiviert." << std::endl;
			}
		}
	}
	else {
		_currentFluidLevel -= _averageWastage * distance / 100;
		_mileage = distance;
		std::cout << "Kilometerstand vorher:  " << _mileage - distance << std::endl;
		std::cout << "Gefahrene Kilometer: " << distance << std::endl;
		std::cout << "Neuer Kilometerstand: " << _mileage << std::endl;
		std::cout << "Neuer Tankfuellstand: " << _currentFluidLevel << std::endl;
	}
};

void Car::refuel(float amount) {
	if (amount <= 0)
	{
		std::cout << std::fixed << std::setprecision(2) << "Sie koennen dem Tank kein Benzin entnehmen. Aktueller Fuellstand: " << _currentFluidLevel << " Liter " << std::endl;
	}
	else if (_currentFluidLevel == _siceOfTank) {
		std::cout << "Der Tank ist schon voll!" << std::endl;
	}
	else if (amount > _siceOfTank) {
		_currentFluidLevel = _siceOfTank;
		std::cout << std::fixed << std::setprecision(2) << "Maximale Tankgroesse erreicht! Fuellstand: " << _siceOfTank << " Liter" << std::endl;
		std::cout << "Es ist: " << amount - _siceOfTank << " Liter Benzin daneben gelaufen" << std::endl;
		std::cout << "Die Rechnung der Putzarbeiten wird Ihnen per Post zugesendet" << std::endl;
		std::cout << "Auto wurde mit " << amount << " Liter getankt." << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "Aktueller Fuellstand nach dem Tanken: " << _currentFluidLevel << " Liter " << std::endl;
	}
	else {
		_currentFluidLevel += amount;
		std::cout << "Auto wurde mit " << amount << " Liter getankt." << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "Aktueller Fuellstand nach dem Tanken: " << _currentFluidLevel << " Liter " << std::endl;
	}
};

void Car::print() {
	std::cout << "Automarke: " << _brand << std::endl;
	std::cout << "Automodell: " << _model << std::endl;
	std::cout << "Tankgroesse: " << _siceOfTank << std::endl;
	std::cout << "Aktueller Fuellstand: " << _currentFluidLevel << std::endl;
	std::cout << "Durchschnittsverbrauch (kombiniert): " << _averageWastage << std::endl;
	std::cout << "Maximale Reichweite: " << _maxRange << std::endl;
	std::cout << "Kilometerstand: " << _mileage << std::endl;
	std::cout << "ECO-Modus: " << std::boolalpha << _ecomodus << std::endl;
};