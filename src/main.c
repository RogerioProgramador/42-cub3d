/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:09:42 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/06/05 23:22:57 by rsiqueir         ###   ########.fr       */
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

int main(void)
{
    void *mlx;
    void *win;
    t_image img;
    
    //posicao inicial do player

    double posX = 22, posY = 12;

    //direcao que o player estara no inicio
    double dirX = -1, dirY = 0;
    
    //the 2d raycaster version of camera plane/plano de visao da camera
    double planeX = 0, planeY = 0.66;


    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    // screen(screenWidth, screenHeight, 0, "Raycaster");
    create_window(&win, &mlx, screenWidth, screenHeight);
    printf("oi\n");
    //cria a imagem na mlx que desenharemos por cima na função draw vertical line
    mlx_new_image(mlx, screenWidth, screenHeight);
    img.pointer = mlx_new_image(mlx, screenWidth, screenHeight);
    img.pixels = mlx_get_data_addr(img.pointer, &(img.bits_per_pixel), &img.line_size, &img.endian);
    // img->pointer = mlx_new_image(mlx, screenWidth, screenHeight);
    
    printf("oi\n");
    while(1)
    {
        for(int x = 0; x < screenWidth; x++)
        {
            
            double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;
            
            int mapX = (int)posX;
            int mapY = (int)posY;

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
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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