#include "../include/guimp.h"

void midPointCircleDrawR(t_sdl *sdl, int x_center, int y_center, int r)
{
	while (r != 0)
	{
		midPointCircleDraw(sdl, x_center, y_center, r);
		r--;
	}

}	

void midPointCircleDraw(t_sdl *sdl, int x_center, int y_center, int r)
{
	int P;
	
	P = 1 - r;
    sdl->x = r;
	sdl->y = 0;
    printf("rayon cercle : %d\n", r);
    //pixelm(sdl, sdl->x + x_center, sdl->y + y_center);
     
    if (r > 0)
    {
        pixelm(sdl, sdl->x + x_center, -sdl->y + y_center);
        pixelm(sdl, -sdl->x + x_center, sdl->y + y_center);
        pixelm(sdl, sdl->y + x_center, -sdl->x + y_center);
        pixelm(sdl, -sdl->y + x_center, sdl->x + y_center);
    }
    while (sdl->x > sdl->y)
    {
        sdl->y++;
        
        if (P <= 0)
            P = P + 2*sdl->y + 1;
             
        else
        {
            sdl->x--;
            P = P + 2*sdl->y - 2*sdl->x + 1;
        }
         
        if (sdl->x < sdl->y)
            break;
         
        pixelm(sdl, sdl->x + x_center, sdl->y + y_center);
        pixelm(sdl, -sdl->x + x_center, sdl->y + y_center);
        pixelm(sdl, sdl->x + x_center, -sdl->y + y_center);
        pixelm(sdl, -sdl->x + x_center, -sdl->y + y_center);
         
        if (sdl->x != sdl->y)
        {
            pixelm(sdl, sdl->y + x_center, sdl->x + y_center);
            pixelm(sdl, -sdl->y + x_center, sdl->x + y_center);
            pixelm(sdl, sdl->y + x_center, -sdl->x + y_center);
            pixelm(sdl, -sdl->y + x_center, -sdl->x + y_center);
        }
    }
}
