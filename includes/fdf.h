#ifndef FDF_H
# define FDF_H

# include "mlx.h"

# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

#define WIDTH 1920
#define HEIGHT 1080

#define WHITE 0x00FFFFFF
#define BLACK 0x00000000
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

typedef struct	s_joker
{
	t_vr var;
	t_pt p;
	t_pt p1;
}				t_joker;

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
}				t_color;

void	putPix(t_vr *vars, t_pt p, int color);
void	putLine(t_vr *vars, t_pt p1, t_pt p2, int color);

int move_points(int keycode, t_joker *jkr);

void	put_grad_line(t_vr *vars, t_pt p1, t_pt p2, int clr, int toclr);

#endif
