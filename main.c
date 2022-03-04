/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:28:37 by fleitz            #+#    #+#             */
/*   Updated: 2022/03/04 11:05:12 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count the number of arguments if it is a string
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

// if only one argument, split it to have char ** of arguments
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

// free char ** created with split
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

// main
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
