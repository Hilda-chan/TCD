#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <string.h>
#include <errno.h>

#define IMG_PATH "./Tools/Calculette.png"




int main(int argc, char * argv[])
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {403, 671, 32};
    sfEvent MainWindow;

    sfTexture *empty = sfTexture_createFromFile(IMG_PATH, NULL);
    sfSprite *img = sfSprite_create();
    sfVector2i mouse_pos;

    window = sfRenderWindow_create(video_mode, "Calculatrice",
            sfClose | sfResize, NULL);

    sfSprite_setTexture(img, empty, sfFalse);



    char *expr = malloc(sizeof(char)*51);
    memset(expr, 0, strlen(expr));


    while(sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, img, NULL);

        while(sfRenderWindow_pollEvent(window, &MainWindow))
        {
            if(MainWindow.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if(MainWindow.type == sfEvtMouseButtonPressed)
            {
                mouse_pos = sfMouse_getPositionRenderWindow(window);

                if(mouse_pos.x > 11 && mouse_pos.x < 85 &&
                        mouse_pos.y > 180 && mouse_pos.y < 250)
                {
                    memset(expr, 0, strlen(expr));
                    printf("%s\n", expr); 
                }

                if(mouse_pos.x > 115 && mouse_pos.x < 190 &&
                        mouse_pos.y > 180 && mouse_pos.y < 250)
                {
                    strcat(expr, "(");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 215 && mouse_pos.x < 290 &&
                    mouse_pos.y > 180 && mouse_pos.y < 250)
                {
                    strcat(expr, ")");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 315 && mouse_pos.x < 390 &&
                        mouse_pos.y > 180 && mouse_pos.y < 250)
                {
                    strcat(expr, "/");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 11 && mouse_pos.x < 85 &&
                        mouse_pos.y > 280 && mouse_pos.y < 350)
                {
                    strcat(expr, "7");
                    printf("%s\n", expr);

                }

                if(mouse_pos.x > 115 && mouse_pos.x < 190 &&
                        mouse_pos.y > 280 && mouse_pos.y < 350)
                {
                    strcat(expr, "8");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 215 && mouse_pos.x < 290 &&
                        mouse_pos.y > 280 && mouse_pos.y < 350)
                {
                    strcat(expr, "9");
                    printf("%s\n", expr);
                }
                if(mouse_pos.x > 315 && mouse_pos.x < 390 &&
                        mouse_pos.y > 280 && mouse_pos.y < 350)
                {
                    strcat(expr, "*");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 11 && mouse_pos.x < 85 &&
                        mouse_pos.y > 380 && mouse_pos.y < 450)
                {
                    strcat(expr, "4");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 115 && mouse_pos.x < 190 &&
                        mouse_pos.y > 380 && mouse_pos.y < 450)
                {
                    strcat(expr, "5");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 215 && mouse_pos.x < 290 &&
                        mouse_pos.y > 380 && mouse_pos.y < 450)
                {
                    strcat(expr, "6");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 315 && mouse_pos.x < 390 &&
                        mouse_pos.y > 380 && mouse_pos.y < 450)
                {
                    strcat(expr, "-");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 11 && mouse_pos.x < 85 &&
                        mouse_pos.y > 480 && mouse_pos.y < 550)
                {
                    strcat(expr, "1");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 115 && mouse_pos.x < 190 &&
                        mouse_pos.y > 480 && mouse_pos.y < 550)
                {
                    strcat(expr, "2");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 215 && mouse_pos.x < 290 &&
                        mouse_pos.y > 480 && mouse_pos.y < 550)
                {
                    strcat(expr, "3");
                    printf("%s\n", expr);
                }

                if(mouse_pos.x > 315 && mouse_pos.x < 390 &&
                        mouse_pos.y > 480 && mouse_pos.y < 550)
                {
                    strcat(expr, "+");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 11 && mouse_pos.x < 85 &&
                        mouse_pos.y > 580 && mouse_pos.y < 650)
                {
                    strcat(expr, ".");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 115 && mouse_pos.x < 190 &&
                        mouse_pos.y > 580 && mouse_pos.y < 650)
                {
                    strcat(expr, "0");
                    printf("%s\n", expr);
                }


                if(mouse_pos.x > 215 && mouse_pos.x < 390 &&
                        mouse_pos.y > 580 && mouse_pos.y < 650)
                    printf("%s\n", expr);
            }

        }
    }
}
