#include <iostream>
#include <windows.h>

using namespace std;

struct Lista            // Struktura Listy w ktorej bedzie przechowywana kolejka
{
    Lista *nastepny;    // Wskaznik na kolejna wartosc liczby w kolejce
    int wartosc;        // Wartosc liczby w kolejce
};

class kolejka           // Klasa kolejki, czyli jej elementy oraz stosowane metody
{
    private:
    Lista * Szczyt;     // Szczyt kolejki - niezbedne do usuwania i dodawania elementow

    public:
        kolejka();      // Konstruktor kolejki
        ~kolejka();     // Destruktor kolejki
        void Sprawdz_czyPusta();        // Sprawdz czy kolejka jest pusta czy wystepuja elementy
        void Dodaj();                   // Dodaje elementy do kolejki - po kolej.
        void Wyswietlanie_Kolejki();    // Wyswietlanie Kolejki oraz jej zasady dzialania
        void Usun();                    // Usuwa elementy z kolejki zgodnie z zasada first in first out
        void Usun_Wszystko();           // Usuwa wszystkie elementy znajdujace sie w kolejce
        void Wyswietl_Menu();           // Wyswietlanie prostego menu
};


kolejka::kolejka()          // Konstruktor
{
    Szczyt = NULL;          // Inicjalizuje szczyt kolejki nadajac mu wartosc NULL - 0.
}


kolejka::~kolejka()         // Destruktor
{
    while(Szczyt)           // Do poki istnieje zainicjalizowany szczyt kolejki
        Usun();             // Usuwa elementy wczesniej pozostawione w kolejce
}

void kolejka::Sprawdz_czyPusta() // Sprawdzenie status kolejki
{
    if(Szczyt==NULL){               // Jezeli w kolejce nie ma elementow
        cout<<"Kolejka jest pusta!"<<endl;      // komunikat
    }
    else{
        cout<<"W kolejce pojawia sie elementy!"<<endl; // W innym przypadku niz NULL
    }
    Sleep(800);         // przedluza dzialanie programu aby komunikat byl widoczny
}

void kolejka::Dodaj()   // Metoda dodawania elementow do kolejki
{
    int wartosc2;               // deklaracja wartosci wprowadzonej
    Lista * nowy = new Lista;   // Tworzenie nowego elementu 'nowy' typu Lista w ktorym zostana przechowane info.
    cout<<"Podaj wartosc jaka chcesz wprowadzic do kolejki :"<<endl;
    cin>>wartosc2;              // wczytywanie wartosci podanej przez uzytkownika
    nowy->wartosc = wartosc2;   // przypisanie wartosci wczytanej przez uzytkownika do wartosc
    nowy->nastepny = Szczyt;    // wskaznik nowego elementu wskazuje na szczyt kolejki - kolejny element
    Szczyt = nowy;              // nowy dodany element ustawiany jest na szczycie kolejki
}


void kolejka::Wyswietlanie_Kolejki()        // Metoda wyswietlania kolejki przy komunikacji z uzytkownikiem
{
Lista *temp;                                // deklaracja zmiennej typu Lista
temp = Szczyt;                              // Przypisanie nowej wartosci wartosc kolejki szczytu

system("CLS");                              // Czysczenie za kazdym razem menu
cout<<"---------------------"<<endl;
cout<<"       KOLEJKA       "<<endl;
cout<<"---------------------"<<endl;
cout<<" ------>> first in   "<<endl;
cout<<"     first out<<-----"<<endl;
cout<<"---------------------"<<endl;
if(temp==NULL)                              // Jezeli w zmiennej temp w ktorej przechowana jest kolejka jest pusta ->
    cout<<" Kolejka jest pusta!"<<endl;
else                                        // W innym przypadku
do  {
    cout<<temp->wartosc<<endl;              // Wyswietlanie wartosci przechowanej aktualnie w szczycie kolejki (temp)
    temp = temp-> nastepny;                 // Przekazanie wskaznika tempa na kolejny element
    } while(temp!=NULL);                    // Dzialanie trwa do poki ostatni wskaznik nie bedzie rowny 0, czyli gdy juz nie bedzie elementow

}


void kolejka::Usun()                        // Usuwanie elementu z kolejki
{
 if(Szczyt)                                 // Jesli na szczycie znajduja sie elementy
 {
     Lista *poprzedni = Szczyt;             // Kolejno zadeklarowane zmienne w ktorej przechowwywane sa wartosci kolejki
     Lista *nowy = Szczyt;
     while(nowy->nastepny){                 // Do poki element nowy bedzie posiadal kolejny wskaznik
        nowy = nowy->nastepny;              // przejscie z elementu pierwotnego do nastepnego
     }
     while(!(poprzedni-> nastepny ==nowy)){ //  Do poki wskaznik elementu poprzedni nie bedzie juz wskazywal na nowy element
        poprzedni = poprzedni->nastepny;}   // przejscie wskaznika z elementu pierwotnego do kolejnego
    poprzedni->nastepny=NULL;               // W momencie zakonczenia petli ostatni wskaznik poprzedni przybiera warto NULL
    delete nowy;                            // Usuwanie wartosci nowy.
 }
}

void kolejka::Usun_Wszystko(){              // Usuwanie wszystkich elementow znajdujacych sie w kolejce
while(Szczyt)                               // Dzialanie programu do poki szczyt kolejki istnieje
    {
        Lista *nowy = Szczyt;               // deklaracja nowej zmiennej nowy w ktorej przechowywana jest wartosc Szczyt
        Szczyt = Szczyt->nastepny;          // Wskaznik sczytu jest przekazywana do kolejnego elementu
        delete nowy;                        // usuwanie zadeklarowanego 'nowy'
    }
}


void kolejka::Wyswietl_Menu(){              // Metoda do Wyswietlania Menu
cout<<"-------------------------"<<endl;
cout<<"1 - DODAJ LICZBE         "<<endl;
cout<<"2 - USUN LICZBE          "<<endl;
cout<<"3 - USUN WSZYSTKIE LICZBY"<<endl;
cout<<"4 - PELNY CZY PUSTY?     "<<endl;
cout<<"5 - WYJSCIE              "<<endl;
cout<<"-------------------------"<<endl;
}


int main()
{
int wybor;      // Deklaracja zmiennej wyboru case wyswietlanych w menu
kolejka KK;     // Deklaracja zmiennej typu kolejka potrzebna do odtworzenia poszczegolnych metod

do{KK.Wyswietlanie_Kolejki(); // Dzialanie Wyswietlania kolejki
    KK.Wyswietl_Menu();       // Dzialanie Wyswietlania menu -- DO POKI WYBOR !=5
cin>>wybor;
switch(wybor)
    {
case 1:
    KK.Dodaj();                // Przywolanie metody Dodaj
    break;
case 2:
    KK.Usun();                  // Przywolanie metody Usun
    break;
case 3:
    KK.Usun_Wszystko();         // Przywoalnie metody Usun wszystko
    break;
case 4:
    KK.Sprawdz_czyPusta();      // Przywolanie metody sprawdzenie statusu kolejki
    break;
    }

}while(wybor!=5);
return 0;
}
