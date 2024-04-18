#include "ArrayFunktionen.h"
#include "MenuFunktionen.h"
#include <iostream>

using namespace std;

int main() {

	const int arrayGroesse = 10;
	const int moduloZahl = 1000;
	int meinArray[arrayGroesse];

	int auswahl;
	bool laeuftFuellMenu = true;

	while (laeuftFuellMenu) {

		auswahl = nachFuellmethodeFragen(arrayGroesse, moduloZahl);

		switch (auswahl) {
		case 1:
			arrayMitZufallszahlenFuellen(meinArray, arrayGroesse, moduloZahl);
			break;
		case 2:
			arrayPerHandFuellen(meinArray, arrayGroesse);
			break;
		case 999:
			return 0;
			break;
		default:
			cout << "Inkorrekte Eingabe" << endl;
			break;
		}


		bool laeuftFunktionsMenu = true;

		while (laeuftFunktionsMenu) {

			auswahl = nachFunktionFragen();

			switch (auswahl) {
			case 1:
				cout << "Minimum: " << minimumBestimmen(meinArray, arrayGroesse) << endl;
				break;
			case 2:
				cout << "Maximum: " << maximumBestimmen(meinArray, arrayGroesse) << endl;
				break;
			case 3:
				cout << "Median: " << medianBestimmen(meinArray, arrayGroesse) << endl;
				break;
			case 4:
				cout << "Spannweite: " << spannweiteBestimmen(meinArray, arrayGroesse) << endl;
				break;
			case 5:
				cout << "Mittlere Abweichung: " << mittlereAbweichungBestimmen(meinArray, arrayGroesse) << endl;
				break;
			case 6:
				haeufigkeitenBestimmen(meinArray, arrayGroesse);
				break;
			case 7:
				arrayAufsteigendSortieren(meinArray, arrayGroesse);
				arrayAusgeben(meinArray, arrayGroesse);
				break;
			case 8:
				arrayAusgeben(meinArray, arrayGroesse);
				break;
			case 99:
				laeuftFunktionsMenu = false;
				break;
			case 999:
				return 0;
			default:
				cout << "Inkorrekte Eingabe" << endl;
				break;
			}

			system("PAUSE");

		}
	}
}

