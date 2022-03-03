/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:14 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/03 16:06:50 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fonctiona(t_stack **stck_a, t_stack **stck_b, t_args *info, int *rp)
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

int	ft_count(t_stack **stack)
{
	int	count;

	count = 1;
	if (stack == NULL)
		return (0);
	while ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		count++;
	}
	ft_back_one(stack);
	return (count);
}

void	ft_fonctionb(t_stack **stck_a, t_stack **stck_b, t_args *info, int *rp)
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

void	ft_fonction3(t_stack **stack_a, t_stack **stack_b, t_args *info, int *s)
{
	int	rp[2];

	if (info->newsize > 0/* && (*stack_b)*/)
	{
		ft_memcpy(&rp, (int [2]){info->newsize + 1, 0}, sizeof(int) * 2);
		while ((*stack_a)->nbr != s[1] && rp[1]++ >= 0)
			*stack_a = (*stack_a)->next;
		ft_back_one(stack_a);
		if (s[0] == 2)
		{
			ft_fonctionb(stack_a, stack_b, info, rp);
			return ;
		}
		rp[1] = info->newsize - rp[1];
		ft_fonctiona(stack_a, stack_b, info, rp);
	}
}

int	ft_fonction4(t_stack **stack_a, t_stack **stack_b, t_args *info, int *save)
{
//	(void)stack_b;
//	(void)stack_a;

	if (info->newsize <= save[2])
	{
//		ft_printf("ICI !\nnewsize = %d\nsave[2] = %d\n", info->newsize, save[2]);
//		ft_printf("stack_b = %p\n", (*stack))
		save[0] = 2;
		if (*stack_b == NULL)
		{
			while (info->newsize > 0)
			{
//				ft_printf("ICI \n");
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

void	ft_big_lists(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	int	rp[2];
	int	save[3];

	save[2] = 8;
	info->newsize = info->size;
	save[0] = 1;
	while (info->newsize >= (save[2]) && (*stack_b))
	{
//		ft_printf("Debut : newsize = %d\nsave[2] = %d\n", info->newsize, save[2]);
//		ft_printf("Debut du big while :\n");
//		ft_print(stack_a, stack_b);
		save[1] = (*stack_b)->nbr;
		if ((*stack_a) && (*stack_a)->nbr < (*stack_b)->nbr)
			save[1] = (*stack_a)->nbr;
		while (info->newsize >= save[2] && (*stack_b))
		{
//			ft_printf("Debut du little while :\n");
//			ft_print(stack_a, stack_b);
			ft_memcpy(&rp, (int [2]){save[2] + 1, save[2] / 2}, 8);
			ft_fonctiona(stack_a, stack_b, info, rp);
//			ft_printf("Milieu du little while :\n");
//			ft_print(stack_a, stack_b);
			if (ft_fonction4(stack_a, stack_b, info, save) == 1)
			{
//				ft_printf("Fin du little while special :\n");
//				ft_print(stack_a, stack_b);
				break ;
			}
			ft_memcpy(&rp, (int [2]){save[2] + 1, save[2] / 2}, 8);
//			ft_printf("rp[0] = %d\nrp[1] = %d\nsave[1] = %d\nnewsize = %d\n", rp[0], rp[1], save[1], info->newsize);
			ft_fonctionb(stack_a, stack_b, info, rp);
//			ft_printf("Fin du little while :\n");
//			ft_print(stack_a, stack_b);
		}
		ft_fonction3(stack_a, stack_b, info, save);
		save[2] = save[2] * 2;
		info->newsize = info->size;
//		ft_printf("Fin du big while :\n");
//		ft_print(stack_a, stack_b);
//		ft_printf("Fin : newsize = %d\nsave[2] = %d\n", info->newsize, save[2]);
	}
	return ;
}
