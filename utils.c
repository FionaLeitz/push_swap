/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:40:42 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/25 12:24:41 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find min number in stack
int	ft_min(t_stack **stack)
{
	int	min;

	min = (*stack)->nbr;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		if (min > (*stack)->nbr)
			min = (*stack)->nbr;
	}
	ft_back_one(stack);
	return (min);
}

// fin max number in stack
int	ft_max(t_stack **stack)
{
	int	max;

	max = (*stack)->nbr;
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		if (max < (*stack)->nbr)
			max = (*stack)->nbr;
	}
	ft_back_one(stack);
	return (max);
}

// separate big numbers in stack_a, and little ones in stack_b
// utile seulement dans ce fichier
static void	ft_separate(t_stack **stck_a, t_stack **stck_b, int n, t_args *info)
{
	int	count;

	count = 0;
	while (count < info->size)
	{
		if ((*stck_a)->nbr < n)
			info->str = ft_string(stck_a, stck_b, info->str, "pb\n");
		else
			info->str = ft_string(stck_a, stck_b, info->str, "ra\n");
		count++;
	}
	return ;
}

// move n number in stack_b
void	ft_push_n(t_stack **stack_a, t_stack **stack_b, int n, t_args *infos)
{
	if (ft_search(stack_a, n, infos->newsize) == 1)
	{
		while ((*stack_a)->nbr != n)
			infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
	}
	else
	{
		while ((*stack_a)->nbr != n)
			infos->str = ft_string(stack_a, stack_b, infos->str, "rra\n");
	}
	infos->str = ft_string(stack_a, stack_b, infos->str, "pb\n");
}

void	ft_print(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a) && (*stack_a)->next)
	{
		ft_printf("stack_a->nbr = %d\n", (*stack_a)->nbr);
		*stack_a = (*stack_a)->next;
	}
	if (*stack_a)
		ft_printf("stack_a->nbr = %d\n\n", (*stack_a)->nbr);
	while ((*stack_b) && (*stack_b)->next)
	{
		ft_printf("stack_b->nbr = %d\n", (*stack_b)->nbr);
		*stack_b = (*stack_b)->next;
	}
	if (*stack_b)
		ft_printf("stack_b->nbr = %d\n", (*stack_b)->nbr);
	return ;
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *tab)
{
	t_args	infos;

	infos.size = size;
	infos.tab = tab;
	infos.str = malloc(sizeof(char));
	if (infos.str == NULL)
		return ;
	if (size > 2)
	{
		ft_big1(stack_a, stack_b, &infos);
	}
	else
	{
		ft_separate(stack_a, stack_b, tab[size / 2], &infos);
		ft_step1(stack_a, stack_b, &infos);
		ft_step2(stack_a, stack_b, &infos);
		while ((*stack_a)->nbr != tab[0])
			infos.str = ft_string(stack_a, stack_b, infos.str, "rra\n");
	}
	infos.str = ft_find_reduce(infos.str);
	ft_find_suppress(infos.str);
	ft_print(stack_a, stack_b);
//	ft_printf("%s", infos.str);
	free(infos.str);
	return ;
}
