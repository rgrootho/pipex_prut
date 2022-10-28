#include "../mandatory/pipex.h"

int size_pntr_array(char **pntr_array)
{
    int i;

    i = 0;
    if(!pntr_array)
        return(0);
    while(pntr_array[i] != NULL)
        i++;
    return(i);
}