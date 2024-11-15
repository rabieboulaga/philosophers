/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:51:39 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/21 16:27:43 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




void    sleeping(t_info *philo)
{
    // pthread_mutex_lock(&philo->cdata->mutex_flag);
    // if (philo->cdata->flag == 1)
    // {   
        // pthread_mutex_unlock(&philo->cdata->mutex_flag); 
        // return ;
    // }
    // pthread_mutex_unlock(&philo->cdata->mutex_flag);
    my_printf(philo, "is sleeping");
    my_usleep(philo->cdata->t_sleep, philo);
    pthread_mutex_lock(&philo->cdata->mutex_flag);
    if (philo->cdata->flag == 1)
    {   
        pthread_mutex_unlock(&philo->cdata->mutex_flag); 
        return ;
    }
    pthread_mutex_unlock(&philo->cdata->mutex_flag);
    my_printf(philo, "is thinking");
    if (philo->cdata->philos % 2 != 0)    
        usleep(500);
}

int    even_take_forks(t_info *philo)
{
    if  (philo->l_meal == 0 && philo->cdata->flag_meals != -1)
        return 0;
    pthread_mutex_lock(&philo->right->fork);
    my_printf(philo, "has taken a fork");
    pthread_mutex_lock(&philo->fork);
    my_printf(philo, "has taken a fork");
    my_printf(philo, "is eating");
    pthread_mutex_lock(&philo->mutex_eat);
    philo->start_eat = get_current_time();
    pthread_mutex_unlock(&philo->mutex_eat);
    philo->l_meal--;
    my_usleep(philo->cdata->t_eat, philo);
    pthread_mutex_unlock(&philo->right->fork);
    pthread_mutex_unlock(&philo->fork);
    return 0;
}

int    odd_take_forks(t_info *philo)
{
    if  (philo->l_meal == 0 && philo->cdata->flag_meals != -1)
        return 0;
    pthread_mutex_lock(&philo->fork);
    my_printf(philo, "has taken a fork");
    pthread_mutex_lock(&philo->right->fork);
    my_printf(philo, "has taken a fork");
    pthread_mutex_lock(&philo->mutex_eat);
    philo->start_eat = get_current_time();
    pthread_mutex_unlock(&philo->mutex_eat);
    my_printf(philo, "is eating");
    philo->l_meal--;
    my_usleep(philo->cdata->t_eat, philo);
    pthread_mutex_unlock(&philo->right->    fork);
    pthread_mutex_unlock(&philo->fork);
    return 0;
}
int     eating(t_info *philo)
{
    if (philo->id % 2 != 0)
        odd_take_forks(philo);
    else
        even_take_forks(philo);
    if  (philo->l_meal == 0 && philo->cdata->flag_meals != -1)
    {   
        pthread_mutex_lock(&philo->cdata->monitor);
        philo->cdata->monitor_flag++;
        pthread_mutex_unlock(&philo->cdata->monitor);
        return 1;
    }
    return 0;

}

void    *routine(void   *arg)
{
    t_info *philo = (t_info *)arg; 
    if (philo->id % 2 == 0)
        usleep(450);   
    while (1)
    {
        pthread_mutex_lock(&philo->cdata->mutex_flag);
        if (philo->cdata->flag == 1)
        {   
            pthread_mutex_unlock(&philo->cdata->mutex_flag); 
            break;
        }
        pthread_mutex_unlock(&philo->cdata->mutex_flag);
        if (eating(philo))
           break; 
        sleeping(philo);
    }
    return (NULL);
}

void    run_cycle(t_data *data, t_info *philo)
{
    int i;

    i = 0;
    philo->cdata->start_time = get_current_time();
    while (i < data->philos)
    {
        pthread_create(&philo->thread, NULL, routine, philo);
        i++;
        pthread_mutex_lock(&philo->mutex_eat);
        philo->start_eat = get_current_time();     
        pthread_mutex_unlock(&philo->mutex_eat);
        philo = philo->right;
    }
    i = 0;
    monitor(philo); 
    while (i < data->philos)
    {
        pthread_join(philo->thread, NULL);
        philo = philo->right;
        i++;
    }
}




















































    // if (philo->id % 2 == 0)
    //     usleep(500);
    // if ()
    //     take_forks(philo);
  
  
  
  
    // monitor(philo);
// int     monitor(t_info  *philo)
// {
    
// }

// int     take_forks(t_info  *philo)
// {
//     if ()
        
// }
    // if (philo->id % 2 == 0)
    //     usleep(5000);
    // pthread_mutex_lock(&philo->fork);
    // pthread_mutex_lock(&philo->right->fork);
    // printf("%d\n", philo->id);
    // sleep(2);
    // pthread_mutex_unlock(&philo->right->fork);
    // pthread_mutex_unlock(&philo->fork);