/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:35:36 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 09:53:51 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make movements according to add in create_string
// utile seulement dans ce fichier
static void	ft_movements(t_stack **stack_a, t_stack **stack_b, char *str)
{
	ft_back_one(stack_a);
	ft_back_one(stack_b);
	if (ft_memcmp(str, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_memcmp(str, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_memcmp(str, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_memcmp(str, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_memcmp(str, "sa\n", 3) == 0)
		ft_swap(stack_a);
	else if (ft_memcmp(str, "sb\n", 3) == 0)
		ft_swap(stack_b);
	else if (ft_memcmp(str, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_memcmp(str, "pb\n", 3) == 0)
		ft_push(stack_b, stack_a);
	return ;
}

// ajouter une commande a la string a imprimer a la fin
char	*ft_string(t_stack **stack_a, t_stack **stack_b, char *str, char *add)
{
	char	*str2;

	if (add == NULL || str == NULL)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	ft_movements(stack_a, stack_b, add);
	str2 = ft_strjoin(str, add);
	free(str);
	return (str2);
}

// move min or max to start sort
void	ft_push_n2(t_stack **stack_a, t_stack **stack_b, int n, t_args *infos)
{
	if (ft_search(stack_b, n, infos->newsize) == 1)
	{
		while ((*stack_b)->nbr != n)
			infos->str = ft_string(stack_a, stack_b, infos->str, "rb\n");
	}
	else
	{
		while ((*stack_b)->nbr != n)
			infos->str = ft_string(stack_a, stack_b, infos->str, "rrb\n");
	}
	infos->str = ft_string(stack_a, stack_b, infos->str, "pa\n");
	return ;
}

// chercher dans quel sens rotate pour faire remonter n en premier
int	ft_search(t_stack **stack, int n, int size)
{
	int	search;

	search = 0;
	while ((*stack)->next != NULL && (*stack)->nbr != n)
	{
		*stack = (*stack)->next;
		search++;
	}
	if ((*stack)->next == NULL && (*stack)->nbr != n)
	{
		ft_back_one(stack);
		return (2);
	}
	ft_back_one(stack);
	if (search <= (size / 2))
		return (1);
	return (0);
}

int	ft_new_search(t_stack **stack, int n1, int n2, int size)
{
	int	search;
	int	search2;

	search = 0;
	while ((*stack)->next != NULL && (*stack)->nbr != n1)
	{
		*stack = (*stack)->next;
		search++;
	}
	ft_back_one(stack);
	if (search > (size / 2))
		search = search - size;
	search2 = 0;
	while ((*stack)->next != NULL && (*stack)->nbr != n2)
	{
		*stack = (*stack)->next;
		search2++;
	}
	ft_back_one(stack);
	if (search2 > (size / 2))
		search2 = search2 - size;
	if (search < search2)
		return (1);
	return (2);
}
