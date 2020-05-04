#include <iostream>


using namespace std;

    void aktualizacja_tablicy(int **arr,int n ,int m , int w int k){

    int w;
    int k;
    int new_liczba;


    cout << "Numer wiersza:" << endl;
    cin>>w;
    cout << "Numer columny:" << endl;
    cin >> k;
    cout << "nowa liczba " << endl;
    cin >> new_liczba;
    aktualizacja_tablicy(arr, n, m, w, k, new_liczba);



    }

void aktualizacja_tablicy(int **arr,int n,int m,int w,int k, int new_liczba){
    if (w > n || k > m)	cout << "ERROR-Wejscie poza rozmiar tablicy" << endl;

    else tab[w][k] = new_liczba;
    }




