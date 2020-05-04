#include <iostream>


using namespace std;


void menu_start(void){


    cout<<" Stworz rozmiar tablicy , podaj ilosc kolumn a nastepnie wierszy"<<endl;


}





void menu(){






    cout << endl <<"MENU" << endl;

    cout << "1. Stworz nowa tabele  " << endl <<"2. Zmien rozmiar istniejacej tabeli" << endl <<
			"3. Aktualizuj istniejacych wierszy i kolumn " << endl << "4.Wyswietl tablice "<<endl

			<< "5.Wczytaj plik"<<"6.Zapisz plik "<< endl<<endl;









}

bool run(void) {
	// TO DELETE
	static int **arr = nullptr;
	static int n = 0, m = 0;
	char wybor;



    menu();

    cin >> wybor;


    switch(wybor) {
		case '1':
                tworze_tablice(arr, n, m);

                break;


        case '2':
                zmien_rozmiar(arr,n,m)
                break;

        case '3':
                aktualizacja_tablicy(arr, n, m);
                break;

        case '4':
                wyswietl_tablice(arr,n,m)
                break;


        case '5':
               wczytaj_talbice(arr,n,m)
               break;
        case '6':
                zapisz_plik(arr,n,m)
                break;

