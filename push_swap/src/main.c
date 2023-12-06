/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:06:58 by daraz             #+#    #+#             */
/*   Updated: 2023/12/06 07:57:05 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
	We check if a stack is sorted.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
/* push_swap:
	Depending on the number of values we chose the sorting method.
*/

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}
/*  main:
    We check if the input is correct, then we initialize stacks,
	assign indexes and perform sorting algorithm. 
    After we free the stacks and end the program.
*/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
