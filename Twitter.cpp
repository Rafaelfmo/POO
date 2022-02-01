#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <list>

using namespace std;

class Usuario
{
private:
    string nome;
    map<string, Usuario*> seguindo;
    map<string, Usuario*> seguidores;
    Inbox inbox;

public:
    Usuario(string nome) : nome{nome}{}
    
    Inbox& getInbox()
    {
        return inbox;
    }

    string getNome()
    {
        return nome;
    }

    void Seguir(Usuario* aux)
    {
        this->seguindo[aux->nome] = aux;
        aux->seguidores[this->nome] = this;   
    }

    void Parar_de_seguir(Usuario* aux)
    {
        this->seguindo.erase(aux->nome);
        aux->seguidores.erase(this->nome);
    }

    void Enviar_tweet(Tweet* mensagem)
    {
        this->inbox.Store(mensagem);
        this->inbox.Meu_store(mensagem);
    }

    friend ostream &operator<<(ostream& os, Usuario& usuario) {
        int cont = 0;
        os << usuario.nome << "\n" << "seguidos: [";
        for (auto it : usuario.seguindo) {
            cont++;
            os << it.first;
            if (cont != usuario.seguindo.size()) {
                os << ",";
            }
        }
        os << "]\n";
        os <<"seguidores: [";
        for (auto it : usuario.seguidores) {
            os << it.first;
            if (cont < usuario.seguidores.size()) {
                os << ",";
            }
        }
        os << "]";
        return os;
    }
     Usuario(const std::string& username) : nome{username} {}
    friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario);
};

class Tweet
{
private:
    string nome;
    int id;
    string mensagem;
    set<string> curtidas;
    Tweet *retweet {nullptr};

public:
    Tweet(string& nome, int id, string& mensagem) : nome{nome}, id{id}, mensagem{mensagem}{}

    int getId()
    {
        return id;
    }

    string getRemetente()
    {
        return nome;
    }

    string getMensagem()
    {
        return mensagem;
    }

    set<string> getCurtidas()
    {
        set<string> aux;
        for (auto it : curtidas)
        {
            aux.insert(it);
        }
        return aux;
    }

    void Curtir(string& nome)
    {
        this->curtidas.insert(nome);
    }

    void setRetweet(Tweet *rt)
    {
        this->retweet = rt;
    }

    bool deletar{false};

    void setDeletar()
    {
        deletar = true;
        this->nome = "";
        this->mensagem ="Deletado";
        this->curtidas.clear();
    }

    bool isDeletado()
    {
        return deletar;
    }

     friend ostream& operator<<(ostream& os, const Tweet& tweet)
     {
        int cont = 0;
        os << tweet.id << ":" << tweet.nome << " (" << tweet.mensagem << ") [";
        for(auto it : tweet.curtidas) {
            cont++;
            os << it;
            if (cont != (int) tweet.curtidas.size()) {
                os << ",";
            }
        }
        os << "]\n";
        if(tweet.retweet != nullptr) {
            os << "    " << *tweet.retweet;
        }
        return os;
    }
};

class Inbox
{
private:
    map<int, Tweet*> timeline;
    map<int, Tweet*> Meus_tweets;

public:
    Inbox(){}
    
    void Store(Tweet* tweet)
    {
        this->timeline[tweet->getId()]  = tweet;
    }

    vector<Tweet*> getTimeline()
    {
        vector<Tweet*> aux;
        for (auto it : timeline)
        {
            aux.push_back(it.second);
        }
        return aux;
    }

    Tweet* getTweet(int id)
    {
        for (auto it : timeline)
        {
            if (it.first == id)
            {
                return it.second;
            }
            else
            {
                cout << "Erro" <<endl;
            }
        }
    }

    void Remover_mensagem(string nome)
    {
        for (auto it = timeline.begin(); it != timeline.end();)
        {
            if (it->second->getMensagem() == nome)
            {
                it = this-> timeline.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    void Meu_store(Tweet* tweet)
    {
        this->Meus_tweets[tweet->getId()] = tweet;
    }

    vector<Tweet*> getMeustweets()
    {
        vector<Tweet*> aux;
        for (auto it : Meus_tweets)
        {
            aux.push_back(it.second);
        }
        return aux;
    }

    friend ostream& operator<<(ostream& os, Inbox& inbox) {
        auto key = inbox.getTimeline();
        for(int i = (int) (key.size() - 1); i >= 0;i--) {
            if(key[i]->isDeletado() == false) {
                os << *key[i];
            }
        }
        return os;
    }
};

class Controller
{
private:
    int proximo_tweet {0};
    map<string, shared_ptr<Usuario>> usuarios;
    map<int, shared_ptr<Tweet>> tweets;

    Tweet* Criar_tweet(string nome, string mensagem)
    {
        auto tweet = make_shared<Tweet>(proximo_tweet, nome, mensagem);
        this->tweets[proximo_tweet] = tweet;
        proximo_tweet++;
    }

public:
    Controller(){}

    void Adicionar_usuario(string nome)
    {
        auto  key = usuarios.find(nome);
        if (key != usuarios.end())
        {
            cout << "Erro" << endl;
        }
        else
        {
            this->usuarios[nome] = make_shared<Usuario>(nome);
        }
    }

    Usuario* getUsuario(string nome)
    {
        auto key = usuarios.find(nome);
        if (key != usuarios.end())
        {
            return this->usuarios[nome].get();
        }
        else
        {
            cout << "Erro" << endl;
        }
    }

    void Mandar_tweet(string nome, string mensagem)
    {
        auto key1 = this->getUsuario(nome);
        auto key2 = this->Criar_tweet(nome, mensagem);
        key1->Enviar_tweet(key2);
    }
     
    void Remover_usuario(string nome)
    {
        auto usuario = this->getUsuario(nome);
        auto key = usuario->getInbox();

        for (auto it : usuarios)
        {
            if (it.first == nome)
            {
                this->usuarios.erase(it.first);
            }
        }
    }

     friend std::ostream& operator<<(std::ostream& os, const Controller& controller);
};
std::ostream& operator<<(std::ostream& os, const Controller& controller) 
{
    for (auto it : controller.usuarios) 
    {
        os << *it.second;
    }
    return os;
}

int main() {
    Controller sistema;

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;

        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "addUser") {
                std::string nome;
                ss >> nome;
                sistema.Adicionar_usuario(nome);
            } else if (cmd == "follow") {
                std::string nome;
                std::string aux;
                ss >> nome >> aux;
                sistema.getUsuario(nome)->Seguir(sistema.getUsuario(aux));
            } else if (cmd == "show") {
                std::cout << sistema;
            } else if (cmd == "twittar") {
                std::string nome;
                std::string mensagem;
                ss >> nome;
                std::getline(std::cin,mensagem);
                sistema.Mandar_tweet(nome, mensagem);
            } else if (cmd == "timeline") {
                std::string nome;
                ss >> nome;
                auto key = sistema.getUsuario(nome)->getInbox();
                std::cout << key << std::endl;
            } else if (cmd == "rm") {
                std::string nome;
                ss >> nome;
                sistema.Remover_usuario(nome);
            } else {
                std::cout << "fail: comando invalido" << std::endl;
            }
        } catch (std::runtime_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}