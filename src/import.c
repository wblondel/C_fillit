/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:18:47 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 07:40:37 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** We try to open what's behind the filename. See open_file().
** If OK, we read the file, close the fd, and return the data.
*/

t_data		*import_from_file(char const *filename, t_data *data)
{
	int		fd;

	if ((fd = open_file(filename)) >= 0)
	{
		data = read_file(fd, data);
		close(fd);
		return (data);
	}
	else
		return (NULL);
}

/*
** We try to open what's behind the filename.
** If it's a directory, we return -1 to exit.
** If it's a file, we return the file descriptor.
** If nothing exists of name filename, we return -1.
*/

int			open_file(char const *filename)
{
	int		fd;

	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

/*
** We read the file that is behind the file descriptor fd.
** For each 21 bytes read, we try to create a tet of it.
** If it fails : error.
** We save the created tet in our list of tets.
** We increment the number of tets and save it in data->ntets.
** We then return the data.
*/

t_data		*read_file(int const fd, t_data *data)
{
	int		ret_read;
	char	buf[BUF_SIZE + 1];
	int		ntets;
	t_tet	*tet;

	ntets = 0;
	while ((ret_read = read(fd, buf, BUF_SIZE)))
	{
		buf[ret_read] = '\0';
		tet = create_tet(buf, ntets);
		if (tet == NULL)
			error("error");
		ft_memcpy(&data->tets[ntets], tet, sizeof(*tet));
		free(tet);
		data->ntets = ++ntets;
	}
	if (ft_strlen(buf) != 20)
		error("error");
	return (data);
}
