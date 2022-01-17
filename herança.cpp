#include <iostream>
using namespace std;

class Humano
{
private:
    bool vivo {true};

public:
    Humano(){cout << "O humano foi criado" << endl;}
    

    void Comer()
    {
        cout << "O humano comeu" << endl;
    }

    void Crescer()
    {
        cout << "O humano Cresceu" << endl;
    }
    
    void Reproduzir()
    {
        cout << "O humano reproduziu e foi comprar cigarro" << endl;
    }
    void morrer()
    {
        cout << "O humano morreu" << endl;
        vivo = false;
    }

    bool isvivo()
    {
        return vivo;
    }

    friend ostream& operator << (ostream& os, Humano& humano)
    {
        os << "O humano está vivo? " << humano.vivo << endl;
        return os;
    }
};

class Crianca : public Humano
{
private:
    bool vivo {true};
    string nome {""};
public:
    Crianca(string nome) : nome{nome}{cout << "A criança nasceu" << endl;}

    void Brincar()
    {
        if (this->isvivo())
        {
            cout << this->nome << " Está brincando" << endl;
        }
    }
};


int main()
{
    Crianca humano("mateus");
    cout << humano << endl;
    humano.Comer();
    humano.Crescer();
    humano.Reproduzir();
    humano.morrer();
    humano.Brincar();
    return 0;
}