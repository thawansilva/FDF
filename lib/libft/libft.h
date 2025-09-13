/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:04:57 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/12 17:04:57 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./gnl/get_next_line.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

// Structures
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// ---------------------------- Validation functions --------------------------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);

// ---------------------------- String's Manipulation -------------------------
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int str);
int		ft_tolower(int str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(char *str, char *sub, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// ---------------------------- Memory Manipulation ---------------------------
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// ---------------------------- Conversion ------------------------------------
int		ft_atoi(const char *nbr);

// ---------------------------- Linked list Manipulation ----------------------
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ---------------------------- Print functions -------------------------------
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

// ---------------------------- Extra Functions -------------------------------
void	ft_swap_string(char **str1, char **str2);
void	ft_swap_char(char chr1, char chr2);
void	ft_swap_int(int n1, int n2);

// ---------------------------- Get Next Line ---------------------------------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

// ---------------------------- ft_printf -------------------------------------
typedef unsigned long long	t_ptr;

unsigned int	ft_print_nbr(int nbr);
unsigned int	ft_print_str(char *str);
unsigned int	ft_print_unbr(unsigned int nbr);
unsigned int	ft_print_ptr(unsigned long long ptr);
unsigned int	ft_print_hex(unsigned int nbr, char type);
unsigned int	ft_printf(const char *format, ...);
#endif
