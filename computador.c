#include <stdio.h>
#include <windows.h>

#define TAM 12

/*
    	2
    	
	1       3
	
    	4
*/

int algoritmo(int posicao[2], const int labi[12][12], int direita[2])
{
    int i, k;

	if(posicao[0] == direita[0] - 1 && posicao[1] == direita[1] - 1)
    {
        if(labi[posicao[1] + 1] == 0)
            posicao[1]++;
    }
	if(posicao[0] == direita[0] - 1 && posicao[1] == direita[1] + 1)
    {
        if(labi[posicao[0] + 1] == 0)
            posicao[0]++;
    }	
	if(posicao[0] == direita[0] - 1 && posicao[1] == direita[1])	
    {
        if(labi[posicao[1] + 1] == 0)
            posicao[1]++;
    }


    
	if(posicao[0] == direita[0] + 1 && posicao[1] == direita[1] - 1)
    {
        if(labi[posicao[1] - 1] == 0)
            posicao[1]--;
    }
	if(posicao[0] == direita[0] + 1 && posicao[1] == direita[1] + 1)
    {
        if(labi[posicao[0] - 1] == 0)
            posicao[0]--;
    }
	if(posicao[0] == direita[0] + 1 && posicao[1] == direita[1])
	{
        if(labi[posicao[0] - 1] == 0)
            posicao[0]--;
    }


	if(posicao[0] == direita[0] && posicao[1] == direita[1] - 1)
    {
        if(labi[posicao[1] - 1] == 0)
            posicao[1]--;
    }
	if(posicao[0] == direita[0] && posicao[1] == direita[1] + 1)
    {
        if(labi[posicao[0] + 1] == 0)
        posicao[0]++;
    }





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
    int i=0;
    int direitinha[2] = {3,0};

    while(i!=10)
    {
        printar(labirinto, pos);
        i = algoritmo(pos, labirinto, direitinha);
        Sleep(1000);
        system("cls");
    }

    return 0;
}

