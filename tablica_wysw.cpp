#include <bits/stdc++.h>
#include "tablica_wysw.h"
using namespace std;

void wyswietl_tablice(int** arr, int n , int m){ // Wyswietlanie  tablicy , uprzednio zbudowanej
	cout << "\ntab:\n";
	for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}



