/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:49:03 by dgameiro          #+#    #+#             */
/*   Updated: 2018/09/13 13:57:22 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <libfta.h>
#include <unistd.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
//puts cat test
//segf memcpy
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
	ft_bzero(buf, 9);
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

	int er_bzero = 0;
	char *bzstr = strdup(str);

	ft_bzero(str, 5);
	bzero(bzstr, 5);

	if(memcmp(str, bzstr, sizeof(str)) != 0)
		er_bzero++;

	if (er_bzero)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", er_bzero);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nstrcat test\n");
	
	int error = 0;
	
	if(strcmp("Salut Ca va?", ft_strcat(cstr, str2)) != 0)
		error++;

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	if (strcmp(buf, "Bonjour.") != 0)
		error++;
	if (strcmp(buf, ft_strcat(buf, "")) != 0)
		error++;
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


	printf("\nalpha test\n");
	error = 0;
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isalpha(i) != ft_isalpha(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\ndigit test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (isdigit(i) != ft_isdigit(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nascii test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (isascii(i) != ft_isascii(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nisprint test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (isprint(i) != ft_isprint(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nisalnum test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (isalnum(i) != ft_isalnum(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\ntoUPPER test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (toupper(i) != ft_toupper(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");
	
	printf("\nTOlower test\n");
	error = 0;

	i = -300;
	while (i < 300)
	{
		if (tolower(i) != ft_tolower(i))
			error++;
		i++;
	}
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nstrlen test\n");
	
	error = 0;

	if(strlen(cstr) != ft_strlen(cstr))
		error++;
	if(strlen(str) != ft_strlen(str))
		error++;
	if(strlen(buf) != ft_strlen(buf))
		error++;
	if (strlen("") != ft_strlen(""))
		error++;
	if (strlen("123") != ft_strlen("123"))
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nmemset test\n");

	char *mtstr3 = strdup(str3);
	error = 0;

	if (memcmp(memset(mtstr3, 101, 10), ft_memset(str3, 101, 10), sizeof(str3)) != 0)
		error++;
	if (memcmp(memset(mtstr3, 'A', 11), ft_memset(str3, 'A', 11), sizeof(str3)) != 0)
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	printf("\nmemcpy test\n");
	char *mmcstr = strdup(cstr);
	error = 0;

	if (memcmp(memcpy(mtstr3, mmcstr, 5), ft_memcpy(str3, cstr, 5), 5) != 0)
		error++;
	if (memcmp(memcpy(mtstr3, mmcstr, 8), ft_memcpy(str3, cstr, 8), 8) != 0)
		error++;
	ft_memcpy(NULL, NULL, 0);
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


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

	/*printf("\ncat test\n");
	int fd;
	fd = open("test", O_RDONLY);
	if (fd > 0)
	{
		printf("fd = %d\n", fd);
		ft_cat(fd);
		close(fd);
	}
	else
		printf("erreur open (a tester plus tard)\n");
	
	fd = open("main.c", O_RDONLY);
	if (fd > 0)
	{
		printf("fd = %d\n", fd);
		ft_cat(fd);
		close(fd);
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
	ft_cat(4);
	printf("\ncat test\n");
	ft_cat(42);

	printf("\nstrchr test\n");
	printf("%s\n", buf);
	printf("%s\n", ft_strchr(buf, 0));
	*/
	char btr[2] = "b";
	
	printf("\nstrrev test\n");
	printf("%s\n", buf);
	printf("%s\n", ft_strrev(buf));
	printf("%s\n", buf);
	printf("%s\n", btr);
	printf("%s\n", ft_strrev(btr));
	printf("%s\n", ft_strrev("9876543210"));
	printf("%s\n", ft_strrev(NULL));

	printf("\nputchar test\n");
	ft_putchar('8');

	printf("\nputnbr test\n");
	ft_putnbr(123456789);

	printf("\natoi test\n");
	char num[5] = "1234";
	int er_atoi = 0;
	if (atoi("\n\v\t\r\f -123") != ft_atoi("\n\v\t\r\f -123"))
		er_atoi++;
	if (atoi("12-3") != ft_atoi("12-3"))
		er_atoi++;
	if (atoi("-+123") != ft_atoi("-+123"))
		er_atoi++;
	if (atoi("a123") != ft_atoi("a123"))
		er_atoi++;
	if (atoi("123a") != ft_atoi("123a"))
		er_atoi++;
	if (atoi("123") != ft_atoi("123"))
		er_atoi++;
	if (atoi("-123") != ft_atoi("-123"))
		er_atoi++;
	if (atoi("+123") != ft_atoi("+123"))
		er_atoi++;
	if (atoi(" - 123") != ft_atoi(" - 123"))
		er_atoi++;
	if (atoi("\t -123") != ft_atoi("\t -123"))
		er_atoi++;
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
		er_atoi++;
	if (atoi("2147483647") != ft_atoi("2147483647"))
		er_atoi++;
	if (atoi("") != ft_atoi(""))
		er_atoi++;
	if (atoi(num) != ft_atoi(num))
		er_atoi++;
	if (er_atoi)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", er_atoi);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	return (0);
}
