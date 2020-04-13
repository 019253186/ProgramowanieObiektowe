#include <iostream>
#include <fstream>
#include "naglowki.h"
using  namespace  std ;

void Tablice::wczytaj_plik()
{


int tab[ 4 ][ 4 ];

for( int i = 0; i < 4; i++ )
     for( int j = 0; j < 4; j++ )
        tab[ i ][ j ] = 0;
    fstream plik;
    plik.open("tabx.txt",ios::in);

if(plik.good==false)
{
    cout<<"nie udalo sie otworzyc tablicy"<<endl;
    exit(0);
}


for(int i=0;i<4;++i){
    for (int j=0;j<4;++j){
         plik>>tab[i][j];

    }
}

for(int i=0;i<4;++i){
    for (int j=0;j<4;++j){

        cout<<" "<<tab[i][j];


}}
     plik.close();
}
