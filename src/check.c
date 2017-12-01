/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 21:23:42 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 06:59:14 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Counts the number of links of each block of a tet.
** If the number of links is 6 or 8, it is a valid tet:
** We normalize his coordinates and we return it.
** If not, we return NULL.
*/

t_tet		*check_tet(t_tet *tet)
{
	t_point			*coord;
	int				i;
	int				j;
	int				links;

	coord = tet->coord;
	i = 0;
	links = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			if (i != j && ((coord[i].x + 1 == coord[j].x && coord[i].y ==
			coord[j].y) || (coord[i].x - 1 == coord[j].x && coord[i].y ==
			coord[j].y) || (coord[i].x == coord[j].x && coord[i].y + 1 ==
			coord[j].y) || (coord[i].x == coord[j].x && coord[i].y - 1 ==
			coord[j].y)))
				links++;
		i++;
	}
	if (links == 6 || links == 8)
		return (normalize_coordinates(tet));
	return (NULL);
}

/*
** Moves a tet to the top left corner.
*/

t_tet		*normalize_coordinates(t_tet *tet)
{
	t_point		*coord;
	int			xfirst;
	int			yfirst;
	int			icoord;

	coord = tet->coord;
	icoord = 0;
	xfirst = 5;
	while (icoord < 4)
	{
		xfirst = min(coord[icoord].x, xfirst);
		icoord++;
	}
	yfirst = coord[0].y;
	icoord = 0;
	while (icoord < 4)
	{
		coord[icoord].x = coord[icoord].x - xfirst;
		coord[icoord].y = coord[icoord].y - yfirst;
		icoord++;
	}
	tet->width = calc_width(tet);
	tet->height = calc_height(tet);
	return (tet);
}
