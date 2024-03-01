

//window

int ft_update(t_struct *glob)
{
	static unsigned int	lap = 0;
	static unsigned int lap_fps = 0;
	static unsigned int lap_proj = 0;

	lap++;
	lap_proj++;
	lap_fps++;
	if (POWER / 10 / lap_proj == 1)
	{
		if (glob->info->proj->limit > 0)
			ft_projectile(glob->info, glob->info->proj, glob->info->map);
		ft_update_anim(glob);
		lap_proj = 0;
	}
	if (POWER / 3 / lap == 1)
	{
		if (glob->info->proj->limit == 0)
			ft_player(glob->info, glob->info->mv_y, glob->info->mv_x);
		ft_ennemies(glob->info, glob->info->bad);
		lap = 0;
	}
	if (POWER / 60 / lap_fps == 1)
	{
		ft_new_frame(glob);
		lap_fps = 0;
	}
	return (0);
}

//texture

void	ft_update_anim(t_struct* glob)
{
	if (glob->info->proj->i == 0 && glob->info->player_state == 0
		&& glob->info->proj->shoot == 0)
		return ;
	if (glob->info->player_state <= 10 && glob->info->proj->shoot != 0)
		glob->info->player_state++;
	else
	{
		glob->info->player_state = 0;
		glob->info->proj->shoot = 0;
	}
}
