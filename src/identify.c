/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   identify.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 08:47:28 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:34:26 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Count the number of tetrominos in tets that are equal to
** the reference tetromino ref.
*/

unsigned char	count_t_oftype(t_tet tets[26], unsigned char nb_tetr, char *ref)
{
	unsigned char	nb_of_type;
	unsigned char	itetr;
	char			*strtet;

	itetr = 0;
	nb_of_type = 0;
	while (itetr < nb_tetr)
	{
		strtet = coord_to_str(tets[itetr].coord);
		if (ft_strcmp(strtet, ref) == 0)
			nb_of_type++;
		itetr++;
		free(strtet);
	}
	return (nb_of_type);
}

/*
** Returns the minimum grid size based on the number of
** horizontal or vertical bars found in the list of tetrominos.
*/

unsigned char	calc_min_tab_with_type_b(unsigned char nb_b)
{
	if (nb_b >= 1 && nb_b <= 4)
		return (4);
	if (nb_b >= 5 && nb_b <= 8)
		return (nb_b);
	if (nb_b >= 9 && nb_b <= 16)
		return (8);
	if (nb_b >= 17 && nb_b <= 18)
		return (9);
	if (nb_b >= 19 && nb_b <= 20)
		return (10);
	if (nb_b >= 21 && nb_b <= 22)
		return (11);
	if (nb_b >= 23 && nb_b <= 26)
		return (12);
	return (0);
}

/*
** Returns the minimum grid size based on the number of
** squares found in the list of tetrominos.
*/

unsigned char	calc_min_tab_with_type_s(unsigned char nb_s)
{
	if (nb_s == 1)
		return (2);
	if (nb_s >= 2 && nb_s <= 4)
		return (4);
	if (nb_s >= 5 && nb_s <= 9)
		return (6);
	if (nb_s >= 10 && nb_s <= 16)
		return (8);
	if (nb_s >= 17 && nb_s <= 25)
		return (10);
	if (nb_s == 26)
		return (12);
	return (0);
}
