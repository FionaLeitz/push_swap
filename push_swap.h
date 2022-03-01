/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:30:23 by fleitz            #+#    #+#             */
/*   Updated: 2022/02/25 12:13:28 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_args
{
	int		size;
	int		newsize;
	int		*tab;
	char	*str;
}			t_args;

// errors.c
int		*ft_check_errors(int size, char **stack);
// make_stack.c
void	ft_stackadd_back(t_stack **stack, t_stack *ne);
void	ft_stackadd_front(t_stack **stack, t_stack *ne);
t_stack	*ft_create_stack(int size, char **argv, int *tab);
t_stack	*ft_back_last(t_stack **stack);
// movements.c
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_back_one(t_stack **stack);
// movements2.c
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack *stack);
int		ft_free_all(t_stack *stack_a, t_stack *stack_b, int *tab);
// sort.c
void	ft_step1(t_stack **stack_a, t_stack **stack_b, t_args *infos);
// sort2.c
void	ft_step2(t_stack **stack_a, t_stack **stack_b, t_args *infos);
// strings.c
void	ft_find_suppress(char *str);
char	*ft_find_reduce(char *str);
// under_six.c
int		ft_is_sorted(t_stack *stack, int *tab, int size);
int		ft_under_six(t_stack **stack_a, t_stack **stack_b, int size, int *tab);
// utils.c
int		ft_min(t_stack**stack);
int		ft_max(t_stack **stack);
void	ft_push_n(t_stack **stack_a, t_stack **stack_b, int n, t_args *infos);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *tab);
// utils2.c
char	*ft_string(t_stack **stack_a, t_stack **stack_b, char *str, char *add);
void	ft_push_n2(t_stack **stack_a, t_stack **stack_b, int n, t_args *infos);
int		ft_new_search(t_stack **stack, int ni, int n2, int size);
int		ft_search(t_stack **stack, int n, int size);

void	ft_big1(t_stack **stack_a, t_stack **stack_b, t_args *infos);
void	ft_big_lists(t_stack **stck_a, t_stack **stck_b, t_args *info);
void	ft_print(t_stack **stack_a, t_stack **stack_b);

#endif
