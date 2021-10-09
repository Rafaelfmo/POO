#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

vector<int> clone(const vector<int>& vect)
{
    vector<int> copy;

    for (int i = 0; i < (int)vect.size(); i++)
    {
        copy.push_back(vect[i]); 
    } 
    return copy;
}

vector<int> pegar_homens(const vector<int>& vect)
{
    vector<int> lista_de_homens;

    for (int i = 0; i < (int)vect.size(); i++)
    {
        if (vect[i] > 0)
        lista_de_homens.push_back(vect[i]);
    }
    return lista_de_homens;
}

vector<int> pegar_calmos(const vector<int>& vect)
{
    vector<int> calmos;

    for (int i = 0; i < (int)vect.size();i++)
    {
        if (vect[i] < 10)
        {
            calmos.push_back(vect[i]);
        }
    }
    return calmos;
}

vector<int> pegar_mulheres_calmas(const vector<int>& vect)
{
    vector<int> lista_de_mulheres;

    for(int i = 0; i < (int)vect.size(); i++)
    {
        if (vect[i] > -10 && vect[i <= -1])
        lista_de_mulheres.push_back(vect[i]);
    }
    return lista_de_mulheres;
}

vector<int> inverter_com_copia(const vector<int>& vect)
{
    vector<int> inverso;

    for(int i = 0; i < (int)vect.size(); i++)
    {
        inverso.push_back(vect[i]);
    }
   
    reverse(inverso.begin(), inverso.end());
    
    return(inverso);
}

void inverter_inplace(vector<int>& vect)
{
        reverse(vect.begin(), vect.end());
}

int sortear(const vector<int>& vect)
{
    int x;
    srand(time(NULL));

    x = (rand() % 100);

    return vect[x];
}

void embaralhar(vector<int>& vect)
{
    srand(time(NULL));
    int help;

    for (int i = 0; i < vect.size(); i++)
    {
        int x = rand() % vect.size();
        help = vect[i];
        vect[i] = vect[x];
        vect[x] = help;
    }
}

void ordenar(vector<int>& vect)
{
    int help;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            help = vect[i];
            
            if(vect[i] > vect[j])
            {
            vect[j] = vect[i];
            vect[j] = help;
            }
        }
    }
    
}

vector<int> exclusivos(const vector<int>& vect)
{
    vector<int> sem_repeticao;

    int cont = 0;

    for (int i = 0; i < vect.size(); i ++)
    {
        for(int j = 0; j < vect.size(); j++)
        {
            if (i != j)
            {
                if (vect[i] == vect[j])
                cont++;
            }
        }
        if (cont = 0)
        sem_repeticao.push_back(vect[i]);
    }
    return sem_repeticao;
}

vector<int> diferentes(const vector<int>& vect)
{
    vector<int> diferentes;

    int cont = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            if (i != j)
            {
                if (vect[i] == vect[j])
                cont++;
            }
        }
        if (cont == 0)
        diferentes.push_back(vect[i]);
    }  
    return diferentes;
}

vector<int> abandonados(const vector<int>& vect)
{
    vector<int> restante;

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            if (i != j)
            {
                if (vect[i] == vect[j])
                restante.push_back(vect[i]);
            }
        }
    }
    return restante;
}

int main()
{
    vector<int> vector{1,2,3,4,5};
    
    clone(vector);
    pegar_homens(vector);
    pegar_calmos(vector);
    pegar_mulheres_calmas(vector);
    inverter_com_copia(vector);
    inverter_inplace(vector);
    sortear(vector);
    embaralhar(vector);
    ordenar(vector);
    exclusivos(vector);
    diferentes(vector);
    abandonados(vector);
    
     return 0;
}