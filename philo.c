/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:13:54 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/27 13:12:25 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
# include <pthread.h>

int philo(int ac, char **av)
{
    t_info *philo;
    t_data *data;

    if (parsing(ac, av))
    {
        philo = malloc(sizeof(t_info));
        data = malloc(sizeof(t_data));
        philo->cdata = data;
        build_structurs(ac, av, philo, data);
        run_cycle(data, philo);
    }
    else
    {
        printf("Error");
        return (1); 
    }
    return(0); 
}


// # define N 20000000
// int count = 0;
// pthread_mutex_t mutex;

// void    *routine(void *arg)
// {
//     int i  = 0;
//     while (i < N)
//     {
//         // pthread_mutex_lock(&mutex);
//         count++;
//         // pthread_mutex_unlock(&mutex);
//         i++;
//     }
//     return NULL;
// }

// int main ()
// {
//     int i  = 0;
//     pthread_t t[2];

//     pthread_mutex_init(&mutex, NULL);
//     while (i < 2)
//     {
//         pthread_create(&t[i], NULL, routine, NULL);
//         i++;
//     }
//     i = 0;
//     while (i < 2)
//     {
//         pthread_join(t[i], NULL);
//         i++;
//     }
//     printf("count = %d\n", count);
// }