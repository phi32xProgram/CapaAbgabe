#include <iostream>
#include <string>
#include <vector>
#include "materialien.cpp"
#include "Building.cpp"
using namespace std;

int main() {
	int laenge;
	int breite;
	int menue;
	double gesamtpreis = 0;
	double preisWAK = Wasser().getGesamtPreisGebauede();
	double preisWIN = Wind().getGesamtPreisGebauede();
	double preisSOL = Solar().getGesamtPreisGebauede();
	bool laeuft = true;
	
	string art;

	cout << "Bitte geben Sie die Laenge ein: " << endl;
	cin >> breite;
	cout << "Bitte geben Sie die Breite ein: " << endl;
	cin >> laenge;

	string baubereich[laenge][breite];

	for (int i = 0; i < laenge; i++) {
		for (int j = 0; j < breite; j++) {
			baubereich[i][j] = Empty().getLabel();
		}
	}

	for (int i = 0; i < laenge; i++) {
		for (int j = 0; j < breite; j++) {
			cout << baubereich[i][j] << " ";
		}
		cout << endl;
	}

	while (runner) {
		cout << "||Menue||" << endl;
		cout << "\t 1) Gebauede setzen" << endl;

		cout << "\t 2) Bereich loeschen" << endl;

		cout << "\t 3) Ausgabe Baubereich" << endl;

		cout << "\t 4) Das Ende" << endl;

		cout << "Menuepunkt eingeben:" << endl;

		cin >> menue;
		cout << "__________________" << endl;


		switch (menue) {
		case 1:
			char eingabeArt;
			int lenGebaeude, breGebaeude, posx, posy;
			cout
				<< "Eingabe der Art, Laenge, Breite, x- u. y-Position: \n " "Moegliche Werte für Art: 'e' fuer empty, 'h' fuer wasserkraft, "
				"'w' fuer windkraft, 's' fuer solar" << endl;
			cin >> eingabeArt;
			cin >> lenGebaeude;
			cin >> breGebaeude;
			cin >> posx;
			cin >> posy;

			switch (eingabeArt) {
			case 'h':
				art = Wasser().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisWAK);
				break;

			case 'w':
				art = Wind().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisWIN);
				break;

			case 's':
				art = Solar().getLabel();
				gesamtpreis += (lenGebaeude * breGebaeude * preisSOL);
				break;

			default:
				art = Empty().getLabel();
				break;

			}

			if ((posx + lenGebaeude) > laenge
				|| (posy + breGebaeude) > breite) {
				cout
					<< "Gebaeude konnte nicht gesetzt werden. Angaben liegen ausserhalb des Baubereiches";
			}
			else {
				for (int i = posy; i < posy + lenGebaeude; i++) {

					for (int j = posx; j < posx + breGebaeude; j++) {

						if (baubereich[i][j] != "EMP") {

							cout << "Gebaeude ist bereits vorhanden" << endl;
							break;

						}
						else
							baubereich[i][j] = art;
					}
				}
			}
			break;
		case 2:
			int deletePosx, deletePosy;
			cout << "Bitte x- u. y-Koordinate des Gebaeudes eingeben" << endl;
			cin >> deletePosx;
			cin >> deletePosy;


			if (deletePosx > laenge || deletePosy > breite) {
				cout << "Gebaeude konnte nicht gelöscht werden. "
					"Angaben liegen ausserhalb des Baubereiches";
			}
			else {
				for (int i = 0; i < laenge; i++) {
					for (int j = 0; j < breite; j++) {
						if (i == deletePosy && j == deletePosx) {

							string delGebaeude = baubereich[i][j];

							if (delGebaeude == "WAK")

								gesamtpreis -= preisWAK;

							else if (delGebaeude == "WIK")

								gesamtpreis -= preisWIN;

							else
								gesamtpreis -= preisSOL;

							baubereich[i][j] = Empty().getLabel();
						}
					}
				}
			}
			break;
		case 3:
			cout << "--------Ausgabe Plan--------" << endl;
			for (int i = 0; i < breite; i++) {
				for (int j = 0; j < laenge; j++) {
					cout << "[" << baubereich[i][j] << "]";
				}
				cout << endl;
			}
			cout << "--------Ausgabe Benötigte Materialien--------" << endl;
			Wasser().printMaterialien();
			Wind().printMaterialien();
			Solar().printMaterialien();

			cout << "--------Ausgabe Einzelpreis Gebauede--------" << endl;
			cout << "Preis Wasserkraftwerk: " << preisWAK << endl;
			cout << "Preis Windkraftwerk: " << preisWIK << endl;
			cout << "Preis Solar: " << preisSOL << endl;

			cout << "--------Ausgabe Gesamtpreis--------" << endl;
			cout << "Gesamtpreis: " << gesamtpreis << "\n" << endl;
			break;
		case 4:
			laeuft = false;
			break;
		default:
			cout << "Menuepunkt nicht vorhanden!" << endl;
			break;
		}
		cin.clear();
	}

	return 0;
}
