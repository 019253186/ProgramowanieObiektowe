#include <bits/stdc++.h>
#include "tablica_wysw.h"
#include "tablica.h"
#include "menu.h" 
using namespace std;

int** arr;
int n, m;

void showMenu(){  // Moje menu
    cout << "\nMENU\n";
	cout << "0. Wyjdz z programu.\n";
    cout << "1. Stworz nowa tabele.\n";
    cout << "2. Zmien rozmiar istniejacej tabeli.\n";
    cout << "3. Aktualizuj istniejacych wierszy i kolumn.\n";
    cout << "4. Wyswietl tablice.\n"; 
	cout << "5. Wczytaj plik.\n";
	cout << "6. Zapisz plik.\n";
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
            cout << "Podaj ilosc wierszy" << endl;
            cin >> n;
            cout << "Podaj ilosc kolumn" << endl;
            cin >> m;
			arr = tworze_tablice(n, m);
			break;
        case '2':
			cout << "Podaj nowe rozmiary tablicy: ";
			int newN, newM;
			cin >> newN >> newM;
			zmien_rozmiar(arr, n, m, newN, newM);
			break;
        case '3':
			aktualizacja_tablicy(arr, n, m);
			break;
        case '4':
			wyswietl_tablice(arr, n, m);
			break;
        case '5':
			wczytaj_tablice(arr, n, m);
			break;
        case '6':
			zapisz_plik(arr, n, m);
			break;
		default:
			cout << "Wpisano nieprawidlowy przycisk!\n";
			break;
	}
	return 1;
}
