#include "konsolenausgabe.h"
#include <iostream>

void aufrufDrucken(std::string funktionsname, unsigned long eingabe) {
	std::cout << funktionsname << "(" << eingabe << ") wurde aufgerufen" << std::endl;
}

void aufrufDrucken(std::string funktionsname, unsigned long m, unsigned long n) {
	std::cout << funktionsname << "(" << m << ", " << n << ") wurde aufgerufen" << std::endl;
}

void rueckgabeDrucken(std::string funktionsname, unsigned long eingabe, unsigned long ergebnis) {
	std::cout << funktionsname << "(" << eingabe << ") gibt zurueck: " << ergebnis << std::endl;
}

void rueckgabeDrucken(std::string funktionsname, unsigned long m, unsigned long n, unsigned long ergebnis) {
	std::cout << funktionsname << "(" << m << ", " << n << ") gibt zurueck: " << ergebnis << std::endl;
}