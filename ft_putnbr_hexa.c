/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:13:50 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/04 18:57:58 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int    turn_decimal(char *binary)
{
    unsigned int nbr;
    int i;
    int x;
    int len;
    int c;

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

static char *turn_binary(unsigned int n)
{
    char buffer[32];
    char *binary;
    int i;

    i = 31;
	while (n >= 2)
	{
		buffer[i--] = (n % 2) + '0';
		n = n / 2;
	}
	buffer[i--] = n % 2 + '0';
	while (i >= 0)
	    	buffer[i--] = '0';
	binary = malloc(1 * (33));
	if (!binary)
		return (0);
	return (copy_buffer(buffer, binary));

}

static void	choose_base(char b ,char **base)
{
    if (b == 'x')
    {
        *base = "0123456789abcdef";
    }
    else
        *base = "0123456789ABCDEF";
}

int ft_putnbr_hexa(long n, char b, int *count)
{
    char *base;
    unsigned int base_length;
    char c;
    char *binary;
    unsigned int nbr;

     choose_base(b, &base);
    base_length = 16;
    if (n < 0)
    {
        n *= -1;
        nbr = n;
        binary = turn_binary(nbr);
       nbr = turn_decimal(binary);
       nbr = nbr + 1;
        free(binary);
    }
    else
        nbr = n;
    if (nbr >= base_length)
        ft_putnbr_hexa(nbr / base_length, b, count);
    c = base[nbr % base_length];
    if (write(1 ,&c, 1) == -1)
    	return (-1);
    (*count)++;
    return (1);
}
/*#include <stdio.h>
int main()
{
    ft_putnbr_hexa(140723858646256, 'X');
    printf("\n%c", 63);
}*/
