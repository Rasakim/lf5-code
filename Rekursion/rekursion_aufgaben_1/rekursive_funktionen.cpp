#include "rekursive_funktionen.h"
#include "konsolenausgabe.h"
#include <iostream>

int fibonacci(int eingabe);
int quersumme(int eingabe);
int fakultaet(int eingabe);
unsigned long ggt(unsigned long m, unsigned long n);

void fakultaetVon(int eingabe) {

	int ergebnis;

	aufrufAusgabe(__FUNCTION__, eingabe);

	ergebnis = fakultaet(eingabe);

	rueckgabeAusgabe(__FUNCTION__, eingabe, ergebnis);

	std::cout << std::endl;
}

int fakultaet(int eingabe) {

	int ergebnis;

	aufrufAusgabe(__FUNCTION__, eingabe);

	if (eingabe == 1) {
		ergebnis = 1;
	}
	else {
		ergebnis = eingabe * fakultaet(eingabe - 1);
	}

	rueckgabeAusgabe(__FUNCTION__, eingabe, ergebnis);

	return ergebnis;
}

void quersummeVon(int eingabe) {

	int ergebnis;

	aufrufAusgabe(__FUNCTION__, eingabe);

	ergebnis = quersumme(eingabe);

	rueckgabeAusgabe(__FUNCTION__, eingabe, ergebnis);

	std::cout << std::endl;
}

int quersumme(int eingabe) {

	int ergebnis;

	aufrufAusgabe(__FUNCTION__, eingabe);

	if (eingabe < 10) {
		ergebnis = eingabe;
	}
	else {
		ergebnis = eingabe % 10 + quersumme(eingabe / 10);
	}

	rueckgabeAusgabe(__FUNCTION__, eingabe, ergebnis);

	return ergebnis;
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

	aufrufAusgabe(__FUNCTION__, m, n);

	ergebnis = ggt(m, n);

	rueckgabeAusgabe(__FUNCTION__, m, n, ergebnis);

	std::cout << std::endl;
}

unsigned long ggt(unsigned long m, unsigned long n) {

	int ergebnis;

	aufrufAusgabe(__FUNCTION__, m, n);

	if (n == 0) {
		ergebnis = m;
	}
	else {
		ergebnis = ggt(n, m % n);
	}

	rueckgabeAusgabe(__FUNCTION__, m, n, ergebnis);

	return ergebnis;
}

