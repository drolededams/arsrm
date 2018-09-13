/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:49:03 by dgameiro          #+#    #+#             */
/*   Updated: 2018/09/13 17:18:01 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <libfta.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
// putchar punbr test
// mem test seg
//gcc -Wall -Wextra -Werror -I./ -L./ -lfts main.c
int		main(void)
{
	int error = 0;

/*
 * *********** bzero ***********
 */

	printf("bzero test\n");

	char str[6] = "Salut";
	char *bzstr = strdup(str);

	ft_bzero(str, 5);
	bzero(bzstr, 5);

	if(memcmp(str, bzstr, sizeof(str)) != 0)
		error++;
	free(bzstr);

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

/*
 * *********** strcat ***********
 */

	printf("strcat test\n");
	
	error = 0;
	char buf[9];
	char cstr[13] = "Salut       ";
	cstr[5] = 0;
	char str2[8] = " Ca va?";
	
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


/*
 * *********** alpha ***********
 */

	printf("alpha test\n");
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


/*
 * *********** digit ***********
 */
	printf("digit test\n");
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


/*
 * *********** ascii ***********
 */
	printf("ascii test\n");
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


/*
 * *********** isprint ***********
 */
	printf("isprint test\n");
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


/*
 * *********** isalnum ***********
 */
	printf("isalnum test\n");
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


/*
 * *********** toupper ***********
 */
	printf("toUPPER test\n");
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


/*
 * *********** tolower ***********
 */
	printf("TOlower test\n");
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


/*
 * *********** strlen ***********
 */
	printf("strlen test\n");
	
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


/*
 * *********** memset ***********
 */
	printf("memset test\n");

	
	char *str3;
	str3 = (char*)malloc(16);
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


/*
 * *********** memcpy ***********
 */
	printf("memcpy test\n");
	char *mmcstr = strdup(cstr);
	error = 0;

	if (memcmp(memcpy(mtstr3, mmcstr, 5), ft_memcpy(str3, cstr, 5), 5) != 0)
		error++;
	if (memcmp(memcpy(mtstr3, mmcstr, 8), ft_memcpy(str3, cstr, 8), 8) != 0)
		error++;
	ft_memcpy(NULL, NULL, 3);
	free(str3);
	free(mtstr3);
	free(mmcstr);
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


/*
 * *********** strdup ***********
 */
	printf("strdup test\n");

	char		*ret1;
	char		*ret2;
	char *str4;
	char *str5;
	char *str6;
	char *cstr4;
	char *cstr5;
	char *cstr6;

	error = 0;

	str4 = ft_strdup(cstr);
	str5 = ft_strdup("42");
	cstr4 = ft_strdup(cstr);
	cstr5 = ft_strdup("42");
	str6 = ft_strdup("");
	cstr6 = strdup("");

	if (strcmp(str4, cstr4) != 0)
		error++;
	if (strcmp(str5, cstr5) != 0)
		error++;
	if (strcmp(str6, cstr6) != 0)
		error++;

	free(str4);
	free(cstr4);
	free(str5);
	free(cstr5);
	free(str6);
	free(cstr6);
	str6 = ft_strdup("hello");
	cstr6 = strdup("hello");
	if (strcmp(str6, cstr6) != 0)
		error++;
	free(str6);
	free(cstr6);

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
		error++;
	free(ret1);
	free(ret2);
	
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
		error++;
	free(ret1);
	free(ret2);

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");
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
*/


