#include <chrono>
#include <iostream>
#include <thread>
#include <time.h>
#include <unistd.h>
#include <string>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif

/// Curata consola in functie de sistemul de operare (Windows sau Linux/MacOS)
void console_clean()
{
#ifdef _WIN32
    system("CLS");
#endif
#ifdef __linux__
    system("clear");
#endif
}

/// Pentru a "adormi" procesul.
void console_sleep()
{
#ifdef _WIN32
    Sleep(2000);
#endif

#ifdef __linux__
    // usleep(2000000);
    this_thread::sleep_for(chrono::milliseconds(2000));
#endif
}

/// Mesaj de indrumare
void cout_message(short int stare, short int incercari)
{
    if (!stare)
    {
        console_clean();
        cout << "Numarul este prea mic. Mai ai " << 10 - incercari
             << " incercari.\n";
    }
    else
    {
        console_clean();
        cout << "Numarul este prea mare. Mai ai " << 10 - incercari
             << " incercari.\n";
    }
}

/// Generator de numar random
int number_generator()
{
    srand(time(0));
    return (rand() % 100 + 1);
}

/// Daca numarul introdus respecta cerinta

bool isNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool number_valid(int nr)
{
    string number = to_string(nr);
    if (!isNumber(number))
    {
        console_clean();
        cout << "Caracterul citit nu este un numar, te rog sa introduci un numar.\n";
    }
    else
    {
        if (1 <= nr && nr <= 100)
        {
            return true;
        }
        else
        {
            console_clean();
            return false;
        }
    }
}

/// Afisarea corecta a mesajelor
void grammar_word(short int n)
{
    if (n == 1)
    {
        cout << "o incercare.";
    }
    else
    {
        cout << n << " incercari.";
    }
}

int main()
{
    cout << "Jocul a inceput. Alege un numar intre 1 - 100.\n";
    bool reGame = false;
    while (true)
    {
        int nrAles = number_generator();
        int nrIncercari = 0, nrCitit;
        if (reGame)
        {
            cout << "Jocul a reinceput. Alege un numar intre 1 - 100.\n";
        }
        bool ok = false;
        do
        {
            cin >> nrCitit;
            while (!number_valid(nrCitit))
            {
                cout << "Numarul citit nu respecta inctervalul. Te rog sa introduci un "
                        "numar corect.\n";
                cin >> nrCitit;
            }
            nrIncercari++;
            if (nrAles == nrCitit)
            {
                console_clean();
                ok = true;
            }
            else
            {
                if (nrAles > nrCitit)
                {
                    cout_message(0, nrIncercari);
                }
                else
                    cout_message(1, nrIncercari);
            }
        } while (nrIncercari < 10 && !ok);
        console_clean();
        if (!ok)
        {
            cout << "Ai pierdut. Nu ai reusit sa gasesti numarul " << nrAles
                 << " din un total de 10 incercari.";
        }
        else
        {
            cout << "Bravo! Ai ghicit numarul castigator din ";
            grammar_word(nrIncercari);
        }
        console_sleep();
        console_clean();
        char s = '\0';
        cout << "Vrei sa mai joci o runda ? [y/n] \n";
        cin >> s;
        if (s != 'y' && s != 'Y')
        {
            console_clean();
            cout << "Ne-a facut o placere! Te mai asteptam.\n";
            cout << "Code 4.\n";
            break;
        }
        else
        {
            reGame = true;
            console_clean();
        }
    }
    return 0;
}
