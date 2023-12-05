/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:31:08 by daraz             #+#    #+#             */
/*   Updated: 2023/12/05 11:19:04 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_highest_index:
	We search for the highest index in a stack.
*/
static int	get_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
	We sort a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
	rather than value. Example:
		values:		 0	 9	 2
		indexes:	[1]	[3]	[2]
	Solution, 2 moves:
	rra:
		values:		 2	 0	 9
		indexes:	[2]	[1]	[3]
	sa:
		values:		 0	 2	 9
		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = get_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
