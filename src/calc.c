/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:26:07 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:28:58 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "t_ref.h"

/*
** Calculates the minimum grid size to fill all our tetrominos.
** The calculation is based on the number of tetrominos,
** and the number of pieces by type.
*/

unsigned char	calc_min_tab(unsigned char nb_tetr, t_tet tets[26])
{
	unsigned char	min_tab;
	unsigned char	m_bv;
	unsigned char	m_bh;
	unsigned char	m_sq;

	min_tab = 2;
	while (min_tab * min_tab < (nb_tetr * 4))
		min_tab++;
	m_bv = calc_min_tab_with_type_b(count_t_oftype(tets, nb_tetr, g_ref[0]));
	m_bh = calc_min_tab_with_type_b(count_t_oftype(tets, nb_tetr, g_ref[1]));
	m_sq = calc_min_tab_with_type_s(count_t_oftype(tets, nb_tetr, g_ref[2]));
	return (max(min_tab, max(m_bv, max(m_bh, m_sq))));
}

/*
** Returns the width of a tetromino.
*/

unsigned char	calc_width(t_tet *tet)
{
	t_point			*coord;
	unsigned char	width;
	unsigned char	icoord;

	coord = tet->coord;
	icoord = 0;
	width = 0;
	while (icoord < 4)
	{
		width = max(coord[icoord].x, width);
		icoord++;
	}
	return (width + 1);
}

/*
** Returns the height of a tetromino.
*/

unsigned char	calc_height(t_tet *tet)
{
	t_point			*coord;
	unsigned char	height;
	unsigned char	icoord;

	coord = tet->coord;
	icoord = 0;
	height = 0;
	while (icoord < 4)
	{
		height = max(coord[icoord].y, height);
		icoord++;
	}
	return (height + 1);
}
