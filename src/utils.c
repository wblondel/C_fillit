/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 19:52:55 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 18:09:37 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Prints an error message and exit with error code 1.
*/

void		error(char *msg)
{
	ft_putendl(msg);
	exit(1);
}

/*
** Returns the smallest value between a and b.
*/

int			min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

/*
** Returns the biggest value between a and b.
*/

int			max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

/*
** Creates a point with coordinates x, y and returns it.
*/

t_point		new_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

/*
** Converts a coord[4] to a string.
*/

char		*coord_to_str(t_point coord[4])
{
	char *d;

	d = ft_strnew(8);
	d[0] = coord[0].x + 48;
	d[1] = coord[0].y + 48;
	d[2] = coord[1].x + 48;
	d[3] = coord[1].y + 48;
	d[4] = coord[2].x + 48;
	d[5] = coord[2].y + 48;
	d[6] = coord[3].x + 48;
	d[7] = coord[3].y + 48;
	return (d);
}
