#include "so_long.h"
#include "get_next_line.h"



void f_floodfill(char **map, int x, int z, t_data *data)
{
	// printf("lines : %i", data->lines);
	if (x < 0 || x >= data->lines || z < 0 || z >= (ft_strlen(map[0])) 
		|| map[x][z] == '1' || map[x][z] == 'H')
	{
		//printf("\033[1;31mexited cordonee = {%i,%i} [%c]\033[0m\n",x,z,map[x][z]);
		return ;
	}
	if (map[x][z] == 'E')
	{
		map[x][z] = '1';
		return ;
	}
	//printf("\033[1;32mANA HNA cordonee = {%i,%i} [%c]\033[0m\n",x,z,map[x][z]);

	map[x][z] = 'H';
	f_floodfill(map, x -1, z, data);
	f_floodfill(map, x +1, z, data);
	f_floodfill(map, x, z -1, data);
	f_floodfill(map, x, z +1, data);
}

void check_map(t_data *data)
{
	int i;

	data->lines = 0;
	data->buff = NULL;
	i = 0;
	while (1)
	{
		data->buff = get_next_line(data->fd);
		if (!data->buff)
			break;
		i = 0;
		while (data->buff[i])
		{
			if (i == 1)
				data->lines++;
			i++;
		}
		data->str = ft_strjoin(data->str, data->buff);
		free(data->buff);
	}
}

void new_line(t_data *data)
{
	int i;
	i = 0;
	while (data->str[i])
	{
		if (data->str[i] == '\n')
			data->newl++;
	    i++;
	}
	if (data->newl >=  data->lines)
		ft_error("wa hdaaaa 3liya nl");
	data->map = ft_split(data->str, '\n');
	data->map_cp = ft_split(data->str, '\n');
	free(data->str);
	data->width = ft_strlen(data->map[0]);
}

void check_char(t_data *data)
{

	int c = 0;
	int i = 0;
	while (data->map[i])
	{
		c = 0;
		data->newl = 0;
		while (data->map[i][c])
		{
			if ((data->map[i][c] != '1' && data->map[i][c] != '0' && data->map[i][c] != 'P' 
				&& data->map[i][c] != 'C' && data->map[i][c] != 'E') && data->map[i] != NULL)
				ft_error ("chi haja fchkel");
			if (data->map[i][c] == 'P')
			{
				data->player += 1;
				data->playerx = c;
				data->playery = i;
			}
			if (data->map[i][c] == 'C')
				data->coins += 1;
			if (data->map[i][c] == 'E')
				data->exit += 1;
			c++;
		}
		if ((ft_strlen(data->map[i]) != ft_strlen(data->map[i + 1])) 
			&& data->map[i + 1])
			ft_error ("hada ma hoowa hada");
		i++;
	}
	if (data->player != 1)
		ft_error("la3ib mossab");
	if (data->coins == 0)
		ft_error("finahowa l9ss !!!");
	if (data->exit != 1)
		ft_error("nari lbab !!");
}

void check_wall(t_data *data)
{
	int c;

	c = 0;
	while (data->map[0][c])
	{
		if (data->map[0][c] != '1')
			ft_error("t9ba f l7it\n");
		c++;
	}
	c = 0;
	data->lines -= 1;
	while (data->map[data->lines][c])
	{
		if (data->map[data->lines][c] != '1')
			ft_error("t9ba f l7it");	
		c++;
	}
	c = 1;
	while (c < data->lines)
	{
		if (data->map[c][0] != '1' 
			|| data->map[c][ft_strlen(data->map[c]) - 1] != '1')
			ft_error("t9ba f l7it");
		c++; 
	}
}

void floodfill_check(t_data *data)
{
	data->i = 0;
	f_floodfill(data->map_cp, data->playery, data->playerx, data);

	while (data->map_cp[data->i])
	{
		data->c = 0;
		while (data->map_cp[data->i][data->c])
		{
			if (data->map_cp[data->i][data->c] == 'C' 
				|| data->map_cp[data->i][data->c] == 'E')
				ft_error("ch9itiha !!!");
			data->c++;
		}
		data->i++;
	}
}

