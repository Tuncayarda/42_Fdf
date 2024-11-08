/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:26:35 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 02:34:23 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	t_joker jkr;
	t_vr	mlx_v;
	t_pt	p1 = {.x = 0, .y = 0};
	t_pt	p2 = {.x = 0, .y = 0};
	mlx_v.mlx = mlx_init();
	mlx_v.win = mlx_new_window(mlx_v.mlx, WIDTH, HEIGHT, TITLE);
	mlx_v.img.ptr = mlx_new_image(mlx_v.mlx, WIDTH, HEIGHT);

	mlx_v.img.data = (int *)mlx_get_data_addr(mlx_v.img.ptr, &mlx_v.img.bpp, &mlx_v.img.size_line, &mlx_v.img.endian);
	
	jkr.var = mlx_v;
	jkr.l_vr.p1 = p1;
	jkr.l_vr.p2 = p2;
	jkr.l_vr.b_clr = (t_clr){.color = RED};
	jkr.l_vr.to_clr = (t_clr){.color = GREEN};
	jkr.l_vr.grad = true;

	mlx_put_image_to_window(mlx_v.mlx, mlx_v.win, mlx_v.img.ptr, 0, 0);
	mlx_hook(mlx_v.win, 2, 1L<<0, move_points, &jkr);
	mlx_loop(mlx_v.mlx);
}
