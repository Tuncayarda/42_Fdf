/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putLine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:22:24 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 02:33:10 by tuaydin          ###   ########.fr       */
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

void	put_line(t_vr *vars, t_line_vars l_vr)
{
	if (l_vr.grad)
	{
		put_grad_line(vars, l_vr);
		return ;
	}
	l_vr.dx = abs(l_vr.p2.x - l_vr.p1.x);
	l_vr.dy = abs(l_vr.p2.y - l_vr.p1.y);
	l_vr.err = l_vr.dx - l_vr.dy;
	while (1)
	{
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
	}
}
