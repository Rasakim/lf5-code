#include "MenuFunktionen.h"
#include <iostream>

using namespace std;

int nachFuellmethodeFragen(int arrayGroesse, int moduloZahl) {

	int auswahl;

	system("CLS");

	cout << "==> Array fuellen <==" << endl << endl;

	cout << "Gewaehlte Array Groesse = " << arrayGroesse << endl;
	cout << "Modulo Zahl = " << moduloZahl << endl << endl;

	cout << "Bitte auswaehlen: " << endl << endl;

	cout << "1) Array mit Zufallszahlen fuellen" << endl;
	cout << "2) Array per Hand fuellen" << endl << endl;

	cout << "999) Programm beenden" << endl << endl;

	cout << "Einagabe: ";
	cin >> auswahl;
	cout << endl;

	return auswahl;
}

int nachFunktionFragen() {

	int auswahl;

	system("CLS");

	cout << "==> Funktionen <==" << endl << endl;

	cout << "Bitte auswaehlen: " << endl << endl;

	cout << "1) Minimum bestimmen" << endl;
	cout << "2) Maximum bestimmen" << endl;
	cout << "3) Median bestimmen" << endl;
	cout << "4) spannweite bestimmen" << endl;
	cout << "5) MittlereAbweichung bestimmen" << endl;
	cout << "6) Haeufigkeiten bestimmen" << endl;
	cout << "7) Array sortieren" << endl;
	cout << "8) Array ausgeben" << endl << endl;

	cout << "99) Neue Zahlen eingeben" << endl;
	cout << "999) Programm beenden" << endl << endl;

	cout << "Einagabe: ";
	cin >> auswahl;
	cout << endl;

	return auswahl;
}