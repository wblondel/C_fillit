/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:44:44 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 13:29:47 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Mallocs a grid, fills it with dots, and return it.
*/

char		**create_grid(unsigned int size)
{
	char			**grid;
	unsigned int	i;

	i = 0;
	grid = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		grid[i] = ft_strnew(sizeof(char) * size);
		ft_memset(grid[i], '.', sizeof(char) * size);
		i++;
	}
	return (grid);
}

/*
** Initializes the base structure that will contain all our data.
*/

t_data		*init_data(void)
{
	t_data	*data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	data->grid = NULL;
	return (data);
}

/*
** Initializes a tretromino with 'letter' as name.
** Letter is an int. If letter is 0 then A will be the name.
** We initialize his coordinates to {-3,-3},{-3,-3},{-3,-3},{-3,-3},
** which means that he has no '#' blocks.
** Why -3 ? Because when we will normalize the coordinates, then can go
** as low as -2.
*/

t_tet		*init_tet(unsigned char letter)
{
	t_tet			*tet;
	t_point			*coord;
	unsigned char	i;

	i = 0;
	tet = (t_tet*)ft_memalloc(sizeof(t_tet));
	if (tet)
	{
		tet->letter = letter + 65;
		while (i < 4)
		{
			coord = (t_point*)ft_memalloc(sizeof(t_point));
			coord->x = -3;
			coord->y = -3;
			ft_memcpy(&tet->coord[i], coord, sizeof(t_point));
			free(coord);
			i++;
		}
	}
	return (tet);
}

/*
** We first initialize a tet, see init_tet().
** We then read the 21 bytes buffer.
** A \n is supposed to be the 4th (i = 4) character (0-index) of each line.
** If we find a \n and (i + 1) % 5 != 0, it means the line finished too early,
** so we return NULL.
** If we find a '.' or a '\n', everything is fine.
** Else, if we find a '#' and that's the 1st, the 2nd, the 3rd, or the 4th '#',
** we add his coordinates to the tet.
** Else, we return NULL.
*/

t_tet		*create_tet(char *str, unsigned char letter)
{
	t_tet			*tet;
	unsigned char	i;
	unsigned char	nblock;

	i = 0;
	nblock = 0;
	tet = init_tet(letter);
	if (!tet)
		error("init_tet(): malloc failed");
	while (i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (NULL);
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#' && nblock < 4)
		{
			modify_tet_coord(&tet->coord[nblock], i);
			nblock++;
		}
		else
			return (NULL);
		i++;
	}
	return (check_tet(tet));
}

/*
** Modifies a tet coordinates to current line and column based on
** the position i in the string.
*/

void		modify_tet_coord(t_point *point, unsigned char i)
{
	point->x = i % 5;
	point->y = i / 5;
}
