#include <iostream>
using namespace std;

struct Grafite
{
    float calibre {0};
    string dureza {""};
    int tamanho {0};

    int Desgaste()
    {
        if (this-> dureza == "HB")
        {
            return 1;
        } else if (this-> dureza == "2B")
        {
            return 2;
        } else if (this-> dureza == "4B")
        {
            return 4;
        } else if (this-> dureza == "6B")
        {
            return 6;
        }
        return 0;
    }
    
};

struct Lapiseira
{
    float calibre {0};
    Grafite grafite;

    void Escrever(int folhas)
    {
        int desgaste = this->grafite.Desgaste();

        for (int i = 0; i != folhas; i++)
        {
            if (this->grafite.tamanho - desgaste > 0)
            {
                this-> grafite.tamanho -= desgaste;
            } else if (this-> grafite.tamanho - desgaste <= 0)
            {
                cout << "Acabou o grafite" << endl;
                this-> remover();
                break;
            }
        }
    }

    bool ColocarGrafite(Grafite grafite)
    {
        if (this->grafite.dureza == "nulll")
        {
            if (this->calibre != grafite.calibre)
            {
                cout << "Calibre errado" << endl;
            } else  {
                this-> grafite = grafite;
                    }
            return true;
        }
        return false;    
    }

    Grafite remover()
    {
        Grafite aux{this->grafite};
        this-> grafite = *new Grafite();
        return aux;
    }
};

int main()
{
    

    return 0;
}

