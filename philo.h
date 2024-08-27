/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:15:20 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/27 13:24:01 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct c_stack
{
    int t_eat;
    int t_die;
    int t_sleep;
    int philos;
    int n_meals;
    pthread_mutex_t mutex;
}   t_data;

typedef struct c_info
{
    int id;
    int l_meal;
    pthread_mutex_t fork;
    pthread_t thread;
    struct c_stack *cdata;
    struct c_info *right;
}   t_info;

long long	ft_atoi(const char *str);
int         parsing(int ac, char **av);
void        build_structurs(int ac, char **av, t_info *philo, t_data *data);
void	    ft_lstadd_front(t_info **list, t_info *new_element);
void	    ft_lstadd_back(t_info *lst, t_info *nnew);
int         philo(int ac, char **av);
void        run_cycle(t_data *data, t_info *philo);

#endif