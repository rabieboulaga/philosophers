/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_structurs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:29:38 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/21 21:54:39 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
int     my_usleep(size_t    milliseconds, t_info *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{	
        pthread_mutex_lock(&philo->cdata->mutex_flag);
        if (philo->cdata->flag == 1)
        {   
            pthread_mutex_unlock(&philo->cdata->mutex_flag); 
            return 0;
        }
        pthread_mutex_unlock(&philo->cdata->mutex_flag);
        usleep(500);
    }
    return (0);
}

void    list_info(t_info *philo, int n)
{
    int i;
    t_info *newphilo;
    t_info *tmp;

    i = 2; 
    while(i <= n)
    {
        newphilo = (t_info *)malloc(sizeof(t_info));
        newphilo->right = NULL;
        newphilo->left = NULL;
        newphilo->id = i;
        philo->start_eat = 0;
        newphilo->the_deid = 0;
        newphilo->l_meal = philo->cdata->n_meals;
        pthread_mutex_init(&newphilo->mutex_eat, NULL);
        pthread_mutex_init(&newphilo->fork, NULL);
        ft_lstadd_back(philo, newphilo);
        tmp = philo;
        philo = philo->right;
        philo->left = tmp;
        philo->cdata = tmp->cdata;
        i++; 
    }
}

void    elements(t_info *philo, t_data *data)
{
    t_info *tmp;
    
    tmp = philo;
    philo->id = 1;
    philo->l_meal = philo->cdata->n_meals;
    philo->the_deid = 0;
    philo->right = NULL;
    philo->left = NULL;
    philo->start_eat = 0;
    data->monitor_flag = 0;
    list_info(philo, data->philos);
    while (tmp->right)
        tmp = tmp->right;
    tmp->right = philo;
}   

int    build_structurs(int ac, char **av, t_info *philo, t_data *data)
{   
    memset(data, 0, sizeof(t_data));
    data->int_m = 0;
    data->philos = ft_atoi(av[1], data);
    data->t_die = ft_atoi(av[2], data);
    data->t_eat = ft_atoi(av[3], data);
    data->t_sleep = ft_atoi(av[4], data);
    pthread_mutex_init(&philo->fork, NULL);
    pthread_mutex_init(&philo->mutex_eat, NULL);
    pthread_mutex_init(&data->mutex_flag, NULL);
    pthread_mutex_init(&data->monitor, NULL);
    if (ac == 6)
        data->n_meals = ft_atoi(av[5], data);
    if (ac != 6)
        data->flag_meals = -1;
    if (data->int_m)
        return 1; 
    elements(philo, data);
    return 0;
}