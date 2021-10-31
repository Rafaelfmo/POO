#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pessoa
{
    string nome {""};
    int idade {0};
    float peso {0};

    Pessoa(string nome = "", int idade = 0, float peso = 0) : nome{nome}, idade{idade}, peso{peso}{}

    friend ostream& operator<<(ostream& os, const Pessoa& pessoa)
    {
        os << "nome: " << pessoa.nome << "\n";
        os << "idade: " << pessoa.idade << " anos\n";
        os << "peso: " << pessoa.peso << " kg's";
        return os;
    }
};

struct Moto
{
    int potencia{1};
    int minutos{0};
    Pessoa* pessoa{nullptr};

    Moto(int potencia = 1, int minutos = 0, Pessoa* pessoa = nullptr) : potencia{potencia}, minutos{minutos}, pessoa{pessoa}{}

    bool InserirHumano(Pessoa* pessoa)
    {
        if (this->pessoa = nullptr)
        {
            cout << "não tem criança no volante, vamos colocar uma\n";
            this->pessoa = pessoa;
            return true;
        }
    }

    Pessoa* RemoverHumano()
    {
       if (Pessoa* pessoa = this->pessoa)
        return exchange(this->pessoa, nullptr);
    }

    bool VerificarHumano(Pessoa* pessoa)
    {
        if (this->pessoa != nullptr)
        {
        cout << "Tem uma criança no volante\n";
        return true;
        }
        if (this->pessoa = nullptr)
        {
            cout << "Sem criaças no volante";
            return false;
        }
    }

    void CompraMinutos(int minutos)
    {
        this->minutos += minutos;
    }

    bool Dirigir(int tempo)
    {
        if (this->pessoa == nullptr)
        {
            cout << "Não existe motorista";
            return false;
        }
        if (this->minutos < minutos)
        {
            cout << "A criança dirigu por: " << this->minutos << "minutos\n";
            this->minutos = 0;
            return true;
        }
        cout << "A criança dirigiu por: " << this->minutos << "minutos\n";
        this->minutos -= minutos;
    }
};
    
 ostream& operator<<(ostream& os, const Moto& moto)
    {
        os << "potencia: " << moto.potencia << "\n";
        os << "minutos: " << moto.minutos << " minutos\n";
        os << "Pessoa: " << moto.pessoa->nome << " ";
        return os;
    }

int main()
{
    Pessoa humano ("Rafael", 19, 70);
    Moto vrumvrum (10, 30, &humano);
    cout << vrumvrum << endl;
    return 0;
}