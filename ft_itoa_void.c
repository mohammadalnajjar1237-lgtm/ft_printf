/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:10:48 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/06 12:45:48 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_itoa(char *num, int *count, int start)
{
	write(1, "0x", 2);
	*count += 2;
	while (start < 100)
	{
		if (write(1, &num[start], 1) == -1)
			return (-1);
		start++;
		(*count)++;
	}
	return (1);
}

int	ft_itoa_p(unsigned long long n, int *count)
{
	char	buffer[100];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 99;
	if (n == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		*count += 5;
		return (1);
	}
	while (n >= 16)
	{
		buffer[i--] = base[n % 16];
		n = n / 16;
	}
	buffer[i] = base[n % 16];
	return (ft_putstr_itoa(buffer, count, i));
}
/*#include <stdio.h>
int	main(void)
{
	void *s = "hello";
	//void *b = "heyy";
	int count = 0;
	int i = -1;
	ft_itoa_p(-1,&count );
	printf("\n");
	int x = printf("%p", (void*) i);
	printf("\n%d %d", x, count);
}*/
