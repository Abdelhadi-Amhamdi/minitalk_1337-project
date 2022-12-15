

#include "libc.h"

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int server_id = atoi(av[1]);
        char *c = av[2];

        char c_bin[9];
        unsigned char bit;

        int i = 0;

        while (c[i])
        {
            int n = 8;
            int j = 0;
            while (n--)
            {
                c_bin[j] = (c[i] >> n & 1) + '0';
                j++;
            }
            c_bin[j] = '\0';

            int k = 0;
            while (c_bin[k])
            {
                if (c_bin[k] == '0')
                {
                    kill(server_id, SIGUSR1);
                    printf("%c", c_bin[k]);
                }
                else if (c_bin[k] == '1')
                {
                    kill(server_id, SIGUSR2);
                    printf("%c", c_bin[k]);
                }
                usleep(100);
                k++;
            }
            i++;
        }
        i = 8;
        while (i > 0)
        {
            kill(server_id, SIGUSR1);
            printf("%c", '0');
            i--;
        }
    }

    return 0;
}