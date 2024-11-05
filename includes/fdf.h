#ifndef FDF_H
# define FDF_H

# include "mlx.h"

# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>

#define WIDTH 1920
#define HEIGHT 1080

#define WHITE 0x00FFFFFF
#define TITLE "title"

typedef struct	s_img
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;

}				t_vars;

typedef struct 	s_point
{
	float 	x;
	float	y;
}				t_point;


void	putPix(t_vars *vars, t_point p, int color);
void	putLine(t_vars *vars, t_point p1, t_point p2, int color);
int		create_trgb(int t, int r, int g, int b);

#endif
