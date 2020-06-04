#include <bits/stdc++.h>

#include "../inc/menu.h" 
using namespace std;


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
	cout << "8. Ustaw typ kolumny\n";
}

bool run(Tablica& tab){

	showMenu();
	cout << "wcisnij klawisz: ";
	char wybor;
	cin >> wybor;

    switch(wybor){
		// Odpowiednie przyciski do wyboru danej opcji.
		case '0':
			cout << "Dziekujemy za skorzystanie z programu. Zapraszamy do kupna wersji pro!\n";
			return 0;
		case '1': {
			int n, m;
            cout << "Podaj ilosc wierszy" << endl;
            cin >> n;
            cout << "Podaj ilosc kolumn" << endl;
            cin >> m;
			tab.tworze_tablice(n, m);
			break;
		}
        case '2': {
			cout << "Podaj nowe rozmiary tablicy: ";
			int newN, newM;
			cin >> newN >> newM;
			tab.zmien_rozmiar(newN, newM);
			break;
		}
        case '3':
			tab.aktualizacja_tablicy();
			break;
        case '4':
			tab.wyswietl_tablice();
			break;
        case '5':
			tab.wczytaj_tablice();
			break;
        case '6':
			tab.zapisz_plik();
			break;
		case '7': {
			int minValue, maxValue;
			double avValue;
			if (!tab.znajdz_statystyki(minValue, maxValue, avValue)){
				cout << "tablica pusta!" << endl;
				break;
			}
			cout << "min: " << minValue << ", max: " << maxValue << ", average: " << avValue << endl;
			break;
		}
		case '8': { 
			cout << "Podaj numer kolumny: ";
			int j;
			cin >> j;
			cout << "Podaj typ kolumny: ";
			string s;
			cin >> s;
			tab.ustaw_typ_kolumny(j, s);
			break;
		}
		case '9':
			cout << "Wyswietl typy kolumn\n";
			tab.wyswietl_typy();
		default:
			cout << "Wpisano nieprawidlowy przycisk!\n";
			break;
	}
	return 1;
}