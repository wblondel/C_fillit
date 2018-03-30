/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:36:20 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 07:21:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Shows number of tets
*/

void	show_ntets(t_data *data)
{
	if (data)
	{
		ft_putstr("The number of tets is: ");
		ft_putnbr(data->ntets);
		ft_putchar('\n');
	}
}

/*
** Shows the size of the grid.
*/

void	show_size(t_data *data)
{
	if (data)
	{
		ft_putstr("The grid size is: ");
		ft_putnbr(data->size);
		ft_putstr("*");
		ft_putnbr(data->size);
		ft_putchar('\n');
	}
}

/*
** Shows the coordinates of a t_point
*/

void	show_point(t_point point)
{
	ft_putchar('{');
	ft_putnbr(point.x);
	ft_putchar(',');
	ft_putnbr(point.y);
	ft_putstr("} ");
}

/*
** Shows the coordinates of each block of a tet.
*/

void	show_tet_coordinates(t_tet *tet)
{
	int i;

	i = 0;
	ft_putstr("Coordinates: ");
	while (i < 4)
	{
		show_point(tet->coord[i]);
		i++;
	}
	ft_putchar('\n');
}

/*
** Shows the coordinates of each block of all the tets.
*/

void	show_tets_coordinates(t_tet *tets[26], unsigned char n)
{
	int i;

	i = 0;
	while (i < n)
	{
		show_tet_coordinates(tets[i]);
		i++;
	}
}

/*
** Shows the data of a tet.
*/

void	show_tet(t_tet *tet)
{
	ft_putstr("Letter: ");
	ft_putchar(tet->letter);
	ft_putstr("; ");
	show_tet_coordinates(tet);
}

/*
** Shows the data of all tets.
*/

void	show_tets(t_data *data)
{
	int i;

	i = 0;
	ft_putendl("---> ALL tets <---");
	while (i < data->ntets)
	{
		show_tet(&(data->tets[i]));
		i++;
	}
}
