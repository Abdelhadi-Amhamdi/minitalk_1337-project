/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:58 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/15 17:39:12 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char *char_to_bin(char c)
{
    char *char_bin;
    int n = 8;
    int index = 0;

    char_bin = malloc(sizeof(char) * 9);
    if(!char_bin)
        return (NULL);
    while (n--)
    {
        char_bin[index] = (c >> n & 1) + '0';
        index++;
    }
    char_bin[index] = '\0';

    return (char_bin);
}

void send_char(char *bin, int id)
{
    int index = 0;

    while (bin[index])
    {
        if (bin[index] == '0')
        {
            kill(id, SIGUSR1);
            // printf("%c", bin[index]);
        }
        else if (bin[index] == '1')
        {
            kill(id, SIGUSR2);
            // printf("%c", bin[index]);
        }
        usleep(100);
        index++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *data = av[2];
        int server_id = atoi(av[1]);

        int index = 0;
        // size_t size = strlen(data);
        char *char_bin;

        // send_char(char_to_bin( size + 48), server_id);

        while (data[index])
        {
            char_bin = char_to_bin(data[index]);
            send_char(char_bin, server_id);
            index++;
        }
        
        send_char(char_to_bin(0), server_id);
        
    }
    return 0;
}