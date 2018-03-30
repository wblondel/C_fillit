/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 19:52:42 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:31:38 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** *****************************************************************************
** ******************************** Includes ***********************************
** *****************************************************************************
*/

# include "basics/chars.h"
# include "basics/strings.h"
# include "basics/numbers.h"
# include "basics/memory.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** *****************************************************************************
** **************************** Global variables *******************************
** *****************************************************************************
*/

/*
** BUF_SIZE		buffer size when reading a file
*/

# define BUF_SIZE 21

/*
** *****************************************************************************
** ***************************** Data structure ********************************
** *****************************************************************************
*/

/*
** s_point			coordinates of a '#'
** s_tet		data of a tet: his letter and his '#'
** s_data			the final grid, the grid size, and the list of tets
*/

typedef struct		s_point
{
	char			x;
	char			y;
}					t_point;

typedef struct		s_tet
{
	t_point			coord[4];
	unsigned char	letter;
	unsigned char	width;
	unsigned char	height;
}					t_tet;

typedef struct		s_data
{
	char			**grid;
	unsigned char	size;
	unsigned char	ntets;
	t_tet			tets[26];
}					t_data;

/*
** *****************************************************************************
** ******************************** Prototypes *********************************
** *****************************************************************************
*/

/*
** calc.c
*/

unsigned char		calc_min_tab(unsigned char nb_tetr, t_tet tets[26]);
unsigned char		calc_width(t_tet *tet);
unsigned char		calc_height(t_tet *tet);

/*
** check.c
*/

t_tet				*check_tet(t_tet *tet);
t_tet				*normalize_coordinates(t_tet *tet);

/*
** create.c
*/

char				**create_grid(unsigned int size);
t_data				*init_data(void);
t_tet				*init_tet(unsigned char letter);
t_tet				*create_tet(char *str, unsigned char letter);
void				modify_tet_coord(t_point *point, unsigned char i);

/*
** destroy.c
*/

char				**destroy_grid(char **grid, unsigned int size);
t_data				*destroy_data(t_data *data);

/*
** identify.c
*/

unsigned char		count_t_oftype(t_tet tets[26], unsigned char nb_tetr,\
																	char *ref);
unsigned char		calc_min_tab_with_type_b(unsigned char nb_b);
unsigned char		calc_min_tab_with_type_s(unsigned char nb_s);

/*
** import.c
*/

t_data				*import_from_file(char const *filename, t_data *data);
int					open_file(char const *filename);
t_data				*read_file(int const fd, t_data *data);

/*
** show.c
*/

void				show_grid(t_data *data);

/*
** solve.c
*/

int					place_tet(t_tet *tet, t_data *data, int x, int y);
t_data				*solve(t_data *data);
int					solve_grid(t_data *data, int itetro);
void				write_tet(t_tet *tet, t_data *data, t_point point, char l);

/*
** utils.c
*/

void				error(char *msg);
int					min(int a, int b);
int					max(int a, int b);
t_point				new_point(int x, int y);
char				*coord_to_str(t_point coord[4]);

#endif
