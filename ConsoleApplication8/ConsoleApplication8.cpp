#include <iostream>
#include <random>
#include <ctime>
#include <time.h>
#include <conio.h>
#include <stdlib.h> 
#include "windows.h"

using namespace std;
const int x = 10, y = 10;
int plansza[x][y], planszaKomputera[x][y];
int planszaG1[x][y], planszaG2[x][y];
char zgadywanka[x + 2][y + 2], zgadywankaKomputera[x + 2][y + 2];
char ZgPlanszaG1[x + 2][y + 2], ZgPlanszaG2[x + 2][y + 2];
bool wyjscie = 0, wyjscie2 = 0;
bool czyPoddanie = 0;
char x2 = 0, y2 = 0;
bool czyPowtorzenie = 0;
int counter_punktacji = 20, punkty = 0, zmiennaA = 0, zmiennaB = 0, zmiennaA2 = 0, zmiennaB2 = 0, licznik_strzalow = 0, licznik_strzalow2 = 0, punktyKomputera = 0, counter_punktacji2 = 20;

void wyswietlPlanszeGracza(char zgadywanka[x + 2][y + 2]);
void Run();
void draw_menu();

void wyczysc_plansze()
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            plansza[i][j] = 0;
}

void wyswietl_statki()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (plansza[i][j] == 1 || plansza[i][j] == 2 || plansza[i][j] == 3 || plansza[i][j] == 4)
            {
                cout << "x ";
            }
            else
                cout << "- ";

        }
        cout << endl;
    }
    cout << endl;
}

void ustaw_statek(int ile_statkow, int dlugosc)
{
    //0 - w LEWO //1 - w górę //2 - w prawo //3 - w dół
    bool czyWolne = 0, czyZlyKierunek = 1;
    int a = 0, b = 0, kierunek = 0;
    srand(time(NULL));


    for (int s = 0; s < ile_statkow; s++) {
        czyWolne = 0; czyZlyKierunek = 1;
        while (!czyWolne)
        {
            czyWolne = 1;
            a = rand() % 10;
            b = rand() % 10;

            if (plansza[a][b] == 0)
            {
                while (czyZlyKierunek)
                {
                    czyZlyKierunek = 0;
                    bool czyDobryKierunek = 1;

                    kierunek = rand() % 4;
                    switch (kierunek)
                    {
                    case 0:
                        if (b >= dlugosc - 1)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a][b - i] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a][b - k] = dlugosc;
                                }
                                if (a > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - 1][b - k] = 9;
                                    }
                                }
                                if (a < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + 1][b - k] = 9;
                                    }
                                }

                                if (a > 0 && (b - counter > 0))
                                {
                                    plansza[a - 1][b - counter - 1] = 9;
                                    plansza[a][b - counter - 1] = 9;
                                }
                                if (a < 9 && (b - counter > 0))
                                {
                                    int p = counter - 1;
                                    plansza[a + 1][b - counter - 1] = 9;
                                    plansza[a][b - counter - 1] = 9;
                                }
                                if (a > 0 && b < 9)
                                {
                                    plansza[a - 1][b + 1] = 9;
                                    plansza[a][b + 1] = 9;
                                }
                                if (a < 9 && b < 9)
                                {
                                    plansza[a + 1][b + 1] = 9;
                                    plansza[a][b + 1] = 9;
                                }

                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }


                        break;
                    case 1:
                        if (a >= dlugosc - 1)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a - i][b] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a - k][b] = dlugosc;
                                }
                                if (b > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - k][b - 1] = 9;
                                    }
                                }
                                if (b < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - k][b + 1] = 9;
                                    }
                                }

                                if (b > 0 && (a - counter > 0))
                                {
                                    plansza[a - counter - 1][b] = 9;
                                    plansza[a - counter - 1][b - 1] = 9;
                                }
                                if (b < 9 && (a - counter > 0))
                                {
                                    plansza[a - counter - 1][b] = 9;
                                    plansza[a - counter - 1][b + 1] = 9;
                                }

                                if (b > 0 && a < 9)
                                {
                                    plansza[a + 1][b - 1] = 9;
                                    plansza[a + 1][b] = 9;
                                }
                                if (b < 9 && a < 9)
                                {
                                    plansza[a + 1][b + 1] = 9;
                                    plansza[a + 1][b] = 9;
                                }

                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }

                        break;
                    case 2:
                        if (b <= y - dlugosc)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a][b + i] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a][b + k] = dlugosc;
                                }
                                if (a > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - 1][b + k] = 9;
                                    }
                                }
                                if (a < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + 1][b + k] = 9;
                                    }
                                }

                                if (a > 0 && (b + counter < 9))
                                {
                                    plansza[a - 1][b + dlugosc] = 9;
                                    plansza[a][b + dlugosc] = 9;
                                }
                                if (a < 9 && (b + counter < 9))
                                {
                                    plansza[a + 1][b + dlugosc] = 9;
                                    plansza[a][b + dlugosc] = 9;
                                }
                                if (a > 0 && b > 0)
                                {
                                    plansza[a - 1][b - 1] = 9;
                                    plansza[a][b - 1] = 9;
                                }
                                if (a < 9 && b > 0)
                                {
                                    plansza[a + 1][b - 1] = 9;
                                    plansza[a][b - 1] = 9;
                                }


                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }


                        break;
                    case 3:
                        if (a <= x - dlugosc)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a + i][b] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a + k][b] = dlugosc;
                                }
                                if (b > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + k][b - 1] = 9;
                                    }
                                }
                                if (b < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + k][b + 1] = 9;
                                    }
                                }

                                if (b > 0 && (a + counter < 9))
                                {
                                    plansza[a + counter + 1][b] = 9;
                                    plansza[a + counter + 1][b - 1] = 9;
                                }
                                if (b < 9 && (a + counter < 9))
                                {
                                    plansza[a + counter + 1][b] = 9;
                                    plansza[a + counter + 1][b + 1] = 9;
                                }

                                if (b > 0 && a > 0)
                                {
                                    plansza[a - 1][b - 1] = 9;
                                    plansza[a - 1][b] = 9;
                                }
                                if (b < 9 && a > 0)
                                {
                                    plansza[a - 1][b + 1] = 9;
                                    plansza[a - 1][b] = 9;
                                }



                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }

                        break;
                    default: break;
                    }
                }
            }
            else
            {
                czyWolne = 0;
            }

        }
    }
}

