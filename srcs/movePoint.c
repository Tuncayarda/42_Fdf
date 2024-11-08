#include "fdf.h"

int move_points(int keycode, t_joker *jkr)
{
	if (keycode == XK_Up)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
	 	jkr->l_vr.p1.y-=20;
	}
	if (keycode == XK_Down)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p1.y+=20;
	}
	if (keycode == XK_Right)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p1.x+=20;
	}
	if (keycode == XK_Left)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
	 	jkr->l_vr.p1.x-=20;
	}
	if (keycode == XK_w)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p2.y-=20;
	}

	if (keycode == XK_s)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p2.y+=20;
	}

	if (keycode == XK_d)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p2.x+=20;
	}

	if (keycode == XK_a)
	{
		put_line(&jkr->var, (t_line_vars){.p1 =jkr->l_vr.p1, .p2=jkr->l_vr.p2,.b_clr =((t_clr){BLACK})});
		jkr->l_vr.p2.x-=20;
	}
	mlx_put_image_to_window(jkr->var.mlx, jkr->var.win, jkr->var.img.ptr, 0, 0);
	put_line(&jkr->var, jkr->l_vr);
}

