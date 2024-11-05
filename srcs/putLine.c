/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putLine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:22:24 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/05 22:09:34 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void putVerLine(t_vars *vars, t_point p1, t_point p2, int color)
{
	while (p1.y <= p2.y)
	{
		putPix(vars, p1, color);
		p1.y++;
	}
	while (p1.y >= p2.y)
	{
		putPix(vars, p1, color);
		p1.y--;
	}
}

static void putHorLine(t_vars *vars, t_point p1, t_point p2, int color)
{
	while (p1.x <= p2.x)
	{
		putPix(vars, p1, color);
		p1.x++;
	}
	while (p1.x >= p2.x)
	{
		putPix(vars, p1, color);
		p1.x--;
	}
}

void	putLine(t_vars *vars, t_point p1, t_point p2, int color)
{
	if (p1.x == p2.x)
		putVerLine(vars, p1, p2, color);
	if (p1.y == p2.y)
		putHorLine(vars, p1, p2, color);
}