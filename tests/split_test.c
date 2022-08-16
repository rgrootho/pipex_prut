#include <stdio.h>
#include <stdlib.h>

char *ft_strlcpy(char *dst, char *src, int len)
{
	int i;

	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len --;
	}
	dst[i] = '\0';
	return (dst);
}

static int	free_swp(char **splt_wrd_p, int j)
{
	while (j >= 0)
	{
		free(splt_wrd_p[j]);
		j--;
	}
	free(splt_wrd_p);
	return (0);
}

static char	*set_word_in_swp(char *s, int i, int wordlen)
{
	char	*a;

	a = (char *)malloc((wordlen + 1) * sizeof(char));
	if (a == 0)
		return (0);
	ft_strlcpy(a, (s + i - wordlen + 1), wordlen + 1);
	return (a);
}

static char	**cnt_wrdlen(char *s, char c, char **splt_wrd_p, int wordlen)
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
			splt_wrd_p[j] = set_word_in_swp(s, i, wordlen + 1);
			if (splt_wrd_p[j] == 0)
			{
				free_swp(splt_wrd_p, j - 1);
				return (0);
			}
			wordlen = 0;
			j++;
		}
		i++;
	}
	return (splt_wrd_p);
}

static char	**swp_len(char *s, char c)
{
	int		i;
	int		words_in_s;
	char	**splt_wrd_p;

	i = 0;
	words_in_s = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			words_in_s++;
		i++;
	}
	splt_wrd_p = (char **)malloc((words_in_s + 1) * sizeof(char *));
	if (splt_wrd_p == 0)
		return (0);
	splt_wrd_p[words_in_s] = 0;
	return (splt_wrd_p);
}

char	**ft_split(char *s, char c)
{
	char	**splt_wrd_p;
	int		wordlen;

	if (!s)
		return (0);
	wordlen = 0;
	splt_wrd_p = swp_len(s, c);
	if (splt_wrd_p == 0)
		return (0);
	splt_wrd_p = cnt_wrdlen(s, c, splt_wrd_p, wordlen);
	if (splt_wrd_p == 0)
		return (0);
	return (splt_wrd_p);
}

int main(void)
{
	char **test;
	int i = 0;

	test = ft_split("PATH=/Library/Frameworks/Python.framework/Versions/3.8/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Library/Frameworks/Python.framework/Versions/3.8/bin", ':');
	while(test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	return(0);
}