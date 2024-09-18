/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:32:28 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/17 20:04:45 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     one_philo(t_info *philo, t_data *data)
{
    if(data->philos ==1)
    {    
        printf("0  1 has taken a fork\n");
        printf("%ld  1 died\n", data->t_die + 1);
        free(data);
        free(philo);
        return 1;
    }
    return (0);
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