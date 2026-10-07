/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:12:49 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/04 19:00:30 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c, int *count);
int	ft_putstr(char *s, int *count);
int	ft_itoa_p(unsigned long long n, int *count);
int	ft_putnbr_hexa(unsigned int nbr, char b, int *count);
int	ft_printf(const char *f, ...);

#endif
