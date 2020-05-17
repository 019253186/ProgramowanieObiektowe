#include <bits/stdc++.h>
#include "tablica_wysw.h"
#include "struktura.h"
using namespace std;

void wyswietl_tablice(Tablica& tab){ // Wyswietlanie  tablicy , uprzednio zbudowanej
	cout << "\ntab:\n";
	for (int i = 0; i < tab.n; i ++){
        for (int j = 0; j < tab.m; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}



