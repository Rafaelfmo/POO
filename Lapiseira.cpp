#include <iostream>
using namespace std;

struct Grafite
{
    float calibre {0};
    string dureza {""};
    int tamanho {0};
};

struct Lapiseira
{
    float calibre {0};
    Grafite grafite;

    void Escrever(int tamanho)
    {

    }

    bool ColocarGrafite(string dureza, float calibre)
    {
        if (dureza == "hb" && calibre == 1)
    }
};

int main()
{
    Grafite g = {0.5, "Hb", 1};
    cout  << "o grafite tem calibre: "<< g.calibre << "\n" << "dureza: " << g.dureza << "\n" << "e tamanho: "<< g.tamanho << endl;

    return 0;
}

