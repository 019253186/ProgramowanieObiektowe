#include <iostream>




using namespace std;


void tworze_tablice(int **arr,int n ,int m)
{




	int **tab = new int*[n];
	for (int i = 0; i < n; i ++)
		tab[i] = new int[m];


	for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
    tab[i][j] = 0;
    return tab;
}
void wyswietl_tablice(int** arr,int n , int m){
	cout <<endl<< "tab:\n";
	for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
    cout << tab[i][j] << " ";
}

void zmien_rozmiar(int **arr,int n , int m ,int new_wiersz , int new_kolumna){




int** nowa_tablica = new int* [new_wiersz];
		for (int i = 0; i < new_wiersz; i++)
		{
			nowa_tablica[i] = new int[new_kolumna];
		}




for (int i = 0; i < new_wiersz; i++)
		{
        for (int j = 0; j < new_kolumna; j++)
			{
        if (i >= n || j >= m)
				{
					nowa_tablica[i][j] = 0;
				}
        else
				{
					nowa_tablica[i][j] = tablica[i][j];
				}
			}
		}

		return nowa_tablica;
	}




void wczytaj_talbice(int** arr,int n, int m )
{




for( int i = 0; i < n; i++ )
     for( int j = 0; j < m; j++ )
        tab[ i ][ j ] = 0;
    fstream plik;
    plik.open("tabx.txt",ios::in);

if(plik.good==false)
{
    cout<<"nie udalo sie otworzyc tablicy"<<endl;
    exit(0);
}


for(int i=0;i<n;++i){
    for (int j=0;j<m;++j){
         plik>>tab[i][j];

    }
}




     plik.close();
}





void zapisz_plik(int** arr,int n , int m){
    fstream plik;

plik.open("tabx.txt",ios::out);
for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j)

plik<<tab[i][j]<<endl;

plik.close();
}













