#include"libft.h"
#include<stdio.h>



void ft_writefd(char* name,char* age)
{
	FILE* file;
	size_t	sizeofwrite = ft_strlen(name) + 6;
	char *write = " yasi ";
	char *yas ;



	file = fopen("/Users/abturan/Desktop/names.txt","a");

	fwrite(name ,ft_strlen(name),1,file);
	fwrite(write,6,1,file);
	fwrite(age,2,1,file);
	fwrite("\n",1,1,file);

	fclose(file);

}


void ft_writeage(int age)
{
	FILE* file;
	file = fopen("/Users/abturan/Desktop/age.txt","a");
	fwrite(ft_itoa(age) ,2,1,file);
	fclose(file);
}


int main()
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	yasi = 0;
	int flag = 0;
	size_t t = 0;
	char*	now;
	char*	nallowed = "0123456789,";
	char a[] = "ece 29 ahmet 12 yusuf 28 kadir 25 yener 12 kadir 25";
	char b[] = "umut 20, kadir   25, kaan 30, tuncay 35, yusuf 12";
	char **p;
	char **c;


	p = ft_split(a,' ');
	c = ft_split(b,' ');
	ft_writefd(ft_strtrim(p[i],nallowed),p[i + 1]);
	while (p[i])
	{
		while(j < i)
		{
			if(ft_strncmp(p[i],p[j],ft_strlen(p[i])) == 0)
			{

				break;
			}
			if(i - 1== j )
			{
				if(ft_isalpha(p[i][0]))
				{
					ft_writefd(ft_strtrim(p[i],nallowed),p[i + 1]);
					yasi += ft_atoi(p[i + 1]);
				}

			}
			j++;
		}
		j = 0;
		i++;
	}

	i = 0;
	ft_writefd(ft_strtrim(c[i],nallowed),c[i + 1]);
	while (c[i])
	{
		while(j < i)
		{
			while(p[t])
			{
				printf("%s",ft_strtrim(c[i],","));
				if(ft_strncmp(c[i],p[t],ft_strlen(p[t])) == 0)
				{
					flag = 1;
					break;
				}
				t++;
			}
			t = 0;
			if(ft_strncmp(c[i],c[j],ft_strlen(c[i])) == 0 || flag == 1)
			{
				flag = 0;
				break;
			}
			if(i - 1== j )
			{
				if(ft_isalpha(c[i][0]))
				{
					ft_writefd(ft_strtrim(c[i],nallowed),c[i + 1]);
					yasi += ft_atoi(c[i + 1]);
				}

			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("%lu",yasi);
	ft_writeage(yasi);
	
}




// "umut 20, kadir   25, kaan 30, tuncay 35, yusuf 12"
// "ece 29 ahmet 12 yusuf 28 kadir 25 yener 12"



//isim yaş arasına "yaşı" kelimesi gelecek ve hepsi bir dosyada satır satır yazılacak 
//aynı girdiler  tekrarlanmıcak
//yaş toplamları başka bir dosyada oalcak
