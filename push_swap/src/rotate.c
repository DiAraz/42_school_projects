/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:16:28 by daraz             #+#    #+#             */
/*   Updated: 2023/12/05 10:16:40 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate:
	We send the top element of the stack to the bottom.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = *stack;
	*stack = (*stack)->next;
	end = get_stack_bottom(*stack);
	tmp->next = NULL;
	end->next = tmp;
}

/* For the next three functions we do rotate for stack a, b or both 
    and print the appropriate name of the action.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
