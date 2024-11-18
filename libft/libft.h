/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:05 by pibernar          #+#    #+#             */
/*   Updated: 2024/10/05 16:33:31 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 * The atoi() function converts the initial portion of the string 
 * pointed to by nptr to int.
*/
int		ft_atoi(const char *nptr);

/*
 * The bzero() function erases the data in the n bytes of the memory 
 * starting at the location pointed to by s, by writing zeros 
 * (bytes containing '\0') to that area.
*/
void	ft_bzero(void *s, size_t n);

/*
 * The  calloc() function allocates memory for an array of nmemb elements of 
 * size bytes each and returns a pointer to the allocated memory. The memory 
 * is set to zero. If nmemb or size is 0, then calloc() returns either NULL, 
 * or a unique pointer value that can later be successfully passed to free(). 
 * If the multiplication of nmemb and size would result in integer overflow,
 * then calloc() returns an error.  By contrast, an integer overflow would not
 * be detected in the following call to malloc(), with the result that an
 * incorrectly sized block of memory would be allocated: 
 * malloc(nmemb * size);
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*
* checks for an alphanumeric character;
* it is equivalent to (ft_isalpha(c) || ft_isdigit(c)).
*/
int		ft_isalnum(int c);

/*
* checks for an alphabetic character
*/
int		ft_isalpha(int c);

/*
* checks whether c is a 7-bit unsigned char value that fits into the ASCII 
* character set.
*/
int		ft_isascii(int c);

/*
* checks for a digit (0 through 9)
*/
int		ft_isdigit(int i);

/*
* checks for any printable character including space.
*/
int		ft_isprint(int c);

/*
 * Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * Return NULL if the allocation fails
*/
char	*ft_itoa(int n);

/*
 * The  memchr()  function scans the initial n bytes of the memory area pointed
 * to by s for the first instance of c. Both c and the bytes of the memory area 
 * pointed to by s are interpreted as unsigned char.
 * RETURN: return a pointer to the matching byte or NULL if the character 
 * does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
* compares the first n bytes (each interpreted as
*  unsigned char) of the memory areas s1 and s2.
* RETURN VALUE:
* returns an integer less than, equal to, or greater 
* than zero if the first n bytes of s1 is found, respectively, to be less than,
* to match, or be greater than the first n bytes of s2.
* For a nonzero return value, the sign is determined by the sign of the 
* difference between the first pair of bytes (interpreted as unsigned char)
* that differ in s1 and s2.
* If n is zero, the return value is zero.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
* The memcpy() function copies n bytes from memory area src to memory area dest.
* The memory areas must not overlap. 
* 
* RETURN VALUE:
* The memcpy() function returns a pointer to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
* The  memmove() function copies n bytes from memory area src to memory area
* dest. The memory areas may overlap: copying takes place as though the bytes
* in src are first copied into a temporary array that does not overlap src or
* dest, and the bytes are then copied from the temporary array to dest.
* RETURN VALUE:
* The memmove() function returns a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
* The memset() function fills the first n bytes of the memory area pointed 
* to by s with the constant byte c.
* 
* RETURN VALUE
* The memset() function returns a pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n);

/*
 * Outputs the character ’c’ to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd);

/*
 * Outputs the string ’s’ to the given file descriptor followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd);

/*
 * Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd);

/*
* Outputs the string ’s’ to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
* Allocates (with malloc(3)) and returns an array
* of strings obtained by splitting ’s’ using the
* character ’c’ as a delimiter. The array must end
* with a NULL pointer.
*/
char	**ft_split(char const *s, char c);

/*
* The strchr() function returns a pointer to the first occurrence of the
* character c in the string s.
* RETURN:
* 
* return a pointer to the matched character or NULL if the character is not 
* found. The terminating null byte is considered part of the string, so that
* if c is specified as '\0', these functions return a pointer to the terminator
*/
char	*ft_strchr(const char *s, int c);

/*
 * The strdup() function returns a pointer to a new string which is a
 * duplicate of the string s. Memory for the new string is obtained with 
 * malloc(3), and can be freed with free(3).
*/
char	*ft_strdup(const char *s);

/*
 * Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
* Allocates (with malloc(3)) and returns a new
* string, which is the result of the concatenation
* of ’s1’ and ’s2’
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
 * The strlcat() function concatenates strings. For strlcat() both src and dst
 * must be NUL-terminated.
 * The strlcpy() function copies up to size - 1 characters from the
 * NUL-terminated string src to dst, NUL-terminating the result.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*
 * The strlcpy() function copies strings. They are designed to be safer, 
 * more consistent, and less error prone replacements for strncat(3). Unlike
 * this function, strlcpy() take the full size of the buffer (not just
 * the length) and guarantee to NUL-terminate the result (as long as size is
 * larger than 0.
 * Note that a byte for the NUL should be included in size.  Also note that 
 * strlcpy() only operates on true “C” strings. This means that src must be 
 * NUL-terminated
 * The strlcpy() function copies up to size - 1 characters from the 
 * NUL-terminated string src to dst, NUL-terminating the result.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/*
* The strlen() function calculates the length of the string pointed to by s,
* excluding the terminating null byte ('\0').
*/
size_t	ft_strlen(const char *s);

/*
* Applies the function f to each character of the
* string s, passing its index as the first argument
* and the character itself as the second. A new
* string is created (using malloc(3)) to collect the
* results from the successive applications of f.
* RETURN:
*
* The string created from the successive applications
* of ’f’. Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
 * strncmp() function returns an integer less than, equal to, or greater 
 * than zero if the first n bytes is found, respectively, to be less than,
 * to match, or be greater than s2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * The strnstr() function locates the first occurrence of the null-terminated 
 * string little in the string big, where not more than len characters are 
 * searched.  Characters that appear after a ‘\0’ character are not searched. 
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*
* The strrchr() function returns a pointer to the last occurrence of the
* character c in the string s.
*/
char	*ft_strrchr(const char *s, int c);

/*
 * Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
 * Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);
int		ft_toupper(int c);

//BONUS
/*
* Allocates (with malloc(3)) and returns a new node.
* The member variable ’content’ is initialized with
* the value of the parameter ’content’. The variable
* ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void *content);

/*
* Adds the node ’new’ at the beginning of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new_node);

/*
 * Counts the number of nodes in a list.
*/
int		ft_lstsize(t_list *lst);

/*
 * Returns the last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/*
 * Adds the node ’new’ at the end of the list
*/
void	ft_lstadd_back(t_list **lst, t_list *new_node);

/*
 * Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*
* Deletes and frees the given node and every
* successor of that node, using the function ’del’
* and free(3).
* Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*
 * Iterates the list ’lst’ and applies the function ’f’ on the content 
 * of each node
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
* Iterates the list ’lst’ and applies the function
* ’f’ on the content of each node. Creates a new
* list resulting of the successive applications of
* the function ’f’. The ’del’ function is used to
* delete the content of a node if needed
*/
t_list	*ft_lstmap(t_list*lst, void *(*f)(void *), void (*del)(void *));

//PRINTF
int		ft_printf(const char *str, ...);

//GNL
char	*get_next_line(int fd);

//OTHER
int		ft_strcmp(const char *s1, const char *s2);
int		ft_fprintf(int fd, const char *str, ...);
int		ft_free_split(char **tab);
size_t	ft_split_size(char **tab);
void	ft_display_split(char **tab);
char	**ft_strtok(char *str, char *charset);

#endif