void rozmiesc_statki()
{
    //czteromasztowiec x1
    ustaw_statek(1, 4);
    //trójmasztowiec x2
    ustaw_statek(2, 3);
    //dwumasztowiec x3
    ustaw_statek(3, 2);
    //jednomasztowiec x4
    ustaw_statek(4, 1);
}

void wyswietl_plansze()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int menu_switch = 0;

void ustawZgadywanke()
{
    for (int i = 1; i < (x + 1); i++)
    {
        for (int j = 1; j < (y + 1); j++)
        {
            zgadywanka[i][j] = '-';
        }
    }
    for (int i = 1; i < x; i++)
    {
        zgadywanka[0][i] = (char)(i + '0');
        zgadywanka[i][0] = (char)(i + '0');
    }
    zgadywanka[x][0] = '1';
    zgadywanka[x + 1][0] = '0';
    zgadywanka[0][y] = '1';
    zgadywanka[0][y + 1] = '0';
    zgadywanka[0][0] = '/';
}



void zgadywankaNaPlansze()
{
    for (int i = 1; i < (x + 1); i++)
    {
        for (int j = 1; j < (y + 1); j++)
        {
            if (plansza[i - 1][j - 1] == 9 || plansza[i - 1][j - 1] == 0)
            {
                zgadywanka[i][j] = '-';
            }
            else
                zgadywanka[i][j] = 'x';

        }
    }
    for (int i = 1; i < x; i++)
    {
        zgadywanka[0][i] = (char)(i + '0');
        zgadywanka[i][0] = (char)(i + '0');
    }
    zgadywanka[x][0] = '1';
    zgadywanka[x + 1][0] = '0';
    zgadywanka[0][y] = '1';
    zgadywanka[0][y + 1] = '0';
    zgadywanka[0][0] = '/';
}

void wyswietlZgadywanke()
{
    for (int i = 0; i < (x + 1); i++)
    {
        for (int j = 0; j < (y + 2); j++)
        {
            if (j < y + 1)
            {
                cout << zgadywanka[i][j] << " ";
            }
            else if (i == 0)
                cout << zgadywanka[0][y + 1];

        }
        cout << endl;
    }
    cout << zgadywanka[x + 1][0] << endl;
}

void zwyciestwo()
{
    system("cls");
    cout << "Gratulacje! Udalo Ci sie zebrac wszystkie punkty!" << endl;
    cout << "Udalo Ci sie to w tylu strzalach: " << licznik_strzalow << endl;
    cout << "Oto jak wyglada finalowa plansza: " << endl;
    cout << "--------------------------------------" << endl;
    wyswietlZgadywanke();
    cout << "--------------------------------------" << endl;
    cout << "Wcisnij klawisz Enter by wyjsc.";
    bool czyWyjscie = 0;
    while (!czyWyjscie)
    {
        if (_kbhit)
        {
            char znak = _getch();
            if (znak == 13)
                czyWyjscie = 1;
        }
    }

}

void zwyciestwoGracza()
{
    system("cls");
    cout << "Gratulacje! Udalo Ci sie zebrac wszystkie punkty!" << endl;
    cout << "Udalo Ci sie to w tylu strzalach: " << licznik_strzalow << endl;
    cout << "Komputer skonczyl gre z tyloma punktami: " << punktyKomputera << endl;
    cout << "Oto jak wyglada finalowa plansza komputera: " << endl;
    cout << "--------------------------------------" << endl;
    wyswietlZgadywanke();
    cout << "--------------------------------------" << endl;
    cout << "Wcisnij klawisz Enter by wyjsc.";
    bool czyWyjscie = 0;
    while (!czyWyjscie)
    {
        if (_kbhit)
        {
            char znak = _getch();
            if (znak == 13)
                czyWyjscie = 1;
        }
    }

}

void zwyciestwoKomputera()
{
    czyPoddanie = 1;
    system("cls");
    cout << "Komputer odnosi zwyciestwo!" << endl;
    cout << "Skonczyles gre z punktacja: " << punkty << endl;
    cout << "Oddales tyle strzalow: " << licznik_strzalow << endl;
    cout << "Komputer zwyciezyl w tylu strzalach: " << licznik_strzalow2 << endl;
    cout << "Oto jak wygladala finalowa plansza komputera:" << endl;
    cout << "--------------------------------------" << endl;
    zgadywankaNaPlansze();
    wyswietlZgadywanke();
    cout << "--------------------------------------" << endl;
    cout << "Wcisnij klawisz Enter by wyjsc.";

    bool czyKontynuowac6 = 0;
    while (!czyKontynuowac6)
    {
        char znak = _getch();
        if (znak == 13)
        {
            czyKontynuowac6 = 1;
        }

    }
}


