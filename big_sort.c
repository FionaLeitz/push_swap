/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:41:04 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/25 12:31:28 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end_big_lists(t_stack **stack_a, t_stack **stack_b, t_args *infos)
{
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->nbr < (*stack_a)->nbr)
		{
			infos->str = ft_string(stack_a, stack_b, infos->str, "pa\n");
			infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
		}
		else
			infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
		if ((*stack_a)->nbr == infos->tab[0])
		{
			while (*stack_b)
			{
				infos->str = ft_string(stack_a, stack_b, infos->str, "pa\n");
				infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
			}
		}
	}
	while ((*stack_a)->nbr != infos->tab[0])
		infos->str = ft_string(stack_a, stack_b, infos->str, "ra\n");
}

void	ft_use_swap(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		info->str = ft_string(stack_a, stack_b, info->str, "sa\n");
	if ((*stack_b)->nbr > (*stack_b)->next->nbr)
		info->str = ft_string(stack_a, stack_b, info->str, "sb\n");
	return ;
}

void	ft_fonction(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	int	rp[2];

	while (info->newsize >= 4)
	{
		ft_use_swap(stack_a, stack_b, info);
		ft_memcpy(&rp, (int [2]){5, 2}, sizeof(int) * 2);
		while ((--rp[0] > 0 || rp[1] > 0) && info->newsize-- > 0)
		{
			if (((*stack_a)->nbr > (*stack_b)->nbr || rp[1] - rp[0] == 0)
				&& rp[1]-- > 0)
				info->str = ft_string(stack_a, stack_b, info->str, "pa\n");
			info->str = ft_string(stack_a, stack_b, info->str, "ra\n");
		}
		if (info->newsize < 4)
			break ;
		ft_use_swap(stack_a, stack_b, info);
		ft_memcpy(&rp, (int [2]){5, 2}, sizeof(int) * 2);
		while ((--rp[0] > 0 || rp[1] > 0) && info->newsize-- > 0)
		{
			if (((*stack_b)->nbr > (*stack_a)->nbr || rp[1] - rp[0] == 0)
				&& rp[1]-- > 0)
				info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
		}
	}
}

void	ft_fonction2(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	if (info->newsize == 1)
	{
		info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
		info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
	}
	else if (info->newsize == 2)
	{
		if ((*stack_b)->nbr < (*stack_a)->nbr)
		{
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
		}
		else
		{
			info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
		}
	}
}

void	ft_big1(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	int	r;
	int	p;

	info->newsize = info->size / 2;
	while (info->newsize-- > 0)
		info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
	info->newsize = info->size;
	ft_fonction(stack_a, stack_b, info);
	ft_fonction2(stack_a, stack_b, info);
	if (info->newsize == 3)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			info->str = ft_string(stack_a, stack_b, info->str, "sa\n");
		r = 4;
		p = 2;
		while (info->newsize-- > 0 && --r > 0)
		{
			if (((*stack_b)->nbr > (*stack_a)->nbr || p - r == 0) && p-- > 0)
				info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
			info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
		}
	}
	ft_big_lists(stack_a, stack_b, info);
	return ;
	ft_end_big_lists(stack_a, stack_b, info);
	return ;
}
