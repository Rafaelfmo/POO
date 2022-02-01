#include <iostream>
#include <vector>
#include <memory>
#include <map>
using namespace std;

class Cliente
{
public:
    string id{""};
    long int numero{0};

    Cliente(string id = "", long int numero = 0) : id{id}, numero{numero}{}

    friend ostream& operator<< (ostream& os, const Cliente& cliente)
    {
        os << "id: " << cliente.id << ", " << "Telefone: " << cliente.numero << endl;
        return os;
    }
};

class Sala
{
private:
    map<int, shared_ptr<Cliente>> assentos;

public:

    Sala(int qtd_assentos)
    {
        for (int i = 0; i < qtd_assentos; i++)
        {
            assentos[i] = nullptr;
        }
    }

    bool reservar(const shared_ptr<Cliente>& cliente, int num_vagas)
    {
        for (int i = 0; i < assentos.size(); i++)
        {
            if(this->assentos[i] != nullptr && this->assentos[i]->id == cliente->id)
            {
                cout << "erro" << endl;
                return false;
            }
        }

        if(this->assentos[num_vagas] != nullptr)
        {
            cout << "funcionou" << endl;
            return false;
        }
        if(this->assentos[num_vagas] == nullptr)
        {
            this->assentos[num_vagas] = cliente;
            cout << "funcionou2" << endl;
            return true;
        }
        return false;
    }

    bool cancelar(const shared_ptr<Cliente>& cliente)
    {
        for (int i = 0; i < assentos.size(); i++)
        {
            if(this->assentos[i] != nullptr && this->assentos[i]->id == cliente->id)
            {
                assentos[i] = nullptr;
                cout << "cancelado" << endl;
                return true;
            }
        }
        cout << "erro" << endl;
        return false;
    }

 friend ostream& operator<<(ostream& os, const Sala& sala){
        os << "[ ";
        for(int i = 0; i < sala.assentos.size(); i++){
            auto cadeiras = sala.assentos;
            os << " ";
            if(cadeiras[i] != nullptr){
                os << *cadeiras[i];
            } else {
                os << "-";
            }
            os << " ";
        }
        os << "]" << endl;
        return os;
    }

};

int main()
{
    Sala sala (5);
    cout << sala;
    
    sala.reservar(make_shared<Cliente>("Joao", 1111), 7);
    sala.reservar(make_shared<Cliente>("Joao", 1111), 1);
    sala.reservar(make_shared<Cliente>("Maria", 2222), 6);
    sala.reservar(make_shared<Cliente>("Cladinho", 3333), 6);
    sala.reservar(make_shared<Cliente>("Manu", 4444), 4);
    sala.reservar(make_shared<Cliente>("Teteu", 5555),5);
    sala.reservar(make_shared<Cliente>("Rafael", 6666), 3);
    sala.reservar(make_shared<Cliente>("Adam", 7777), 0);

    cout << sala;

    sala.cancelar(make_shared<Cliente>("Teteu", 5555));   

    cout << sala; 
    return 0;
}