/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:13:54 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/12 18:54:43 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
# include <pthread.h>

void    monitor(t_info *philo)
{
    while (1)
    {
        pthread_mutex_lock(&philo->cdata->monitor);
        if (philo->cdata->monitor_flag == philo->cdata->philos)
        {
            pthread_mutex_unlock(&philo->cdata->monitor);
            return;
        }
        pthread_mutex_unlock(&philo->cdata->monitor);
        pthread_mutex_lock(&philo->cdata->mutex_flag);
        pthread_mutex_lock(&philo->mutex_eat);
        if ((get_current_time()) - (philo->start_eat) > philo->cdata->t_die)
        {   
            my_printf(philo, "this philo is die right now");
            philo->cdata->flag = 1;
            pthread_mutex_unlock(&philo->mutex_eat);
            pthread_mutex_unlock(&philo->cdata->mutex_flag);
            break;
        }
        pthread_mutex_unlock(&philo->mutex_eat);
        pthread_mutex_unlock(&philo->cdata->mutex_flag);
        philo = philo->right;
    }
}

int philo(int ac, char **av)
{
    t_info *philo;
    t_data *data;

    if (parsing(ac, av))
    {
        philo = malloc(sizeof(t_info));
        data = malloc(sizeof(t_data));
        philo->cdata = data;
        if (build_structurs(ac, av, philo, data) == 1) 
            return (1);
        run_cycle(data, philo);        
    }
    else
        return (1);
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