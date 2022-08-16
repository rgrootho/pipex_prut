#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **put_string_in_pointer_array(char **pointer_array, char *string, char dilimeter)
{
	int len_string;
	int i;
	int j;
	int i_save;

	i = 0;
	j = 0;
	i_save = 0;
	len_string = 0;
	while(pointer_array[j])
	{
		while(string[i])
		{
			if (string[i] != dilimeter)
				len_string++;
			else if (string[i] == dilimeter && len_string != 0)
			{
				pointer_array[j] = (char*) malloc ((len_string + 1) * sizeof (char));
				if (!pointer_array[j])
				{
					free_array(pointer_array);
					return(NULL);
				}
				pointer_array[j][len_string] = '\0';
				ft_memcopy(string + i_save, pointer_array[j], len_string);
				j++;
				i++;
				i_save = i;
			}

		}
	}
}

int count_len_pointer_array(char *string, char dilimeter)
{
	int count_dilimeter_occurence;
	int i;

	while (string[i])
	{
		if(string[i] == dilimeter && string[i + 1] != dilimeter && string[i + 1] != '\0')// te lang
			count_dilimeter_occurence++;
		i++;
	}
	return(count_dilimeter_occurence+ 1);
}


char **split(char *string, char dilimeter)
{
	char	**return_array;
	int		len_pointer_array;

	len_pointer_array = count_len_pointer_array(string, dilimeter);
	return_array = (char**) malloc ((len_pointer_array + 1) * sizeof (char*));
	if (!return_array)
		return(NULL);
	return_array[len_pointer_array] = NULL;
	return_array = put_string_in_pointer_array(return_array, string, dilimeter);
}