void poddanie()
{
    czyPoddanie = 1;
    system("cls");
    cout << "Niestety nie udalo Ci sie wygrac :(" << endl;
    cout << "Skonczyles gre z punktacja: " << punkty << endl;
    cout << "Oddales tyle strzalow: " << licznik_strzalow << endl;
    cout << "Oto jak wygladala finalowa plansza:" << endl;
    cout << "--------------------------------------" << endl;
    zgadywankaNaPlansze();
    wyswietlZgadywanke();
    cout << "--------------------------------------" << endl;
    cout << "Wcisnij klawisz Enter by wyjsc.";


}

void poddanieGracza()
{
    czyPoddanie = 1;
    system("cls");
    cout << "Niestety nie udalo Ci sie wygrac :(" << endl;
    cout << "Skonczyles gre z punktacja: " << punkty << endl;
    cout << "Oddales tyle strzalow: " << licznik_strzalow << endl;
    cout << "Komputer skonczyl gre z tyloma punktami: " << punktyKomputera << endl;
    cout << "Oto jak wygladala finalowa plansza komputera:" << endl;
    cout << "--------------------------------------" << endl;
    zgadywankaNaPlansze();
    wyswietlZgadywanke();
    cout << "--------------------------------------" << endl;
    cout << "Wcisnij klawisz Enter by wyjsc.";


}

void zgadywanie(int zmiennaA, int zmiennaB)
{
    bool petladanych = 1, petladanych2 = 1;
    while (petladanych)
    {
        cout << "Podaj wspolrzedna x: "; cin >> zmiennaA;
        while (cin.fail())
        {
            cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Podaj wspolrzedna x: "; cin >> zmiennaA;
        }
        if (zmiennaA > 0 && zmiennaA <= 10)
        {
            zmiennaA--;
            while (petladanych2)
            {
                cout << "Podaj wspolrzedna y: "; cin >> zmiennaB;
                while (cin.fail())
                {
                    cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Podaj wspolrzedna x: "; cin >> zmiennaB;
                }
                if (zmiennaB > 0 && zmiennaB <= 10)
                {
                    zmiennaB--;
                    petladanych = 0;
                    petladanych2 = 0;
                }
                else
                    cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
            }

        }
        else
            cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
    }
    if (zgadywanka[zmiennaB + 1][zmiennaA + 1] == 'X' || zgadywanka[zmiennaB + 1][zmiennaA + 1] == 'O')
    {
        cout << "Nie mozesz strzelic w ten sam punkt dwa razy!" << endl;
    }
    else if ((plansza[zmiennaB][zmiennaA] == 1) || (plansza[zmiennaB][zmiennaA] == 2) || (plansza[zmiennaB][zmiennaA] == 3) || (plansza[zmiennaB][zmiennaA] == 4))
    {
        if (counter_punktacji != 1)
        {
            counter_punktacji--;
            punkty++; licznik_strzalow++;
            cout << "Celny strzal! Zdobywasz punkt. Do zdobycia zostalo tyle punktow: " << counter_punktacji << endl;
            zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'X';
        }
        else if (counter_punktacji == 1)
        {
            counter_punktacji--; licznik_strzalow++;
            zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'X';
            punkty++;
            zwyciestwo();
        }

    }
    else
    {
        licznik_strzalow++;
        cout << "Niestety, nie udalo Ci sie trafic!" << endl;
        zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'O';
    }
    if (punkty < 20)
    {
        cout << "Nacisnij Enter zeby grac dalej, lub Q zeby sie poddac." << endl;
        bool czyKontynuowac = 0;
        while (!czyKontynuowac)
        {
            char znak = _getch();
            if (znak == 13)
            {
                czyKontynuowac = 1;
            }
            else if (znak == 'q' || znak == 'Q')
            {
                poddanie();
            }

        }
    }

}

void zgadywanieGracza(int zmiennaA, int zmiennaB)
{

    cout << "--------------------------------------" << endl;
    cout << "TURA GRACZA" << endl;
    cout << "--------------------------------------" << endl;
    cout << "PUNKTY: " << punkty << endl;
    wyswietlZgadywanke();
    bool petladanych = 1, petladanych2 = 1;
    while (petladanych)
    {
        cout << "Podaj wspolrzedna x: "; cin >> zmiennaA;
        while (cin.fail())
        {
            cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Podaj wspolrzedna x: "; cin >> zmiennaA;
        }
        if (zmiennaA > 0 && zmiennaA <= 10)
        {
            zmiennaA--;
            while (petladanych2)
            {
                cout << "Podaj wspolrzedna y: "; cin >> zmiennaB;
                while (cin.fail())
                {
                    cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Podaj wspolrzedna x: "; cin >> zmiennaB;
                }
                if (zmiennaB > 0 && zmiennaB <= 10)
                {
                    zmiennaB--;
                    petladanych = 0;
                    petladanych2 = 0;
                }
                else
                    cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
            }

        }
        else
            cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
    }
    if (zgadywanka[zmiennaB + 1][zmiennaA + 1] == 'X' || zgadywanka[zmiennaB + 1][zmiennaA + 1] == 'O')
    {
        cout << "Nie mozesz strzelic w ten sam punkt dwa razy!" << endl;
        czyPowtorzenie = 1;
    }
    else if ((plansza[zmiennaB][zmiennaA] == 1) || (plansza[zmiennaB][zmiennaA] == 2) || (plansza[zmiennaB][zmiennaA] == 3) || (plansza[zmiennaB][zmiennaA] == 4))
    {
        if (counter_punktacji != 1)
        {
            counter_punktacji--;
            punkty++; licznik_strzalow++;
            cout << "Celny strzal! Zdobywasz punkt. Do zdobycia zostalo tyle punktow: " << counter_punktacji << endl;
            zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'X';
        }
        else if (counter_punktacji == 1)
        {
            counter_punktacji--; licznik_strzalow++;
            zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'X';
            punkty++;
            zwyciestwoGracza();
        }

    }
    else
    {
        licznik_strzalow++;
        cout << "Niestety, nie udalo Ci sie trafic!" << endl;
        zgadywanka[zmiennaB + 1][zmiennaA + 1] = 'O';
    }

    if (punkty < 20 && czyPoddanie == 0 && punktyKomputera < 20)
    {
        cout << "Wcisnij Enter by przejsc dalej." << endl;
        bool czyKontynuowac3 = 0;
        while (!czyKontynuowac3)
        {
            char znak = _getch();
            if (znak == 13)
            {
                czyKontynuowac3 = 1;
            }

        }
    }

}

