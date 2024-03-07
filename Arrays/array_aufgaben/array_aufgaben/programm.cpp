#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    const int arrayGroesse = 10;

    int meinArray[arrayGroesse];
    
    // Seed fuer die rand()-Funktion festlegen
    srand((unsigned) time(NULL));

    // 1. Fuellen des Arrays mit zufaelligen Zahlen
    for (int index = 0; index < arrayGroesse; index++) {

        int zufallszahl = rand();

        meinArray[index] = zufallszahl;

        cout << "Array an Stelle = " << index << " gefuellt mit Wert = " << zufallszahl << endl;

    }

    // 2. Groesstes Element im Array finden
    // Annahme maxiumum: das erste Element im Array ist das aktuelle Maximum
    // Annahme minimum: das erste Element im Array ist das aktuelle Minimum
    int maximum = meinArray[0];
    int minimum = meinArray[0];

    for (int index = 1; index < arrayGroesse; index++) {

        if (meinArray[index] > maximum) {
            maximum = meinArray[index];
        }

        if (meinArray[index] < minimum) {
            minimum = meinArray[index];
        }

    }

    // Maximum & Minimum ausgeben
    cout << "Groesster Wert im Array: " << maximum << endl;
    cout << "Kleinster Wert im Array: " << minimum << endl;

    return 0;
}

