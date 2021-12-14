/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:02:37 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/13 22:48:53 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCH_H
#define CATCH_H

#define SPACE 32

typedef struct	s_info
{
	char	**poke;
	char	*tab;
}	t_info;

extern int	ft_catch(t_info *info);
extern void	ft_print_tab(t_info info);

#endif
