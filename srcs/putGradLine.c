/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putGradLine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:28:24 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 02:16:10 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_x_cords(t_pt *p1, t_pt *p2)
{
	if (p1->x < p2->x)
		p1->x++;
	else if (p1->x > p2->x)
		p1->x--;
}

static void	set_y_cords(t_pt *p1, t_pt *p2)
{
	if (p1->y < p2->y)
		p1->y++;
	else if (p1->y > p2->y)
		p1->y--;
}

static void	assign_l_vars(t_line_vars *l_vr)
{
	l_vr->dx = abs(l_vr->p2.x - l_vr->p1.x);
	l_vr->dy = abs(l_vr->p2.y - l_vr->p1.y);
	l_vr->err = l_vr->dx - l_vr->dy;
	if (l_vr->dx > l_vr->dy)
		l_vr->steps = l_vr->dx;
	else
		l_vr->steps = l_vr->dy;
	l_vr->red = l_vr->b_clr.r;
	l_vr->green = l_vr->b_clr.g;
	l_vr->blue = l_vr->b_clr.b;
}

void	put_grad_line(t_vr *vars, t_line_vars l_vr)
{
	assign_l_vars(&l_vr);
	while (1)
	{
		l_vr.b_clr.r = (unsigned char)l_vr.red;
		l_vr.b_clr.g = (unsigned char)l_vr.green;
		l_vr.b_clr.b = (unsigned char)l_vr.blue;
		put_pix(vars, l_vr.p1, l_vr.b_clr.color);
		if (l_vr.p1.x == l_vr.p2.x && l_vr.p1.y == l_vr.p2.y)
			break ;
		l_vr.err2 = 2 * l_vr.err;
		if (l_vr.err2 > -l_vr.dy)
		{
			l_vr.err -= l_vr.dy;
			set_x_cords(&l_vr.p1, &l_vr.p2);
		}
		if (l_vr.err2 < l_vr.dx)
		{
			l_vr.err += l_vr.dx;
			set_y_cords(&l_vr.p1, &l_vr.p2);
		}
		l_vr.red += (l_vr.to_clr.r - l_vr.b_clr.r) / (float)l_vr.steps;
		l_vr.green += (l_vr.to_clr.g - l_vr.b_clr.g) / (float)l_vr.steps;
		l_vr.blue += (l_vr.to_clr.b - l_vr.b_clr.b) / (float)l_vr.steps;
	}
}
