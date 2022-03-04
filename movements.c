/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:25 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/04 10:52:33 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first and second in stack
void	ft_swap(t_stack **stack)
{
	int	tmp;

	ft_back_one(stack);
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	return ;
}

// put first of stack in last
void	ft_rotate(t_stack **stack)
{
	t_stack	*save;

	ft_back_one(stack);
	save = (*stack)->next;
	ft_stackadd_back(stack, *stack);
	save->prev = NULL;
	ft_back_one(stack);
	return ;
}

// put last of stack in first
void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*save;

	ft_back_one(stack);
	end = *stack;
	while (end->next != NULL)
		end = end->next;
	save = end->prev;
	ft_stackadd_front(stack, end);
	save->next = NULL;
	*stack = end;
	return ;
}

// put first of stack_b in first of stack_a
void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*save;
	t_stack	*save2;

	save2 = *stack_a;
	if ((*stack_b)->next == NULL)
	{
		(*stack_a)->prev = *stack_b;
		*stack_a = (*stack_a)->prev;
		(*stack_a)->next = save2;
		*stack_b = NULL;
		return ;
	}
	save = (*stack_b)->next;
	if (*stack_a == NULL)
		*stack_a = *stack_b;
	else
	{
		(*stack_a)->prev = *stack_b;
		*stack_a = (*stack_a)->prev;
	}
	(*stack_a)->next = save2;
	save->prev = NULL;
	*stack_b = save;
	return ;
}

// go back at the beggining of stack
void	ft_back_one(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	return ;
}
