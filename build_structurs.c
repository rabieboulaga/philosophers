/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_structurs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:29:38 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/27 13:30:58 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    list_info(t_info *philo, int n)
{
    int i;
    t_info *newphilo;

    i = 2;
    philo->id = 1;
    philo->l_meal = 0;
    philo->right = NULL;
    pthread_mutex_init(&philo->fork, NULL);
    while(i <= n)
    {
        newphilo = (t_info *)malloc(sizeof(t_info));
        newphilo->right = NULL;
        newphilo->id = i;
        newphilo->l_meal = 0;
        pthread_mutex_init(&newphilo->fork, NULL);
        ft_lstadd_back(philo, newphilo);
        i++;
        philo = philo->right;
    }
}

void    build_structurs(int ac, char **av, t_info *philo, t_data *data)
{   
    memset(data, 0, sizeof(t_data));
    data->philos = ft_atoi(av[1]);
    data->t_die = ft_atoi(av[2]);
    data->t_eat = ft_atoi(av[3]);
    data->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->n_meals = ft_atoi(av[5]);
    list_info(philo, data->philos);
    // for (int i = 0; i < data->philos; i++)
    // {
    //     printf("id %d\n",philo->id);
    //     philo = philo->right;
    // }
    
}