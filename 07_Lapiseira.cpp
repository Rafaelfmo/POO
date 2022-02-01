#include <iostream>
#include <algorithm>
#include <vector>
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

    int desgaste()
    {
        if (this->dureza == "HB") return 1;
        else if (this->dureza == "2B") return 2;
        else if (this->dureza == "4B") return 4;
        else if (this->dureza == "6B") return 6;
        else return 0;
    }
};

struct Lapiseira
{
    float calibre {0};
    vector<Grafite> grafite;
    

    Lapiseira(float calibre = 0) : calibre{calibre}{}

    friend ostream &operator<< (ostream &os, const Lapiseira &lapiseira){
        os << "Calibre: " << lapiseira.calibre << "\n";
        if (lapiseira.grafite.empty()){
            os << "Grafite: null\n";
        }
        else{
            for (int i = 0; i < lapiseira.grafite.size(); i++)
            {
                os << lapiseira.grafite[i];
            }
            
        }
        return os;
    }

    bool Colocargrafite(Grafite &grafite)
    {
        if (grafite.calibre != this->calibre)
        {
            cout << "Calibre incompativel" << endl;
            return true;
        }
        if (this->grafite.size() == 4)
        {
            cout << "Grafite completo" << endl;
            return true;
        }
        this->grafite.push_back(grafite);
        return true;
    }
    
    vector<Grafite> Tirargrafite(int i)
    {
        if (this->grafite.empty())
        {
            cout << "Não possui grafite" << endl;
            return this->grafite;
        }
        vector<Grafite> aux = this->grafite;
        this->grafite.erase(this->grafite.begin()+i);
        return aux;
    }
};

int main()
{
    Grafite grafite(10, "HC", 10);
    Lapiseira lapiseira(0.5);
    return 0;
}