void zgadywanieKomputera()
{
    srand(time(NULL));
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "TURA KOMPUTERA" << endl;
    cout << "--------------------------------------" << endl;
    cout << "PUNKTY: " << punktyKomputera << endl;
    bool punkt_dodany = 0;
    wyswietlPlanszeGracza(zgadywankaKomputera);
    bool trafienie = 0;
    while (!trafienie)
    {
        punkt_dodany = 0;
        zmiennaB2 = rand() % 10;
        zmiennaA2 = rand() % 10;
        trafienie = 1;
        if (zgadywankaKomputera[zmiennaB2 + 1][zmiennaA2 + 1] == 'X' || zgadywankaKomputera[zmiennaB2 + 1][zmiennaA2 + 1] == 'O')
        {
            trafienie = 0;
        }
        else if ((planszaG1[zmiennaB2][zmiennaA2] == 1) || (planszaG1[zmiennaB2][zmiennaA2] == 2) || (planszaG1[zmiennaB2][zmiennaA2] == 3) || (planszaG1[zmiennaB2][zmiennaA2] == 4))
        {
            if (counter_punktacji2 != 1)
            {
                punkt_dodany = 1;
                counter_punktacji2--;
                punktyKomputera++; licznik_strzalow2++;
                zgadywankaKomputera[zmiennaB2 + 1][zmiennaA2 + 1] = 'X';
            }
            else if (counter_punktacji == 1)
            {
                punkt_dodany = 1;
                counter_punktacji2--; licznik_strzalow2++;
                zgadywankaKomputera[zmiennaB2 + 1][zmiennaA2 + 1] = 'X';
                punktyKomputera++;
            }

        }
        else
        {
            licznik_strzalow2++;
            zgadywankaKomputera[zmiennaB2 + 1][zmiennaA2 + 1] = 'O';
        }
    }
    cout << "Podaj wspolrzedna x: "; Sleep(1500); cout << zmiennaA2 + 1; Sleep(500);
    cout << endl << "Podaj wspolrzedna y: "; Sleep(1500); cout << zmiennaB2 + 1 << endl; Sleep(500);

    if (punkty < 20 && czyPoddanie == 0 && punktyKomputera < 20)
    {
        if (punkt_dodany == 1)
        {
            cout << "Celny strzal! Zdobywasz punkt. Do zdobycia zostalo tyle punktow: " << counter_punktacji2 << endl;
        }
        else
        {
            cout << "Niestety, nie udalo Ci sie trafic!" << endl;
        }
        Sleep(1000); 
        cout << "--------------------------------------" << endl;
        cout << "KONIEC TURY KOMPUTERA" << endl;
        cout << "--------------------------------------" << endl;
    }
    if (punktyKomputera == 20)
    {
        cout << "Celny strzal! Zdobywasz punkt."<< endl;
        Sleep(1000);
        cout << "--------------------------------------" << endl;
        cout << "KONIEC TURY KOMPUTERA" << endl;
        cout << "--------------------------------------" << endl;
        Sleep(1500);
        zwyciestwoKomputera();
    }




} //

void proces_gry()
{
    system("cls");
    //CHEATY
    //wyswietl_statki();
    //KONIEC CHEATOW
    cout << "PUNKTY: " << punkty << endl;
    wyswietlZgadywanke();
    zgadywanie(zmiennaA, zmiennaB);
}

void startGame()
{
    wyczysc_plansze();
    rozmiesc_statki();
    ustawZgadywanke();
    while (punkty < 20 && czyPoddanie == 0)
    {
        proces_gry();
    }
}

void planszaGraczaNaPlansze(int plansza[x][y], char zgadywanka[x + 2][y + 2])
{
    for (int i = 1; i < (x + 1); i++)
    {
        for (int j = 1; j < (y + 1); j++)
        {
            if (plansza[i - 1][j - 1] == 9 || plansza[i - 1][j - 1] == 0)
            {
                zgadywanka[i][j] = '-';
            }
            else
                zgadywanka[i][j] = 'x';

        }
    }
    for (int i = 1; i < x; i++)
    {
        zgadywanka[0][i] = (char)(i + '0');
        zgadywanka[i][0] = (char)(i + '0');
    }
    zgadywanka[x][0] = '1';
    zgadywanka[x + 1][0] = '0';
    zgadywanka[0][y] = '1';
    zgadywanka[0][y + 1] = '0';
    zgadywanka[0][0] = '/';
}

void wyswietlPlanszeGracza(char zgadywanka[x + 2][y + 2])
{
    for (int i = 0; i < (x + 1); i++)
    {
        for (int j = 0; j < (y + 2); j++)
        {
            if (j < y + 1)
            {
                cout << zgadywanka[i][j] << " ";
            }
            else if (i == 0)
                cout << zgadywanka[0][y + 1];

        }
        cout << endl;
    }
    cout << zgadywanka[x + 1][0] << endl;
}

void wyswietl_plansze2()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << planszaG1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void wyczysc_planszeG1()
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            planszaG1[i][j] = 0;
}

