#include <bits/stdc++.h>
#include "tablica.h"
#include "struktura.h"
using namespace std;



void tworze_tablice(Tablica& tab, int n, int m){  // Tutaj tworze pierwszy raz tablice
	tab.arr = new int*[n];
	for (int i = 0; i < n; i ++)
        tab.arr[i] = new int[m];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            arr[i][j] = 0;
    tab.n = n;
    tab.m = m;
}


void aktualizacja_tablicy(Tablica& tab){ 
    int w, k, x;
    cout << "Podaj wierz i kolumne komorki ktora chcesz zakturalizowac: ";
    cin >> w >> k;
    cout << "Podaj wartosc tej komorki: ";
    cin >> x;

    if (w > tab.n || k > tab.m)	
        cout << "ERROR-Wejscie poza rozmiar tablicy" << endl;
    else 
        tab.arr[w][k] = x;
}


void zmien_rozmiar(Tablica& tab, int new_wiersz, int new_kolumna){   // Zmieniam rozmiar tablicy
    int** arrBuf = new int*[new_wiersz];
    for (int i = 0; i < new_wiersz; i ++)
        arrBuf[i] = new int[new_kolumna];
    
    for (int i = 0; i < new_wiersz; i ++)
        for (int j = 0; j < new_kolumna; j ++)
            if (i < n && j < m)
                arrBuf[i][j] = tab.arr[i][j];
    tab.arr = arrBuf;
    tab.n = new_wiersz;
    tab.m = new_kolumna;
}


void wczytaj_tablice(Tablica& tab){  // Wczytuje tablice z pliku
    fstream plik;
    plik.open("tabx.txt", ios::in);

    if (!plik.good()){
        cout << "nie udalo sie otworzyc tablicy\n";
        exit(0);
    }

    for (int i = 0; i < tab.n; i ++)
        for (int j = 0; j < tab.m; j ++) 
            plik >> tab.arr[i][j];
    plik.close();
}


void zapisz_plik(Tablica& tab){  // Zapisuje tablice do pliku
    fstream plik;
    plik.open("tabx.txt", ios::out);
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++)
            plik << arr[i][j] << " ";
        cout << endl;
    }
    plik.close();
}



void wyswietl_sumy_kolumn(Tablica &tab){
    cout << "sumy kolumn: ";
    for (int j = 0; j < tab.m; j ++){
        int sum = 0;
        for (int i = 0; i < tab.n; i ++)
            sum += tab[i][j];
        cout << sum << endl;
    }
}


void wyswietl_sumy_wierszy(Tablica &tab){
    cout << "sumy wierszy: ";
    for (int i = 0; i < tab.n; i ++){
        int sum = 0;
        for (int j = 0; j < tab.m; j ++)
            sum += tab.arr[i][j];
        cout << sum << " ";
    }
    cout << endl;
}

void znajdz_statystyki(Tablica &tab){
    if (tab.n <= 0 || tab.m <= 0){
        cout << "tablica pusta!" << endl;
        return;
    }
    int maxValue = tab.arr[0][0], minValue = tab.arr[0][0];
    double avValue = 0.0; 

    for (int i = 0; i < tab.n; i ++)
        for (int j = 0; j < tab.m; j ++){
            maxValue = max(maxValue, tab.arr[i][j]);
            minValue = min(minValue, tab.arr[i][j]);
            avValue += tab.arr[i][j]
        }
    avValue /= tab.n * tab.m;
    cout << "min: " << minValue << ", max: " << maxValue << ", average: " << avValue << endl;
}






