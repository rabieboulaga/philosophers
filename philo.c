/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:13:54 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/17 19:58:50 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
# include <pthread.h>

int     bye(t_info  *philo)
{
    size_t	time;
	time = get_current_time() - philo->cdata->start_time;
    if ((get_current_time()) - (philo->start_eat) > philo->cdata->t_die)
    {   
	    printf("%ld  %d died\n",time, philo->id);
        philo->cdata->flag = 1;
        pthread_mutex_unlock(&philo->cdata->mutex_flag);
        pthread_mutex_unlock(&philo->mutex_eat);
        return 1;
    }
    return (0);
}


void    monitor(t_info *philo)
{
    while (1)
    {
        pthread_mutex_lock(&philo->cdata->monitor);
        if (philo->cdata->monitor_flag == philo->cdata->philos)
        {
            pthread_mutex_unlock(&philo->cdata->monitor);
            break ;
        }
        pthread_mutex_unlock(&philo->cdata->monitor);
        pthread_mutex_lock(&philo->cdata->mutex_flag);
        pthread_mutex_lock(&philo->mutex_eat);
        if (bye(philo))
            break;
        pthread_mutex_unlock(&philo->cdata->mutex_flag);
        pthread_mutex_unlock(&philo->mutex_eat);
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
        if (one_philo(philo, data))
            return 0;                   
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