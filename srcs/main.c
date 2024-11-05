/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:26:35 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/05 22:56:53 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	t_vars	mlx_v;
	
	
	mlx_v.mlx = mlx_init();
	mlx_v.win = mlx_new_window(mlx_v.mlx, WIDTH, HEIGHT, TITLE);
	mlx_v.img.ptr = mlx_new_image(mlx_v.mlx, WIDTH, HEIGHT);


	mlx_v.img.data = (int *)mlx_get_data_addr(mlx_v.img.ptr, &mlx_v.img.bpp, &mlx_v.img.size_line, &mlx_v.img.endian);
	
	putLine(&mlx_v, (t_point){.x = 10, .y = 10}, (t_point){.x = 1000, .y = 10}, 0xFFFF0000);

	mlx_put_image_to_window(mlx_v.mlx, mlx_v.win, mlx_v.img.ptr, 0, 0);
	mlx_loop(mlx_v.mlx);
}
