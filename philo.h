/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:15:20 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/21 21:58:56 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct c_stack
{
    int monitor_flag;
    int flag;
    int t_eat;
    size_t t_die;
    int t_sleep;
    int philos;
    int n_meals;
    int flag_meals;
    size_t  start_time;
    pthread_mutex_t monitor;
    pthread_mutex_t mutex_flag;
    int     int_m;
}   t_data;

typedef struct c_info
{
    long long start_eat;
    int id;
    int l_meal;
    pthread_t thread;
    pthread_mutex_t mutex_eat;
    pthread_mutex_t fork;
    struct c_stack *cdata;
    struct c_info *right;
    struct c_info *left;
    size_t         the_deid;
}   t_info;

int         parsing(int ac, char **av);
int         build_structurs(int ac, char **av, t_info *philo, t_data *data);
void	    ft_lstadd_back(t_info *lst, t_info *nnew);
int         philo(int ac, char **av);
void        run_cycle(t_data *data, t_info *philo);
int		    my_printf(t_info *philo, char *str);
int         my_usleep(size_t    milliseconds, t_info *philo);
size_t	    get_current_time(void);
void        monitor(t_info *philo);
void         one_philo(t_info *philo, t_data *data);
long long	ft_atoi(const char *str, t_data *data);

#endif