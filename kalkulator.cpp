#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> oceny;

inline int min(vector<int> v)
{
    int naj = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < naj)
        {
            naj = v[i];
        }
    }

    return naj;
}

inline int max(vector<int> v)
{
    int naj = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > naj)
        {
            naj = v[i];
        }
    }

    return naj;
}

inline int srednia(vector<int> v)
{
    double suma;

    for (int i = 0; i < v.size(); i++)
    {
        suma += v[i];
    }

    return suma / oceny.size();
}

void wypiszOceny()
{
    if (oceny.size() == 0)
    {
        return;
    }

    cout << "Twoje oceny: " << endl;
    for (int i = 0; i < oceny.size(); i++)
    {
        if (i == oceny.size() - 1)
        {
            cout << oceny[i];
            continue;
        }

        cout << oceny[i] << ", ";
    }
    cout << endl << endl;
}

vector<long long> fibonacci(int cyfry)
{
    vector<long long> ciag;

    ciag.push_back(0);
    ciag.push_back(1);

    int i = 2;
    while (i <= cyfry)
    {
        long long c = ciag[i - 2] + ciag[i - 1];
        ciag.push_back(c);
        i++;
    }

    return ciag;
}

string fibonacci(int cyfry, bool t)
{
    if (!t)
    {
        return "";
    }

    vector<long long> f = fibonacci(cyfry);
    string s = "";

    for (int i = 0; i < f.size(); i++)
    {
        s.append(to_string(f[i]));
    }

    return s;
}

int main()
{
    wypiszOceny();

    cout << "[1] Dodaj oceny koncowe" << endl;
    cout << "[2] Oblicz srednia ocen koncowych" << endl;
    cout << "[3] Pokaz najwyzsza ocene" << endl;
    cout << "[4] Pokaz najnizsza ocene" << endl;
    cout << "[5] Oblicz frekwencje" << endl;
    cout << "[6] Sprawdz czy zdales" << endl;
    cout << "[7] Ciag fibonacciego" << endl;
    cout << "[8] Pokaz informacje o programie" << endl;

    cout << endl;
    
    string b;
    getline(cin, b);

    char a = '0';
    if (b.size() != 0)
    {
        a = b[0];
    }
    if (b.size() > 1)
    {
        a = '0';
    }

    switch (a)
    {
        case '1':
        {
            cout << "Aby powrocic do menu nalezy nacisnac enter" << endl;
            cout << "Dodaj oceny: " << endl;

            oceny.clear();

            string a = "";
            while (getline(cin, a))
            {
                if (a.empty() || a == "")
                {
                    break;
                }

                int b = 0;

                try
                {
                    b = stoi(a);
                }
                catch(const exception& e)
                {
                    cout << "Wpisz poprawna liczbe." << endl;
                    continue;
                }

                if (b > 6 || b < 1)
                {
                    cout << "Nie ma takiej oceny." << endl;
                    continue;
                }

                oceny.push_back(b);

                cout << "Dodano " << b << endl;
            }

            wypiszOceny();
            break;
        }
        case '2':
        {
            if (oceny.size() == 0)
            {
                cout << "Nie masz zadnych ocen." << endl;
                break;
            }

            double suma;

            for (int i = 0; i < oceny.size(); i++)
            {
                suma += oceny[i];
            }

            double srednia = suma / oceny.size();

            cout << "Twoja srednia wynosi " << srednia;
            break;
        }
        case '3':
        {
            if (oceny.size() == 0)
            {
                cout << "Nie masz zadnych ocen." << endl;
                break;
            }

            cout << "Twoja najwyzsza ocena to " << max(oceny) << endl;
            break;
        }
        case '4':
        {
            if (oceny.size() == 0)
            {
                cout << "Nie masz zadnych ocen." << endl;
                break;
            }

            cout << "Twoja najnizsza ocena to " << min(oceny) << endl;
            break;
        }
        case '5':
        {
            cout << "Podaj przez ile dni byles w szkole: " << endl;
            int ob;
            cin >> ob;
            cout << "Podaj przez ile dni cie nie bylo w szkole: " << endl;
            int nb;
            cin >> nb;

            int dni = ob + nb;
            double frekwencja = (double) ob / dni * 100;

            cout << "Twoja frekwencja wynosi " << frekwencja << "%" << endl;
            break;
        }
        case '6':
        {
            if (oceny.size() == 0)
            {
                cout << "Nie dodales zadnych ocen. Jezeli zadnej nie masz to nie zdales." << endl;
                break;
            }

            int zagrozenia = 0;

            for (int i = 0; i < oceny.size(); i++)
            {
                if (oceny[i] == 1)
                {
                    zagrozenia++;
                }
            }

            if (zagrozenia != 0)
            {
                cout << "Masz " << zagrozenia << " zagrozenia, jesli ich nie poprawisz to nie zdasz." << endl;
            }
            else
            {
                cout << "Nie masz zadnych zagrozen. Na razie zdajesz." << endl;
            }
            break;
        }
        case '7':
        {
            string s = fibonacci(65, true);
            cout << "Pierwsze " << s.size() << " znakow ciagu fibonacciego" << endl;
            cout << s << endl;
            break;
        }
        case '8':
        {
            cout << "Nazwa programu: \"Kalkulator ocen\"" << endl;
            cout << "Autor: Szymon Desperak" << endl;
            break;
        }
        default:
        {
            system("cls");
            cout << "Wybierz poprawna opcje " << endl;
            return main();
        }
    }

    system("pause > null");
    system("cls");
    return main();
}