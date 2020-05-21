#include <bits/stdc++.h>


using namespace std;

void wyswietl_tablice(Tablica& tab){ // Wyswietlanie  tablicy , uprzednio zbudowanej
	cout << "\ntab:\n";
	for (int i = 0; i < this->n; i ++){
    for (int j = 0; j < this->m; j ++)
    cout << this->arr[i][j] << " ";
    cout << endl;
    }
}



