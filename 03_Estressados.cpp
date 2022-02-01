#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>

using namespace std;

vector<int>sozinhos(const vector<int>& vect)
{
    vector<int> sozinhos;
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; i < vect.size(); j++)
        {
            if (abs(vect[i] == vect[j]))
            cont++;
        }
        if (cont == 1)
        sozinhos.push_back(vect[i]);
    }
    return sozinhos;
}

vector<int>mais_ocorrencias(const vector<int>& vect)
{
    vector<int> mais_ocorrencias;
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            if (vect[i] == vect[j])
            cont++;
        }
        if (cont == 1)
        mais_ocorrencias.push_back(vect[i]);
    }
return mais_ocorrencias;    
}

vector<int>mais_recorrente(const vector<int>& vect)
{
    vector<int> mais_recorrente;
    int cont2 = 0;

    for (int i = 0; i < vect.size(); i++)
    {

        int cont1 = 0;
        for (int j = 0; j < vect.size(); j++)
        {
            if (vect[i] == vect[j])
            cont1++; 
        }
        if (cont1 > cont2)
        cont2 = cont1;
    }
    for (int i = 0; i < vect.size(); i++)
    {
        int cont1 = 0;
        for (int j = 0; j < vect.size(); j++)
        {
            if (vect[i] == vect[j])
            cont1++;
        }
        if (cont1 == cont2)
        mais_recorrente.push_back(vect[i]);
    }
    return mais_recorrente;
}

int briga(const vector<int>& vect)
{
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 50 && vect[i - 1] > 30 && vect[i + 1] > 30)
        cont++;
    }
    return cont;
}

vector<int>apaziguados(const vector<int>& vect)
{
    vector<int> apaziguados;

    for (int i = 0; i < vect.size(); i++)
    {
        if(vect[i] > 80 && vect[i - 1] < 10 || vect[i] > 80 && vect[i + 1] < 10)
        apaziguados.push_back(vect[i]);
    }
    return apaziguados;
}

int quantos_times(const vector<int>& vect)
{
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 0 && vect[i + 1] > 0 || vect[i] < 0 && vect[i + 1] < 0)
        cont++;
    }
    return cont; 
}

vector<int>maior_time(const vector<int>& vect)
{
    vector<int> time_masculino;
    vector<int> time_feminino;

    int contM = 0;
    int contF = 0;
    int maior_time;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 0 && vect[i + 1] > 0)
        {
            contM++;
            time_masculino.push_back(vect[i]);
        }
        else if (vect[i] < 0 && vect[i + 1] < 0)
        {
            contF++;
            time_feminino.push_back(vect[i]);
        }
        else break;
    }
    if (contM > contF) return time_masculino;
    else return time_feminino;
}

int sozinhos2(const vector<int>& vect)   
{
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 0 && vect[i + 1] < 0 || vect[i] < 0 && vect[i + 1] > 0)
        cont++;
    }
    return cont;
}

int casais(const vector<int>& vect)
{
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            if (vect[i] == -(vect[j]))
            cont++;
        }
    }
    return cont;
}

int trios(const vector<int>& vect)
{
    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            for (int k = i + 2; k < vect.size(); k++)
            {
                if (vect[i] == vect[j] == vect[k])
                cont++;
            }
        }
    }
    return cont;
}

vector<int>remove(vector<int>& vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        int removido = 0;
        cin >> removido;

        for (int i = 0; i < vect.size(); i++)
        {
            if (vect[i] == removido)
            break;
            vect.erase(remove(vect.begin(), vect.end(), vect[i]), vect.end());
        }
    }
    return vect;
}

vector<int>insert(vector<int>& vect)
{
    int inserido = 0;
    int posicao = 0;
    cin >> inserido;
    cin >> posicao;

    for (int i = 0; i < vect.size(); i++)
    {
        vect[posicao] = inserido;
    }
    return vect;
}

vector<int>dance(vector<int>& vect)
{

}

int main()
{
    vector<int> vector{1,2,3,4,5};

    sozinhos(vector);
    mais_ocorrencias(vector);
    mais_recorrente(vector);
    briga(vector);
    apaziguados(vector);
    quantos_times(vector);
    maior_time(vector);
    sozinhos2(vector);
    casais(vector);
    trios(vector);
    remove(vector);
    insert(vector);
    dance(vector);

    return 0;
}