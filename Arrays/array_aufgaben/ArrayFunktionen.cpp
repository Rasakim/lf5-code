#include "ArrayFunktionen.h"
#include <iostream>
#include <ctime>

using namespace std;

void arrayAusgeben(int meinArray[], int arrayGroesse) {

    for (int i = 0; i < arrayGroesse; i++) {
        cout << "Array[" << i << "] = " << meinArray[i] << endl;
    }

}

void arrayMitZufallszahlenFuellen(int meinArray[], int arrayGroesse) {

	// Seed fuer die rand()-Funktion festlegen
	srand((unsigned)time(NULL));

    for (int index = 0; index < arrayGroesse; index++) {

        int zufallszahl = rand();

        meinArray[index] = zufallszahl;

        cout << "Array an Stelle = " << index << " gefuellt mit Wert = " << zufallszahl << endl;

    }
}

void arrayPerHandFuellen(int meinArray[], int arrayGroesse) {

    for (int index = 0; index < arrayGroesse; index++) {

        int eingabe;

        cout << "Wert eingeben fuer array[" << index << "] = ";
        cin >> eingabe;

        meinArray[index] = eingabe;
    }
}

int minimumBestimmen(int meinArray[], int arrayGroesse) {

    // Annahme: die erste Stelle des Arrays ist zu Beginn der kleinste Wert des Arrays
    int minimum = meinArray[0];

    for (int index = 1; index < arrayGroesse; index++) {

        if (meinArray[index] < minimum) {
            minimum = meinArray[index];
        }

    }

    return minimum;
}

int maximumBestimmen(int meinArray[], int arrayGroesse) {

    // Annahme: die erste Stelle des Arrays ist zu Beginn der groesste Wert des Arrays
    int maximum = meinArray[0];

    for (int index = 1; index < arrayGroesse; index++) {

        if (meinArray[index] > maximum) {
            maximum = meinArray[index];
        }

    }

    return maximum;
}

void arrayAufsteigendSortieren(int meinArray[], int arrayGroesse) {
    
    // Verwendung des "Bubble-Sort"-Algorithmus
    for (int a = arrayGroesse; a > 0; a--) {
        for (int b = 0; b < a - 1; b++) {

            if (meinArray[b] > meinArray[b + 1]) {
                int zwischenspeicher = meinArray[b];
                meinArray[b] = meinArray[b + 1];
                meinArray[b + 1] = zwischenspeicher;
            }

        }
    }
}

int medianBestimmen(int meinArray[], int arrayGroesse) {

    int median = 0;

    // Vorraussetzung: Array ist sortiert
    arrayAufsteigendSortieren(meinArray, arrayGroesse);

    // Wenn die Anzahl der Stellen gerade ist, dann ist der Median der durchschnitt von beiden 'mittleren Zahlen'
    if (arrayGroesse % 2 == 0) {
        int zahlMitteLinks = meinArray[(arrayGroesse / 2) - 1];
        int zahlMitteRechts = meinArray[(arrayGroesse / 2)];

        median = (zahlMitteLinks + zahlMitteRechts) / 2;
    }
    else {
        median = meinArray[(arrayGroesse / 2)];
    }

    return median;
}

int spannweiteBestimmen(int meinArray[], int arrayGroesse) {

    int maximum = maximumBestimmen(meinArray, arrayGroesse);
    int minimum = minimumBestimmen(meinArray, arrayGroesse);

    int spannweite = maximum - minimum;

    return spannweite;

}

int mittlereAbweichungBestimmen(int meinArray[], int arrayGroesse) {

    int mittelwert = 0;
    int mittlereAbweichung = 0;

    // 1. Alles Zahlen des Arrays zusammenrechnen
    for (int i = 0; i < arrayGroesse; i++) {
        mittelwert += meinArray[i];
    }

    // 2. Zusammengerechnete Zahl durch Anzahl Zahlen dividieren
    mittelwert = mittelwert / arrayGroesse;
    cout << "Mittelwert: " << mittelwert << endl;

    // 3. Mittelwert von den Zahlen innerhalb des Arrays abziehen
    // und den Betrag auf mittlereAbweichung draufrechnen
    for (int i = 0; i < arrayGroesse; i++) {
        meinArray[i] = meinArray[i] - mittelwert;

        // Wenn die Zahl im Array danach < 0 ist, mit -1 multiplizieren (wir brauchen der positiven Betrag) 
        if (meinArray[i] < 0) {
            meinArray[i] = meinArray[i] * (-1);
        }

        mittlereAbweichung += meinArray[i];
    }

    // 4. mittlereAbweichung durch Anzahl Zahlen dividieren und ausgeben
    mittlereAbweichung = mittlereAbweichung / arrayGroesse;

    return mittlereAbweichung;

}

void haeufigkeitenBestimmen(int meinArray[], int arrayGroesse) {

/*

ich hab kein bock mehr
nix funktioniert 

*/

}
