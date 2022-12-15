
#include "libc.h"
#include "ft_printf.h"

static unsigned char c;
static int i ;
char tab[100];

void handle_siguser1(int sig)
{
    if(sig == 30)
        c = (c * 2) + 0;
    else if(sig == 31)
        c = (c * 2) + 1;
    i++;
}
// void handle_siguser2(int sig)
// {
//     c = (c * 2) + 1;
//     i++;
// }

int main()
{
    printf("%d\n", getpid());

    signal(SIGUSR1, handle_siguser1);
    signal(SIGUSR2, handle_siguser1);

    int j = 0;

    while (1)
    {
        sleep(2);
        ft_printf("%d",  i);
        if (i == 8)
        {
            // ft_printf("%c", c);
            tab[j] = c;
            if (!c)
            {
                ft_printf("%s %d\n", tab, j );
                j = -1;
                i = 0;
            }
            c = 0 ;
            i = 0;
            j++;
        }
    }
    return 0;
}