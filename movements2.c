/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:12:24 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 11:54:12 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// echanger les deux premiers nombres de la stack_a, puis pareil sur la stack_b
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	return ;
}

// passer le premier nombre de la stack_a en dernier, puis pareil sur la stack_b
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	return ;
}

// passer le dernier nombre de la stack_a en premier, puis pareil sur la stack_b
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	return ;
}

// liberer la memoire de stack
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

//liberer toute la memoire utilisée
int	ft_free_all(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(tab);
	return (0);
}
