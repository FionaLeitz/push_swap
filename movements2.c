/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:12:24 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/04 10:49:19 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first and second in stack_a, and same for stack_b
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	return ;
}

// put first number of stack_a in last, and same for stack_b
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	return ;
}

// put last number of stack_a in first, and same for stack_b
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	return ;
}

// free all of stack
void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	ft_back_one(&stack);
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}

// free both stacks and tab
int	ft_free_all(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(tab);
	return (0);
}
