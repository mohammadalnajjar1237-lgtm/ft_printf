/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:02:05 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/06 15:50:51 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *s, int *count)
{	
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*count += 6;
		return (1);
		
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		(*count)++;
	}
	
	return (1);
}
/*int main()
{
	int i = 0;
	ft_putstr(NULL, &i);
}*/
