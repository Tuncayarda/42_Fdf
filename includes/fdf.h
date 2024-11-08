#ifndef FDF_H
# define FDF_H

#include "colors.h"

# include "mlx.h"

# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
#define WIDTH 1920
#define HEIGHT 1080
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

}				t_vr;

typedef struct 	s_point
{
	float 	x;
	float	y;
}				t_pt;

typedef union	u_color
{
	struct
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	};
	unsigned int color;
}				t_clr;


typedef struct	s_line_vars
{
	t_pt	p1;
	t_pt	p2;
	int		dx;
	int		dy;
	int		err;
	int		err2;
	int		steps;
	float	red;
	float	green;
	float	blue;
	t_clr	b_clr;
	t_clr	to_clr;
	bool	grad;
}				t_line_vars;

typedef struct	s_joker
{
	t_vr var;
	t_line_vars l_vr;
}				t_joker;


void	put_pix(t_vr *vars, t_pt p, int color);

void	put_line(t_vr *vars, t_line_vars l_vr);
void	put_grad_line(t_vr *vars, t_line_vars l_vr);

int		move_points(int keycode, t_joker *jkr);
#endif
