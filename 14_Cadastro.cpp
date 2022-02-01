#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <sstream>
using namespace std;

class Conta
{
protected:
    int id;
    float saldo;
    string clienteId;
    string tipo_de_conta {""};

public:
    Conta(int id = 0, string clienteId = "") : id{id}, clienteId{clienteId}{};

    virtual void Atualizacao_mensal(){}

    void Saque(float valor)
    {
        this->saldo -= valor;
    }

    void Deposito(float valor)
    {
        this->saldo += valor;
    }

    void Transferir(shared_ptr<Conta> aux, float valor)
    {
        this->saldo -= valor;
        aux->saldo += valor;
    }

    int getId()
    {
        return this->id;
    }

    float getSaldo()
    {
        return this->saldo;
    }

    string getClienteId()
    {
        return this->clienteId;
    }            

    string getType()
    {
        return this->tipo_de_conta;
    }    

    friend ostream& operator<< (ostream& os, const Conta& conta)
    {
        os << conta.id << ":" << conta.clienteId << ":" << conta.saldo << ":" << conta.tipo_de_conta;
        return os;
    }
};

class VerificandoConta : public Conta
{
public:
    VerificandoConta(int id = 0, string clienteId = "") : Conta{id, clienteId}
    {
        tipo_de_conta = "CC";
    };

    void Atualizacao_mensal()
    {
        if (this->saldo - 20 < 0)
        {
            saldo = 0;
        }
        else 
        {
            saldo -= 20;
        }
    } 
};

class SavingConta : public Conta
{
public:
    SavingConta(int id = 0, string clienteId = "") : Conta{id, clienteId}{}

    void Atualizaao_mensal()
    {
        this->saldo = this->saldo + (saldo * 0.01);
    }
};

class Cliente
{
private:
    list<shared_ptr<Conta>> contas;
    string clienteId;
public:    
    Cliente(string clienteId) : clienteId{clienteId}{}

    void AdicionarConta(shared_ptr<Conta> conta)
    {
        this->contas.push_back(conta);
    }

    list<shared_ptr<Conta>> getContas()
    {
        return this->contas;
    }

    string getClienteId()
    {
        return this->clienteId;
    }

    void setClienteId(string clienteId)
    {
        this->clienteId = clienteId;
    }
    
    void setContas(list<shared_ptr<Conta>> contas)
    {
        this->contas = contas;
    }

    friend ostream& operator<<(ostream& os, Cliente& cliente)
    {
        for (auto &conta : cliente.contas)
        {
            os << *conta << "\n";
        }
        return os;
    }
};

class Banco
{
private:
    map<int, shared_ptr<Conta>> contas;
    map<string, shared_ptr<Cliente>> clientes;

    Conta* getConta(int id)
    {
        return this->contas[id].get();
    }

    void Conta_existe(int conta)
    {
        if(this->contas.size() <= conta)
        {
            cout << "Erro" << endl;
        }
    }

public:
    Banco(){}

    void AdicionarCliente(string clienteId)
    {
        for (auto conta : clientes)
        {
            if (conta.first == clienteId)
            {
                cout << "Erro" << endl;
            }
        }
    }

    void deposito (int ClienteID, float valor)
    {
        auto conta = getConta(ClienteID);
        if (this->contas.size() <= ClienteID)
        {
            cout << "Erro" << endl;
        }
        else
        {
            conta->Deposito(valor);
        }
    }
    
    void atualizacao_mensal()
    {
        for (auto conta : contas)
        {
            conta.second->Atualizacao_mensal();
        }
    }

    void transferencia(int conta1, int conta2, float valor)
    {
        Conta_existe(conta1);
        Conta_existe(conta2);
        auto conta = getConta(conta1);

        conta->Transferir( *(this->contas[conta2]), valor);
    }

    void Saque(int ClienteID, float valor)
    {
        Conta_existe(ClienteID);
        auto conta = getConta(ClienteID);

        conta->Transferir(valor);
    }

    friend ostream& operator<<(ostream& os, Banco& banco) {
        int cont = 0;
        os << "Clientes:\n";
        for (auto a : banco.clientes) {
            os << "- " << a.first << "[" << cont << (cont + 1) << "]\n";
            cont += 2;
        }
        os << "Contas:\n";
        for (auto c : banco.contas) {
            os << c.second;
        }
        return os;
    }
};

int main () {
    Banco* banco = new Banco;
    while (true){
        std::string line, cmd;
        std::cin >> cmd;
        getline(std::cin, line);
        std::stringstream ss(line);

        try{
            if (cmd == "end")
                break;
            else if (cmd == "show")
                std::cout << banco;
            else if (cmd == "update")
                banco->atualizacao_mensal();
            else if (cmd == "addCli") {
                std::string nome;
                ss >> nome;
                banco->AdicionarCliente(nome);
            }
            else if (cmd == "saque") {
                int conta;
                float value;
                ss >> conta >> value;
                banco->Saque(conta, value);
            }
            else if (cmd == "deposito") {
                int conta;
                float valor;
                ss >> conta >> valor;
                banco->deposito(conta, valor);
            }
            else if (cmd == "transf") {
                int envio, remetente;
                float value;
                ss >> envio >> remetente >> value;
                banco->transferencia(envio, remetente, value);
            }
            else
                std::cout << "fail: comando invalido\n";
        } catch (std::runtime_error &e) {
            std::cout << "fail: " << e.what() << '\n';
        }
    }

    delete banco;

    return 0;
}
