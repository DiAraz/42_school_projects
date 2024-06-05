/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:41:42 by daraz             #+#    #+#             */
/*   Updated: 2024/06/02 20:24:29 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av) {

    std::string const msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    
    if (ac == 1)
        std::cout << msg;
    else {
        int i = 1;
        while (av[i]) {
            int j = 0;
            while (av[i][j]) {
                std::cout << (char) toupper(av[i][j]);
                j++;
            }
            if (i < ac - 1)
                std::cout << ' ';
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}