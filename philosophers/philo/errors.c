/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:36:39 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 10:52:43 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_error(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    write(2, "Error: ", 7);
    write(2, str, len);
    write(2, "\n", 1);
    return (1);
}

int ft_init_error(int i)
{
    if (i == 1)
        return (ft_error("Invalid arguments"));
    if (i == 2)
        return (ft_error("Fail mutex initialisation"));
    return (1);
}