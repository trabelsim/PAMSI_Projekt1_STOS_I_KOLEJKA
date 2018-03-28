#include <iostream>
#include <time.h>
#include <windows.h>
#define ROZMIAR 10          // ROZMIAR tablicy Kolejki

using namespace std;


int Tab_Kolejki[ROZMIAR];   // Deklaracja Tablicy jednowymiarowej o rozmiarze 10
int Rozmiar_Kolejki=0;      // Deklaracja zmiennej do odnoszenia sie poszczegolnych pol tablicy
int Glowa=0;                // Deklaracja glowy - zmienna pomocnicza do oczytania wartosci

// Funkcja dodawania elementu do stosu
// 2 Mo¿liwe przypadki:
// 1 - Stos jest pe³ny
// 3 - Dodawanie.

void Dodaj() {              // Metoda dodawania elementow do Tablicy kolejki

    if(Rozmiar_Kolejki>= ROZMIAR){      // Przypadek gdy Rozmiar Tablicy jest juz wiekszy od ROZMIAR - niemozliwe jest dodawania kolejnych elementow
        cout << "Stos jest pelny!"<<endl<<"Nalezy usunac jeden element!"<<endl;
    }

    else {                              // Przypadek gdy Rozmiar tablicy jest mniejszy od ROZMIAR - mozliwe dodawanie kolejnych wartosci elementow
        cout<<"Podaj wartosc liczby:"<<endl;
        cin>>Tab_Kolejki[Rozmiar_Kolejki];      // Wprowadzenie wartosci do miejsca Rozmiar_Kolejki w Tablicy Kolejki
        Rozmiar_Kolejki++;                      // Zwiekszenie rozmiaru kolejki, tak aby bylo mozliwe dodawanie kolejnych elementow w nastepnym polu
    }
}


void Usun(){                                    // Metoda Usuwania elementow z tablicy
    if(Rozmiar_Kolejki>0){                      // Przypadek gdy Rozmiar Kolejki jest wiekszy od 0, wtedy mozliwe jest usuwanie poniewaz wystepuja juz elementy
    Tab_Kolejki[0]=0;                           // Inicjalizacja pierwszego pola tablicy wartoscia 0
    for(int i=0;i<=Rozmiar_Kolejki;i++)         // Petla for pomocna do przesuwania wczesniejszej wartosci do kolejnego pola Tablicy
    {
        Tab_Kolejki[i]= Tab_Kolejki[i+1];
    }
    Rozmiar_Kolejki--;   // Zmniejszanie Rozmiaru kolejki po usuniecie.
    }
    else{                                       // Przypadek gdy Rozmiar Kolejki jest rowny 0 - Wtedy jest niemozliwe usuwanie elementow.
    cout<<"Stos jest pusty. Nie mozna usunac zadnego z niej elementu."<<endl;
    }
}

void Usun_W() {         // Metoda usuwania wszystkich zmiennych znajdujacych sie w tablicy
if(Rozmiar_Kolejki >= 1) {      // Przypadek Gdy Rozmiar Kolejki posiada przynajmniej jeden element w tablicy.
        Rozmiar_Kolejki = 0;    // Rozmiar Kolejki przyjmuje wartosc 0 i wszystkie elementy sa kasowane
        cout<<"Nastepuje usuwanie wszystkich liczb"<<endl;
        Sleep(2000);
        cout<<"Stos jest pusty!"<<endl;
}
else                            // Przypadek gdy Rozmiar Kolejki nie posiada zadnego elementu.
    cout<<"Stos jest pusty!!"<<endl;
}

void Wyswietlanie_Kolejki(){        // Metoda wyswietlania Kolejki
    system("CLS");                  // system("CLS") pomocny do czysczenia strumienia wyjsciowego za kazdym razem gdy nastepuje zmiana.
     int zm=0;                      // Zmienna pomocnicza w petli.
    cout<<"-------------------------"<<endl;
    cout<<"          KOLEJKA        "<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"----->>> first in        "<<endl;
    cout<<"         first out<<<----"<<endl;
    cout<<"-------------------------"<<endl;
    for (zm=Rozmiar_Kolejki; zm>=1; zm--){          // Zmienna zm przyjmuje wartosc rozmiaru kolejki i jest zmniejszona do poki nie bedzie 0 ale wieksza lub rowna 1.
    cout<<"|^|"<<"\t"<<Tab_Kolejki[zm-1]<<endl;}    // Wyswietlanie wartosci Tablicy na strumieniu wyjsciowym
    cout<<"-------------------------"<<endl;
    cout<<Rozmiar_Kolejki<<"\t: elementow na stosie"<<endl; // Wyswietlanie rozmiaru kolejki w momencie wprowadzenia zmian.
    cout<<"-------------------------"<<endl;
}

void Wyswietl_Menu(){           // Metoda wyswietlania Menu.
    cout<<"-------------------------"<<endl;
    cout<<" 1 - DODAJ LICZBE        "<<endl;
    cout<<" 2 - USUN LICZBE         "<<endl;
    cout<<" 3 - USUN WSZYSTKIE LICZ."<<endl;
    cout<<" 4 - STATUS STOSU        "<<endl;
    cout<<" 5 - ZAKONCZENIE PROGR.  "<<endl;

}

void Sprawdz_czyPuste() {       //Metoda sluzy do sprawdzenia czy w Kolejce pojawiaja sia elementy
if(Rozmiar_Kolejki==0){         // W przypadku rozmiaru kolejki == 0
    cout<<"Stos jest pusty!"<<endl;}
else{                           // W przypadkku rozmiar kolejki !=0
    cout<<"Na stosie sa elementy"<<endl;
}
Sleep(2000);
}

 int main()
 {
     int wybor;         // Deklaracja zmiennej pomocniczej do wybierania poszczegolnych case'ow
     do {Wyswietlanie_Kolejki();            // Wylowanie metody Wyswietlania Kolejki
        Wyswietl_Menu();                    // Wylowanie metody Wyswietlania Menu   ---- Dopoki wybor != 5
     cin>>wybor;            // wprowadzenie wyboru uzytkownika.
     switch(wybor)
     {
 case 1:
     Dodaj();           // Wywolanie metody Dodawania
     break;

case 2:
    Usun();             // Wywolanie metody Usuniecia
    break;
case 3:
    Usun_W();           // Wywolanie metody Usuniecia wszystkich elementow
    break;
case 4:
    Sprawdz_czyPuste(); // Wywolanie metody sprawdzenia statusu kolejki
    break;
     }
    }while(wybor!=5);
     return 0;
 }
