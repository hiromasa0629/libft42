/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:43:30 by marvin            #+#    #+#             */
/*   Updated: 2021/05/18 14:51:47 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_bstnode
{
	void				*content;
	struct s_bstnode	*parent;
	struct s_bstnode	*left;
	struct s_bstnode	*right;
}				t_bstnode;

enum color {
	RED,
	BLACK
};

typedef struct	s_rbtnode
{
	void				*content;
	struct s_rbtnode	*parent;
	struct s_rbtnode	*left;
	struct s_rbtnode	*right;
	enum color			color;
}				t_rbtnode;

t_rbtnode	*g_nil;

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_numlen(long long n);
int		ft_hexlen(long long n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strstr(const char *big, const char *little);
int		ft_atoi(const char *s);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_bstnode	*ft_bstnew(void *content, t_bstnode *parent);
t_bstnode	*ft_bst_search(t_bstnode *node, void *content);
void		ft_bst_insert(t_bstnode **node, void *content, t_bstnode *parent);
t_bstnode	*ft_bst_findmax(t_bstnode *root);
t_bstnode	*ft_bst_findmin(t_bstnode *root);
int			ft_bst_findheight(t_bstnode *root);
void		ft_bst_preorder_iter(t_bstnode *root, void (*f)(void *));
void		ft_bst_inorder_iter(t_bstnode *root, void (*f)(void *));
void		ft_bst_postorder_iter(t_bstnode *root, void (*f)(void *));
void		ft_bst_delone(t_bstnode **root, t_bstnode *tbd, void (*del)(void *));

t_rbtnode	*ft_rbt_createnil(void);
t_rbtnode	*ft_rbtnew(void *content, t_rbtnode *parent);
t_rbtnode	*ft_rbt_search(t_rbtnode *node, void *content);

void		ft_rbt_insert(t_rbtnode **node, void *content);
void		ft_rbt_delone(t_rbtnode **root, t_rbtnode *tbd, void (*del)(void *));


t_rbtnode	*ft_rbt_findmax(t_rbtnode *root);
t_rbtnode	*ft_rbt_findmin(t_rbtnode *root);
int			ft_rbt_findheight(t_rbtnode *root);
void		ft_rbt_preorder_iter(t_rbtnode *root, void (*f)(void *));
void		ft_rbt_inorder_iter(t_rbtnode *root, void (*f)(void *));
void		ft_rbt_postorder_iter(t_rbtnode *root, void (*f)(void *));

void		ft_rbt_rotate_left(t_rbtnode **root, t_rbtnode *node);
void		ft_rbt_rotate_right(t_rbtnode **root, t_rbtnode *node);



#endif
