#include <stdio.h>
#include "my_mat.h"

int main()
{
    char items[MAXITEMS][MAXSLEN];
    int values[MAXITEMS];
    int weights[MAXITEMS];
    int selected_bool[MAXITEMS];
    int result[MAXITEMS];
    for(size_t i = 0; i<MAXITEMS;i++)
    {
        scanf("%s %d %d",items[i], &values[i], &weights[i]);
    }


    printf("Maximum profit: %d\n",knapSack(weights,values,selected_bool));
    printf("Selected items: ");
    for(size_t i = 0; i<MAXITEMS;i++)
    {
        if(selected_bool[i])
        {
            printf("%c ",items[i]);
        }
    }
    printf("\n");
    return 0;
}