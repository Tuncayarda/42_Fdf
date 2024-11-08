#include "fdf.h"

int move_points(int keycode, t_joker *jkr)
{
	if (keycode == XK_Up)
	{
		putPix(&jkr->var, jkr->p, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p.y-=20;
		putPix(&jkr->var, jkr->p, WHITE);
	}
	if (keycode == XK_Down)
	{
		putPix(&jkr->var, jkr->p, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p.y+=20;

		putPix(&jkr->var, jkr->p, WHITE);
	}
	if (keycode == XK_Right)
	{
		putPix(&jkr->var, jkr->p, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p.x+=20;

		putPix(&jkr->var, jkr->p, WHITE);
	}
	if (keycode == XK_Left)
	{
		putPix(&jkr->var, jkr->p, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p.x-=20;

		putPix(&jkr->var, jkr->p, WHITE);
	}


	if (keycode == XK_w)
	{
		putPix(&jkr->var, jkr->p1, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p1.y-=20;
		putPix(&jkr->var, jkr->p1, WHITE);
	}

	if (keycode == XK_s)
	{
		putPix(&jkr->var, jkr->p1, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p1.y+=20;

		putPix(&jkr->var, jkr->p1, WHITE);
	}

	if (keycode == XK_d)
	{
		putPix(&jkr->var, jkr->p1, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p1.x+=20;
		putPix(&jkr->var, jkr->p1, WHITE);
	}

	if (keycode == XK_a)
	{
		putPix(&jkr->var, jkr->p1, BLACK);
		putLine(&jkr->var, jkr->p, jkr->p1, BLACK);
		jkr->p1.x-=20;
		putPix(&jkr->var, jkr->p1, WHITE);
	}

	mlx_put_image_to_window(jkr->var.mlx, jkr->var.win, jkr->var.img.ptr, 0, 0);
	put_grad_line(&jkr->var, jkr->p, jkr->p1, WHITE, BLACK);
}

