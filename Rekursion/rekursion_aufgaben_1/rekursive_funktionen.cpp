#include "rekursive_funktionen.h"
#include "konsolenausgabe.h"
#include <iostream>

int fibonacci(int eingabe);
int quersumme(int eingabe);
int fakultaet(int eingabe);
unsigned long ggt(unsigned long m, unsigned long n);

void fakultaetVon(int eingabe) {

	int ergebnis;

	aufrufDrucken(__FUNCTION__, eingabe);	// Funktionsaufruf in der Konsole ausgeben

	ergebnis = fakultaet(eingabe);	// Startpunkt der Rekursion -> Ruft fakultaet() auf 

	rueckgabeDrucken(__FUNCTION__, eingabe, ergebnis);	// Rueckgabewert der Funktion in der Konsole ausgeben

	std::cout << std::endl;
}

int fakultaet(int eingabe) {

	int ergebnis;

	aufrufDrucken(__FUNCTION__, eingabe);

	if (eingabe == 1) {	// Wenn die Funktion mit dem Wert 1 aufgerufen wird, gebe 1 zurueck
		ergebnis = 1;	
	}
	else {	// Ansonsten multipliziere meine Eingabe mit Eingabe-1
		ergebnis = eingabe * fakultaet(eingabe - 1);	
	}

	rueckgabeDrucken(__FUNCTION__, eingabe, ergebnis);

	return ergebnis;	// Hier wird das Ergebnis an die obere Instanz zurueckgegeben!
}

void quersummeVon(int eingabe) {

	int ergebnis;	

	aufrufDrucken(__FUNCTION__, eingabe);	// Funktionsaufruf in der Konsole ausgeben

	ergebnis = quersumme(eingabe);	// Startpunkt der Rekursion -> Ruft quersumme() auf

	rueckgabeDrucken(__FUNCTION__, eingabe, ergebnis);	// Rueckgabewert der Funktion in der Konsole ausgeben

	std::cout << std::endl;
}

int quersumme(int eingabe) {

	int ergebnis;

	aufrufDrucken(__FUNCTION__, eingabe);

	if (eingabe < 10) {	// Wenn meine Eingabe < 10 ist, dann ist diese Einstellig -> gebe die Eingabe zurueck
		ergebnis = eingabe;
	}
	else {	// Ansonsten addiere die letzte Ziffer meiner Eingabe mit eingabe/10
		ergebnis = eingabe % 10 + quersumme(eingabe / 10); // -> wir 'schneiden' die letzte Ziffer der Eingabe ab (bsp: 1234/10 = 123, 123/10 = 12, 12/10 = 1)
	}

	rueckgabeDrucken(__FUNCTION__, eingabe, ergebnis);

	return ergebnis;	// Hier wird das Ergebnis an die obere Instanz zurueckgegeben!
}

void fibonacciBis(int eingabe) {

	std::cout << "Fibonacci Reihe bis " << eingabe << " = ";

	std::cout << fibonacci(1);

	for (int i = 2; i <= eingabe; i++) {

		std::cout << ", " << fibonacci(i);

	}

	std::cout << std::endl << std::endl;
}

int fibonacci(int eingabe) {

	if (eingabe <= 2) {
		return 1;
	}
	else {
		return fibonacci(eingabe - 1) + fibonacci(eingabe - 2);
	}
}

void ggtErmitteln(unsigned long m, unsigned long n) {

	int ergebnis;

	aufrufDrucken(__FUNCTION__, m, n);

	ergebnis = ggt(m, n);

	rueckgabeDrucken(__FUNCTION__, m, n, ergebnis);

	std::cout << std::endl;
}

unsigned long ggt(unsigned long m, unsigned long n) {

	int ergebnis;

	aufrufDrucken(__FUNCTION__, m, n);

	if (n == 0) {	// -> m/0 funktioniert nicht, wir haben den kleinsten ggT gefunden! (m)
		ergebnis = m;
	}
	else {	// ansonsten teile n mit m%n -> bsp: ggt(49, 28) -> ggt(28, 49%28 = 21) -> ggt(21, 28%21 = 7)
		ergebnis = ggt(n, m % n);
	}

	rueckgabeDrucken(__FUNCTION__, m, n, ergebnis);

	return ergebnis;
}

