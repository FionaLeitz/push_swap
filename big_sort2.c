
#include "push_swap.h"

void	ft_fonction3(t_stack **stack_a, t_stack **stack_b, t_args *info, int repere2, int save_a)
{
	int	r;
	int	p;

	if (info->newsize > 0 && (*stack_b))
	{
		r = info->newsize + 1;
		p = 0;
		while ((*stack_a)->nbr != save_a && p++ >= 0)
			*stack_a = (*stack_a)->next;
		ft_back_one(stack_a);
		if (repere2 == 2)
		{
			while (--r > 0 || p > 0)
			{
				if (((*stack_b)->nbr > (*stack_a)->nbr || p - r == 0) && p-- > 0)
					info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
				info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
			}
			return ;
		}
		p = info->newsize - p;
		while ((--r > 0 || p > 0))
		{
			if (((*stack_a)->nbr > (*stack_b)->nbr || p - r == 0) && p-- > 0)
				info->str = ft_string(stack_a, stack_b, info->str, "pa\n");
			info->str = ft_string(stack_a, stack_b, info->str, "ra\n");
		}
	}
}

void	ft_big_lists(t_stack **stack_a, t_stack **stack_b, t_args *info)
{
	int	repere;
	int	p;
	int	r;
	int	save_a;
	int	repere2;

	repere = 8;
	info->newsize = info->size;
	repere2 = 1;
	while (info->newsize >= repere && (*stack_b))
	{
		if ((*stack_a)->nbr < (*stack_b)->nbr)
			save_a = (*stack_a)->nbr;
		else
			save_a = (*stack_b)->nbr;
		while (info->newsize >= repere && (*stack_b))
		{
			p = repere / 2;
			r = repere + 1;
			while ((--r > 0 || p > 0) && info->newsize-- >= 0 && (*stack_b))
			{
				if (((*stack_a)->nbr > (*stack_b)->nbr || p - r == 0)
					&& p-- > 0)
					info->str = ft_string(stack_a, stack_b, info->str, "pa\n");
				info->str = ft_string(stack_a, stack_b, info->str, "ra\n");
			}
			if (info->newsize < repere && (*stack_b))
			{
				repere2 = 2;
				break ;
			}
			p = repere / 2;
			r = repere + 1;
			while ((--r > 0 || p > 0) && info->newsize-- >= 0 && (*stack_b))
			{
				if (((*stack_b)->nbr > (*stack_a)->nbr || p - r == 0)
					&& p-- > 0)
					info->str = ft_string(stack_a, stack_b, info->str, "pb\n");
				info->str = ft_string(stack_a, stack_b, info->str, "rb\n");
			}
		}
		ft_fonction3(stack_a, stack_b, info, repere2, save_a);
		repere = repere * 2;
		info->newsize = info->size;
	}
	return ;
}
