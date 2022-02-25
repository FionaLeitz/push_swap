/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:44 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/16 13:55:37 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* deuxieme fonction utilisee
trouver une string dans une autre
utile seulement dans ce fichier
*/
static int	ft_new_strstr(char *haystack, char *needle)
{
	int	i;
	int	size;

	size = (int)ft_strlen(needle);
	i = 0;
	if (needle[0] == '\0')
		return (ft_strlen(haystack));
	while (haystack[i])
	{
		if (ft_memcmp(&haystack[i], needle, size) == 0)
			return (i);
		i++;
	}
	return (ft_strlen(haystack));
}

/* troisieme fonction utilisee
supprimer les parties inutiles
utile seulement dans ce fichier
*/
static void	ft_suppress(char *str, char *sup, int p)
{
	int	count;

	count = ft_new_strstr(str, sup);
	ft_memcpy(&str[count], &str[count + p], ft_strlen(&str[count + p]) + 1);
	return ;
}

/* premiere fonction utilisee
trouver les parties inutiles
*/
void	ft_find_suppress(char *str)
{
	int	count;

	while (1)
	{
		count = (int)ft_strlen(str);
		if (count != ft_new_strstr(str, "sa\nsa\n"))
			ft_suppress(str, "sa\nsa\n", 6);
		else if (count != ft_new_strstr(str, "sb\nsb\n"))
			ft_suppress(str, "sb\nsb\n", 6);
		else if (count != ft_new_strstr(str, "\nra\nrra\n"))
			ft_suppress(str, "\nra\nrra\n", 7);
		else if (count != ft_new_strstr(str, "\nrb\nrrb\n"))
			ft_suppress(str, "\nrb\nrrb\n", 7);
		else if (count != ft_new_strstr(str, "rra\nra\n"))
			ft_suppress(str, "rra\nra\n", 7);
		else if (count != ft_new_strstr(str, "rrb\nrb\n"))
			ft_suppress(str, "rrb\nrb\n", 7);
		else if (count != ft_new_strstr(str, "pa\npb\n"))
			ft_suppress(str, "pa\npb\n", 6);
		else if (count != ft_new_strstr(str, "pb\npa\n"))
			ft_suppress(str, "pb\npa\n", 6);
		else
			break ;
	}
	return ;
}

/* cinquieme fonction utilisee
remplacer les parties redondantes
utile seulement dans ce fichier
*/
static char	*ft_reduce(char *str, char *sup, char *rep, int plus)
{
	int		count;
	char	*str2;
	char	*save;

	count = ft_new_strstr(str, sup);
	str2 = ft_strndup(str, count);
	if (str2 == NULL)
		return (NULL);
	save = ft_strjoin(rep, &str[count + plus]);
	if (save == NULL)
	{
		free(str2);
		return (NULL);
	}
	free(str);
	str = ft_strjoin(str2, save);
	free(str2);
	free(save);
	return (str);
}

/* quatrieme fonction utilisee
trouver les parties redondantes
*/
char	*ft_find_reduce(char *str)
{
	int	count;

	while (1)
	{
		count = (int)ft_strlen(str);
		if (count != ft_new_strstr(str, "sa\nsb\n"))
			str = ft_reduce(str, "sa\nsb\n", "ss\n", 6);
		else if (count != ft_new_strstr(str, "sb\nsa\n"))
			str = ft_reduce(str, "sb\nsa\n", "ss\n", 6);
		else if (count != ft_new_strstr(str, "\nra\nrb\n"))
			str = ft_reduce(str, "\nra\nrb\n", "\nrr", 6);
		else if (count != ft_new_strstr(str, "\nrb\nra\n"))
			str = ft_reduce(str, "\nrb\nra\n", "\nrr", 6);
		else if (count != ft_new_strstr(str, "rra\nrrb\n"))
			str = ft_reduce(str, "rra\nrrb\n", "rrr\n", 8);
		else if (count != ft_new_strstr(str, "rrb\nrra\n"))
			str = ft_reduce(str, "rrb\nrra\n", "rrr\n", 8);
		else
			break ;
	}
	return (str);
}
