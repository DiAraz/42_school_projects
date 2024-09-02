/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:40:11 by daraz             #+#    #+#             */
/*   Updated: 2024/09/02 12:17:40 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_HPP_
#define _ITER_HPP_

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T& var));

template<typename T>
void	printParam(T &val);

#endif