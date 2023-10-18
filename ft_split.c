/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:26:45 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/14 18:11:02 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_sub(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != 0 && s[i] != c)
			i++;
	}
	return (count);
}

static	char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s, n + 1);
	str[n] = '\0';
	return (str);
}

static	void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	find_pos(char const *s, int *i, int *n, char c)
{
	while (s[*i] == c)
		(*i)++;
	*n = *i;
	while (s[*i] != 0 && s[*i] != c)
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	int		ints[3];
	char	**substrings;

	if (!s)
		return (NULL);
	ints[0] = 0;
	ints[2] = 0;
	substrings = (char **)malloc (sizeof(char *) * (ft_count_sub(s, c) + 1));
	if (substrings == 0)
		return (0);
	while (s[ints[0]])
	{
		find_pos(s, &ints[0], &ints[1], c);
		if (ints[0] > ints[1])
		{
			substrings[ints[2]++] = ft_strndup(s + ints[1], ints[0] - ints[1]);
			if (substrings[ints[2] - 1] == 0)
			{
				free_all(substrings);
				return (0);
			}
		}
	}
	substrings[ints[2]] = 0;
	return (substrings);
}

// int main()
// {
// 	int i = 0;
// 	const char *input = "aaaaa,bbbbbb,ccccc,dddd";
// 	char **result = ft_split(NULL, ',');
// 	while (result && result [i] != 0)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// }