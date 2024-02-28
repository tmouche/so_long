/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_checker_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:16 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/28 18:51:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	_check_v(int x1, int x2, int o_x1, int (*check)[2])
{
	if (o_x1 == -1)
	{	
		check[0][0] = x1 + o_x1;
		check[0][1] = x2;
		check[1][0] = x1 + o_x1;
		check[1][1] = x2 + 1;
		check[2][0] = x1 + o_x1;
		check[2][1] = x2 + 2;
	}
	else
	{
		check[0][0] = x1 + 2 + o_x1;
		check[0][1] = x2;
		check[1][0] = x1 + 2 + o_x1;
		check[1][1] = x2 + 1;
		check[2][0] = x1 + 2 + o_x1;
		check[2][1] = x2 + 2;
	}
}

void	_check_h(int x1, int x2, int o_x2, int (*check)[2])
{
	if (o_x2 == -1)
	{
		check[0][0] = x1;
		check[0][1] = x2 + o_x2;
		check[1][0] = x1 + 1;
		check[1][1] = x2 + o_x2;
		check[2][0] = x1 + 2;
		check[2][1] = x2 + o_x2;
	}
	else
	{
		check[0][0] = x1;
		check[0][1] = x2 + 2 + o_x2;
		check[1][0] = x1 + 1;
		check[1][1] = x2 + 2 + o_x2;
		check[2][0] = x1 + 2;
		check[2][1] = x2 + 2 + o_x2;
	}
}

void	_check_d(int x1, int x2, int m_x1, int m_x2, int (*check)[2])
{
	if (m_x1 == 1)
		check[0][0] = x1 + 3;
	else
		check[0][0] = x1 - 1;
	if (m_x2 == 1)
		check[0][1] = x2 + 3;
	else
		check[0][1] = x2 - 1;
}