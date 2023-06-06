/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:46:16 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/06/05 02:27:59 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void create_window(void **win, void **mlx, int width, int height)
{
    *mlx = mlx_init();
    *win = mlx_new_window(*mlx, width, height, "Raycaster");
}