/*
 * *********** strcat ***********
 */

	printf("cat test\n");

	error = 0;

	int pids[2];
	struct stat	data;
	char buf2[10];
	int saved_stdout;
	int fd;
	void *ptr;

	saved_stdout = dup(1);
	pipe(pids);
	dup2(pids[1], 1);

	system("echo '12345678912345678' > catout");
	fd = open("catout", O_RDONLY);
	if (fd < 0)
		return (-1);
	ft_cat(fd);
	read(pids[0], buf2, 17);
	dup2(saved_stdout, 1);

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(saved_stdout);
	system("rm catout");
	if (memcmp(buf2, "12345678912345678", 17) != 0)
		error++;

	if ((fd = open("main.c", O_RDONLY)) < 0)
		return (-2);
	if (fstat(fd, &data) == -1)
		return (-3);
	if ((ptr = mmap(0, data.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (-4);
	
	char buf3[data.st_size];
	saved_stdout = dup(1);
	pipe(pids);
	dup2(pids[1], 1);
	ft_cat(fd);
	read(pids[0], buf3, data.st_size);
	dup2(saved_stdout, 1);
	close(fd);
	close(pids[0]);
	close(pids[1]);

	if (memcmp(buf3, ptr, data.st_size) != 0)
		error++;

	munmap(ptr, data.st_size);

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


/*
 * *********** puts ***********
 */

	printf("puts test\n");

	error = 0;
	int		ret;
	int		ft_puts_ret1;
	int		out;
	int		p[2];
	char	buf4[10000];
	char	buf5[10000];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_puts_ret1 = ft_puts("aaa");
	dup2(out, 1);
	ret = read(p[0], buf4, 10000);
	buf4[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	puts("aaa");
	dup2(out, 1);
	ret = read(p[0], buf5, 10000);
	buf5[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);

	if (strcmp(buf4, buf5) != 0)
		error++;
	if (ft_puts_ret1 < 0)
		error++;

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_puts_ret1 = ft_puts(NULL);
	dup2(out, 1);
	ret = read(p[0], buf4, 10000);
	buf4[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	puts(NULL);
	dup2(out, 1);
	ret = read(p[0], buf5, 10000);
	buf5[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);

	if (strcmp(buf4, buf5) != 0)
		error++;
	if (ft_puts_ret1 < 0)
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

/*
 * *********** strchr ***********
 */

	printf("strchr test\n");
	error = 0;
	if(ft_strchr(buf, 0) != strchr(buf,0))
		error++;
	if(ft_strchr(buf, 'B') != strchr(buf,'B'))
		error++;
	if(ft_strchr(buf, 'o') != strchr(buf,'o'))
		error++;
	if(ft_strchr(buf, 'Y') != strchr(buf,'Y'))
		error++;
	
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


/*
 * *********** strrev ***********
 */
	printf("strrev test\n");
	
	char btr[2] = "b";
	char *fub;
	char *rtb;
	char *mun;

	error = 0;
	if(strcmp((fub = ft_strrev(buf)), ".ruojnoB") != 0)
		error++;
	if(strcmp((rtb = ft_strrev(btr)), "b") != 0)
		error++;
	if(strcmp((mun = ft_strrev("9876543210")), "0123456789") != 0)
		error++;
	if (ft_strrev(NULL) != NULL)
		error++;

	free(fub);
	free(rtb);
	free(mun);

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

/*
 * *********** strcmp ***********
 */
	printf("strcmp test\n");
	
	int a;

	error = 0;
	a = ft_strcmp("abc", "abc");
	if (a != strcmp("abc", "abc"))
		error++;
	if (a)
		error++;
	a = ft_strcmp("cba", "abc");
	if (a != strcmp("cba", "abc"))
		error++;
	if (!a)
		error++;
	a = ft_strcmp("abc", "cba");
	if (a != strcmp("abc", "cba"))
		error++;
	if (!a)
		error++;
	if (ft_strcmp("", "") != strcmp("", ""))
		error++;
	if (ft_strcmp("-123", "-123") != strcmp("-123", "-123"))
		error++;
	if (ft_strcmp("-123", "-1223") != strcmp("-123", "-1223"))
		error++;
	if (ft_strcmp("-123", "123") != strcmp("-123", "123"))
		error++;
	if (ft_strcmp("-123", "-12") != strcmp("-123", "-12"))
		error++;
	if (ft_strcmp("-12", "-123") != strcmp("-12", "-123"))
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


/*
 * *********** putchar ***********
 */

	printf("putchar test\n");
	error = 0;
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putchar('-');
	ft_putchar('b');
	ft_putchar('\n');
	dup2(out, 1);
	read(p[0], buf3, 3);
	buf3[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	
	if(strcmp(buf3, "-b\n") != 0)
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");


/*
 * *********** putnbr ***********
 */

	printf("putnbr test\n");
	error = 0;
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(123);
	ft_putnbr(-123);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	dup2(out, 1);
	a = read(p[0], buf4, 100);
	buf4[a] = 0;
	close(p[0]);
	close(p[1]);
	close(out);

	if (strcmp(buf4, "01-1123-1232147483647-2147483648") != 0)
		error++;

	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

/*
 * *********** atoi ***********
 */
	printf("atoi test\n");
	char num[5] = "1234";
	error = 0;
	if (atoi("\n\v\t\r\f -123") != ft_atoi("\n\v\t\r\f -123"))
		error++;
	if (atoi("12-3") != ft_atoi("12-3"))
		error++;
	if (atoi("-+123") != ft_atoi("-+123"))
		error++;
	if (atoi("a123") != ft_atoi("a123"))
		error++;
	if (atoi("123a") != ft_atoi("123a"))
		error++;
	if (atoi("123") != ft_atoi("123"))
		error++;
	if (atoi("-123") != ft_atoi("-123"))
		error++;
	if (atoi("+123") != ft_atoi("+123"))
		error++;
	if (atoi(" - 123") != ft_atoi(" - 123"))
		error++;
	if (atoi("\t -123") != ft_atoi("\t -123"))
		error++;
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
		error++;
	if (atoi("2147483647") != ft_atoi("2147483647"))
		error++;
	if (atoi("") != ft_atoi(""))
		error++;
	if (atoi(num) != ft_atoi(num))
		error++;
	if (error)
		printf(ANSI_COLOR_RED "KO %d error(s)"  ANSI_COLOR_RESET "\n", error);
	else
		printf(ANSI_COLOR_GREEN   "OK"   ANSI_COLOR_RESET "\n");

	return (0);
}
