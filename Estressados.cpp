 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;

bool existe (vector<int> vect, int valor) 
{
    for (int i = 0; i < vect.size(); i++){
        if (vect[i] == valor){
        return true;}
    }    
     return false;
}

int contar (vector<int> vect, int valor)
{
    int contar = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == valor) contar++;
    }
    return contar;   
}

int procurar (vector<int> vect, int valor)
{
    int position = -1;
    
    for (int i = 0; i < vect.size(); i++){
        position++;
        if (vect[i] == valor) 
        break; 
    }
    return position; 
}
 
int procurar2 (vector<int> vect, int valor, int posicao)
{
    posicao = 0;
    for (int i = posicao; i < vect.size(); i++)
    {
    if (vect[i] == valor)
    return i;
    }
}

int menor (vector<int> vect, int menor)
{
     menor = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] < menor)
        menor = vect[i];
    }
    return menor;
}

int procurar_menor (vector<int> vect, int menor)
{
    menor = 0;
    
    for (int i = 0; i < vect.size(); i++)
    {
        if(vect[i] < menor)
        menor = vect[i];
    }

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == menor)
        return(i);
    }
}

int procurar_menor_apos (vector<int> vect, int menor, int posicao)
{
    menor = 0;
    posicao = 0;

    for (int i = 0; i < vect.size(); i++)
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
 
 int procurar_menor_apos_partir (vector<int> vect, int inicio)
 {

 }
 
 int procurar_melhor_se (vector<int> vect, int menor, )
 {
     menor = 0;

     for (int i = 0; i < vect.size(); i++)
     {
         if (vect[i] < menor && vect[i] > 0)
         menor = vect[i];
     }
     return menor;
 }
 
 float calcular_stress_medio (vector<int> vect, float media, float soma)
 {
     media = 0;
     soma = 0;

     for(int i = 0; i < vect.size(); i++)
     {
         soma += vect[i];
         media = soma/i;
     } 
     return media;
 }
 
int mais_homens_ou_mulheres (vector<int> vect, int homens, int mulheres)
{
    homens = 0;
    mulheres = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > 0) homens++;
        else mulheres++;
    }
    if (homens > mulheres) return homens;
    else return mulheres; 
}

float qual_metade_eh_mais_estressada (vector<int> vect, float mediaH, float mediaM)
{
    mediaH = 0;
    mediaM = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] < 0) mediaM += vect[i];
        else mediaH += vect[i];
        mediaM = mediaM/(i/2);
        mediaH = mediaH/(i/2);
    }

    if (mediaH > mediaM) cout << "Mais mulheres que homens";
    else cout << "mais homens que mulheres";




    
}

float homens_sao_mais_estressados_que_mulheres (vector<int> vect, float mediaM, float mediaH)
{
    mediaM = 0;
    mediaH = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        mediaM = mediaM/(i/2);
        mediaH = mediaH/(i/2);
        if (vect[i] < 0) mediaM += vect[i];
        else mediaH += vect[i];
    }
    if (mediaH > mediaM) return mediaH;
    else cout << "A média foi menor que o esperado";
}
