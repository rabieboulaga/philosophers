/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:40:21 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/06 23:46:32 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int checker(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (!av)
        return 1;
    while (ac > i)
    {
        j = 0;
        if (!av[i])
            return 1;
        if (av[i][0] == '+' && av[i][1] != '\0')
            j++;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int parsing(int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        if (checker(ac, av))
            return 0;
        return 1;   
    }
    else
        return 0;  
}
