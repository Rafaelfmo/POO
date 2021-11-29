#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Telefone
{
private:
    string id;
    string numero;

public:
    Telefone(string id = "", string numero = 0) : id{id}, numero{numero}{}

    string getId()
    {
        return this->id;
    }

    string getNumero()
    {
        return this->numero;
    }

    bool Validar(string numero)
    {
        for (int i = 0; i < (int) numero.size(); i++)
        {
            if (numero[i] >= '0' && numero[i] <= '9')
            {
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<< (ostream& os, const Telefone& telefone)
    {
        os << "Id: " << telefone.id << ", " << "Número: " << telefone.numero << endl;
        return os;
    }
};

class Contato
{
private:
    string nome;
    vector <Telefone> telefones;

public:
    Contato(string nome = "") : nome{nome}{}

    string getNome()
    {
        return this->nome;
    }
    
    void Adicionar(Telefone telefone)
    {
        this->telefones.push_back(telefone);
        cout << "Telefone adicionado" << endl;
    }

    void Remover(string numero)
    {
        for (int i = 0; i < telefones.size(); i ++)
        {
            if (this->telefones[i].getNumero() == numero)
            {
                this->telefones.erase(telefones.begin()+i);
                cout << "telefone removido" << endl;
            }
        }
    }

    friend ostream& operator<< (ostream& os, const Contato& contatos)
    {
        for (int i = 0; i < contatos.telefones.size(); i++)
        {
            os << contatos.telefones[i] << endl;
        }
        return os;
    }
};

class Agenda
{
private:
    vector <Contato> contatos;

public:
    Agenda(){}

    vector<Contato> getContato()
    {
        return this->contatos;
    }
    
    void AdicionarContato(Contato contato)
    {
        this->contatos.push_back(contato);
        cout << "Contato adicionado" << endl;
    }

    void RemoverContato(string nome)
    {
        for (int i = 0; i < contatos.size(); i++)
        {
            if (this->contatos[i].getNome() == nome)
            {
                this->contatos.erase(contatos.begin()+i);
                cout << "Contato removido" << endl;              
            }
        }
    }

    vector<Contato> ProcurarContato(string palavra)
    {
        vector<Contato> aux;
        for (auto& c : this->contatos)
        {
            stringstream ss;
            ss << c;
            string texto = ss.str();
            if (texto.find(palavra) != string::npos)
            {
                aux.push_back(c);
            }
        }
        return aux;
    }

    int EncontrarPosicao(string nome)
    {
        for (int i = 0; i < contatos.size(); i++)
        {
            if (contatos[i].getNome() == nome)
            {
                return i;
            }
        }
        return -1;
    }

    friend ostream& operator<< (ostream& os, const Agenda& agenda)
    {
        for (int i = 0; i < (int) agenda.contatos.size(); i++)
        {
            os << agenda.contatos[i] << endl;
        }
        return os;
    }
};

int main()
{
    Agenda agenda;
    Contato contato("rafael");
    Telefone telefone("oi", "988794094");
    

    telefone.Validar("996237064");
    telefone.getNumero();

    contato.Adicionar(telefone.getNumero());
    contato.getNome();

    agenda.AdicionarContato(contato);
    agenda.getContato();
    agenda.EncontrarPosicao("rafael");
    agenda.ProcurarContato("r");
    
    return {0};
}