#include "ArrayFunktionen.h"
#include <iostream>
#include <ctime>

using namespace std;

void arrayAusgeben(int meinArray[], int arrayGroesse) {

    for (int i = 0; i < arrayGroesse; i++) {
        cout << "Array[" << i << "] = " << meinArray[i] << endl;
    }

}

void arrayMitZufallszahlenFuellen(int meinArray[], int arrayGroesse, int moduloZahl) {

	// Seed fuer die rand()-Funktion festlegen
	srand((unsigned)time(NULL));

    for (int index = 0; index < arrayGroesse; index++) {

        int zufallszahl;

        // Wenn moduloZahl == 0 ist, Array mit random Zahlen fuellen
        // Wir nutzen moduloZahl = 1000 damit die Wahrscheinlichkeit fuer doppelte Werte erhoeht ist 
        // relevant fuer die letzte Aufgabe mit haeufigkeitenBestimmen
        if (moduloZahl == 0) {
            zufallszahl = rand();
        }
        else {
            zufallszahl = rand() % moduloZahl;
        }

        meinArray[index] = zufallszahl;
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
    // Wenn die Anzahl der Stellen gerade ist, dann ist der Median der durchschnitt von beiden 'mittleren Zahlen'
    // Wenn die Anzahl der Stellen ungerade ist, dann ist der Median die Zahl "in der Mitte" des Arrays

    arrayAufsteigendSortieren(meinArray, arrayGroesse);

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

    // Array fuer die Haeufigkeiten, hat 100 Stellen -> Jede Stelle hat zwei Werte: haeufigkeitenArray[0] = Zahl, haeufigkeitenArray[1] = Haeufigkeit 
    int haeufigkeitenArray[100][2];
    bool gefunden;
    int aktuelleStelleZumSchreibenImHaeufigkeitenArray = 0;

    // Komplettes haeufigkeitenArray mit -1 fuellen
    // Die Zahl -1 benutzen wir als "Marker" fuer unbeschriebene Stellen im haeufigkeitenArray (relevant bei Ausgabe des Arrays)
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 2; j++) {
            haeufigkeitenArray[i][j] = -1;
        }
    }

    // Haeufigkeiten zaehlen und in haeufigkeiten schreiben
    for (int i = 0; i < arrayGroesse; i++) {


        // Durch mein haeufigkeitenArray gehen und schauen, ob die Zahl bereits in dem haeufigkeitenArray drin ist
        gefunden = false;

        // Wenn gefunden: Haeufigkeit um 1 erhoehen
        for (int x = 0; x < 100; x++) {
            if (haeufigkeitenArray[x][0] == meinArray[i]) {
                gefunden = true;
                haeufigkeitenArray[x][1]++;
            }
        }

        // Wenn nicht gefunden: Zahl in mein haeufigkeitenArray schreiben und die Haeufigkeit von -1 auf 1 setzen
        if (!gefunden) {
            haeufigkeitenArray[aktuelleStelleZumSchreibenImHaeufigkeitenArray][0] = meinArray[i];
            haeufigkeitenArray[aktuelleStelleZumSchreibenImHaeufigkeitenArray][1] = 1;
            aktuelleStelleZumSchreibenImHaeufigkeitenArray++;
        }
    }


    // haeufigkeitenArray absteigend nach Haeufigkeiten sortieren; abgewandelter "Bubble-Sort"-Algorithmus fuer 2d-Arrays
    for (int a = 100; a > 0; a--) {
        for (int b = 0; b < a - 1; b++) {

            if (haeufigkeitenArray[b][1] < haeufigkeitenArray[b + 1][1]) {
                int zwischenspeicher[2] = {haeufigkeitenArray[b][0], haeufigkeitenArray[b][1]};
                haeufigkeitenArray[b][0] = haeufigkeitenArray[b + 1][0];
                haeufigkeitenArray[b][1] = haeufigkeitenArray[b + 1][1];
                haeufigkeitenArray[b + 1][0] = zwischenspeicher[0];
                haeufigkeitenArray[b + 1][1] = zwischenspeicher[1];
            }

        }
    }

    // Die ersten 5 Eintraege des haeufigkeitenArray ausgeben 
    for (int i = 0; i < 5; i++) {
        if (haeufigkeitenArray[i][0] == -1) {
            continue;
        }
        else {
            cout << "Zahl: " << haeufigkeitenArray[i][0] << "; Haeufigkeit: " << haeufigkeitenArray[i][1] << endl;
        }
    }
}
