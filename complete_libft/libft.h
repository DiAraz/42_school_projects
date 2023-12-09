/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:10:00 by daraz             #+#    #+#             */
/*   Updated: 2023/12/09 15:41:04 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/* ---------------	LISTS		--------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ---------------	CHARS		--------------- */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ---------------	STRINGS		--------------- */
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ---------------  FILE DESCRIPTORS   --------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ---------------	MEMORY		--------------- */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* ---------------	NUMBERS		--------------- */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* ---------------	GET_NEXT_LINE		--------------- */
char	*get_next_line(int fd);
void	ft_free_strs(char **str, char **str2, char **str3);
void	*ft_malloc_zero(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*join_strs(const char *s1, const char *s2);
int		contains_newline(const char *s);
char	*get_next_line_bonus(int fd);

/* ---------- PRINTF -------------------- */
/* ---------- PRINTF -------------------- */

# if defined (__linux__)
#  define PTRNULL "(nil)"
# elif defined (__APPLE__)
#  define PTRNULL "0x0"
# endif

/* ---------- FLAGS --------------------- */
typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flags flags);

/* ---------- PRINT SPECIFIERS ---------- */
// c
int		ft_print_char(char c, t_flags flags);
int		ft_print_c(char c);
// s
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_s(const char *str);
int		ft_print_s_pre(const char *str, int precision);
int		ft_print_sign_pre(int n, t_flags *flags);
// i, d
int		ft_print_int(int n, t_flags flags);
int		ft_print_integer(char *nbstr, int n, t_flags flags);
int		ft_print_i(char *nbstr, int n, t_flags flags);
// u
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_u(char *nbstr, t_flags flags);
int		ft_print_unint(char *nbstr, t_flags flags);
// x, X
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_hexadec(char *nbstr, int n, int is_upper, t_flags flags);
// p
int		ft_print_ptr(unsigned long int n, t_flags flags);
int		ft_print_p(unsigned long int n);
void	ft_print_adr(unsigned long int n);

/* ---------- HELPER FUNCTIONS ---------- */
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long int nb, int is_upper);
int		ft_unint_len(unsigned int n);
int		ft_hex_len(unsigned int n);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

/* ---------- FLAG FUNCTIONS ------------ */
int		ft_pad_width(int total_width, int size, int zero);

#endif
