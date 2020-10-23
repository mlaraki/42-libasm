/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:02:30 by mlaraki           #+#    #+#             */
/*   Updated: 2020/10/22 17:06:59 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"

void ft_print_ok(int test){
		printf("test [%d] : ", test);
		printf("\033[0;32m [OK] \033[0m");
}

void ft_print_failed(int test){
		printf("test [%d] : ", test);
		printf("\033[0;31m [FAILED] \033[0m");
}

void ft_compare(int pass)
{
	static int test_n;

	test_n++;
	if(pass == 1)
		ft_print_ok(test_n);
	else
		ft_print_failed(test_n);
	printf("\n");
}


void ft_compare_ft_strcmp(int mine , int real){
	static int test_n;

	test_n++;
	if ((mine < 0 && real < 0) || \
	    (mine > 0 && real > 0) || \
	    (mine == 0 && real == 0))
			ft_print_ok(test_n);
	else
		ft_print_failed(test_n);
	printf("\n");
}

void check_ft_strcmp(){
	ft_compare_ft_strcmp(ft_strcmp("coucou", "coucou") ,strcmp("coucou", "coucou"));
	ft_compare_ft_strcmp(ft_strcmp("a", "c") ,strcmp("a", "c"));
	ft_compare_ft_strcmp(ft_strcmp("c", "a") ,strcmp("c", "a"));
	ft_compare_ft_strcmp(ft_strcmp("abz", "abc") ,strcmp("abz", "abc"));
	ft_compare_ft_strcmp(ft_strcmp("", "") ,strcmp("", ""));
	ft_compare_ft_strcmp(ft_strcmp("", "abc") ,strcmp("", "abc"));
	ft_compare_ft_strcmp(ft_strcmp("abc", "") ,strcmp("abc", ""));
	ft_compare_ft_strcmp(ft_strcmp("a\0bc", "ab\0c") ,strcmp("a\0bc", "ab\0c"));
	ft_compare_ft_strcmp(ft_strcmp("! & ? \n yolo", "! & ? \t yolo") ,strcmp("! & ? \n yolo", "! & ? \t yolo"));
}


void ft_compare_ft_strcpy(int diff){
	static int test_n;

	test_n++;
	if(diff == 0)
		ft_print_ok(test_n);
	else
		ft_print_failed(test_n);
	printf("\n");
}

void check_ft_strcpy(){

	char str[7];
	ft_strcpy(str, "coucou");
	char str2[7];
	strcpy(str2, "coucou");
	ft_compare_ft_strcpy(strcmp(str, str2));

	char str3[48];
	ft_strcpy(str3, "Que se passe-t-il quand 2 poissons s'énervent?");
	char str4[48];
	strcpy(str4, "Que se passe-t-il quand 2 poissons s'énervent?");
	ft_compare_ft_strcpy(strcmp(str3, str4));

	char str5[31];
	ft_strcpy(str5, "Le thon monte ====> je sors xD");
	char str6[31];
	strcpy(str6, "Le thon monte ====> je sors xD");
	ft_compare_ft_strcpy(strcmp(str5, str6));

	char str7[12];
	ft_strcpy(str7, "hello\0world");
	char str8[12];
	strcpy(str8, "hello\0world");
	ft_compare_ft_strcpy(strcmp(str7, str8));

	char str9[501];
	ft_strcpy(str9, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.");
	char str10[501];
	strcpy(str10, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.");
	ft_compare_ft_strcpy(strcmp(str9, str10));

	char str11[12];
	ft_strcpy(str11, "\t \n &!?");
	char str12[12];
	strcpy(str12, "\t \n &!?");
	ft_compare_ft_strcpy(strcmp(str11, str12));

}

void ft_compare_ft_strdup(int diff){
	static int test_n;

	test_n++;
	diff == 0 ? ft_print_ok(test_n) : ft_print_failed(test_n);
	printf("\n");
}

void check_ft_strdup(char *str){
	char *tmp = ft_strdup(str);
	char *tmp2 = strdup(str);
	ft_compare_ft_strdup(strcmp(tmp, tmp2));
	free(tmp);
	free(tmp2);
}

void ft_compare_files(){
	char 		ch1 = '\0';
	char 		ch2 = '\0';
	FILE * 		fptr1;
	FILE * 		fptr2;
	static		int test_n;

	test_n++;
	fptr1 = fopen("./mine", "r");
	fptr2 = fopen("./real", "r");
	while(ch1 != -1 && ch2 != -1)
	{
		ch1 = getc(fptr1);
		ch2 = getc(fptr2);
		if (ch1 != ch2)
		{
			fclose(fptr1);
			fclose(fptr2);
			ft_print_failed(test_n);
			printf("\n");
			return;
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	ft_print_ok(test_n);
	printf("\n");
}

void check_ft_write(char *str){
	int		 	fd1;
	int			fd2;

	fd1 = open("./mine",O_RDWR | O_CREAT, 0644);
	fd2 = open("./real",O_RDWR | O_CREAT, 0644);
	ft_write(fd1, str, strlen(str));
	write(fd2, str, strlen(str));
	close(fd1);
	close(fd2);
	ft_compare_files("./mine", "./real");
}

void ft_compare_ft_read(char *mine, char *real){
	static int test_n;

	test_n++;
	if(strcmp(mine, real) == 0)
		ft_print_ok(test_n);
	else
		ft_print_failed(test_n);
	printf("\n");
}

void check_ft_read(char *filename){
	int fd;
	int rsize;
	char buffer[100];
	int fd2;
	int rsize2;
	char buffer2[100];

	fd = open(filename, O_RDONLY);
	while((rsize = (ft_read(fd, buffer, sizeof buffer))) > 0){
			buffer[rsize] = '\0';
	}
	close(fd);

	fd2 = open(filename, O_RDONLY);
	while((rsize2 = (read(fd2, buffer2, sizeof buffer2))) > 0){
			buffer2[rsize2] = '\0';
	}
	close(fd2);
	ft_compare_ft_read(buffer, buffer2);
}

int main(){
	printf("================================== ft_strlen ===================================\n\n");
	int i = -1;
	char *arr[7] = {
		"coucou",
		"Que se passe-t-il quand 2 poissons s'énervent?",
		"Le thon monte ====> je sors xD",
		"hello\0world",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.",
		"\t \n &!?",
		NULL
	};
	while(arr[++i])
		ft_compare(ft_strlen(arr[i]) == strlen(arr[i]));

	printf("================================== ft_strcmp ===================================\n\n");
	check_ft_strcmp();
	printf("================================== ft_strcpy ===================================\n\n");
	check_ft_strcpy();

	printf("================================== ft_write ====================================\n\n");
	check_ft_write("coucou");
	check_ft_write("Que se passe-t-il quand 2 poissons s'énervent?");
	check_ft_write("Le thon monte ====> je sors xD");
	check_ft_write("hello\0world");
	check_ft_write("\t \n &!?");
	check_ft_write("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.");

	printf("================================== ft_read ======================================\n\n");
	check_ft_read("ft_read.s");
	check_ft_read("ft_write.s");
	check_ft_read("ft_strcpy.s");
	check_ft_read("ft_strdup.s");
	check_ft_read("ft_strlen.s");
	check_ft_read("main.c");

	printf("================================== ft_strdup ====================================\n\n");
	check_ft_strdup("coucou");
	check_ft_strdup("Que se passe-t-il quand 2 poissons s'énervent?");
	check_ft_strdup("Le thon monte ====> je sors xD");
	check_ft_strdup("hello\0world");
	check_ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.");
	check_ft_strdup("\t \n &!?");

	return 0;
}
