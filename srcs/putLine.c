/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putLine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:22:24 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/08 22:52:27 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putLine(t_vr *vars, t_pt p1, t_pt p2, int clr)
{
	int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putPix(vars, p1, clr);
        
        if (p1.x == p2.x && p1.y == p2.y)
            break;
        
        int e2 = 2 * err;
        
        if (e2 > -dy) { 
            err -= dy;
            p1.x += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            p1.y += sy;
        }
    }
}

void	put_grad_line(t_vr *vars, t_pt p1, t_pt p2, int clr, int toclr)
{
	t_color c1 = {.color = clr};
	t_color c2 = {.color = toclr};
	int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

	int steps = dx > dy ? dx : dy;
	
	float	r_step = (c2.r - c1.r) / steps; 
	float	g_step = (c2.g - c1.g) / steps;
	float	b_step = (c2.b - c1.b) / steps;

	float	red = c1.r;
	float	green = c1.g;
	float	blue = c1.b;

    while (1) {
		c1.r = (unsigned char)red;
		c1.g = (unsigned char)green;
		c1.b = (unsigned char)blue;
        putPix(vars, p1, c1.color);
        
        if (p1.x == p2.x && p1.y == p2.y)
            break;
        
        int e2 = 2 * err;
        
        if (e2 > -dy) { 
            err -= dy;
            p1.x += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            p1.y += sy;
        }

		red += r_step;
		green += g_step;
		blue += b_step;
    }
}