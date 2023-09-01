/*
    const char *naipe[4] = {"Copas","Ouros","Paus","Espadas"};
    const char *face[13] = {"As", "Dois","Tres", "Quatro", 
                            "Cinco","Seis","Sete","Oito", 
                            "Nove","Dez","Valete","Dama", "Rei"};
*/
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

void determinar(int mao[2][5])
{
    int l,c, descobrirFace[2][5], descobrirNaip[2][5];

    for(l=0;l<2;l++)
    {
        for(c=0;c<5;c++)
        {
            descobrirFace[l][c] = mao[l][c] % 13;
            descobrirNaip[l][c] = mao[l][c] / 13;
        }
    }
    


}

void enbaralhar(int bar[4][13])
{
    srand(time(NULL));

    int linha,coluna, carta;
    for(carta=0;carta<52;carta++)
    {
        linha = rand()%4;
        coluna = rand()%13;
        while(bar[linha][coluna] != 0)
        {
            linha = rand()%4;
            coluna = rand()%13;   
        }
        bar[linha][coluna] = carta;
    }
}

void destribur(int bar[4][13], const char *naip[4], const char *fac[13], int user[2][5])
{
    int i=0, j=0;
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 13; c++)
        {
            int carta = bar[l][c];
            if(i<5)
            {
                user[0][i++] = carta;
            }
            else if(j<5)
            {
                user[1][j++] = carta;
            }
        }
    }
}

int main()
{
    const char *naipe[4] = {"Copas","Ouros","Paus","Espadas"};
    const char *face[13] = {"As", "Dois","Tres", "Quatro", 
                            "Cinco","Seis","Sete","Oito", 
                            "Nove","Dez","Valete","Dama", "Rei"};
    int baralho[4][13] = {0};
    int mao[2][5];

    srand(time(NULL));

    enbaralhar(baralho);
    destribur(baralho, naipe, face, mao);
    determinar(mao);

}