/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:26:19 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/06 16:28:58 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int main() {
    printf("Max unsigned int: %u\n", UINT_MAX);
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    return 0;
}

