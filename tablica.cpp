#include <bits/stdc++.h>
#include "tablica.h"
using namespace std;

int** tworze_tablice(int n, int m){  // Tutaj tworze pierwszy raz tablice
	int** arr = new int*[n];
	for (int i = 0; i < n; i ++)
        arr[i] = new int[m];
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            arr[i][j] = 0;
    return arr;
}


void aktualizacja_tablicy(int **arr, int n, int m){ 
    int w, k, x;
    cout << "Podaj wierz i kolumne komorki ktora chcesz zakturalizowac: ";
    cin >> w >> k;
    cout << "Podaj wartosc tej komorki: ";
    cin >> x;

    if (w > n || k > m)	
        cout << "ERROR-Wejscie poza rozmiar tablicy" << endl;
    else 
        arr[w][k] = x;
}


void zmien_rozmiar(int **arr, int& n, int& m, int new_wiersz, int new_kolumna){   // Zmieniam rozmiar tablicy
    int** arrBuf = tworze_tablice(new_wiersz, new_kolumna);
    for (int i = 0; i < new_wiersz; i ++)
        for (int j = 0; j < new_kolumna; j ++)
            if (i < n && j < m)
                arrBuf[i][j] = arr[i][j];
    arr = arrBuf;
    n = new_wiersz;
    m = new_kolumna;
}


void wczytaj_tablice(int** arr, int n, int m){  // Wczytuje tablice z pliku
    fstream plik;
    plik.open("tabx.txt", ios::in);

    if (!plik.good()){
        cout << "nie udalo sie otworzyc tablicy\n";
        exit(0);
    }

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) 
            plik >> arr[i][j];
    plik.close();
}


void zapisz_plik(int** arr, int n, int m){  // Zapisuje tablice do pliku
    fstream plik;
    plik.open("tabx.txt", ios::out);
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++)
            plik << arr[i][j] << " ";
        cout << endl;
    }
    plik.close();
}












