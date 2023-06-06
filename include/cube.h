/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:26 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/06/05 01:46:58 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_image
{
	void	*pointer;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_image;

void create_window(void **win, void **mlx, int width, int height);
#endif