/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:42:38 by daraz             #+#    #+#             */
/*   Updated: 2023/12/05 10:19:55 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rotate:
	We send the bottom element of a stack to the top.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*before_end;

	end = get_stack_bottom(*stack);
	before_end = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = end;
	(*stack)->next = tmp;
	before_end->next = NULL;
}

/* do_rra:
	For the next three functions we do reverse rotate for stack a, b or both 
    and print the appropriate name of the action.
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
