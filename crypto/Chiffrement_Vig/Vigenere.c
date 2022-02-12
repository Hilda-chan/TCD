#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>


void extend(int size, char key[], char returned[])
{
    int j = 0;
    for(int i = 0; i <= size; i++)
    {
        if(key[j] == '\0')
        {
            j = 0;
            returned[i] = key[j];
            j++;
        }
        else
        {
            returned[i] = key[j];
            j++;
        }
    }
}

void Vigenere2_0(char msg[], char key[])
{
    char ret[strlen(msg)+1];
    ret[strlen(msg)] = '\0';
    extend(strlen(msg)-1, key, ret);

    for(size_t i = 0; msg[i] != '\0'; i++)
    {
        if(msg[i] <= 122 && msg[i] >= 97)
        {
            size_t val = ((msg[i] - 97) + (ret[i] - 97)) % 26;
            msg[i] = val + 97;
        }
        if(msg[i] <= 90 && msg[i] >= 65)
        {
            ret[i] -= 32;
            size_t val = ((msg[i] - 65) + (ret[i] - 65)) % 26;
            msg[i] = val + 65;
        }
    }
}


int main(int argc, char * argv[])
{
    if(argc != 3)
        printf("too much or too few argument (EX: message, keyword)\n");
    else
    {
        Vigenere2_0(argv[1], argv[2]);
        printf("%s\n", argv[1]);
    }
}
