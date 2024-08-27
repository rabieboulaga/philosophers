/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:51:39 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:14 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void   *arg)
{
    t_info *philo = (t_info *)arg;
    printf("---->%d\n", philo->id);
    pthread_mutex_lock(&philo->fork);
    sleep(1);       
    printf("%d<----\n", philo->id);
    pthread_mutex_unlock(&philo->fork);

    return 0;
}

void    run_cycle(t_data *data, t_info *philo)
{
    int i;
    t_info *tmp;
    tmp = philo;
    i = 0;
  
    
    pthread_mutex_init(&data->mutex, NULL);
    while (i < data->philos)
    {
        philo->cdata = tmp->cdata;
        pthread_create(&philo->thread, NULL, routine, philo);
        i++;
        philo = philo->right;
    }
    
}