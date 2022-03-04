/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:14 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/04 13:11:24 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put group in stack_a
void	ft_put_in_a(t_stack **stck_a, t_stack **stck_b, t_args *info, int *rp)
{
	if (info->newsize < rp[0] - 1)
	{
		while (info->newsize-- > 0)
		{
			info->str = ft_string(stck_a, stck_b, info->str, "pa\n");
			if ((*stck_a)->next != NULL)
				info->str = ft_string(stck_a, stck_b, info->str, "ra\n");
		}
		return ;
	}
	while ((--rp[0] > 0 || rp[1] > 0) && info->newsize-- >= 0)
	{
		if ((*stck_b) && ((*stck_a)->nbr > (*stck_b)->nbr
				|| rp[1] - rp[0] == 0) && rp[1]-- > 0)
			info->str = ft_string(stck_a, stck_b, info->str, "pa\n");
		info->str = ft_string(stck_a, stck_b, info->str, "ra\n");
	}
}

// put group in stack_b
void	ft_put_in_b(t_stack **stck_a, t_stack **stck_b, t_args *info, int *rp)
{
	if (info->newsize < rp[0] - 1)
	{
		while (info->newsize-- > 0)
		{
			info->str = ft_string(stck_a, stck_b, info->str, "pb\n");
			if ((*stck_b)->next != NULL)
				info->str = ft_string(stck_a, stck_b, info->str, "rb\n");
		}
		return ;
	}
	while ((--rp[0] > 0 || rp[1] > 0) && info->newsize-- >= 0 && (*stck_b))
	{
		if (((*stck_b)->nbr > (*stck_a)->nbr || rp[1] - rp[0] == 0)
			&& rp[1]-- > 0)
			info->str = ft_string(stck_a, stck_b, info->str, "pb\n");
		info->str = ft_string(stck_a, stck_b, info->str, "rb\n");
	}
}

// move last group
void	ft_end(t_stack **stack_a, t_stack **stack_b, t_args *info, int *save)
{
	int	rp[2];

	if (info->newsize > 0)
	{
		ft_memcpy(&rp, (int [2]){info->newsize + 1, 0}, sizeof(int) * 2);
		while ((*stack_a)->nbr != save[1] && rp[1]++ >= 0)
			*stack_a = (*stack_a)->next;
		ft_back_one(stack_a);
		if (save[0] == 2)
		{
			ft_put_in_b(stack_a, stack_b, info, rp);
			return ;
		}
		rp[1] = info->newsize - rp[1];
		ft_put_in_a(stack_a, stack_b, info, rp);
	}
}

// if group is little
int	ft_little(t_stack **stack_a, t_stack **stack_b, t_args *info, int *save)
{
	if (info->newsize <= save[2])
	{
		save[0] = 2;
		if (*stack_b == NULL)
		{
			while (info->newsize > 0)
			{
				info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
				if ((*stack_b)->next != NULL)
					info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
				info->newsize--;
			}
		}
		return (1);
	}
	return (0);
}

// sort 8 by 8, 16 by 16, ...
void	ft_big_lists(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	int	rp[2];
	int	save[3];

	save[2] = 8;
	info->newsize = info->size;
	save[0] = 1;
	while (info->newsize >= (save[2]) && (*stack_b))
	{
		save[1] = (*stack_b)->nbr;
		if ((*stack_a) && (*stack_a)->nbr < (*stack_b)->nbr)
			save[1] = (*stack_a)->nbr;
		while (info->newsize >= save[2] && (*stack_b))
		{
			ft_memcpy(&rp, (int [2]){save[2] + 1, save[2] / 2}, 8);
			ft_put_in_a(stack_a, stack_b, info, rp);
			if (ft_little(stack_a, stack_b, info, save) == 1)
				break ;
			ft_memcpy(&rp, (int [2]){save[2] + 1, save[2] / 2}, 8);
			ft_put_in_b(stack_a, stack_b, info, rp);
		}
		ft_end(stack_a, stack_b, info, save);
		save[2] = save[2] * 2;
		info->newsize = info->size;
	}
	return ;
}
