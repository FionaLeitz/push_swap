/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:44 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/17 10:36:18 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ceci est un fichier qui verifie les cs d'erreurs.

/* deuxieme fonction utilisee
verifier si les arguments reçus sont bien des nombres,
et qu'ils ne sont pas trop grands pour des ints
utile seulement dans ce fichier
*/
static int	ft_digit(int size, char **stack)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		if (stack[j][0] == '\0')
			return (0);
		if (ft_strlen(stack[j]) > 11)
			return (0);
		i = 0;
		if ((stack[j][i] == '-' || stack[j][i] == '+') && stack[j][i + 1])
			i++;
		while (stack[j][i])
		{
			if (stack[j][i] < '0' || stack[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

/* quatrieme fonction utilisee
copier long_tab dans int *tab
utile seulement dans ce fichier
*/
static int	*ft_intcpy(int size, long int *long_tab)
{
	int	*tab;
	int	count;

	tab = (int *)malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	count = 0;
	while (count < size)
	{
		tab[count] = (int)long_tab[count];
		count++;
	}
	free(long_tab);
	return (tab);
}

/* troisieme fonction utilisee
créer tab en passant par long_tab, et vérifier si les nombres sont des ints
utile seulement dans ce fichier
*/
static int	*ft_create_tab(int size, char **stack)
{
	int			count;
	int			*tab;
	long int	*long_tab;

	long_tab = (long int *)malloc(sizeof(long int) * size);
	if (long_tab == NULL)
		return (NULL);
	count = 0;
	while (count < size)
	{
		long_tab[count] = ft_atol(stack[count]);
		if (long_tab[count] > 2147483647 || long_tab[count] < -2147483648)
		{
			ft_printf("Error\n");
			free(long_tab);
			return (NULL);
		}
		count++;
	}
	tab = ft_intcpy(size, long_tab);
	return (tab);
}

/* cinquieme fonction utilisee
ranger les nombres dans l'ordre et verifier les doublons
utile seulement dans ce fichier
*/
static int	ft_bubblesort(int size, int *tab)
{
	int	count;
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		count = i + 1;
		while (count < size)
		{
			if (tab[i] > tab[count])
			{
				tmp = tab[count];
				tab[count] = tab[i];
				tab[i] = tmp;
			}
			else if (tab[i] == tab[count])
				return (0);
			count++;
		}
		i++;
	}
	return (1);
}

/* première fonction utilisée.
verifier les cas d'erreurs, imprimer erreur si besoin,
et retourner NULL si probleme malloc
*/
int	*ft_check_errors(int size, char **stack)
{
	int	*tab;

	if (*stack == NULL)
		return (NULL);
	if (ft_digit(size, stack) == 0)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	tab = ft_create_tab(size, stack);
	if (tab == NULL)
		return (NULL);
	if (ft_bubblesort(size, tab) == 0)
	{
		ft_printf("Error\n");
		free(tab);
		return (NULL);
	}
	return (tab);
}
