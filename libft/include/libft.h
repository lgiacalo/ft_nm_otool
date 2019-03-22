/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:57:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/22 20:11:24 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ABS(x) ((x) < 0 ? ((x) * -1) : (x))
# define BUFF_SIZE 15

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	char			*str;
	int				fd;
	struct s_file	*next;
}					t_file;

int					ft_fdprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					get_next_line(const int fd, char **line);
void				ft_arrayprint(char **tab);
int					ft_isnumber(char *nb);
int					ft_arraylen(char **table);
void				ft_arraydel(char ***s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
				size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long long int		ft_atolli(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strnsplit(char const *s, char c, int	start);
int					ft_nbwords(char const *s, char c);
int					*ft_poswords(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_len_numbers(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstrev(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd_end(t_list **alst, t_list *new);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstend(t_list *lst);
t_list				*ft_lstat(t_list *lst, unsigned int nbr);
char				*ft_strrev(char *str);
void				ft_swap(int *a, int *b);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strcapitalize(char *str);
int					ft_strdigit(char *str);
int					ft_strchr_ind(char *s, int c);
int					ft_chrstr_ind(char c, char *str);
int					ft_strstrchr_ind(char *s1, char *s2);
char				*ft_strstrchr(char *s1, char *s2);
int					ft_putnbr_fd_nb(int n, int fd);
int					ft_putnbr_nb(long long int n);
int					ft_putpnbr_nb(unsigned long long int n);
int					ft_putstr_fd_nb(char const *s, int fd);
int					ft_putendl_fd_nb(char const *s, int fd);
int					ft_putendl_nb(char const *s);
int					ft_putwchar_fd(wchar_t chr, int fd);
int					ft_putwchar(wchar_t chr);
void				ft_putwstr_fd(wchar_t *str, int fd);
void				ft_putwstr(wchar_t *str);
int					ft_putwstr_fd_nb(wchar_t *str, int fd);
int					ft_putwstr_nb(wchar_t *str);
int					ft_verif_base(char *base);
void				ft_putnbr_base(int n, char *base);
void				ft_putnbr_base_fd(int n, char *base, int fd);
int					ft_putnbr_base_nb(long long int n, char *base);
int					ft_putpnbr_base_nb(unsigned long long int n, char *base);
int					ft_putnbr_base_fd_nb(int n, char *base, int fd);
int					ft_len_numbers_base(long long int n, char *base);
int					ft_len_pnumbers_base(unsigned long long int n, char *base);
char				*ft_itoa_base(long long int n, char *base);
char				*ft_pitoa_base(unsigned long long int n, char *base);
int					ft_atoi_base(const char *str, char *base);
int					ft_wcharlen_o(wchar_t chr);
int					ft_wstrlen_o(wchar_t *str);
int					ft_wstrlen(wchar_t *str);

#endif
