/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:09:44 by lugonzal          #+#    #+#             */
/*   Updated: 2021/11/22 18:09:45 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}
