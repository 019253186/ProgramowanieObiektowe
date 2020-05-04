#include <iostream>

using namespace std;








void menu(void ){  // Moje menu






    cout << endl <<"MENU" << endl;

    cout << "1. Stworz nowa tabele  " << endl <<"2. Zmien rozmiar istniejacej tabeli" << endl <<
			"3. Aktualizuj istniejacych wierszy i kolumn " << endl << "4.Wyswietl tablice "<<endl

			 <<endl<< "5.Wczytaj plik"<<"6.Zapisz plik "<< endl<<endl;









}

bool run(void) {

	 int** arr = nullptr;
	 int n = 0, m = 0;
	char wybor;

	menu();

	cout << "przycisnij klawisz : "<<endl;
	cin >> wybor;


    switch(wybor) {
      {
                                                // Odpowiednie przyciski do wyboru danej opcji.
		case '1':
            cout<<"Podaj ilosc wierszy"<<endl;
            cin>>n
            cout<<"Podaj ilosc kolumn"<<endl;
            cin>>m;
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
        }
        default:
                return 0;
                }
                return 1;
                }
