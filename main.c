/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:32:28 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/21 22:00:54 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    *op_routine(void *arg)
{
    t_info *philo = (t_info *)arg;
    printf("0  1 has taken a fork\n");
    printf("%ld  1 died\n", philo->cdata->t_die + 1);
    free(philo);
    return (NULL);
}

void    one_philo(t_info *philo, t_data *data)
{
    pthread_create(&philo->thread, NULL, op_routine, philo);
    pthread_join(philo->thread, NULL);
    free(data);
}



int main(int ac, char **av)
{
    if(philo(ac, av))
    {    
        printf("Error, Something is wrong\n");
        return 1;     
    }    
    return 0;
}