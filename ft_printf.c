/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:32:37 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/28 12:17:49 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 18

int	ft_putchar(int c, int i)
{
	i++;
	write (1, &c, 1);
	return (i);
}

int	ft_printf_write(int c, int i)
{
	i++;
	write (1, &c, 1);
	return (i);
}

int	ft_found_x(size_t d, int i)
{
	unsigned int	k;

	k = (unsigned int)d;
	if (k == 0)
		i = ft_printf_write('0', i);
	else if (k >= 16)
	{
		i = ft_found_x(k / 16, i);
		i = ft_found_x(k % 16, i);
	}
	else
	{
		if (k <= 9)
			i = ft_printf_write(k + '0', i);
		else
			i = ft_printf_write(k + 'a' - 10, i);
	}
	return (i);
}

int	ft_found_d(int d, int i)
{
	if (d == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = i + 11;
	}
	else if (d < 0)
	{
		i = ft_printf_write('-', i);
		i = ft_found_d(-d, i);
	}
	else if (d >= 0 && d < 10)
	{
		i++;
		ft_printf_write(d + '0', i);
	}
	else
	{
		i = ft_found_d(d / 10, i);
		i = ft_printf_write(d % 10 + '0', i);
	}
	return (i);
}

int	ft_found_str(const char *s, int i)
{
	if (!s)
		i = ft_found_str("(null)", i);
	else
	{
		while (*s)
		{
			write (1, &(*s), 1);
			i++;
			s++;
		}
	}
	return (i);
}

void	pointerprinter(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		pointerprinter(ptr / 16);
		pointerprinter(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printf_write(ptr + '0', 1);
		else
			ft_printf_write(ptr + 'a' - 10 , 1);
	}
}


int	digitcounter(unsigned long long ptr)
{
	int	digit;

	digit = 0;
	if (ptr == 0)
		digit++;
	while (ptr != 0)
	{
		ptr /= 16;
		digit++;
	}

	return (digit);
}

int	ft_found_ptr(unsigned long long ptr)
{
	int	size;

	size = digitcounter(ptr) + 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	pointerprinter(ptr);
	return (size);	
}


int	ft_next_p(const char *input, va_list args, int i, int j)
{
	if (input[j] == 's')
		i = ft_found_str(va_arg(args, char *), i);
	if (input[j] == 'd' || input[j] == 'i')
		i = ft_found_d(va_arg(args, int), i);
	if (input[j] == 'x')
		i = ft_found_x(va_arg(args, size_t), i);
	if (input[j] == 'c')
		i = ft_putchar(va_arg(args, int), i);
	if (input[j] == 'p')
		i = ft_found_ptr(va_arg(args, unsigned long long));
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, input);
	while (input[j])
	{
		if (input[j] == '%')
			i = ft_next_p(input, args, i, ++j);
		else
		{
			i++;
			write(1, &input[j], 1);
		}
		j++;
	}
	va_end(args);
	return (i);
}

int main()
{
	int i;
	
	// i = printf("hi\n");
	// printf("i: %i\n", i);
	char *s = "asdfdfgjdjsdjrhercdgfg";
	
	//ft_printf("hi 42! s: %s, d: %d, x: %x, c: %c, p: %p\n", NULL, 42, 42, 'a', s);
	//printf("hi 42! s: %s, d: %d, x: %x, c: %c, p: %p\n", NULL, 42, 42, 'a', s);

	int *p;
	int result;

	result = ft_printf("%p",p);
	ft_printf("\n%d\n",result);
	result = printf("%p",p);
	printf("\n%d\n",result);

// 	printf("%s\n", "toto");
// 	printf("magic %s is %d\n", "number", 42);
// 	printf("hexadecimal for %d is %x\n", 42, 42);
// 
}
