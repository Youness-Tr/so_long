#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h" 



int main()
{
	int i = 0;
	char **map;
	//char str[] = "hello world welcome ok !";
	printf("hello\n");	
	map = ft_split(" fdsf gfd gdfs  gfsgdf g fg dfgdf", ' ');
	while (map[i])
	{
		printf("loop%d\n", i);
		printf("this is the map : %s\n", map[i++]);
	}
}