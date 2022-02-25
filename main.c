/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:28:37 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/17 11:15:09 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_print(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a) && (*stack_a)->next)
	{
		ft_printf("stack_a->nbr = %d\n", (*stack_a)->nbr);
		*stack_a = (*stack_a)->next;
	}
	if (*stack_a)
		ft_printf("stack_a->nbr = %d\n\n", (*stack_a)->nbr);
	while ((*stack_b) && (*stack_b)->next)
	{
		ft_printf("stack_b->nbr = %d\n", (*stack_b)->nbr);
		*stack_b = (*stack_b)->next;
	}
	if (*stack_b)
		ft_printf("stack_b->nbr = %d\n", (*stack_b)->nbr);
	return ;
}*/

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	countwords;

	i = 0;
	countwords = 0;
	if (s[0] != c && s[0] != '\0')
		countwords++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			countwords++;
		i++;
	}
	return (countwords);
}

static int	ft_arguments(int argc, char **argv, char ***arguments)
{
	if (argc == 1)
	{
		argc = ft_countwords(argv[1], ' ');
		if (argc == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		*arguments = ft_split(argv[1], ' ');
		if (*arguments == NULL)
			return (0);
	}
	else
		*arguments = &argv[1];
	return (argc);
}

static void	ft_free_arguments(char **arguments, int argc, int repere)
{
	int	count;

	if (repere == 0)
		return ;
	count = 0;
	while (count < argc)
	{
		free(arguments[count]);
		count++;
	}
	free(arguments);
	return ;
}

int	main(int argc, char **argv)
{
	int		repere;
	int		*tab;
	char	**arguments;
	t_stack	*stack_a;
	t_stack	*stack_b;

	argc -= 1;
	stack_b = NULL;
	arguments = NULL;
	repere = 0;
	if (argc == 1)
		repere = 1;
	argc = ft_arguments(argc, argv, &arguments);
	if (argc == 0)
		return (0);
	tab = ft_check_errors(argc, arguments);
	stack_a = ft_create_stack(argc, arguments, tab);
	ft_free_arguments(arguments, argc, repere);
	if (ft_is_sorted(stack_a, tab, argc) == 1)
		return (0);
	if (argc < 6)
		return (ft_under_six(&stack_a, &stack_b, argc, tab));
	ft_sort_stack(&stack_a, &stack_b, argc, tab);
	ft_free_all(stack_a, stack_b, tab);
	return (0);
}
