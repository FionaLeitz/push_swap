/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:25 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 11:54:12 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// echanger les deux premiers nombres de la stack
void	ft_swap(t_stack **stack)
{
	int	tmp;

	ft_back_one(stack);
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	return ;
}

// passer le premier nombre de la stack, en dernier
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

// passer le dernier nombre de la stack, en premier
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

// passer le premier nombre de la stack_b en haut de la stack_a
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

// retrouver le premier element de la stack
void	ft_back_one(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	return ;
}
