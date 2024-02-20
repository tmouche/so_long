





char	**_map_dup(t_map *info)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(info->map_height * 3 + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < info->map_height * 3)
	{
		new_map[i] = ft_calloc(info->map_width * 3 + 1, 1);
		if (!new_map[i])
			return (_freemap(new_map), NULL);
		i++;
	}
	_map_charger(info, new_map);
	_freemap(info->map);
	return (new_map);
}

static void	_map_charger(t_map *info, char **map)
{
	int	x1;
	int	x2;
	
	x1 = 0;
	while (info->map[x1])
	{
		x2 = 0;
		while (info->map[x1][x2])
		{
			_square_three(map, x1 * 3, x2 * 3, info->map[x1][x2]);
			x2++;
		}
		x1++;
	}
}
static void	_square_three(char **map, int x1, int x2, char c)
{
	int	n_x1;
	int	n_x2;
	
	n_x1 = 0;
	while (n_x1 < 3)
	{
		n_x2 = 0;
		while (n_x2 < 3)
		{
			map[x1 + n_x1][x2 + n_x2] = c;
			n_x2++;
		}
		n_x1++;
	}
}

void	_kill_opps(t_opps *bad, int x1, int x2)
{
	int	temp_x1;
	int temp_x2;

	while (bad)
	{
		temp_x1 = x1;
		while (bad->x1 != temp_x1 && x1 - temp_x1 < 2)
			temp_x1--;
		temp_x2 = x2;
		while (bad->x2 != temp_x2 && x2 - temp_x2 < 2)
			temp_x2--;
		if (bad->x1 == temp_x1 && bad->x2 == temp_x2)
		{
			bad->state = -1;
			return ;
		}
		bad = bad->next;
	}
}
