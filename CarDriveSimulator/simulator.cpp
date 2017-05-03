/*************************************************************************
*
* Daniel Bitzer
* d@bitzer.io
* https://bitzer.io
* __________________
* simulator.cpp
* [2017]
*
*
*/

#include "stdafx.h"
#include <iostream>
#include <limits>
#include "Car.h"


// Vordeklaration der Methoden
void createNewCar(Car **cars);
void showCars(Car **cars);
void deleteCars(Car **cars);
void addDemoCars(Car **cars);
void refuelCar(Car **cars);
void driveCar(Car **cars);


// Globale Variablen
int MAXANZAHL = 0;
int CARCOUNTER = 0;

int choiceMenu;
bool menuOn = true;

int main()
{
	// Abfrage für reservierten Speicher
	std::cout << "Bitte geben Sie die gewuenschte Anzahl Autos ein: " << std::endl;
	std::cin >> MAXANZAHL;
	// Array mit Objekten erstellen
	std::cout << "Es wurden " << MAXANZAHL << " Autos im Speicher reserviert" << std::endl;


	// Array wird anhand der Anzahl erstellt und speicher reserviert
	Car **CarArray = new Car*[MAXANZAHL]; // where n is number of arrays to create

	// While Schleife für Menu
	while (menuOn != false) {
		std::cout << "*******************************\n";
		std::cout << " 1 - Add Car.\n";
		std::cout << " 2 - Add Demo Cars.\n";
		std::cout << " 3 - Show Cars.\n";
		std::cout << " 4 - Delete Car.\n";
		std::cout << " 5 - Refuel Car.\n";
		std::cout << " 6 - Drive Car.\n";
		std::cout << " 7 - Exit.\n";
		std::cout << " Enter your choice and press return: ";

		std::cin >> choiceMenu;

		switch (choiceMenu)
		{
		case 1:
			std::cout << "\n";
			// Aufruf der Methode createNewCar
			createNewCar(CarArray);
			break;
		case 2:
			std::cout << "\n";
			// Aufruf der Methode addDemoCars
			addDemoCars(CarArray);
			break;
		case 3:
			std::cout << "\n";
			// Aufruf der Methode showCars
			showCars(CarArray);
			break;
		case 4:
			std::cout << "\n";
			// Aufruf der Methode deleteCars
			deleteCars(CarArray);
			break;
		case 5:
			// Aufruf der Methode showCars für Auswahlanzeige
			showCars(CarArray);
			refuelCar(CarArray);
			//CarArray[1]->refuel(10);
			break;
		case 6:
			// Aufruf der Methode showCars für Auswahlanzeige
			showCars(CarArray);
			driveCar(CarArray);
			//CarArray[1]->drive(10);
			break;
		case 7:
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
	return 0;
}


// Methode zum erstellen eines neuen Autos
void createNewCar(Car **cars) {
	// Fehlerüberprüfung für Speicher
	if (CARCOUNTER < MAXANZAHL)
	{
		std::string brand;
		std::string model;
		float siceOfTank;
		double averageWastage;
		float maxRange;

		std::cout << "Bitte geben Sie die Automarke an:" << std::endl;
		std::cin >> brand;
		std::cout << "Input is: " << brand << std::endl;
		std::cout << "Bitte geben Sie das Modell an:" << std::endl;
		std::cin >> model;
		std::cout << "Input is: " << model << std::endl;
		std::cout << "Bitte geben Sie die Tankgroesse an:" << std::endl;
		//std::cin >> siceOfTank;
		while (!(std::cin >> siceOfTank))
		{
			std::cout << "A number must be entered" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Input is: " << siceOfTank << " Liter." << std::endl;
		std::cout << "Bitte geben Sie den durchschnittsverbrauach an:" << std::endl;
		//std::cin >> averageWastage;
		while (!(std::cin >> averageWastage))
		{
			std::cout << "A number must be entered" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Input is: " << averageWastage << " Liter pro 100km." << std::endl;
		std::cout << "Bitte geben Sie die maximale Reichweite an:" << std::endl;
		//std::cin >> maxRange;
		while (!(std::cin >> maxRange))
		{
			std::cout << "A number must be entered" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Input is: " << maxRange << " km." << std::endl;

		cars[CARCOUNTER] = new Car(brand, model, siceOfTank, averageWastage, maxRange);
		CARCOUNTER++;
	}
	else {
		std::cout << "Es steht kein Speicherplatz mehr zur Verfuegung!" << std::endl;
	}
};


// Methode zum Anzeigen aller Autos im Speicher
void showCars(Car **cars) {
	// Fehlerübrprüfung für Speicher
	if (CARCOUNTER == 0)
	{
		std::cout << "Keine Autos vorhanden!" << std::endl;
	}
	else {
		std::cout << "Aktive Autos:" << std::endl;
		std::cout << "----------------------------" << std::endl;
		for (int i = 0; i < CARCOUNTER; i++) {
			std::cout << "---------Carobject-----------" << std::endl;
			std::cout << "Nummer: " << i << std::endl;
			cars[i]->print();
			std::cout << "--------/Carobject-----------" << std::endl;
		}
		std::cout << "----------------------------" << std::endl;
	}
};

// Löscht alle Autos aus dem reservierten Speicher (ANZAHL)
void deleteCars(Car **cars) {
	if (CARCOUNTER == 0)
	{
		std::cout << "Keine Autos vorhanden!" << std::endl;
	}
	else {
		for (int i = 0; i < CARCOUNTER; i++) {
			std::cout << "Auto Nummer: " << i << " wird geloescht!" << std::endl;
			delete cars[i];
			std::cout << "Auto Nummer: " << i << " wurde geloescht!" << std::endl;
		}
		std::cout << "Alle Autos wurden geloescht!" << std::endl;
		CARCOUNTER = 0;
	}
};


// Fügt dem Speicher ein Template von Autos hinzu
void addDemoCars(Car **cars) {
	if (MAXANZAHL < 6 && CARCOUNTER + 6 > MAXANZAHL)
	{
		std::cout << "\nFehler! Zu wenig Speicherplatz steht zur Verfügung.\nBitte reservieren Sie mehr Speicher.\nMinimum: 6 Autos!\n" << std::endl;
	}
	else {
		// Erstellen der Demo Cars
		cars[0] = new Car("Porsche", "Panamera 4S", 75.00, 8.20, 800.00);
		cars[1] = new Car("BMW", "125", 60.00, 7.50, 700.00);
		cars[2] = new Car("Audi", "4", 60.00, 9.00, 720.00);
		cars[3] = new Car("VW", "GTI", 55.00, 8.20, 750.00);
		cars[4] = new Car("Opel", "Astra", 50.00, 6.10, 900.00);
		cars[5] = new Car("Ford", "Mustang", 70.00, 8.00, 700.00);
		std::cout << "Demo Cars wurden erstellt!" << std::endl;
		CARCOUNTER = 6;
	}
};

// MainMethode zum tanken des Car Objektes
// Ruft Klassenmethode refuel auf
void refuelCar(Car **cars) {
	int carnumber;
	float amount;

	std::cout << "----------------------------" << std::endl;
	std::cout << "Bitte geben Sie die gewuenschte Nummer des Autos an!" << std::endl;

	// Überprüfung der Autonummer (Fehlerüberprüfung)
	while (std::cin >> carnumber) {
		if (carnumber < CARCOUNTER)
			break;
		std::cout << "Bitte ueberpruefen Sie die Autonummer!" << std::endl;
	}

	std::cout << "Wieviel Liter Benzin benoetigen Sie?\n";
	std::cin >> amount;
	cars[carnumber]->refuel(amount);
};

// MainMethode zum fahren des Car Objektes
// Ruft Klassenmethode drive auf
void driveCar(Car **cars) {
	int carnumber;
	float distance;

	std::cout << "----------------------------" << std::endl;
	std::cout << "Bitte geben Sie die gewuenschte Nummer des Autos an!" << std::endl;

	// Überprüfung der Autonummer (Fehlerüberprüfung)
	while (std::cin >> carnumber) {
		if (carnumber < CARCOUNTER)
			break;
		std::cout << "Bitte ueberpruefen Sie die Autonummer!" << std::endl;
	}

	std::cout << "Wieviel kilometer moechten Sie fahren?\n";
	std::cin >> distance;
	cars[carnumber]->drive(distance);
};