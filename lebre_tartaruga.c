#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define TF 70

typedef struct
{
    int tamanho[TF];
    int posicao_tartaruga, posicao_coelho;
}corrida;

void ImprimirMapa(int pos_t, int pos_c)
{
    int i, morder;

    Sleep(600);
    morder=0;

    system("cls");

    for(i=1;i<=TF;i++)
    {
        if(pos_t == i && pos_c == i)
        {
            printf("X");
            morder=1; 
        }
        else if(pos_t == i)
        {
            printf("T");
        }
        else if(pos_c == i)
        {
            printf("L");
        }
        else if(pos_c >= 70 && i == 70)
        {
        	printf("L\nLebre Venceu. Yuch");
        }
        else if(pos_t >= 70 && i == 70)
        {
        	printf("T\nTARTARUGA VENCEU !!!!YAY!!!");
        }
        else
            printf("_");
    }
    if(morder == 1)
    {
        printf("\nOUCH\nE o Lebre morde a Tartaruga");
    }
    printf("\n\n\nT-Tartaruga \t L-Lebre\nDistancia:[%d.0]", (pos_t > pos_c)? pos_t - pos_c : pos_c - pos_t);
}

void TMovRapido(int *pos_t)
{
    *pos_t += 3;
}

void TEscorr(int *pos_t)
{
    *pos_t -= 6;
    if(*pos_t < 1)
        *pos_t = 1;
}

void TMovLento(int *pos_t)
{
    *pos_t += 1;
}

void CSaltoGrade(int *pos_c)
{
    *pos_c += 9;
}

void CGrandEscorr(int *pos_c)
{
    *pos_c -= 12;
    if(*pos_c < 1)
        *pos_c = 1;
}

void CSaltoLeve(int *pos_c)
{
    *pos_c += 1;
}

void CLeveEscorr(int *pos_c)
{
    *pos_c -= 2;
    if(*pos_c < 1)
        *pos_c = 1;
}

void Andamento(int *pos_t, int *pos_c)
{
    int i;

    i = 1 + rand() % 10;

    if(i<6)
        TMovRapido(pos_t);

        if(i>2 && i<5)
            CSaltoGrade(pos_c);
        if(i == 5)
            CGrandEscorr(pos_c);

    else if(i>5 && i<8)
        TEscorr(pos_t);
    else 
        TMovLento(pos_t);

    if(i>5 && i<9)
        CSaltoLeve(pos_c);
    else if(i>8)
        CLeveEscorr(pos_c);
}

int main(void)
{
    corrida c;
    c.posicao_tartaruga=1;
    c.posicao_coelho = 1;
    
    int *tart = &c.posicao_tartaruga, *coei= &c.posicao_coelho;
    int i=0;

    srand(time(NULL));

    printf("\n\nBANG ELES DISPARAM!!!");
    while(i == 0)
    {
    Beep(1000, 200);
    ImprimirMapa(c.posicao_tartaruga, c.posicao_coelho);
    if(c.posicao_tartaruga >= 70 || c.posicao_coelho >= 70)
        i=100;
    Andamento(tart, coei);
	}
	
    for ( i = 0; i < 4; i++) {
        Beep(100, 100);
        Sleep(50);

        Beep(300, 50);

        Beep(600, 30);
  
        Sleep(50);

        Beep(300, 50);

        Sleep(100);
    }
}