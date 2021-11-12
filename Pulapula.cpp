#include <iostream>
#include <list>
#include <algorithm>
#include <memory>
using namespace std;

class Crianca
{
private:
    int idade{0};
    string nome{""};

public:
    Crianca(int idade = 0, string nome = "") : idade{idade}, nome{nome}{}

    friend ostream& operator<< (ostream& os, const Crianca& crianca)
    {
         os << "Nome: " << crianca.nome <<", " << " Idade: " << crianca.idade << endl;
        return os;
    }
};

class Pulapula
{
private:
    list <shared_ptr<Crianca>> fila;
    list <shared_ptr<Crianca>> pulapula;

public:
    Pulapula(int tamanho) : fila(tamanho, nullptr){}

    void Colocar(const shared_ptr<Crianca> &crianca)
    {
        this->fila.push_back(crianca);
    }

    void entrar()
    {
            this->pulapula.push_back(*(this->fila.rbegin()));
            this->fila.pop_back();
    }

    void sair()
    {
        this->fila.push_back(*(this->pulapula.rbegin()));
        this->pulapula.pop_back();
    }

    friend ostream& operator<< (ostream& os, const Pulapula& pulapula)
    {
        os << "Brincando: ";
        for(auto brincando: pulapula.pulapula){
            if(brincando != nullptr){
                os << *brincando;
            }
        }
        os << "\n";
        os << "Esperando: \n";
        for(auto esperando: pulapula.fila){
            if(esperando != nullptr){
                os << *esperando;
            }
        }
        os << "\n";

        return os;
    }
};

int main()
{
    Pulapula fila(5);

    fila.Colocar(make_shared<Crianca>(19, "Rafael"));
    fila.Colocar(make_shared<Crianca>(19, "Mateus"));
    cout << fila << endl;

    fila.entrar();
    fila.sair();

    cout << fila << endl; 
    return 0;
}
