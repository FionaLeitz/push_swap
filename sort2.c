/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:36:45 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/04 10:45:28 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the end of move_b2
// all of stack_b is sorted in stack_a
// the all list is sorted
static void	ft_end_b2(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	t_stack	*last;

	last = ft_back_last(stack_a);
	while ((*stack_b)->nbr < last->nbr)
	{
		ft_back_one(stack_a);
		infos->str = ft_string(stack_a, stack_b, infos->str, "rra\n");
		last = ft_back_last(stack_a);
	}
	ft_back_last(stack_a);
	infos->str = ft_string(stack_a, stack_b, infos->str, "pa\n");
	infos->str = ft_string(stack_a, stack_b, infos->str, "rra\n");
	return ;
}

// inside move_b2, when max of stack_b is found,
// move in stack_a to place max of stack_b
static void	ft_move_b2_n(t_stack **stk_a, t_stack **stck_b, int n, t_args *info)
{
	t_stack	*last;

	last = ft_back_last(stk_a);
	while (last->nbr > n)
	{
		ft_back_one(stk_a);
		info->str = ft_string(stk_a, stck_b, info->str, "rra\n");
		last = ft_back_last(stk_a);
	}
	ft_back_one(stk_a);
	while ((*stk_a)->nbr < n)
		info->str = ft_string(stk_a, stck_b, info->str, "ra\n");
	info->str = ft_string(stk_a, stck_b, info->str, "pa\n");
	return ;
}

// move in stack_b to find next in stack_a
// find max of stack_b to put it in stack_a, repeatedly
static void	ft_move_b2(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int		count;
	int		max;

	count = infos->size / 4;
	while (count > 1)
	{
		max = ft_max(stack_b);
		if (ft_search(stack_b, max, count) == 1)
		{
			while ((*stack_b)->nbr != max)
				infos->str = ft_string(stack_a, stack_b, infos->str, "rb\n");
		}
		else
		{
			while ((*stack_b)->nbr != max)
				infos->str = ft_string(stack_a, stack_b, infos->str, "rrb\n");
		}
		ft_move_b2_n(stack_a, stack_b, max, infos);
		count--;
	}
	ft_end_b2(stack_a, stack_b, infos);
	return ;
}

// move in stack_a to put the first of stack_b
static void	ft_move_a2(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int		count;
	t_stack	*last;

	count = (infos->size / 2) - 2;
	while (count > (infos->size / 4))
	{
		while ((*stack_b)->nbr > (*stack_a)->nbr)
			infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
		last = ft_back_last(stack_a);
		while ((*stack_b)->nbr < last->nbr)
		{
			ft_back_one(stack_a);
			infos->str = ft_string(stack_a, stack_b, infos->str, "rra\n");
			last = ft_back_last(stack_a);
		}
		ft_back_one(stack_a);
		infos->str = ft_string(stack_a, stack_b, infos->str, "pa\n");
		count--;
	}
	ft_move_b2(stack_a, stack_b, infos);
	return ;
}

// put min and max of stack_b in stack_a
void	ft_step2(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int		min;
	int		max;

	min = infos->tab[0];
	max = infos->tab[(infos->size / 2) - 1];
	infos->newsize = infos->size / 2;
	if (ft_new_search(stack_b, max, min, infos->size) == 1)
	{
		ft_push_n2(stack_a, stack_b, min, infos);
		infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
		infos->newsize -= 1;
		ft_push_n2(stack_a, stack_b, max, infos);
	}
	else
	{
		ft_push_n2(stack_a, stack_b, max, infos);
		infos->newsize -= 1;
		ft_push_n2(stack_a, stack_b, min, infos);
		infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
	}
	ft_move_a2(stack_a, stack_b, infos);
	return ;
}
