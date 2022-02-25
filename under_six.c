/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:44 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 13:20:17 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* premiere fonction utilisee
verifier si la liste est deja triée
*/
int	ft_is_sorted(t_stack *stack, int *tab, int size)
{
	int	count;

	if (stack == NULL)
		return (1);
	count = 0;
	while (count < size)
	{
		if (stack->nbr != tab[count])
			break ;
		stack = stack->next;
		count++;
	}
	if (count == size)
	{
		ft_free_all(stack, NULL, tab);
		return (1);
	}
	return (0);
}

/* troisieme fonction utilisee
comment trier si il y a 3 nombres
utile seulement dans ce fichier
*/
static void	ft_three(t_stack **stack)
{
	if ((*stack)->nbr > (*stack)->next->nbr)
	{
		if ((*stack)->nbr > (*stack)->next->next->nbr)
		{
			ft_printf("ra\n");
			ft_rotate(stack);
		}
		else
		{
			ft_printf("sa\n");
			ft_swap(stack);
		}
		if ((*stack)->nbr > (*stack)->next->nbr)
			ft_printf("sa\n");
	}
	else if ((*stack)->nbr > (*stack)->next->next->nbr)
		ft_printf("rra\n");
	else if ((*stack)->next->nbr > (*stack)->next->next->nbr)
		ft_printf("sa\nra\n");
	return ;
}

/* quatrieme fonction utilisee
comment trier si il y a 4 nombres
utile seulement dans ce fichier
*/
static void	ft_four(t_stack **stack_a, t_stack **stack_b, int min)
{
	if (ft_search(stack_a, min, 4) == 0)
	{
		while ((*stack_a)->nbr != min)
		{
			ft_printf("rra\n");
			ft_reverse_rotate(stack_a);
		}
	}
	else
	{
		while ((*stack_a)->nbr != min)
		{
			ft_printf("ra\n");
			ft_rotate(stack_a);
		}
	}
	ft_printf("pb\n");
	ft_push(stack_b, stack_a);
	ft_three(stack_a);
	ft_printf("pa\n");
	return ;
}

/* cinquieme fonction utilisee
comment trier si il y a 5 nombres
utile seulement dans ce fichier
*/
static void	ft_five(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	if (ft_search(stack_a, tab[0], 5) == 0)
	{
		while ((*stack_a)->nbr != tab[0])
		{
			ft_printf("rra\n");
			ft_reverse_rotate(stack_a);
		}
	}
	else
	{
		while ((*stack_a)->nbr != tab[0])
		{
			ft_printf("ra\n");
			ft_rotate(stack_a);
		}
	}
	ft_printf("pb\n");
	ft_push(stack_b, stack_a);
	ft_four(stack_a, stack_b, tab[1]);
	ft_printf("pa\n");
	return ;
}

/* deuxieme fonction utilisee
si moins de 6 nombres, alors j'envoie dans un tri special
selon le nombre d'arguments
*/
int	ft_under_six(t_stack **stack_a, t_stack **stack_b, int size, int *tab)
{
	if (size == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			ft_printf("sa\n");
	}
	else if (size == 3)
		ft_three(stack_a);
	else if (size == 4)
		ft_four(stack_a, stack_b, tab[0]);
	else if (size == 5)
		ft_five(stack_a, stack_b, tab);
	ft_free_all(*stack_a, *stack_b, tab);
	return (0);
}
