#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct Lista            // Struktura Listy w ktorej bedzie przechowywana stos
{
    Lista *nastepny;        // Wskaznik na kolejna wartosc liczby w stosie
    int wartosc;            // Wartosc liczby w stosie
};

class stos                  // Klasa stosu, czyli jej elementy oraz stosowane metody
{
private:
        Lista *Szczyt;      // Szczyt stosu - niezbedne do usuwania i dodawania elementow

public:
    stos();                 // konstruktor stosu
    ~stos();                // destruktor stosu
    void Sprawdz_czyPusty();     // Szczyt stosu - niezbedne do usuwania i dodawania elementow
    void Dodaj(int wartosc2);    // Dodaje elementy do stosu- po kolej.
    void Usun();                 // Usuwa elementy ze stosu zgodnie z zasada first in first out
    void Usun_W();               // Usuwa wszystkie elementy znajdujace sie na stosie
    void Wyswietlanie_Stosu();   // Wyswietlanie stosu oraz jej zasady dzialania
    void Wyswietl_Menu();        // Wyswietlanie prostego menu
};

stos::stos()            // Konstruktor
{
    Szczyt = NULL;      // Inicjalizuje szczyt stosu nadajac mu wartosc NULL - 0
}

stos::~stos()           // Destruktor
{
    while(Szczyt)       // Do poki istnieje zainicjalizowany szczyt stosu
        Usun();         // Usuwa elementy wczesniej pozostawione na stosie
}

void stos::Sprawdz_czyPusty()       // Sprawdzenie status stosu
{
if(Szczyt == NULL){                 // Jezeli na stosie nie ma elementow

    cout<<"Stos jest pusty!"<<endl;
}
else{                               // Przypadek gdy na stosie znajduja sie elementy

    cout<<"W stosie sa lementy!"<<endl;
    }

}

void stos::Dodaj(int wartosc2)      // Metoda dodawania elementow na stos, na wejsciu jest wartosc podana przez uzytkownika
{
Lista * nowy = new Lista;           // Tworzenie nowego elementu 'nowy' w ktorym zostana przechowane informacje.
cout<<"Podaj wartosc ktora chcesz wprowadzic"<<endl;
cin>>wartosc2;                      // Wczytywanie wartosci podanej przez uzytkownika
nowy->wartosc = wartosc2;           // przypisanie wartosci wczytaj do pola wartosc zmiennej nowy
nowy->nastepny=Szczyt;              // wskaznik nowego elementu wskazuje teraz na szczyt stosu
Szczyt=nowy;                        // nowy dodany element jest ustawiany na szczyt stosu
}


void stos::Usun(){                  // Metoda usuwania elementow ze stosu
if(Szczyt){                         // Jezeli w Szczyt znajduja sie elementy
Lista *nowy = Szczyt;               // W zmiennej nowy jest przechowana teraz wartosc szczyt stosu
Szczyt=Szczyt->nastepny;            // Przejscie wskaznika z elementu pierwotnego do nastepnego
delete nowy;                        // Usuwanie zmiennej nowej
    }
}

void stos::Usun_W(){                // Metoda usuwania wszystkich elementow ze stosu
while(Szczyt)                       // Jezeli w szczyt znajduja sie elementy
    {
    Lista *nowy = Szczyt;           // Deklaracja zmiennej nowy w ktorej przechowywana jest wartosc Szczyt
    Szczyt=Szczyt->nastepny;        // Wskaznik szczyt jest przekazywany do kolejnego elementu
    delete nowy;                    // Usuwanie zadeklarowanej zmiennej nowy.
    }
}

void stos::Wyswietlanie_Stosu(){        // Metoda wyswietlania stosu przy komunikacji z uzytkownikiem
    Lista *temp;                        // deklaracja zmiennej typu lista
    temp = Szczyt;                      // Przechowywanie wartosc Szczyt do zmiennej temp
    system("CLS");
    cout<<"-------------------------"<<endl;
    cout<<"            STOS         "<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"----->>> last in         "<<endl;
    cout<<"         first out<<<----"<<endl;
    cout<<"-------------------------"<<endl;
    if(temp==NULL)                      // Jezeli zmienna temp jest pusta (czyli Szczyt stosu jest pusty)
        cout<<"Stos jest pusty!"<<endl;
    else                                // W innym przypadku
    do{
        cout<<temp->wartosc<<endl;      // Wyswietlanie wartosci przechowanej w zmiennej temp
        temp = temp->nastepny;          // Przekazanie wskaznik temp do kolejnego elementu.
    }while(temp!=NULL);                 // Petla dziala do poki ostatni wskaznik nie bedzie rowny NULL - czyli nie bedzie juz elementow

}

void stos::Wyswietl_Menu(){             // Metoda do wyswietlania Menu
    cout<<"-------------------------"<<endl;
    cout<<" 1 - DODAJ LICZBE        "<<endl;
    cout<<" 2 - USUN LICZBE         "<<endl;
    cout<<" 3 - USUN WSZYSTKIE LICZ."<<endl;
    cout<<" 4 - STATUS STOSU        "<<endl;
    cout<<" 5 - ZAKONCZENIE PROGR.  "<<endl;
    cout<<"-------------------------"<<endl;
}


int main()
 {
     int w;     // zmienna przechowujaca wartosc podana przez uzytkownika przy wywolaniu metody Dodaj
     int wybor; // zmienna pomocnicza do wyboru case'ow wyswietlanych w menu
     stos LL;   // Deklaracja zmiennej typu stos potrzebna do odtworzenia poszczegolnych metod
     do {LL.Wyswietlanie_Stosu();   // Dzialanie Wyswietlania stosu
        LL.Wyswietl_Menu();         // Dzialanie Wyswietlania Menu -- DO POKI WYBOR !=5
     cin>>wybor;
     switch(wybor)
     {
 case 1:
     LL.Dodaj(w);           // Przywolanie metody Dodaj

    break;

case 2:
    LL.Usun();              // Przywolanie metody Usun
    break;
case 3:
    LL.Usun_W();            // Przywoalnie metody Usun wszystko
    break;
case 4:
    LL.Sprawdz_czyPusty();  // Przywolanie metody sprawdzenie statusu stosu
    break;
     }
    }while(wybor!=5);
     return 0;
 }
