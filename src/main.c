/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/18 16:10:43 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:35:40 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc == 2)
	{
		data = init_data();
		if (data)
		{
			if ((data = import_from_file(argv[1], data)))
			{
				data = solve(data);
				show_grid(data);
				data->grid = destroy_grid(data->grid, data->size);
				data = destroy_data(data);
			}
			else
				error("import_from_file(): import failed");
		}
		else
			error("init_data(): malloc failed");
	}
	else
		error("usage: ./fillit tets_file");
	return (0);
}
