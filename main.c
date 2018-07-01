/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:49:03 by dgameiro          #+#    #+#             */
/*   Updated: 2018/07/01 14:59:13 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <libfta.h>
#include <unistd.h>

/*void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
*/
//gcc -Wall -Wextra -Werror -I./ -L./ -lfts main.c
int		main(void)
{
	char buf[9];
	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	printf("buf = %s\n", buf);
	if (strcmp(buf, "Bonjour.") == 0)
		printf("buf ok = %s\n", buf);
	if (buf == ft_strcat(buf, ""))
		printf("buf oko = %s\n", buf);
	char		*ret1;
	char		*ret2;
	printf("bzero test\n");
	ret1 = strdup("");
	printf("bzero test\n");
	ret2 = ft_strdup("");
	printf("bzero test\n");
	ft_puts(ret2);
	if (strcmp(ret1, ret2) != 0)
		printf("No match 1st test\n");
	printf("bzero test\n");
	free(ret1);
	printf("bzero test\n");
	free(ret2);
	printf("bzero test\n");
	ret1 = strdup("hello");
	printf("bzero test\n");
	ret2 = ft_strdup("hello");
	printf("bzero test\n");
	if (strcmp(ret1, ret2) != 0)
		printf("No match 2nd test\n");
	free(ret1);
	free(ret2);
	char str[6] = "Salut";
	char cstr[13] = "Salut       ";
	cstr[5] = 0;
	char str2[8] = " Ca va?";
	char *str3;
	//str3 = (char*)calloc(4, 4);
	str3 = (char*)malloc(16);
	

	printf("bzero test\n");
	printf("Avant = %s\n", str);
	ft_bzero(str, 5);
	printf("Après = %s\n", str);

	printf("\nstrcat test\n");
	printf("str 1 = %s\n", cstr);
	printf("str 2 = %s\n", str2);
	printf("cat str1 + str2 = %s\n", ft_strcat(cstr, str2));
	printf("str 1 = %s\n", cstr);

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	printf("buf = %s\n", buf);
	if (strcmp(buf, "Bonjour.") == 0)
		printf("buf ok = %s\n", buf);
	if (buf == ft_strcat(buf, ""))
		printf("buf oko = %s\n", buf);

	printf("\nalpha test\n");
	printf("a = %d\n", ft_isalpha('a'));
	printf("z = %d\n", ft_isalpha('z'));
	printf("A = %d\n", ft_isalpha('A'));
	printf("Z = %d\n", ft_isalpha('Z'));
	printf("2 = %d\n", ft_isalpha('2'));
	printf("@ = %d\n", ft_isalpha('@'));
	printf("{ = %d\n", ft_isalpha('{'));
	printf("[ = %d\n", ft_isalpha('['));
	printf("r = %d\n", ft_isalpha('r'));
	printf("R = %d\n", ft_isalpha('R'));

	printf("\ndigit test\n");
	printf("0 = %d\n", ft_isdigit('0'));
	printf("5 = %d\n", ft_isdigit('5'));
	printf("9 = %d\n", ft_isdigit('9'));
	printf(": = %d\n", ft_isdigit(':'));

	printf("\nascii test\n");
	printf(": = %d\n", ft_isascii(':'));
	printf("128 = %d\n", ft_isascii(128));
	printf("-1 = %d\n", ft_isascii(-1));
	printf("0 = %d\n", ft_isascii(0));
	printf("127 = %d\n", ft_isascii(127));

	printf("\nisprint test\n");
	printf(": = %d\n", ft_isprint(':'));
	printf("31 no = %d\n", ft_isprint(31));
	printf("127 no = %d\n", ft_isprint(127));
	printf("sp = %d\n", ft_isprint(' '));

	printf("\ntoUPPER test\n");
	printf("a = %c\n", ft_toupper('a'));
	printf("A = %c\n", ft_toupper('A'));
	printf("z = %c\n", ft_toupper('z'));
	printf("t = %c\n", ft_toupper('t'));
	printf("{ = %c\n", ft_toupper('{'));

	printf("\nTOlower test\n");
	printf("a = %c\n", ft_tolower('a'));
	printf("A = %c\n", ft_tolower('A'));
	printf("z = %c\n", ft_tolower('z'));
	printf("t = %c\n", ft_tolower('t'));
	printf("{ = %c\n", ft_tolower('{'));
	printf("Z = %c\n", ft_tolower('Z'));

	printf("\nPuts and strlen test\n");
	printf("add %p\n", cstr);
	printf("len %lu\n", ft_strlen(cstr));
	ft_puts(cstr);
	printf("add %p\n", cstr);
	printf("str 1 = %s\n", cstr);
	printf("len %lu\n", ft_strlen(cstr));

	ft_puts("aaa");
	ft_puts(NULL);

	printf("\nmemset test\n");
	ft_puts(str3);
	printf("len %lu\n", ft_strlen(str3));
	ft_puts(ft_memset(str3, 101, 10));
	ft_puts(str3);
	printf("len %lu\n", ft_strlen(str3));
	ft_memset(str3, 'A', 11);
	ft_puts(str3);
	printf("len %lu\n", ft_strlen(str3));

	printf("\nmemcpy test\n");//overlap a faire
	ft_memcpy(str3, cstr, 5);
	ft_puts(str3);
	ft_puts(cstr);
	ft_puts(ft_memcpy(str3, cstr, 8));


	printf("\nstrdup test\n");
	char *str4;
	char *str5;
	char *str6;
	char *str7;
	str4 = ft_strdup(cstr);
	str5 = ft_strdup("42");
	ft_puts(str4);
	printf("str5 = %s\n", str5);
	ft_puts(str5);
	ft_puts(ft_strdup(cstr));
	ft_puts(cstr);
	str6 = ft_strdup("");
	str7 = strdup("");
	if (strcmp(str6, str7) != 0)
		printf("No match 1st test\n");
	printf("free str7\n");
	free(str7);
	printf("free str6\n");
	free(str6);
	printf("dup str6\n");
	str6 = ft_strdup("hello");
	printf("dup str7\n");
	str7 = strdup("hello");
	if (strcmp(str6, str7) != 0)
		printf("No match 2nd test\n");
	free(str6);
	free(str7);

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
		printf("No match 1st test\n");
	free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
		printf("No match 2nd test\n");
	free(ret1);
	free(ret2);

	printf("\ncat test\n");
	int fd;
	fd = open("test1", O_RDONLY);
	if (fd > 0)
	{
		printf("fd = %d\n", fd);
		ft_cat(fd);
	}
	else
		printf("erreur open (a tester plus tard)\n");
	ssize_t a;

	a = read(42, buf, 9);
	printf("a=== %zd\n", a);
	printf("a=== %zd\n", sizeof(ssize_t));
	printf("\ncat test\n");
	ft_cat(-1);
	printf("\ncat test\n");
	ft_cat(0);
	printf("\ncat test\n");
	ft_cat(42);
	return (0);
}
