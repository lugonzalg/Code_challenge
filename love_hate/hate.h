/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:02:37 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 00:41:20 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCH_H
#define CATCH_H

#define SPACE 32

typedef struct	s_dict
{
	char			letter;
	float			value;
	struct s_dict	*next;
}	t_dict;

extern void	ft_create_list_1(char **dict, t_dict **head);
extern void	ft_substitute(char *str);
extern void	ft_free_d2(char **tab);
extern void	ft_free_head(t_dict *head);
extern void	ft_print_winner(t_dict *head, char **data);

#endif
