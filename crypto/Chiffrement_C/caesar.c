#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <errno.h>
#include "Tools.h"

#define IMG_PATH "./Tools/caesar.bmp"


int main(int argc, char * argv[])
{
    if(argc != 3)
        printf("too much or too few argument (TYPE EX : message, shift)\n");
    else
    {
        char *saved_un = malloc((sizeof(char) * strlen(argv[1]))+sizeof(char));
        char *saved_ci = malloc((sizeof(char) * strlen(argv[1]))+sizeof(char));
        char *saved_ro = malloc((sizeof(char) * strlen(argv[2]))+sizeof(char));

        strcpy(saved_ro, argv[2]);
        strcpy(saved_un, argv[1]);

        char u1 = saved_un[0];
        char u2 = saved_un[1];
        char u3 = saved_un[2];
        char u4 = saved_un[3];
        char u5 = saved_un[4];
        char u_n_1 = saved_un[strlen(argv[1])-2];
        char u_n = saved_un[strlen(argv[1])-1];

        int key = atoi(argv[2]);
        if(argv[2][0] == '-')
        {
            caesar2(argv[1], key);
        }
        else
            caesar2(argv[1], key);

        strcpy(saved_ci, argv[1]);

        char c1 = saved_ci[0];
        char c2 = saved_ci[1];
        char c3 = saved_ci[2];
        char c4 = saved_ci[3];
        char c5 = saved_ci[4];
        char cn_1 = saved_ci[strlen(argv[1])-2];
        char cn = saved_ci[strlen(argv[1])-1];

        sfRenderWindow *window;
        sfVideoMode video_mode = {1401, 800, 32};
        sfEvent event;
        sfTexture *empty = sfTexture_createFromFile(IMG_PATH, NULL);


        sfSprite *img = sfSprite_create();
        sfFont* f;
        f = sfFont_createFromFile("./Tools/ayar.ttf");


        //set uncipher text
        sfText *uncipher = SetText(saved_un, 70, 110, f, sfRed, 30);

        //set cipher text
        sfText *cipher = SetText(saved_ci, 250, 720, f, sfBlue, 30);


        //set rotation
        sfText *rot = SetText(saved_ro, 748, 110, f, sfGreen, 30);


        //set cipher chars
        sfText *cn1 = SetText(c_to_s(c1), 675, 195, f, sfBlue, 35);
        sfText *cn2 = SetText(c_to_s(c2), 675, 245, f, sfBlue, 35);
        sfText *cn3 = SetText(c_to_s(c3), 675, 295, f, sfBlue, 35);
        sfText *cn4 = SetText(c_to_s(c4), 675, 345, f, sfBlue, 35);
        sfText *cn5 = SetText(c_to_s(c5), 675, 395, f, sfBlue, 35);
        sfText *cnn_1 = SetText(c_to_s(cn_1), 675, 585, f, sfBlue, 35);
        sfText *cnn = SetText(c_to_s(cn), 675, 633, f, sfBlue, 35);


        //set unciphers chars
        sfText *un1 = SetText(c_to_s(u1), 402, 195, f, sfRed, 35);
        sfText *un2 = SetText(c_to_s(u2), 402, 245, f, sfRed, 35);
        sfText *un3 = SetText(c_to_s(u3), 402, 295, f, sfRed, 35);
        sfText *un4 = SetText(c_to_s(u4), 402, 345, f, sfRed, 35);
        sfText *un5 = SetText(c_to_s(u5), 402, 395, f, sfRed, 35);
        sfText *unn_1 = SetText(c_to_s(u_n_1), 402, 585, f, sfRed, 35);
        sfText *unn = SetText(c_to_s(u_n), 402, 633, f, sfRed, 35);

        window = sfRenderWindow_create(video_mode, "Caesear Cipher",
                sfClose | sfResize , NULL);



        sfSprite_setTexture(img, empty, sfFalse);

        while(sfRenderWindow_isOpen(window))
        {
            sfRenderWindow_display(window);
            sfRenderWindow_drawSprite(window, img, NULL);

            //draw ciph, unciph and key
            sfRenderWindow_drawText(window, uncipher, NULL);
            sfRenderWindow_drawText(window, cipher, NULL);
            sfRenderWindow_drawText(window, rot, NULL);

            //draw each char
            sfRenderWindow_drawText(window, un1, NULL);
            sfRenderWindow_drawText(window, un2, NULL);
            sfRenderWindow_drawText(window, un3, NULL);
            sfRenderWindow_drawText(window, un4, NULL);
            sfRenderWindow_drawText(window, un5, NULL);
            sfRenderWindow_drawText(window, unn_1, NULL);
            sfRenderWindow_drawText(window, unn, NULL);
            sfRenderWindow_drawText(window, cn1, NULL);
            sfRenderWindow_drawText(window, cn2, NULL);
            sfRenderWindow_drawText(window, cn3, NULL);
            sfRenderWindow_drawText(window, cn4, NULL);
            sfRenderWindow_drawText(window, cn5, NULL);
            sfRenderWindow_drawText(window, cnn_1, NULL);
            sfRenderWindow_drawText(window, cnn, NULL);

            //save the image on disk 
            sfTexture *saved = sfTexture_createFromFile(IMG_PATH, NULL);

            sfTexture_updateFromRenderWindow(saved, window, 0, 0);
            sfImage* screenshot = sfTexture_copyToImage(saved);
            sfImage_saveToFile(screenshot, "./processed/saved.bmp");


            while(sfRenderWindow_pollEvent(window, &event))
            {
                if(event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
            }
        }
    }


}
