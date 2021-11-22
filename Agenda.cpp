#include <iostream>
#include <vector>

using namespace std;

class Telefone
{
private:
    string id;
    string numero;

public:
    Telefone(string id = "", string numero = 0) : id{id}, numero{numero}{}

    friend ostream& operator<<(ostream& os, const Telefone& telefone)
    {
        cout << telefone.id << ": " << telefone.numero << endl;
    }
    
    string getId()
    {
        return this->id;
    }

    void setId(string id)
    {
        if (this->id == " ")
        {
            cout << "Id inválido" << endl;
        }
        else
        {
            this->id = id;
        }
    }

    string getnumero()
    {
        return this->numero;
    }

    void setNumero(int numero)
    {
            this->numero = numero;    
    }

    bool Validação(string numero)
    {
        int verificador;
        for (int i = 0; i < numero.size(); i++)
        {
            if (numero[i] >= 0 || numero[i] <= 9)
            {
                return true;
            }
        }
        return false;
    }

};

class Contato
{
private:
    string nome;
    vector <Telefone> telefones;

public:
    Contato(string nome = "") : nome{nome}{}

    void Remover(string nome)
    {
        for (int i = 0; i < telefones.size(); i ++)
        {
           if (telefones[i].getId() == nome)
           {
               telefones.erase(telefones.begin()+i);
           }
        }
    }

    void Adicionar(Telefone telefone)
    {  
        telefones.push_back(telefone);
        cout << "Contato adicionado" << endl;     
    }

    friend ostream& operator<<(ostream& os, const Contato& contato)
    {
        int cont = 0;
        os << "- " << contato.nome << " " << endl;
        for (auto it = contato.telefones.begin(); it != contato.telefones.end(); it++)
        {
            cout << "[" << cont << ":" << *it;
            cont++;
        }
        os << "\n";
        return os;
    }
};

int main()
{
    Contato fone ("Rafael");
    return(0);
}
