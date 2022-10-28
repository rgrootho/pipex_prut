#include "../mandatory/pipex.h"

int free_dbl_pointer(char **array, int len)
{
	int i;

	i = 0;
	if (len == 0)
	{
		while(array[i] != NULL)
		{
			if(array[i])
				free(array[i]);
			i++;
		}
	}
	else
	{
		while(i < len)
		{
			if (array[i] != NULL)
				free(array[i]);
			i++;
		}
	}
	free(array);
	return(0);
}