/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:13:50 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/06 16:54:59 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	turn_decimal(char *binary)
{
	unsigned int	nbr;
	int				i;
	int				x;
	int				len;
	int				c;

	nbr = 0;
	len = 32;
	i = 0;
	while (binary[i] != '\0')
	{
		c = binary[i] - '0';
		x = len - 1;
		while (x > 0)
		{
			c *= 2;
			x--;
		}
		nbr += c;
		i++;
		len--;
	}
	return (nbr);
}

static char	*copy_buffer(char *buff, char *binary)
{
	int	j;

	j = 0;
	while (j < 32)
	{
		if (buff[j] == '1')
			buff[j] = '0';
		else
			buff[j] = '1';
		binary[j] = buff[j];
		j++;
	}
	binary[j] = '\0';
	return (binary);
}

static char	*turn_binary(unsigned int n)
{
	char	buffer[32];
	char	*binary;
	int		i;

	i = 31;
	while (n >= 2)
	{
		buffer[i--] = (n % 2) + '0';
		n = n / 2;
	}
	buffer[i--] = n % 2 + '0';
	while (i >= 0)
		buffer[i--] = '0';
	binary = malloc(sizeof(char) * (33));
	if (!binary)
		return (NULL);
	return (copy_buffer(buffer, binary));
}

static void	choose_base(char b, char **base)
{
	if (b == 'x')
	{
		*base = "0123456789abcdef";
	}
	else
		*base = "0123456789ABCDEF";
}

int	ft_putnbr_hexa(unsigned int n, char b, int *count)
{
	char	*base;
	char	c;
	char	*binary;

	choose_base(b, &base);
	if (n < 0)
	{
		n *= -1;
		binary = turn_binary(n);
		n = turn_decimal(binary);
		n = n + 1;
		free(binary);
	}
	if (n >= 16)
		ft_putnbr_hexa(n / 16, b, count);
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}
/*#include <stdio.h>
int	main(void)
{
	int i = 0;
    ft_putnbr_hexa(42949672950, 'X', &i);
    printf("\n");
    int x = printf("%X", 42949672950);
    printf("\n%d %d", i, x);
}*/
