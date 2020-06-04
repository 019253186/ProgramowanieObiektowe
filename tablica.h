#include <bits/stdc++.h>
#include "../inc/cell.h"

using namespace std;

class Tablica{
    private:
        Cell** arr;
        int n, m;
        Type* types;
    public:
        void wyswietl_tablice();
        void tworze_tablice(int n, int m);
        void aktualizacja_tablicy();
        void zmien_rozmiar(int new_wiersz, int new_kolumna);
        void wczytaj_tablice();
        void zapisz_plik();
        void wyswietl_sumy_kolumn();
        void wyswietl_sumy_wierszy();
        bool znajdz_statystyki(int minValue, int maxValue, double avValue);
        void ustaw_typ_kolumny(int j, string typ);
        void wyswietl_typy();
};