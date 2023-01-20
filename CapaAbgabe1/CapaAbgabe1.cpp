// CapacityProject.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;
int main()
{
	int x;
	int y;
	int nummer;
	bool laeuft = true;

	enum FieldStatus { empty, solar, wind, wasser };
	FieldStatus gebaeudeart;

	cout << "Geben Sie die Breite ein!" << endl;
	cin >> x;
	cout << "Geben Sie die Laenge ein!" << endl;
	cin >> y;

	FieldStatus baubereich[x][y];	// veraltete c++ compiler version, 10 als default, eigtl muss hier x und y aus der Eingabe stehen

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			baubereich[i][j] = empty;
		}
	}
	//Anzeigemenü  ############################################
	//Schleifenaufruf des Menues bis abbruchbedingung
	while (laeuft) {
		//Menue
		cout << "      // Menue // \n" << endl;
		cout << "|| 1.Gebaeude setzen.    ||\n" << endl;
		cout << "|| 2.Bereich loeschen.   ||\n" << endl;
		cout << "|| 3.Ausgabe Baubereich. ||\n" << endl;
		cout << "|| 4.End.                ||\n" << endl;
		cout << "Nummer Eingeben!:" << endl;
		cin >> nummer;
		cout << "________________________" << endl;
		//#########################################################
		//Menuelogik
		switch (nummer) {
		case 1:
			char eingabeArt;
			FieldStatus art;
			int lengthg, widthg, posx, posy;
			cout << "Bitte geben Sie Art, Laenge, Breite und die x und y Position ihres Gebaeudes an! \n Entweder 'w' fuer Wind, 'e' fuer empty, 's' fuer solar oder 'a fuer wasser'" << endl;
			cin >> eingabeArt; cin >> lengthg; cin >> widthg; cin >> posx; cin >> posy;
			switch (eingabe) {
			case 'a':
				art = FieldStatus::wasser;
				break;
			case 'w':
				art = FieldStatus::wind;
				break;
			case 's':
				art = FieldStatus::solar;
				break;
			default:
				art = FieldStatus::empty;
				break;
			}
			//eintragen
			if ((posx + lengthg) > x || (posy + widthg > y)) {
				cout << "Gebäude wäre außerhalb des Bereichs" << endl;
			}
			else {
				for (int i = posx; i < posx + lengthg; i++) {
					for (int j = posy; j < posy + widthg; j++) {
						if (baubereich[i][j] == 1) {
							cout << "Hier steht schon ein Gebäude" << endl;
							break;
						}
						else {
							baubereich[i][j] = art;
						}
					}
				}
			}
			break;
		case 2:
			//loeschen
			int dposx, dposy;
			cout << "Bitte geben Sie) die x und y Position ihres Gebaeudes an!";
			cin >> dposx; cin >> dposy;
			if (dposx > y || dposy > y) {
				cout << "Gebaeude konnte nicht gelöscht werden. "
					"Angaben liegen ausserhalb des Baubereiches";
			}
			else {
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						if (i == dposx && j == dposy) {
							baubereich[i][j] = FieldStatus::empty;
						}
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < x; i++) {
				cout << endl;
				for (int j = 0; j < y; j++) {
					cout << "[" << baubereich[i][j] << "]";
				}
			}cout << endl;
			break;
		case 4:
			laeuft = false;
			break;
		default:
			cout << "Gibts nich!" << endl;
			break;
		}cin.clear();
	}
	return 0;
}