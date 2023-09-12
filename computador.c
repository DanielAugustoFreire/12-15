#include <stdio.h>
#include <windows.h>

#define TAM 12

/*
    2
1       3
    4
*/


int direita(int posicao[2], const int labi[12][12], int direita[2]) {
    int l=posicao[0],c=posicao[1];
    int iso = 0; // Inicializa com valor padrão (neste caso, nenhum movimento)

    if(labi[l-1][c] == 1 && labi[l+1][c] == 1 && labi[l][c+1] == 0)
        iso =  1;
    else if(labi[l][c-1] == 1 && labi[l][c] == 1 && labi[l+1][c] == 0)
        iso =  2;
    else if(labi[l-1][c] == 1 && labi[l+1][c] == 1 && labi[l][c-1] == 0)
        iso =  3;
    else if(labi[l][c-1] == 1 && labi[l][c] == 1 && labi[l-1][c] == 0)
        iso =  4;

    // Atualiza a posição do movimento a ser feito
    if(iso == 1) {
        direita[0] = l+1;
        direita[1] = c;
    }
    else if(iso == 2) {
        direita[0] = l;
        direita[1] = c-1;
    }
    else if(iso == 3) {
        direita[0] = l-1;
        direita[1] = c;
    }
    else if(iso == 4) {
        direita[0] = l;
        direita[1] = c+1;
    }

    return iso;
}

int algoritmo(int posicao[2], const int labi[12][12], int direita[2])
{
    int l=posicao[0],c=posicao[1];
    int i, k;

    for(i=-1;i<2;i++)
    {
        for(k=-1;k<2;k++)
        {
            if(posicao[0] == direita[0] + i && posicao[1] == direita[0] + k)
        }
    }






    posicao[0] = l;
    posicao[1] = c;

    if(posicao[0] == 4 && posicao[1] ==11)
        return 10;
    else 
        return 1;
}

void printar(const int lab[12][12], int posicao[2])
{
	int l, c;
	
    for (l = 0; l < TAM; l++)
    {
        for (c = 0; c < TAM; c++)
        {
            if (lab[l][c] == 1)
                printf("1 ");

            else if(posicao[0] == l && posicao[1] == c)
                printf("X ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    const int labirinto[12][12] = {
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,1,0,0,0,0,0,0,1,
        0,0,1,0,1,0,1,1,1,1,0,1,
        1,1,1,0,1,0,0,0,0,1,0,1,
        1,0,0,0,0,1,1,1,0,1,0,0,
        1,1,1,1,0,1,0,1,0,1,0,1,
        1,0,0,1,0,1,0,1,0,1,0,1,
        1,1,0,1,0,1,0,1,0,1,0,1,
        1,0,0,0,0,0,0,0,0,1,0,1,
        1,1,1,1,1,1,0,1,1,1,0,1,
        1,0,0,0,0,0,0,1,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1
    };
    int pos[2] = {2,0};
    int i=0, isso;
    int direitinha[2];

    isso = direita(pos, labirinto, direitinha);

    while(i!=10)
    {
        printar(labirinto, pos);
        i = algoritmo(pos, labirinto, direitinha);
        Sleep(1000);
        system("cls");
    }

    return 0;
}
