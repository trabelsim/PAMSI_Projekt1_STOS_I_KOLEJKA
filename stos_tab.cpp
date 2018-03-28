#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int Tab_Stosu[5];       // Deklaracja tablicy jednowymiarowej o rozmiarze 5
int Rozmiar_Stosu;      // Deklaracja zmiennej przechowujacej rozmiar stosu

// Funkcja dodawania elementu do stosu
// 2 Mo¿liwe przypadki:
// 1 - Stos jest pe³ny
// 3 - Dodawanie.

void Dodaj() {  //Metoda dodawania elementow do Tablicy stosu

    if(Rozmiar_Stosu>= 4){  // Przypadek gdy rozmiar Tablicy jest wiekszy od granicznej wartosci 4.
        cout << "Stos jest pelny!"<<endl<<"Nalezy usunac jeden element!"<<endl;
    }

    else {      // Przypadek gdy rozmiar jest mniejsze od granicznej wartosci 4.
        cout<<"Podaj wartosc liczby:"<<endl;
        Rozmiar_Stosu += 1;              // Zwiekszanie rozmiaru stosu o jedno miejsce.
        cin>>Tab_Stosu[Rozmiar_Stosu];  //  Przechowanie wartosci podanej do Tablicy stosu.

    }
}


void Usun(){        // Metoda usuwania elementow ze stosu
    if(Rozmiar_Stosu >= 1){                                                         // przypadek gdy Rozmiar stosu nie jest pusty, wiec mozliwe jest usuwanie elementow
    cout<<"Liczba"<<"\t"<<Tab_Stosu[Rozmiar_Stosu]<<"\t"<<"zostala usunieta"<<endl; // Wyswietlanie usunietej wartosci na strumieniu wyjsciowym
     Rozmiar_Stosu = Rozmiar_Stosu - 1;                                             // Zmniejszanie Rozmiaru stosu o jedno miejsce
    }
    else{                                                                           // przypadek gdy na stosie nie ma zadnych elementow.
    cout<<"Stos jest pusty. Nie mozna usunac zadnego z niej elementu."<<endl;
}
Sleep(800);
}

void Usun_W() {         // Metoda usuwania wszystkich zmiennych ze stosu
if(Rozmiar_Stosu >= 1) {    // Przypadek gdy rozmiar stosu jest wiekszy lub rowny 1.
        Rozmiar_Stosu = 0;  // Inicjalizacja pierwszego pola tablicy wartoscia 0.
        cout<<"Nastepuje usuwanie wszystkich liczb"<<endl;
        Sleep(800);
        cout<<"Stos jest pusty!"<<endl;
        Sleep(500);
}
}


void Wyswietlanie_Stosu(){                  // Metoda wyswietlania Stosu
    system("CLS");                          // system("CLS") pomocny do czysczenia strumienia wyjsciowego za kazdym razem gdy nastepuje zmiana
     int zm;                                // zmienna pomocnicza w petli
    cout<<"-------------------------"<<endl;
    cout<<"            STOS         "<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"----->>> last in        "<<endl;
    cout<<"         first out<<<----"<<endl;
    cout<<"-------------------------"<<endl;
    for (zm=Rozmiar_Stosu; zm>=1; zm--)     // Zmienna zm przyjmuje wartosc rozmiaru stosu i jest zmniejszana do poki nie bedzie >=1
    cout<<"|^|"<<"\t"<<Tab_Stosu[zm]<<endl; // Wyswietlanie wartosci tablicy na strumieniu wyjsciowym
    cout<<"-------------------------"<<endl;
    cout<<Rozmiar_Stosu<<"\t: elementow na stosie"<<endl;   // Wyswietlanie ilosc elementow na stosie w momencie wprowadzenia zmian
    cout<<"-------------------------"<<endl;
}

void Wyswietl_Menu(){                           // Metoda wyswietlania menu
    cout<<"-------------------------"<<endl;
    cout<<" 1 - DODAJ LICZBE        "<<endl;
    cout<<" 2 - USUN LICZBE         "<<endl;
    cout<<" 3 - USUN WSZYSTKIE LICZ."<<endl;
    cout<<" 4 - STATUS STOSU        "<<endl;
    cout<<" 5 - ZAKONCZENIE PROGR.  "<<endl;

}

void Sprawdz_czyPuste() {       // Metoda sluzy do sprawdzenia czy na stosie sa przechowane elementu
if(Rozmiar_Stosu==0){           // W przypadku rozmiaru stosu == 0
    cout<<"Stos jest pusty!"<<endl;}
else{                           // W przypadku Rozmiaru stosu !==0
    cout<<"Na stosie sa elementy"<<endl;
}
Sleep(2000);
}

 int main()
 {
     int wybor;                 // Deklaracja zmiennej pomocniczej do wybierania poszczegolnych case'ow
     do {Wyswietlanie_Stosu();  // Wylowanie metody Wyswietlania Kolejki
        Wyswietl_Menu();        // Wylowanie metody Wyswietlania Menu   ---- Dopoki wybor != 5
     cin>>wybor;                // wprowadzenie wyboru uzytkownika
     switch(wybor)
     {
 case 1:
     Dodaj();                   // Wywolanie metody Dodawania

    break;

case 2:
    Usun();                     // Wywolanie metody Usuniecia
    break;
case 3:
    Usun_W();                   // Wywolanie metody Usuniecia wszystkich elementow
    break;
case 4:
    Sprawdz_czyPuste();         // Wywolanie metody sprawdzenia statusu stosu
    break;
     }
    }while(wybor!=5);
     return 0;
 }