/*
bool soloGraczUstawiaStatki(int dlugosc, int plansza[10][10], int a, int b, int kierunek)
{
    //0 - w LEWO //1 - w górę //2 - w prawo //3 - w dół
    bool czyWolne = 0, czyZlyKierunek = 1;
    int a = 0, b = 0, kierunek = 0;
    srand(time(NULL));


    for (int s = 0; s < 1; s++) {
        czyWolne = 0; czyZlyKierunek = 1;
        while (!czyWolne)
        {
            czyWolne = 1;
            if (plansza[a][b] == 0)
            {
                while (czyZlyKierunek)
                {
                    czyZlyKierunek = 0;
                    bool czyDobryKierunek = 1;
                    switch (kierunek)
                    {
                    case 0:
                        if (b >= dlugosc - 1)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a][b - i] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a][b - k] = dlugosc;
                                }
                                if (a > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - 1][b - k] = 9;
                                    }
                                }
                                if (a < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + 1][b - k] = 9;
                                    }
                                }

                                if (a > 0 && (b - counter > 0))
                                {
                                    plansza[a - 1][b - counter - 1] = 9;
                                    plansza[a][b - counter - 1] = 9;
                                }
                                if (a < 9 && (b - counter > 0))
                                {
                                    int p = counter - 1;
                                    plansza[a + 1][b - counter - 1] = 9;
                                    plansza[a][b - counter - 1] = 9;
                                }
                                if (a > 0 && b < 9)
                                {
                                    plansza[a - 1][b + 1] = 9;
                                    plansza[a][b + 1] = 9;
                                }
                                if (a < 9 && b < 9)
                                {
                                    plansza[a + 1][b + 1] = 9;
                                    plansza[a][b + 1] = 9;
                                }

                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }


                        break;
                    case 1:
                        if (a >= dlugosc - 1)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a - i][b] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a - k][b] = dlugosc;
                                }
                                if (b > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - k][b - 1] = 9;
                                    }
                                }
                                if (b < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - k][b + 1] = 9;
                                    }
                                }

                                if (b > 0 && (a - counter > 0))
                                {
                                    plansza[a - counter - 1][b] = 9;
                                    plansza[a - counter - 1][b - 1] = 9;
                                }
                                if (b < 9 && (a - counter > 0))
                                {
                                    plansza[a - counter - 1][b] = 9;
                                    plansza[a - counter - 1][b + 1] = 9;
                                }

                                if (b > 0 && a < 9)
                                {
                                    plansza[a + 1][b - 1] = 9;
                                    plansza[a + 1][b] = 9;
                                }
                                if (b < 9 && a < 9)
                                {
                                    plansza[a + 1][b + 1] = 9;
                                    plansza[a + 1][b] = 9;
                                }

                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }

                        break;
                    case 2:
                        if (b <= y - dlugosc)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a][b + i] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a][b + k] = dlugosc;
                                }
                                if (a > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a - 1][b + k] = 9;
                                    }
                                }
                                if (a < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + 1][b + k] = 9;
                                    }
                                }

                                if (a > 0 && (b + counter < 9))
                                {
                                    plansza[a - 1][b + dlugosc] = 9;
                                    plansza[a][b + dlugosc] = 9;
                                }
                                if (a < 9 && (b + counter < 9))
                                {
                                    plansza[a + 1][b + dlugosc] = 9;
                                    plansza[a][b + dlugosc] = 9;
                                }
                                if (a > 0 && b > 0)
                                {
                                    plansza[a - 1][b - 1] = 9;
                                    plansza[a][b - 1] = 9;
                                }
                                if (a < 9 && b > 0)
                                {
                                    plansza[a + 1][b - 1] = 9;
                                    plansza[a][b - 1] = 9;
                                }


                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }


                        break;
                    case 3:
                        if (a <= x - dlugosc)
                        {

                            for (int i = 1; i < dlugosc; i++)
                            {
                                if (plansza[a + i][b] != 0)
                                {
                                    czyZlyKierunek = 1;
                                    czyDobryKierunek = 0;
                                }
                            }
                            if (czyDobryKierunek)
                            {
                                int counter = dlugosc - 1;
                                for (int k = 0; k < dlugosc; k++)
                                {
                                    plansza[a + k][b] = dlugosc;
                                }
                                if (b > 0)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + k][b - 1] = 9;
                                    }
                                }
                                if (b < 9)
                                {
                                    for (int k = 0; k < dlugosc; k++)
                                    {
                                        plansza[a + k][b + 1] = 9;
                                    }
                                }

                                if (b > 0 && (a + counter < 9))
                                {
                                    plansza[a + counter + 1][b] = 9;
                                    plansza[a + counter + 1][b - 1] = 9;
                                }
                                if (b < 9 && (a + counter < 9))
                                {
                                    plansza[a + counter + 1][b] = 9;
                                    plansza[a + counter + 1][b + 1] = 9;
                                }

                                if (b > 0 && a > 0)
                                {
                                    plansza[a - 1][b - 1] = 9;
                                    plansza[a - 1][b] = 9;
                                }
                                if (b < 9 && a > 0)
                                {
                                    plansza[a - 1][b + 1] = 9;
                                    plansza[a - 1][b] = 9;
                                }



                            }
                        }
                        else
                        {
                            czyZlyKierunek = 1;
                        }

                        break;
                    default: break;
                    }
                }
            }
            else
            {
                czyWolne = 0;
            }

        }
    }
}
*/

