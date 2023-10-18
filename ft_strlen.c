/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:31:46 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/13 20:04:20 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
		i++;
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[] = "abhdg";
// 	// printf("%lu", strlen(NULL));
// 	printf("%zu", ft_strlen(NULL));
// }