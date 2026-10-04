/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:11:26 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/04 19:06:38 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_putnbr(long n, int *count)
{
	char	c;
    if (n < 0)
    {
        write(1, "-", 1);
        n *= -1;
    }
	if (n >= 10)
		ft_putnbr(n / 10, count);
	c = n % 10 + '0';
	 if (write(1, &c, 1) == -1)
	 	return (-1);
	(*count)++;
	return (1);
}

int	ft_putnbr_u(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		ft_putnbr_u(n / 10, count);
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}

int choose_type(va_list *ap ,char b, int *count)
{
     if (b == 'c')
     {
        if (ft_putchar(va_arg(*ap, int), count) == -1)
        	return (-1);
     }
    else if (b == 's')
    {
        if (ft_putstr(va_arg(*ap, char*), count) == -1)
        	return (-1);
    }
    else if (b == 'X' || b == 'x')
    {
        if (ft_putnbr_hexa(va_arg(*ap, int), b, count) == -1)
        	return (-1);
    }
    else if (b == 'i' || b == 'd')
    {
        if (ft_putnbr(va_arg(*ap, int), count) == -1)
        	return (-1);
	}
    else if (b == 'p')
    {
        if (ft_itoa_p((unsigned long long) va_arg(*ap, void*), count) == -1)
        	return (-1);
    }
    else if (b == 'u')
    {
        if (ft_putnbr_u((unsigned int)va_arg(*ap, int), count) == -1)
        	return (-1);
    }
    else if (b == '%')
    {
    	if (write(1, "%", 1) == -1)
        	return (-1);
	(*count)++;
    }
    return (1);
}

int ft_printf(const char *f, ...)
{
    va_list ap;
    va_start(ap,f);
    unsigned int i;
     int count;

    i = 0;
    count = 0;
    while (f[i] != '\0')
    {
        if (f[i] != '%')
	{
            if (write(1, &f[i], 1) == -1)
            	return (-1);
	    count++;
	}
        else if (f[i] == '%')
        {
        	if (choose_type(&ap, f[i + 1], &count) == -1)
           		return (-1);
                i++;
        }
        if (f[i] != '\0')
            i++;
    }
    va_end(ap);
    return (count);
}
