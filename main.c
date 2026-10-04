/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:26:19 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/04 19:09:41 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
	void *s = "heyy";

	close(1);
    //int i = ft_printf("\nheyy%c %s %d %X %p %%",'a', "hey", 21, 2133, &s);
    int x = printf("\nheyy%c %s %d %X %p %%",'a', "hey", 21, 2133, &s);
    printf("\n%d", x);
    return (0);
}
