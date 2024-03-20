#include "MenuFunktionen.h"
#include <iostream>

using namespace std;

int nachFuellmethodeFragen(int arrayGroesse) {

	int auswahl;

	system("CLS");
	cout << "==> Array fuellen <==" << endl;
	cout << "Gewaehlte Array Groesse = " << arrayGroesse << endl;
	cout << endl << "Bitte auswaehlen: " << endl;
	cout << "1) Array mit Zufallszahlen fuellen" << endl;
	cout << "2) Array per Hand fuellen" << endl;
	cout << "999) Programm beenden" << endl;
	cout << "Einagabe: ";
	cin >> auswahl;
	cout << endl;

	return auswahl;
}

int nachFunktionFragen() {

	int auswahl;

	system("CLS");

	cout << "==> Funktionen <==" << endl;
	cout << endl << "Bitte auswaehlen: " << endl;
	cout << "1) minimumBestimmen" << endl;
	cout << "2) maximumBestimmen" << endl;
	cout << "3) medianBestimmen" << endl;
	cout << "4) spannweiteBestimmen" << endl;
	cout << "5) mittlereAbweichungBestimmen" << endl;
	cout << "6) haeufigkeitenBestimmen" << endl;
	cout << "7) array ausgeben" << endl;
	cout << "8) array sortieren" << endl;
	cout << "99 neue Zahlen eingeben" << endl;
	cout << "999) beenden" << endl;
	cout << "Einagabe: ";
	cin >> auswahl;
	cout << endl;

	return auswahl;
}