void soloGraczUstawiaStatki(int dlugosc)
{
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "USTAWIANIE STATKOW" << endl;
    cout << "--------------------------------------" << endl;
    planszaGraczaNaPlansze(planszaG1, ZgPlanszaG1);
    wyswietlPlanszeGracza(ZgPlanszaG1);
    bool czyWolne2 = 0, czyZlyKierunek = 1;
    int a, b, kierunek;
    int SGZmiennaA, SGZmiennaB, SGZmiennaC;
    while (!czyWolne2)
    {
        // TEN FRAGMENT KODU ODPOWIADA ZA SPRAWDZENIE CZY WSPOLRZEDNE SA W PORZADKU "GRAMATYCZNIE"

        bool petladanych = 1, petladanych2 = 1, petladanych3 = 1;
        while (petladanych)
        {
            cout << "Podaj wspolrzedna x ustawienia statku: "; cin >> SGZmiennaA;
            while (cin.fail())
            {
                cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Podaj wspolrzedna x ustawienia statku: "; cin >> SGZmiennaA;
            }
            if (SGZmiennaA > 0 && SGZmiennaA <= 10)
            {
                SGZmiennaA--;
                while (petladanych2)
                {
                    cout << "Podaj wspolrzedna y ustawienia statku: "; cin >> SGZmiennaB;
                    while (cin.fail())
                    {
                        cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Podaj wspolrzedna y ustawienia statku: "; cin >> SGZmiennaB;
                    }
                    if (SGZmiennaB > 0 && SGZmiennaB <= 10)
                    {
                        SGZmiennaB--;
                        if (dlugosc > 1)
                        {
                            while (petladanych3)
                            {
                                //0 - w LEWO //1 - w górę //2 - w prawo //3 - w dół
                                cout << "Podaj kierunek, w ktorym ma byc ustawiony statek (1 - w lewo, 2 - w gore, 3 - w prawo, 4 - w dol): "; cin >> SGZmiennaC;
                                while (cin.fail())
                                {
                                    cout << "Prosze podac prawidlowy kierunek!" << endl;
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Podaj kierunek, w ktorym ma byc ustawiony statek (1 - w lewo, 2 - w gore, 3 - w prawo, 4 - w dol): "; cin >> SGZmiennaC;
                                }
                                if (SGZmiennaC > 0 && SGZmiennaC <= 4)
                                {
                                    SGZmiennaC--;

                                    petladanych = 0;
                                    petladanych2 = 0;
                                    petladanych3 = 0;
                                }
                                else
                                    cout << "Prosze podac prawidlowy kierunek!" << endl;
                            }
                        }
                        else
                        {
                            SGZmiennaC = 0;
                            petladanych = 0;
                            petladanych2 = 0;
                            petladanych3 = 0;
                        }



                    }
                    else
                        cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
                }

            }
            else
                cout << "Prosze podac prawidlowa wspolrzedna!" << endl;
        }


        // TEN FRAMGENT ODPOWIADA ZA SPRAWDZENIE CZY MIEJSCA SĄ WOLNE
        czyWolne2 = 1;
        a = SGZmiennaB;
        b = SGZmiennaA;

        if (planszaG1[a][b] == 0)
        {

            czyZlyKierunek = 0;
            bool czyDobryKierunek = 1;

            kierunek = SGZmiennaC;
            switch (kierunek)
            {
            case 0:
                if (b >= dlugosc - 1)
                {

                    for (int i = 1; i < dlugosc; i++)
                    {
                        if (planszaG1[a][b - i] != 0)
                        {
                            czyZlyKierunek = 1;
                            czyWolne2 = 0;
                            czyDobryKierunek = 0;
                            cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                        }
                    }
                    if (czyDobryKierunek)
                    {
                        int counter = dlugosc - 1;
                        for (int k = 0; k < dlugosc; k++)
                        {
                            planszaG1[a][b - k] = dlugosc;
                        }
                        if (a > 0)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a - 1][b - k] = 9;
                            }
                        }
                        if (a < 9)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a + 1][b - k] = 9;
                            }
                        }

                        if (a > 0 && (b - counter > 0))
                        {
                            planszaG1[a - 1][b - counter - 1] = 9;
                            planszaG1[a][b - counter - 1] = 9;
                        }
                        if (a < 9 && (b - counter > 0))
                        {
                            int p = counter - 1;
                            planszaG1[a + 1][b - counter - 1] = 9;
                            planszaG1[a][b - counter - 1] = 9;
                        }
                        if (a > 0 && b < 9)
                        {
                            planszaG1[a - 1][b + 1] = 9;
                            planszaG1[a][b + 1] = 9;
                        }
                        if (a < 9 && b < 9)
                        {
                            planszaG1[a + 1][b + 1] = 9;
                            planszaG1[a][b + 1] = 9;
                        }

                    }
                }
                else
                {
                    czyZlyKierunek = 1;
                    czyWolne2 = 0;
                    cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                }


                break;
            case 1:
                if (a >= dlugosc - 1)
                {

                    for (int i = 1; i < dlugosc; i++)
                    {
                        if (planszaG1[a - i][b] != 0)
                        {
                            czyZlyKierunek = 1;
                            czyWolne2 = 0;
                            czyDobryKierunek = 0;
                            cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                        }
                    }
                    if (czyDobryKierunek)
                    {
                        int counter = dlugosc - 1;
                        for (int k = 0; k < dlugosc; k++)
                        {
                            planszaG1[a - k][b] = dlugosc;
                        }
                        if (b > 0)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a - k][b - 1] = 9;
                            }
                        }
                        if (b < 9)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a - k][b + 1] = 9;
                            }
                        }

                        if (b > 0 && (a - counter > 0))
                        {
                            planszaG1[a - counter - 1][b] = 9;
                            planszaG1[a - counter - 1][b - 1] = 9;
                        }
                        if (b < 9 && (a - counter > 0))
                        {
                            planszaG1[a - counter - 1][b] = 9;
                            planszaG1[a - counter - 1][b + 1] = 9;
                        }

                        if (b > 0 && a < 9)
                        {
                            planszaG1[a + 1][b - 1] = 9;
                            planszaG1[a + 1][b] = 9;
                        }
                        if (b < 9 && a < 9)
                        {
                            planszaG1[a + 1][b + 1] = 9;
                            planszaG1[a + 1][b] = 9;
                        }

                    }
                }
                else
                {
                    czyZlyKierunek = 1;
                    czyWolne2 = 0;
                    cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                }

                break;
            case 2:
                if (b <= y - dlugosc)
                {

                    for (int i = 1; i < dlugosc; i++)
                    {
                        if (planszaG1[a][b + i] != 0)
                        {
                            czyZlyKierunek = 1;
                            czyDobryKierunek = 0;
                            czyWolne2 = 0;
                            cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                        }
                    }
                    if (czyDobryKierunek)
                    {
                        int counter = dlugosc - 1;
                        for (int k = 0; k < dlugosc; k++)
                        {
                            planszaG1[a][b + k] = dlugosc;
                        }
                        if (a > 0)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a - 1][b + k] = 9;
                            }
                        }
                        if (a < 9)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a + 1][b + k] = 9;
                            }
                        }

                        if (a > 0 && (b + counter < 9))
                        {
                            planszaG1[a - 1][b + dlugosc] = 9;
                            planszaG1[a][b + dlugosc] = 9;
                        }
                        if (a < 9 && (b + counter < 9))
                        {
                            planszaG1[a + 1][b + dlugosc] = 9;
                            planszaG1[a][b + dlugosc] = 9;
                        }
                        if (a > 0 && b > 0)
                        {
                            planszaG1[a - 1][b - 1] = 9;
                            planszaG1[a][b - 1] = 9;
                        }
                        if (a < 9 && b > 0)
                        {
                            planszaG1[a + 1][b - 1] = 9;
                            planszaG1[a][b - 1] = 9;
                        }


                    }
                }
                else
                {
                    czyZlyKierunek = 1;
                    czyWolne2 = 0;
                    cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                }


                break;
            case 3:
                if (a <= x - dlugosc)
                {

                    for (int i = 1; i < dlugosc; i++)
                    {
                        if (planszaG1[a + i][b] != 0)
                        {
                            czyZlyKierunek = 1;
                            czyDobryKierunek = 0;
                            czyWolne2 = 0;
                            cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                        }
                    }
                    if (czyDobryKierunek)
                    {
                        int counter = dlugosc - 1;
                        for (int k = 0; k < dlugosc; k++)
                        {
                            planszaG1[a + k][b] = dlugosc;
                        }
                        if (b > 0)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a + k][b - 1] = 9;
                            }
                        }
                        if (b < 9)
                        {
                            for (int k = 0; k < dlugosc; k++)
                            {
                                planszaG1[a + k][b + 1] = 9;
                            }
                        }

                        if (b > 0 && (a + counter < 9))
                        {
                            planszaG1[a + counter + 1][b] = 9;
                            planszaG1[a + counter + 1][b - 1] = 9;
                        }
                        if (b < 9 && (a + counter < 9))
                        {
                            planszaG1[a + counter + 1][b] = 9;
                            planszaG1[a + counter + 1][b + 1] = 9;
                        }

                        if (b > 0 && a > 0)
                        {
                            planszaG1[a - 1][b - 1] = 9;
                            planszaG1[a - 1][b] = 9;
                        }
                        if (b < 9 && a > 0)
                        {
                            planszaG1[a - 1][b + 1] = 9;
                            planszaG1[a - 1][b] = 9;
                        }



                    }
                }
                else
                {
                    czyWolne2 = 0;
                    czyZlyKierunek = 1;
                    cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
                }

                break;
            default: break;
            }

        }
        else
        {
            czyWolne2 = 0;
            cout << "Nie mozna ustawic statku w taki sposob. Sprobuj ponownie" << endl;
        }

    }


}

