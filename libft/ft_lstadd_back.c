#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pointer = ft_lstlast(*lst);
	pointer->next = new;
}
