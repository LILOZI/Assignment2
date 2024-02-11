#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int fw(int mat[MAT_SIZE][MAT_SIZE], int size, int i, int j);

void matValues(int mat[MAT_SIZE][MAT_SIZE], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            scanf("%d", &(mat[i][j])); // Scaning to the address in the memory fo the matrix
        }
    }
}

int isPath(int mat[MAT_SIZE][MAT_SIZE], int size, int i, int j)
{   
    int dist = fw(mat,size,i,j);
    return (dist == -1) ? False :  True;
}

int shortesPath(int mat[MAT_SIZE][MAT_SIZE], int size, int i, int j)
{
    return fw(mat,size,i,j);
}

int fw(int mat[MAT_SIZE][MAT_SIZE], int size, int i, int j)
{
    int dist[MAT_SIZE][MAT_SIZE] = {0};
    for(size_t i = 0; i<size;i++)
    {
        for(size_t j =0; j<size;j++)
        {
            if(i == j)
            {
                continue;
            }
            if(mat[i][j] != 0)
            {
                dist[i][j] = mat[i][j];
            }
            else
            {
                dist[i][j] = INFINITY;                    
            }
        }
    }

    for(size_t i = 0; i<size;i++)
    {
        for(size_t j = 0; j<size;j++)
        {
            for(size_t k = 0; k<size;k++)
            {
                if(i != j && dist[j][i] != INFINITY && dist[i][k] != INFINITY)
                {
                    if(dist[j][k] > dist[j][i] + dist[i][k])
                    {
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }
    }
    if(dist[i][j] != INFINITY && dist[i][j] != 0)
    {
        return dist[i][j];
    }
    return -1;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int weights[], int values[], int selected_bool[])
{
    int maxVal[MAXITEMS+1][MAXWEIGHT+1] = {0};

    for(size_t i = 1; i<=MAXITEMS;i++)
    {
        for(size_t j = 1; j<=MAXWEIGHT;j++)
        {
            if(weights[i-1] > j)
            {
                maxVal[i][j] = 0;
            }
            else
            {
                maxVal[i][j] = max(maxVal[i-1][j], values[i-1] + maxVal[i-1][j-weights[i-1]]);
            }
        }
    }

    size_t max = 0;
    for(size_t i = 0; i <=MAXWEIGHT;i++)
    {
        if(maxVal[MAXITEMS][i] > maxVal[MAXITEMS][max])
        {
            max = i;
        }
    }

    for(size_t i = MAXITEMS; i>0; i--)
    {
        if(maxVal[i][max] != maxVal[i-1][max])
        {
            selected_bool[i-1] = 1;
            max -= weights[i-1];
        }
        else
        {
            selected_bool[i-1] = 0;
        }
    }

    return maxVal[MAXITEMS][MAXWEIGHT];
}