void soloGraczUstawiaPlansze()
{
    wyczysc_planszeG1();
    soloGraczUstawiaStatki(4);
    soloGraczUstawiaStatki(3);
    soloGraczUstawiaStatki(3);
    soloGraczUstawiaStatki(2);
    soloGraczUstawiaStatki(2);
    soloGraczUstawiaStatki(2);
    soloGraczUstawiaStatki(1);
    soloGraczUstawiaStatki(1);
    soloGraczUstawiaStatki(1);
    soloGraczUstawiaStatki(1);
    system("cls");

}

void procesGry2()
{
    czyPowtorzenie = 0;
    system("cls");
    //CHEATY
    //wyswietl_statki();
    //KONIEC CHEATOW



    zgadywanieGracza(zmiennaA, zmiennaB);

    if (czyPowtorzenie == 0 && punkty < 20)
    {
        zgadywanieKomputera();
        if (punkty < 20 && punktyKomputera < 20)
        {
            cout << "Nacisnij Enter zeby grac dalej, lub Q zeby sie poddac." << endl;
            bool czyKontynuowac = 0;
            while (!czyKontynuowac)
            {
                char znak = _getch();
                if (znak == 13)
                {
                    czyKontynuowac = 1;
                }
                else if (znak == 'q' || znak == 'Q')
                {
                    poddanieGracza();
                }

            }
        }
    }


}

