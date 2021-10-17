 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;

bool existe (vector<int> vect, int valor) 
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] == valor)
        {
            return true;
        }
    }    
     return false;
}

void contar (int valor)
{
    vector<int> vect; 
    int contar = 0;
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] == valor) contar++;
    }
     cout << contar; 
}

int procurar_valor (int valor)
{
    vector<int> vect;
    
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] == valor)
        return i; 
        break; 
    }
    return 0; 
}
 
int procurar_valor_apos (int valor, int posicao)
{
    vector<int> vect;
    int contar = 0;

    for (size_t posicao; posicao < vect.size(); posicao++)
    {
    if (vect[posicao] == valor)
    contar++;
    }
    printf("%d", contar);
}

int menor (int menor)
{
    vector<int> vect;
     menor = 0;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] < menor)
        menor = vect[i];
    }
    return menor;
}

int procurar_menor_pos (int menor)
{
    vector<int> vect;
    menor = 0;
    
    for (size_t i = 0; i < vect.size(); i++)
    {
        if(vect[i] < menor)
        menor = vect[i];
    }

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] == menor)
        return(i);
    }
    return 0;
}

int procurar_menor_pos_apos (int menor, int posicao)
{
    vector<int> vect;
    menor = 0;
    posicao = 0;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] < menor)
        menor = vect[i];
    }

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == menor)
        posicao = i;
    }
    return posicao;
}
 
 int procurar_menor_apos_partir ( int inicio)
 {
     vector<int> vect;
     int menor = 0;

     for (size_t i = inicio; (int)vect.size(); i++)
     {
         if (i == inicio) menor = vect[i];
         if (menor > vect[i]) menor = vect[i];
     }
    return menor;
 }
 
 int procurar_melhor_se (int menor)
 {
     vector<int> vect;
     menor = 0;

     for (size_t i = 0; i < vect.size(); i++)
     {
         if (i == 0) menor = vect[i];
         if (menor > vect[i] && vect[i] > 0) menor = vect[i];
     }
     return menor;
 }
 
 float calcular_stress_medio (float media, float soma)
 {
     vector<int> vect;
     media = 0;
     soma = 0;

     for(size_t i = 0; i < vect.size(); i++)
     {
         soma += abs(vect[i]);
     } 
     media = soma / vect.size();
     return media;
 }
 
void mais_homens_ou_mulheres (int homens, int mulheres)
{
    vector<int> vect;
    homens = 0;
    mulheres = 0;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 0) homens++;
        if (vect[i] < 0) mulheres++;
    }
    if (homens > mulheres) printf ("%d", homens);
    else printf("%d", mulheres); 
}

void qual_metade_eh_mais_estressada (float mediaH, float mediaM)
{
    vector<int> vect;
    mediaH = 0;
    mediaM = 0;

    for (size_t i = 0; i < (vect.size())/2; i++)
    {
        mediaH += abs(vect[i]);
    }
    for (size_t i = (vect.size())/2; i < (vect.size())/2; i++)
    {
        mediaM += abs(vect[i]);
    }

    if (mediaH > mediaM) printf("homens são mais estressados");
    else printf ("mulheres são mais estressadas");    
}

void homens_sao_mais_estressados_que_mulheres (float mediaM, float mediaH)
{
    vector<int> vect;
    mediaM = 0;
    mediaH = 0;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] < 0) mediaM += abs(vect[i]);
        if (vect[i] > 0) mediaH += abs(vect[i]);
    }
    if (mediaH > mediaM) printf ("Os homens são mais estressados");
    else printf ("As mulheres são mais estressadas");
}