char	*ft_strnstr(const char *big, const char *little)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (!big)
		return (NULL);
	if (little[b] == '\0')
		return ((char *)big);
	while (big[b] != '\0')
	{
		l = 0;
		while (big[b + l] == little[l] && big[b + l] != '\0')
		{
			l++;
		}
		if (little[l] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
// int main(int argc, char** argv)
// {
// 	t_data data;

// 	// data = (t_data *)malloc(sizeof(t_data));
// 	// if (!data)
// 	// 	return (0);
// 	// int i = 0;
// 	// char *str = NULL;
// 	// char *buff = NULL;
// 	// char **map;
// 	// int newl;
// 	// int len = 0;
// 	// int first_len = 0;
// 	// data->lines = 0;
// 	// char **map_cp;

// 	if (argc < 2 || !ft_strnstr(argv[1], ".ber"))
// 	{
// 		printf("few arges\n");
// 		exit(1);
// 	}

// 	printf("%s\n", argv[1]);
// 	data.fd = open(argv[1], O_RDWR);
// 	if (data.fd < 0)
// 	{
// 		printf("error\n");
// 		exit(1);
// 	}
// 	//printf("function one\n");
// 	check_map(&data);
// 	printf("function 2");
// 	new_line(&data);
// 	// printf ("str : %s\n", data.str);
// 	// data.map = ft_split(data.str, '\n');
// 	printf ("//////map : %s\n", data.map[0]);
// 	check_char(&data);
// 	printf("function 3");
// 	check_wall(&data);
// 	printf("function 4\n");
// 	printf("lines : %i\n", data.lines);
// 	floodfill_check(&data);
// 	// fd = open("map->ber", O_RDWR);
// 	// i = 0;
// 	// while (1)
// 	// {
// 	// 	//printf("enter\n");
// 	// 	newl = 0;
// 	// 	buff = get_next_line(fd);
// 	// 	if (!buff)
// 	// 		break;
// 	// 	// len = ft_strlen(buff);
// 	// 	// if (i == 0)
// 	// 	// {
// 	// 	// 	i++;
// 	// 	// 	first_len = len;
// 	// 	// }
// 	// 	// printf("len is : %d and f_len is %d\n", len, first_len);
// 	// 	// if (len && first_len != len)
// 	// 	// {
// 	// 	// 	printf("%c\n", buff[3]);
// 	// 	// 	printf("line : %d AND first line : %d\n", len, first_len);
// 	// 	// 	printf("wa hdaaaa 3liya,\n");
// 	// 	// 	exit(1);
// 	// 	// }
// 	// 	i = 0;
// 	// 	while (buff[i])
// 	// 	{
// 	// 		if (i == 1)
// 	// 			data->lines++;
// 	// 		i++;
// 	// 	}
// 	// 	printf ("this it\n" );	
// 	// 	str = ft_strjoin(str, buff);
// 	// 	//printf("nwe line here ! %d\n", newl);
// 	// }
// 	// printf ("lines %d\n", data->lines);
// 	// i = 0;
// 	// while (str[i])
// 	// {
// 	// 	if (str[i] == '\n')
// 	// 		newl++;
// 	//     i++;
// 	// }
// 	// printf ("new line %d\n", newl);
// 	// if (newl >=  data->lines)
// 	// {
// 	// 	printf("wa hdaaaa 3liya nl");
// 	// 	exit (1);
// 	// }

// 	// 	//printf("str is : %s\n", str);
// 	// map = ft_split(str, '\n');
// 	// data->lines = 0;
// 	// while (1)
// 	// {
// 	// 	printf("str is : %s\n", map[data->lines]);
// 	// 	if (!map[data->lines])
// 	// 		break;
// 	// 	data->lines++;
// 	// }
// 	// i = 0;
// 	// int c = 0;
// 	// while (map[i + 1])
// 	// {
// 	// 	c = 0;
// 	// 	newl = 0;
// 	// 	while (map[i][c])
// 	// 	{
// 	// 		//printf("str is : %c\n", map[i][c]);
// 	// 		if ((map[i][c] != '1' && map[i][c] != '0' && map[i][c] != 'P' && map[i][c] != 'C' && map[i][c] != 'E') && map[i] != NULL)
// 	// 		{
// 	// 			printf ("chi haja fchkel");
// 	// 			exit (1);
// 	// 		}
// 	// 		if (map[i][c] == 'P')
// 	// 		{
// 	// 			data->player += 1;
// 	// 			data->posi = i;
// 	// 			data->posc = c;
// 	// 		}
// 	// 		if (map[i][c] == 'C')
// 	// 			data->coins += 1;
// 	// 		if (map[i][c] == 'E')
// 	// 			data->exit += 1;
// 	// 		c++;
// 	// 	}
// 	// 	//printf("this is s");
// 	// 	if ((ft_strlen(map[i]) != ft_strlen(map[i + 1])))
// 	// 	{
// 	// 		printf ("hada ma hoowa hada");
// 	// 		exit (1);
// 	// 	}
// 	// 	i++;
// 	// }
// 	// if (data->player != 1)
// 	// 	printf("la3ib mossab");
// 	// if (data->coins == 0)
// 	// 	printf("finahowa l9ss !!!");
// 	// if (data->exit != 1)
// 	// 	printf("nari lbab !!");
// 	// c = 0;
// 	// while (map[0][c])
// 	// {
// 	// 	if (map[0][c] != '1')
// 	// 		printf("t9ba f l7it");
// 	// 	c++;
// 	// }
// 	// c = 0;
// 	// data->lines -= 1;
// 	// while (map[data->lines][c])
// 	// {
// 	// 	if (map[data->lines][c] != '1')
// 	// 		printf("t9ba f l7it");	
// 	// 	c++;
// 	// }
// 	// c = 1;
// 	// while (c < data->lines)
// 	// {
// 	// 	if (map[c][0] != '1' || map[c][ft_strlen(map[c]) - 1] != '1')
// 	// 		printf("t9ba f l7it");
// 	// 	c++; 
// 	// }
// 	// map_cp = map;
// 	// c = 0;
// 	// i = 0;
// 	// f_floodfill(map_cp, data->posi, data->posc);
// 	// while (1)
// 	// {
// 	// 	printf("str is : %s\n", map_cp[i]);
// 	// 	if (!map_cp[i])
// 	// 		break;
// 	// 	i++;
// 	// }
// 	// i = 0;
// 	// while (map_cp[i])
// 	// {
// 	// 	c = 0;
// 	// 	while (map_cp[i][c])
// 	// 	{
// 	// 		///printf ("char is : %c", map_cp[i][c]);
// 	// 		if (map_cp[i][c] == 'C')
// 	// 		{
// 	// 			printf("ch9itiha !!!");
// 	// 			exit (1);
// 	// 		}
// 	// 			;
// 	// 		c++;
// 	// 	}
// 	// 	i++;
// 	// }
// }
