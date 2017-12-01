/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 21:23:43 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 15:37:03 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Shows a grid.
*/

void	show_grid(t_data *data)
{
	unsigned int	i;

	if (data)
	{
		if (data->grid)
		{
			i = 0;
			while (i < data->size)
			{
				ft_putendl(data->grid[i]);
				i++;
			}
		}
	}
}
