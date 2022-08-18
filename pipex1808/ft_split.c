#include "pipex.h" 

static int	free_swp(char **splitted_string, int j)
{
	while (j >= 0)
	{
		free(splitted_string[j]);
		j--;
	}
	free(splitted_string);
	return (0);
}

static char	*set_word_in_ss(char *s, int i, int wordlen)
{
	char	*a;

	a = (char *)malloc((wordlen + 1) * sizeof(char));
	if (a == 0)
		return (0);
	ft_strlcpy(a, s + i - wordlen + 1, wordlen);
	return (a);
}

static char	**cnt_wrdlen(char *s, char c, char **splitted_string, int wordlen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] != c && s[i + 1] != '\0')
			wordlen++;
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			splitted_string[j] = set_word_in_ss(s, i, wordlen + 1);
			if (splitted_string[j] == 0)
			{
				free_swp(splitted_string, j - 1);
				return (0);
			}
			wordlen = 0;
			j++;
		}
		i++;
	}
	return (splitted_string);
}

static char	**swp_len(char *s, char c)
{
	int		i;
	int		words_in_s;
	char	**splitted_string;

	i = 0;
	words_in_s = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			words_in_s++;
		i++;
	}
	splitted_string = (char **)malloc((words_in_s + 1) * sizeof(char *));
	if (splitted_string == 0)
		return (0);
	splitted_string[words_in_s] = 0;
	return (splitted_string);
}

char	**ft_split(char *s, char c)
{
	char	**splitted_string;
	int		wordlen;

	if (!s)
		return (0);
	wordlen = 0;
	splitted_string = swp_len(s, c);
	if (splitted_string == 0)
		return (0);
	splitted_string = cnt_wrdlen(s, c, splitted_string, wordlen);
	if (splitted_string == 0)
		return (0);
	return (splitted_string);
}