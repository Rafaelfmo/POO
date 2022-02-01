#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>

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

    vector<Telefone> getTelefone()
    {
        return this->telefones;
    }
    
    void Adicionar(Telefone telefone)
    {
        this->telefones.push_back(telefone);
        cout << "Telefone adicionado" << endl;
    }

    void Remover(int index)
    {
        for (int i = 0; i < telefones.size(); i ++)
        {
            if (i == index)
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
    map <string, Contato> contatos;

public:
    Agenda(){}
 
    void AdicionarContato(Contato contato)
    {
        auto it = contatos.find(contato.getNome());
        if (it == contatos.end())
        {
            contatos[contato.getNome()] = contato;
        }
        else 
        {
            for (Telefone telefone : contato.getTelefone())
            {
                it->second.Adicionar(telefone);
            }
        }
    }

    void RemoverContato(string nome)
    {
        auto it = contatos.find(nome);
        if (it != contatos.end())
        {
            contatos.erase(it);
        }
    }

    vector<Contato> ProcurarContato(string palavra)
    {
        vector<Contato> aux;
        for (auto& i : this->contatos)
        {
            stringstream ss;
            ss << i.second;
            string texto = ss.str();
            if (texto.find(palavra) != string::npos)
            {
                aux.push_back(i.second);
            }
        }
        return aux;
    }

    friend ostream& operator<< (ostream& os, const Agenda& agenda)
    {
        for (auto i : agenda.contatos)
        {
            os << i.first << i.second << endl;
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
    agenda.ProcurarContato("r");
    
    return {0};
}