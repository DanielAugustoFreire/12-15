#include <stdio.h>
#define TAM 12

void algoritmo(int posicao[2], int labi[12][12])
{
    int l=posicao[0],c=posicao[1];

    if(labi[l+1][c] == 1 && labi[l][c+1] == 0)
    {
        c++;
    }
    else if(labi[l][c+1] == 1 && labi[l-1][c] == 0)
    {
        l--;
    }    
    else if(labi[l][c] && labi[l-1][c])
    {

    }    
    else if(labi[l][c] && labi[l-1][c])
    {

    }    
    else if(labi[l][c] && labi[l][c])
    {

    }


    posicao[0] = l;
    posicao[1] = c;
}

void printar(int lab[12][12], int posicao[2])
{
    for (int l = 0; l < TAM; l++)
    {
        for (int c = 0; c < TAM; c++)
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
    int labirinto[12][12] = {
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

    printar(labirinto, *pos);

    return 0;
}
