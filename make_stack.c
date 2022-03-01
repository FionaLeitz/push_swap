/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:09:46 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/01 15:44:35 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* deuxieme fonction utilisee
creer un nouvel element t_stack
utile seulement dans ce fichier
*/
static t_stack	*ft_stacknew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/* troisieme fonction utilisee
ajouter l'element new a la fin de la stack
*/
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*save;

	if (*stack == NULL)
	{
		(*stack) = new;
		return ;
	}
	ft_back_one(stack);
	save = *stack;
	while (save->next != NULL)
		save = save->next;
	save->next = new;
	new->prev = save;
	new->next = NULL;
	return ;
}

/*
ajouter l'element new au debut de la liste
*/
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	ft_back_one(stack);
	new->next = *stack;
	(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
	ft_back_one(stack);
	return ;
}

/* premiere fonction utilisee
creer une stack grace a un char **
*/
t_stack	*ft_create_stack(int size, char **argv, int *tab)
{
	t_stack	*stack;
	t_stack	*new;
	int		count;

	if (tab == NULL)
		return (NULL);
	stack = ft_stacknew(ft_atol(argv[0]));
	if (stack == NULL)
	{
		free(tab);
		return (NULL);
	}
	count = 1;
	while (count < size)
	{
		new = ft_stacknew(ft_atol(argv[count]));
		if (new == NULL)
		{
			ft_free_all(stack, NULL, tab);
			return (NULL);
		}
		ft_stackadd_back(&stack, new);
		count++;
	}
	return (stack);
}

/*
trouver le dernier element de la stack
*/
t_stack	*ft_back_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	ft_back_one(stack);
	return (tmp);
}
