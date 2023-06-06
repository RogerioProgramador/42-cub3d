/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:09:42 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/06/06 02:54:48 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1280
#define screenHeight 720

/*mapa exemplo*/
int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_player {
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
} t_player;

int get_color(int option)
{
    int red = 255;
    int green = 255;
    int blue = 255;
    
    if (option == 1) { // Vermelho
        green = 0;
        blue = 0;
    } else if (option == 2) { // Verde
        red = 0;
        blue = 0;
    } else if (option == 3) { // Azul
        red = 0;
        green = 0;
    }
    else if (option == 4) {
        red = 0;
        green = 0;
    }
    else if (option == 5) {
        red = 0;
    }
    else if (option != 6) { // Amarelo (qualquer outra opção)
        blue = 0;
    } 
    
    int color = (red << 16) | (green << 8) | blue;
    
    return color;
}

void move_player(int key, t_player *player)
{
  double moveSpeed = 0.05;
  double rotSpeed = 0.05;

  if (key == 13) // W key
  {
    if (!worldMap[(int)(player->posX + player->dirX * moveSpeed)][(int)(player->posY)])
      player->posX += player->dirX * moveSpeed;
    if (!worldMap[(int)(player->posX)][(int)(player->posY + player->dirY * moveSpeed)])
      player->posY += player->dirY * moveSpeed;
  }
  if (key == 1) // S key
  {
    if (!worldMap[(int)(player->posX - player->dirX * moveSpeed)][(int)(player->posY)])
      player->posX -= player->dirX * moveSpeed;
    if (!worldMap[(int)(player->posX)][(int)(player->posY - player->dirY * moveSpeed)])
      player->posY -= player->dirY * moveSpeed;
  }
  if (key == 0) // A key
  {
    double oldDirX = player->dirX;
    player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
    player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
    double oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
    player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
  }
  if (key == 2) // D key
  {
    double oldDirX = player->dirX;
    player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
    player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
    double oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
    player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
  }
}

int key_hook(int keycode, t_player *player)
{
  if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
    {
        printf("Ratinho\n");
        move_player(player, keycode); 
    }
    else{
        printf("Caiu aqui mas tecla errada: %i", keycode);
    }
    
  return (0);
}

int main(void)
{
    void *mlx;
    void *win;
    t_image img;
    t_player player;

    player.posX = 22;
    player.posY = 12;
    player.dirX = -1;
    player.dirY = 0;
    player.planeX = 0;
    player.planeY = 0.66;

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    create_window(&win, &mlx, screenWidth, screenHeight);
    
    mlx_new_image(mlx, screenWidth, screenHeight);
    img.pointer = mlx_new_image(mlx, screenWidth, screenHeight);
    img.pixels = mlx_get_data_addr(img.pointer, &(img.bits_per_pixel), &img.line_size, &img.endian);

    while(1)
    {
        for(int x = 0; x < screenWidth; x++)
        {
            double cameraX = 2 * x / (double)screenWidth - 1;
            double rayDirX = player.dirX + player.planeX * cameraX;
            double rayDirY = player.dirY + player.planeY * cameraX;
            
            int mapX = (int)player.posX;
            int mapY = (int)player.posY;

            double sideDistX;
            double sideDistY;
            
            double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
            double perpWallDist;

            int stepX;
            int stepY;

            int hit = 0;
            int side;

            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (player.posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - player.posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (player.posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - player.posY) * deltaDistY;
            }

            //perform DDA
            while (hit == 0)
            {

                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }

                if (worldMap[mapX][mapY] > 0)
                    hit = 1;
            }
            if(side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);

            int lineHeight = (int)(screenHeight / perpWallDist);

            int drawStart = -lineHeight / 2 + screenHeight / 2;
            if(drawStart < 0) drawStart = 0;
            int drawEnd = lineHeight / 2 + screenHeight / 2;
            if(drawEnd >= screenHeight)
                drawEnd = screenHeight - 1;

            int color;
            switch(worldMap[mapX][mapY])
            {
                case 1:  color = get_color(1);    break; //red
                case 2:  color = get_color(2);  break; //green
                case 3:  color = get_color(3);   break; //blue
                case 4:  color = get_color(4);  break; //white
                default: color = get_color(0); break; //yellow
            }

            if(side == 1)
                {color = color / 2;}
                
            draw_vertical_line(x, drawStart, drawEnd, color, &win, &mlx, &img);
        }
    }
}

void draw_vertical_line(int x, int drawStart, int drawEnd, int color, void **win, void **mlx, t_image *img)
{
    int color_floor = get_color(4);
    int color_ceilling = get_color(5);

    for (int y = 0; y < drawStart; y++)
    {
        int pixel_index = y * screenWidth + x;
        img->pixels[pixel_index * (img->bits_per_pixel / 8)] = color_ceilling & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 1] = (color_ceilling >> 8) & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 2] = (color_ceilling >> 16) & 0xFF;
    }
    for (int y = drawStart; y <= drawEnd; y++)
    {
        int pixel_index = y * screenWidth + x;
        img->pixels[pixel_index * (img->bits_per_pixel / 8)] = color & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 1] = (color >> 8) & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 2] = (color >> 16) & 0xFF;
    }
    for (int y = drawEnd; y <= screenHeight; y++)
    {
        int pixel_index = y * screenWidth + x;
        img->pixels[pixel_index * (img->bits_per_pixel / 8)] = color_floor & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 1] = (color_floor >> 8) & 0xFF;
        img->pixels[pixel_index * (img->bits_per_pixel / 8) + 2] = (color_floor >> 16) & 0xFF;
    }
    mlx_put_image_to_window(*mlx, *win, img->pointer, 0, 0);
}