/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:25:39 by rboulaga          #+#    #+#             */
/*   Updated: 2024/09/17 14:13:34 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		my_printf(t_info *philo, char *str)
{
	size_t	time;
	time = get_current_time() - philo->cdata->start_time;
	pthread_mutex_lock(&philo->cdata->mutex_flag);
        if (philo->cdata->flag == 1)
        {   
            pthread_mutex_unlock(&philo->cdata->mutex_flag); 
            return 0;
        }
    pthread_mutex_unlock(&philo->cdata->mutex_flag);
	printf("%ld  %d %s\n",time, philo->id ,str);
	
	return 0;
}

t_info	*ft_lstlast(t_info *list)
{
	if (!list)
		return (NULL);
	while (list->right)
	{
		list = list->right;
	}
	return (list);
}

void	ft_lstadd_back(t_info *lst, t_info *nnew)
{
	t_info	*head;

	if (!lst || !nnew)
		return ;
	if (!lst)
		lst = nnew;
	else
	{
		head = ft_lstlast(lst);
		head->right = nnew;
	}
}


// void	ft_lstadd_front(t_info **list, t_info *new_element)
// {
// 	if (!list || !new_element)
// 		return ;
// 	new_element->left = *list;
// 	*list = new_element;
// }

long long	ft_atoi(const char *str, t_data *data)
{
	int			i;
	long long	res;
	int			s;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (res > 2147483647)
		data->int_m = 1;
	return (res * s);
}

// void    list_info(t_info *philo, int n)
// {
//     int i;
//     t_info  *left;

//     left = philo;
//     i = 1;  
//     while(i <= n)
//     {
//         philo->id = i;
//         philo->l_meal = 0;
//         left = philo;
//         printf("-----------------\n");
        
//         printf("id : %d\n meals : %d \n", philo->id, philo->l_meal);
//         pthread_mutex_init(&philo->fork, NULL);
//         philo->right = (t_info *)malloc(sizeof(t_info));
        
//         philo->right = NULL;
//         ft_lstadd_back(philo, philo->right);
//         philo = philo->right;
//         // philo->left = left;
//         i++;
//     }
// }
