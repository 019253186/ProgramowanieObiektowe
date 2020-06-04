#include <bits/stdc++.h>

#include "../inc/tablica.h"
using namespace std;


void Tablica::tworze_tablice(int n, int m){  
    this->types = new Type[m];
    this->arr = new Cell*[n];
    for (int i = 0; i < n; i ++)
        this->arr[i] = new Cell[m];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            this->arr[i][j].set_type(NONE);
    this->n = n;
    this->m = m;
}

void Tablica::ustaw_typ_kolumny(int j, string typ) {
    if(j < 0 || j >= this->m) {
        cout << "ERROR-Bledny indeks kolumny!\n";
        return;
    }

    if(typ == "TEXT")
        this->types[j] = TEXT;
    if(typ == "NUMBER")
        this->types[j] = NUMBER;
}

void Tablica::wyswietl_typy() {
    for(int i = 0; i < this->m; i ++) {
        if(this->type == TEXT)
            cout << "TEXT ";
        if(this->type == NUMBER)
            cout << "NUMBER ";
    }
    cout << endl;
}


void Tablica::aktualizacja_tablicy(){
    int w, k;
    cout << "Podaj wiersz i kolumne komorki ktora chcesz zakturalizowac: ";
    cin >> w >> k;
    cout << "Podaj wartosc tej komorki: ";

    if (w > this->n || k > this->m)
        cout << "ERROR-Wejscie poza rozmiar tablicy" << endl;
    else {
        if(this->types[k] == NUMBER) {
            int x;
            cin >> x;
            this->arr[w][k].set_number(x);
        }
        if(this->types[k] == TEXT) {
            string x;
            cin >> x;
            this->arr[w][k].set_text(x);
        }
    }
}

void Tablica::zmien_rozmiar(int new_wiersz, int new_kolumna){   // Zmieniam rozmiar tablicy
    Cell** arrBuf = new Cell*[new_wiersz];
    Type* typesBuf = new Type[new_kolumna];

    for (int i = 0; i < new_wiersz; i ++)
        arrBuf[i] = new Cell[new_kolumna];

    for (int i = 0; i < new_wiersz; i ++)
        for (int j = 0; j < new_kolumna; j ++)
            if (i < n && j < m)
                arrBuf[i][j] = this->arr[i][j];
    for(int i = 0; i < new_kolumna; i ++)
        typesBuf[i] = this->types[i];

    this->types = typesBuf;    
    this->arr = arrBuf;
    this->n = new_wiersz;
    this->m = new_kolumna;
}

void Tablica::wczytaj_tablice(){  // Wczytuje tablice z pliku
    fstream plik;
    plik.open("tabx.txt", ios::in);

    if (!plik.good()){
        cout << "nie udalo sie otworzyc tablicy\n";
        exit(0);
    }

    for(int i = 0; i < this->m; i ++) {
        string t;
        plik >> t;
        if(t == "TEXT")
            types[i] = TEXT;
        if(t == "NUMBER")
            types[i] = NUMBER;
    }

    for (int i = 0; i < this->n; i ++) {
        for (int j = 0; j < this->m; j ++) {
            if(types[j] == TEXT)
            {
                string s;
                plik >> s;
                arr[i][j].set_text(s);
            }
            else if(types[j] == NUMBER)
            {
                int x;
                plik >> x;
                arr[i][j].set_number(x);
            }
        }
    }
    plik.close();
}

void Tablica::zapisz_plik(){  // Zapisuje tablice do pliku
    fstream plik;
    plik.open("tabx.txt", ios::out);
    for(int i = 0; i < this->m; i ++){
        for(int j = 0; j < this->n; j ++) {
            if(this->arr[i][j].get_cell_type() == TEXT)
                plik << this->arr[i][j].get_text() << " ";
            if(this->arr[i][j].get_cell_type() == NUMBER)
                plik << this->arr[i][j].get_number() << " ";
        }
        cout << endl;
    }
    plik.close();
}

void Tablica::wyswietl_sumy_kolumn(){
    
    cout << "sumy kolumn: ";
    for (int j = 0; j < this->m; j ++){
        if(this->types[j] != NUMBER) {
            cout << "text" << endl;
        }
        int sum = 0;
        for (int i = 0; i < this->n; i ++)
            sum += this->arr[i][j].get_number();
        cout << sum << endl;
    }
}

void Tablica::wyswietl_sumy_wierszy(){
    cout << "sumy wierszy: ";
    for (int i = 0; i < this->n; i ++){
        int sum = 0;
        for (int j = 0; j < this->m; j ++) {
            if(this->types[j] == NUMBER)
                sum += this->arr[i][j].get_number();
        }
        cout << sum << " ";
    }
    cout << endl;
}

void Tablica::wyswietl_tablice(){ // Wyswietlanie  tablicy , uprzednio zbudowanej
    cout << "\ntab:\n";
    for (int i = 0; i < this->n; i ++){
        for (int j = 0; j < this->m; j ++) {
            if(this->types[j] == TEXT)
                cout << this->arr[i][j].get_text() << " ";
            else if(this->types[j] == NUMBER)
                cout << this->arr[i][j].get_number() << " ";
            else cout << "_ ";
        }
        cout << endl;
    }
}

// return true, jesli mozna znaleźć statystyki
bool Tablica::znajdz_statystyki(int minValue, int maxValue, double avValue){
    if (this->n<= 0 || this->m <= 0){
        return false;
    }
    maxValue = this->arr[0][0].get_number(), minValue = this->arr[0][0].get_number();
    avValue = 0.0;

    for (int i = 0; i < this->n; i ++)
        for (int j = 0; j < this->m; j ++){
            maxValue = max(maxValue, this->arr[i][j].get_number());
            minValue = min(minValue, this->arr[i][j].get_number());
            avValue += this->arr[i][j].get_number();
        }

    avValue /= this->n * this->m;
    return true;
}
