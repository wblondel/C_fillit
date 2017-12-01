/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:23:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 18:08:15 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks if we can place the given tetromino at the current position.
** If so, we write the tetromino in the grid.
*/

int			place_tet(t_tet *tet, t_data *data, int x, int y)
{
	int			i;
	t_point		*coord;

	i = 0;
	while (i < 4)
	{
		coord = &tet->coord[i];
		if ((data->grid[y + coord->y][x + coord->x] != '.'))
			return (0);
		i++;
	}
	write_tet(tet, data, new_point(x, y), tet->letter);
	return (1);
}

/*
** Calculates the minimum grid size to fit our ntets tetrominos, and stores
** it to data->size.
** Then, creates a grid of size data->size and stores it in data->grid.
** While it can't solve the grid, destroys the grid, increases its size
** and recreates it.
*/

t_data		*solve(t_data *data)
{
	if (data)
	{
		data->size = calc_min_tab(data->ntets, data->tets);
		data->grid = create_grid(data->size);
		while (!solve_grid(data, 0))
		{
			data->grid = destroy_grid(data->grid, data->size);
			data->size += 1;
			data->grid = create_grid(data->size);
		}
		return (data);
	}
	return (NULL);
}

/*
** If the current tetromino is after the last one, it means we solved the grid.
** We cross the grid until we can place a tetromino. When it happens, we
** call our function recursively to place the next tetromino. If we can't
** place this one, we return 0 and erase it from the grid. We come back to
** the previous tetromino.
*/

int			solve_grid(t_data *data, int itetro)
{
	int			x;
	int			y;
	t_tet		*tetro;

	if (itetro >= data->ntets)
		return (1);
	y = 0;
	tetro = &data->tets[itetro];
	while (y < (data->size - tetro->height + 1))
	{
		x = 0;
		while (x < (data->size - tetro->width + 1))
		{
			if (place_tet(&data->tets[itetro], data, x, y))
			{
				if (solve_grid(data, itetro + 1))
					return (1);
				else
					write_tet(&data->tets[itetro], data, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Writes a tetromino to the grid using the given character.
** The character is either the tetrominos' letter or a dot (to erase a tet.)
*/

void		write_tet(t_tet *tet, t_data *data, t_point point, char l)
{
	char	*c;
	int		i;
	t_point	*coord;

	i = 0;
	while (i < 4)
	{
		coord = &tet->coord[i];
		c = &data->grid[point.y + coord->y][point.x + coord->x];
		*c = l;
		i++;
	}
}
