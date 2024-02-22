

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