void graczVsKomputer()
{
    //ustawienie planszy komputera
    wyczysc_plansze();
    rozmiesc_statki();
    ustawZgadywanke();

    //ustawienie planszy przez gracza
    soloGraczUstawiaPlansze();
    cout << "--------------------------------------" << endl;
    cout << "TWOJA PLANSZA: " << endl;
    cout << "--------------------------------------" << endl;

    planszaGraczaNaPlansze(planszaKomputera, zgadywankaKomputera);
    planszaGraczaNaPlansze(planszaG1, ZgPlanszaG1);
    wyswietlPlanszeGracza(ZgPlanszaG1);
    cout << "Wcisnij Enter by rozpoczac zgadywanie." << endl;

    //rozpoczecie zgadywania
    char znak = 0;
    while (znak != 13)
    {
        if (_kbhit)
        {
            znak = _getch();
            if (znak == 13)
            {
                while (punkty < 20 && czyPoddanie == 0 && punktyKomputera < 20)
                {
                    procesGry2();
                }
            }
        }
    }

}






void zasady()
{
    char znak = 0;
    cout << "Zasady ogolne:" << endl;
    cout << "Na planszy o wymiarach 10x10 rozstawionych jest 10 statkow:" << endl;
    cout << "czteromasztowiec, dwa trojmasztowce, trzy dwumasztowce i cztery jednomasztowce." << endl;
    cout << "Za trafienie w statek gracz otrzymuje 1 punkt. " << endl;
    cout << "Nie mozna oddac strzalu w to samo miejsce wiecej niz raz." << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Tryb: Zgadywanka." << endl;
    cout << "Celem gracza jest uzyskanie 20 punktow, oddajac jak najmniej strzalow." << endl;
    cout << "Gracz ma mozliwosc poddania sie po kazdym strzale," << endl << "i mozliwosc sprawdzenia jak wygladala finalowa plansza." << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Tryb: Gracz vs Komputer." << endl;
    cout << "Celem gracza jest ustrzelenie wszystkich statkow komputera przed nim." << endl;
    cout << "Uzytkownik sam ustawia swoje statki przed startem." << endl;
    cout << "Gracz ma mozliwosc poddania sie po kazdym strzale," << endl << "i mozliwosc sprawdzenia jak wygladala plansza komputera." << endl << endl;

    cout << "Wcisnij klawisz Q zeby wrocic do menu.";
    while (znak != 'q')
    {
        if (_kbhit)
        {
            znak = _getch();
            if (znak == 'q' || znak == 'Q')
                Run();
        }
    }

}



int menu_switch2 = 0;

void draw_menu_trybow()
{
    system("cls");
    cout << "------------------------------------------------------" << endl;
    cout << "                   WYBOR TRYBU                        " << endl;
    cout << "------------------------------------------------------" << endl;
    switch (menu_switch2)
    {
    case 0:
        cout << ">> 1. Zgadywanka" << endl;
        cout << "2. Gracz vs Komputer" << endl;
        cout << "3. Powrot" << endl;
        break;
    case 1:
        cout << "1. Zgadywanka" << endl;
        cout << ">> 2. Gracz vs Komputer" << endl;
        cout << "3. Powrot" << endl;
        break;
    case 2:
        cout << "1. Zgadywanka" << endl;
        cout << "2. Gracz vs Komputer" << endl;
        cout << ">> 3. Powrot" << endl;
        break;
    }

}

void sterowanie_menu_trybow()
{
    if (_kbhit())
    {

        char znak = _getch();
        switch (znak)
        {
            //keyDown
        case 80:
            if (menu_switch2 < 2)
            {
                menu_switch2++;
                draw_menu_trybow();
            }


            break;
            //keyUp
        case 72:
            if (menu_switch2 > 0)
            {
                menu_switch2--;
                draw_menu_trybow();
            }


            break;
            //enter
        case 13:
            switch (menu_switch2)
            {
            case 0:
                system("cls");
                startGame();

                break;
            case 1:
                system("cls");
                graczVsKomputer();

                break;
            case 2:
                wyjscie2 = 1;
                system("cls");
                draw_menu();
                break;
            }


            break;
        }




    }
}

void draw_menu()
{
    system("cls");
    cout << "------------------------------------------------------" << endl;
    cout << "                        STATKI                        " << endl;
    cout << "------------------------------------------------------" << endl;
    switch (menu_switch)
    {
    case 0:
        cout << ">> 1. Rozpocznij gre" << endl;
        cout << "2. Zasady" << endl;
        cout << "3. Wyjscie" << endl;
        break;
    case 1:
        cout << "1. Rozpocznij gre" << endl;
        cout << ">> 2. Zasady" << endl;
        cout << "3. Wyjscie" << endl;
        break;
    case 2:
        cout << "1. Rozpocznij gre" << endl;
        cout << "2. Zasady" << endl;
        cout << ">> 3. Wyjscie" << endl;
        break;
    }
}

void sterowanie_menu()
{
    if (_kbhit())
    {

        char znak = _getch();
        switch (znak)
        {
            //keyDown
        case 80:
            if (menu_switch < 2)
            {
                menu_switch++;
                draw_menu();
            }


            break;
            //keyUp
        case 72:
            if (menu_switch > 0)
            {
                menu_switch--;
                draw_menu();
            }


            break;
            //enter
        case 13:
            switch (menu_switch)
            {
            case 0:
                menu_switch2 = 0;
                wyjscie2 = 0;
                system("cls");
                draw_menu_trybow();



                while (!wyjscie2 && punkty < 20 && czyPoddanie == 0 && punktyKomputera < 20)
                {
                    sterowanie_menu_trybow();
                }

                break;
            case 1:
                system("cls");
                zasady();

                break;
            case 2:
                wyjscie = 1;
                break;
            }


            break;
        }




    }
}



void Run()
{
    draw_menu();
    while (!wyjscie && punkty < 20 && czyPoddanie == 0)
    {
        sterowanie_menu();
    }
}

int main()
{
    srand(time(NULL));
    Run();
    cout << endl;
    return 0;
}
