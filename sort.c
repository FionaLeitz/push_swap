/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:36:36 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 11:54:13 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the end of move_a
// utile seulement dans ce fichier
static void	ft_end_a(t_stack **stck_a, t_stack **stck_b, int max, t_args *infos)
{
	t_stack	*last;
	int		count;

	last = ft_back_last(stck_b);
	while (last->nbr != max)
	{
		ft_back_one(stck_b);
		infos->str = ft_string(stck_a, stck_b, infos->str, "rrb\n");
		last = ft_back_last(stck_b);
	}
	ft_back_one(stck_b);
	count = 1;
	if (infos->size % 2 != 0)
		count--;
	while (count < (infos->size / 2))
	{
		infos->str = ft_string(stck_a, stck_b, infos->str, "pa\n");
		count++;
	}
	infos->str = ft_string(stck_a, stck_b, infos->str, "rrb\n");
	infos->str = ft_string(stck_a, stck_b, infos->str, "pa\n");
	infos->str = ft_string(stck_a, stck_b, infos->str, "ra\n");
	return ;
}

// inside move_a
// utile seulement dans ce fichier
static void	ft_move_a_n(t_stack **stck_a, t_stack **stck_b, int n, t_args *info)
{
	t_stack	*last;

	last = ft_back_last(stck_b);
	while (last->nbr < n)
	{
		ft_back_one(stck_b);
		info->str = ft_string(stck_a, stck_b, info->str, "rrb\n");
		last = ft_back_last(stck_b);
	}
	ft_back_one(stck_b);
	while ((*stck_b)->nbr > n)
		info->str = ft_string(stck_a, stck_b, info->str, "rb\n");
	info->str = ft_string(stck_a, stck_b, info->str, "pb\n");
	return ;
}

// move in a to find next in b
// utile seulement dans ce fichier
static void	ft_move_a(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int		count;
	int		min;

	count = infos->size / 4;
	if (infos->size % 2 != 0)
		count += 1;
	while (count > 0)
	{
		min = ft_min(stack_a);
		if (ft_search(stack_a, min, count) == 1)
		{
			while ((*stack_a)->nbr != min)
				infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
		}
		else
		{
			while ((*stack_a)->nbr != min)
				infos->str = ft_string(stack_a, stack_b, infos->str, "rra\n");
		}
		ft_move_a_n(stack_a, stack_b, min, infos);
		count--;
	}
	ft_end_a(stack_a, stack_b, infos->tab[infos->size - 1], infos);
	return ;
}

// first step, move in b to put the first of a
// utile seulement dans ce fichier
static void	ft_move_b(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int		count;
	int		size2;
	t_stack	*last;

	count = (infos->size / 2) - 1;
	size2 = (infos->size / 4) + 1;
	while (count > size2)
	{
		while ((*stack_a)->nbr < (*stack_b)->nbr)
			infos->str = ft_string(stack_a, stack_b, infos->str, "rb\n");
		last = ft_back_last(stack_b);
		while ((*stack_a)->nbr > last->nbr)
		{
			ft_back_one(stack_b);
			infos->str = ft_string(stack_a, stack_b, infos->str, "rrb\n");
			last = ft_back_last(stack_b);
		}
		ft_back_one(stack_b);
		infos->str = ft_string(stack_a, stack_b, infos->str, "pb\n");
		count--;
	}
	ft_move_a(stack_a, stack_b, infos);
	return ;
}

// first step of sorting ?
void	ft_step1(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	int	min;
	int	max;

	min = infos->tab[infos->size / 2];
	max = infos->tab[infos->size - 1];
	infos->newsize = infos->size / 2;
	if (infos->size % 2 != 0)
		infos->newsize += 1;
	if (ft_new_search(stack_a, max, min, infos->size) == 1)
	{
		ft_push_n(stack_a, stack_b, max, infos);
		infos->str = ft_string(stack_a, stack_b, infos->str, "rb\n");
		infos->newsize -= 1;
		ft_push_n(stack_a, stack_b, min, infos);
	}
	else
	{
		ft_push_n(stack_a, stack_b, min, infos);
		infos->newsize -= 1;
		ft_push_n(stack_a, stack_b, max, infos);
		infos->str = ft_string(stack_a, stack_b, infos->str, "rb\n");
	}
	ft_move_b(stack_a, stack_b, infos);
	return ;
}
