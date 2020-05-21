#include <bits/stdc++.h>
#include "tablica_wysw.h"
#include "tablica.h"
#include "menu.h" 
using namespace std;

Tablica tab;

void showMenu(){  // Moje menu
    cout << "\nMENU\n";
	cout << "0. Wyjdz z programu.\n";
    cout << "1. Stworz nowa tabele.\n";
    cout << "2. Zmien rozmiar istniejacej tabeli.\n";
    cout << "3. Aktualizuj istniejacych wierszy i kolumn.\n";
    cout << "4. Wyswietl tablice.\n"; 
	cout << "5. Wczytaj plik.\n";
	cout << "6. Zapisz plik.\n";
	cout << "7. Znajdz statystyki\n";
}

bool run(){

	showMenu();
	cout << "wcisnij klawisz: ";
	char wybor;
	cin >> wybor;

    switch(wybor){
		// Odpowiednie przyciski do wyboru danej opcji.
		case '0':
			cout << "Dziekujemy za skorzystanie z programu. Zapraszamy do kupna wersji pro!\n";
			return 0;
		case '1':
			int n, m;
            cout << "Podaj ilosc wierszy" << endl;
            cin >> n;
            cout << "Podaj ilosc kolumn" << endl;
            cin >> m;
			tworze_tablice(tab, n, m);
			break;
        case '2':
			cout << "Podaj nowe rozmiary tablicy: ";
			int newN, newM;
			cin >> newN >> newM;
			zmien_rozmiar(tab, newN, newM);
			break;
        case '3':
			aktualizacja_tablicy(tab);
			break;
        case '4':
			wyswietl_tablice(tab);
			break;
        case '5':
			wczytaj_tablice(tab);
			break;
        case '6':
			zapisz_plik(tab);
			break;
		case '7':
			int minValue, maxValue;
			double avValue;
			if (!znajdz_statystyki(tab, minValue, maxValue, avValue)){
				cout << "tablica pusta!" << endl;
				break;
			}
			cout << "min: " << minValue << ", max: " << maxValue << ", average: " << avValue << endl;
			break;
		default:
			cout << "Wpisano nieprawidlowy przycisk!\n";
			break;
	}
	return 1;
}
