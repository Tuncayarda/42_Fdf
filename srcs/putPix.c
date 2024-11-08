/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putPix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:23:07 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/08 22:28:34 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putPix(t_vr *vars, t_pt p, int color)
{
	if (p.x < WIDTH && p.y < HEIGHT && p.y >= 0  && p.x >= 0)
	vars->img.data[(long)p.x + ((long)p.y * WIDTH)] = color;
}