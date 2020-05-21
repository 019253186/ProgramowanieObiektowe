#include <bits/stdc++.h>

using namespace std;



class Tablica{
    private:
        int** arr;
        int n, m;

    public:

void tworze_tablice(int n, int m){  //      Tutaj tworze pierwszy raz tablice
    this->arr = new int*[n];
    for (int i = 0; i < n; i ++)
    this->arr[i] = new int[m];
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
        this->arr[i][j] = 0;
        this->n = n;
        this->m = m;
    }

void aktualizacja_tablicy(){
    int w, k, x;
    cout << "Podaj wierz i kolumne komorki ktora chcesz zakturalizowac: ";
    cin >> w >> k;
    cout << "Podaj wartosc tej komorki: ";
    cin >> x;

        if (w > this->n || k > this->m)
            cout << "ERROR-Wejscie poza rozmiar tablicy" << endl;
        else
            this->arr[w][k] = x;
    }

void zmien_rozmiar(int new_wiersz, int new_kolumna){   // Zmieniam rozmiar tablicy
    int** arrBuf = new int*[new_wiersz];
    for (int i = 0; i < new_wiersz; i ++)
            arrBuf[i] = new int[new_kolumna];

    for (int i = 0; i < new_wiersz; i ++)
    for (int j = 0; j < new_kolumna; j ++)
        if (i < n && j < m)
            arrBuf[i][j] = this->arr[i][j];
    this->arr = arrBuf;
    this->n = new_wiersz;
    this->m = new_kolumna;
    }
void wczytaj_tablice(){  // Wczytuje tablice z pliku
    fstream plik;
    plik.open("tabx.txt", ios::in);

        if (!plik.good()){
    cout << "nie udalo sie otworzyc tablicy\n";
        exit(0);
    }

    for (int i = 0; i < this->n; i ++)
    for (int j = 0; j < this->m; j ++)
        plik >> this->arr[i][j];
        plik.close();
}


void zapisz_plik(){  // Zapisuje tablice do pliku
    fstream plik;
        plik.open("tabx.txt", ios::out);
    for(int i = 0; i < m; i ++){
    for(int j = 0; j < n; j ++)
        plik << this->arr[i][j] << " ";
    cout << endl;
    }
        plik.close();
}


void wyswietl_sumy_kolumn(){
    cout << "sumy kolumn: ";
    for (int j = 0; j < this->m; j ++){
    int sum = 0;
    for (int i = 0; i < this->n; i ++)
    sum += this->arr[i][j];
    cout << sum << endl;
    }
}



void wyswietl_sumy_wierszy(){
    cout << "sumy wierszy: ";
    for (int i = 0; i < tab.n; i ++){
    int sum = 0;
    for (int j = 0; j < tab.m; j ++)
        sum += this->arr[i][j];
    cout << sum << " ";
    }
    cout << endl;
}


void wyswietl_tablice(){ // Wyswietlanie  tablicy , uprzednio zbudowanej
	cout << "\ntab:\n";
	for (int i = 0; i < this->n; i ++){
    for (int j = 0; j < this->m; j ++)
    cout << this->arr[i][j] << " ";
    cout << endl;
    }
}



// return true, jesli mozna znaleźć statystyki
bool znajdz_statystyki(int minValue, int maxValue, double avValue){
    if (this->n<= 0 || this->m <= 0){
        return false;
    }
            maxValue = this->arr[0][0], minValue = this->arr[0][0];
            avValue = 0.0;

    for (int i = 0; i < this->n; i ++)
    for (int j = 0; j < this->m; j ++){
            maxValue = max(maxValue, this->arr[i][j]);
            minValue = min(minValue, this->arr[i][j]);
            avValue += this->arr[i][j]
        }
            avValue /= this->n * this->m;
    return true;
}


}; // tab.zmien_rozmiar(2, 3);
// wczesniej -> zmien_rozmiar(tab, 2, 3);



