#include <iostream>
#include <algorithm>
using namespace std;

struct Grafite
{
    float calibre {0.0};
    string dureza {""};
    int tamanho {0};

    Grafite(float calibre = 0.0, string dureza = "", int tamanho = 0) : calibre{calibre}, dureza{dureza}, tamanho{tamanho}{}

    friend ostream& operator<<(ostream& os, const Grafite& grafite)
    {
        os << "Calibre: " << grafite.calibre << " mm, ";
        os << "Dureza: " << grafite.dureza << ", ";
        os << "Tamanho: " << grafite.tamanho << " mm\n ";
        return os;
    }
};

struct Lapiseira
{
    float calibre {0};
    Grafite* grafite;
    

    Lapiseira(float calibre, Grafite* grafite = nullptr) : calibre{calibre}, grafite{grafite}{}

    bool Colocargrafite(Grafite* grafite)
    {
        if (this->grafite != nullptr)
        {
            cout << "Lapiseira já possui grafite\n";
            return false;
        }
        if (grafite->calibre != this->calibre)
        {
            cout << "Calibre errado\n";
            return false;
        }
        this->grafite = grafite;
        return true;
    }
    
    Grafite* Tirargrafite()
    {
        if (this->grafite == nullptr)
        {
            cout << "Não possui grafite";
            return nullptr;
        }
        return exchange(this->grafite, nullptr);
    }
};

int main()
{
    Grafite grafite(10, "HC", 10);
    Lapiseira lapiseira(0.5, &grafite);
    return 0;
}
