/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destroy.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 19:21:55 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 12:05:41 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Destroy a grid and return NULL.
*/

char	**destroy_grid(char **grid, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
	return (grid);
}

/*
** Free everything.
*/

t_data	*destroy_data(t_data *data)
{
	free(data);
	data = NULL;
	return (data);
}
