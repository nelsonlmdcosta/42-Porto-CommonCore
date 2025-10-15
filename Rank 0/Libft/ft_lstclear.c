/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:18:13 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 21:34:48 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Function To Delete A List In Its Entirety, We Don't Need To Worry About
 *		Linking Nodes, Takes In The List To Free, And A Function To Free The
 *		Content In Case It Needs To Be Done In Some Special Way
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*currentnode;
	t_list	*nextnode;

	if (lst == NULL || del == NULL)
		return ;
	currentnode = *lst;
	while (currentnode)
	{
		nextnode = currentnode->next;
		ft_lstdelone(currentnode, del);
		currentnode = nextnode;
	}
	*lst = NULL;
}
