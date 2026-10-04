/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:10:48 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/04 19:07:05 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr_itoa(char *num, int *count)
{
    int i;

    i = 0;
    write(1, "0x",2);
    *count += 2;
    while (i < 12)
    {
        if (write(1, &num[i], 1) == -1)
        	return (-1);
        i++;
	(*count)++;
    }
    return (1);
}

int    ft_itoa_p(unsigned long long n, int *count)
{
	char	buffer[12];
	long	nbr;
	int		i;
    char *base = "0123456789abcdef";

	nbr = n;
	i = 11;
	while (nbr >= 16)
	{
		buffer[i--] = base[nbr % 16] ;
		nbr = nbr / 16;
	}
	buffer[i--] = base[nbr % 16];
    return (ft_putstr_itoa(buffer, count));
}
/*#include <stdio.h>
int main()
{
	void *s = "hello";
	void *b = "heyy";
	ft_itoa_p((unsigned long long)&b);
	printf("\n%p", &b);
}*/
