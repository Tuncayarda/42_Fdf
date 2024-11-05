/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putPix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:23:07 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/05 22:09:55 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putPix(t_vars *vars, t_point p, int color)
{
	vars->img.data[(long)p.x + ((long)p.y * WIDTH)] = color;
}