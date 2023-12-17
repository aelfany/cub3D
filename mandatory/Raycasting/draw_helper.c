/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:41:21 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/12 15:48:46 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_ato(char *str)
{
	int		a;
	size_t	res;
	int		nb;

	a = 0;
	nb = 1;
	res = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '-')
		nb *= -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		res *= 10;
		res = res + str[a] - 48;
		a++;
	}
	return (res * nb);
}

int	fun(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
	return (a << 24 | b << 16 | c << 8 | d);
}

uint32_t	convetcolor(char *str)
{
	char		**s;
	int			a;
	uint32_t	x;

	a = 0;
	x = 0;
	s = NULL;
	while (str[a])
	{
		if (ft_isdigit(str[a]))
		{
			s = ft_split(str + a, ',');
			x = fun(ft_ato(s[0]), ft_ato(s[1]), ft_ato(s[2]), 255);
			break ;
		}
		a++;
	}
	free_string(s);
	return (x);
}
