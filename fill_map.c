#include"cub3d.h"

void fill_textures(t_cub *cub,char *v)
{
	int i = 0;
	if(check_NO(v))
	{
		i=check_NO(v);
		if(cub->no)
			error_msg("Oops!Something Happens!\n");
		printf("v==%s\n",v);
		printf("i==%d\n",i);
		printf("strlen==%zu\n",ft_strlen(v)-4);
		cub->no=ft_substr(v,i,ft_strlen(v)-(i+1));
		//file_existance(open(cub->no,O_RDONLY),cub->no);
		//free(v);
		cub->count++;
	}
	else if(check_SO(v))
	{
		i=check_SO(v);
		if(cub->so)
			error_msg("Oops!Something Happens!\n");
		cub->so = ft_substr(v,i,ft_strlen(v)-(i+1));
		//file_existance(open(cub->so,O_RDONLY),cub->so);
		//free(v);
		cub->count++;
	}
	else if(check_EA(v))
	{
		i=check_EA(v);

		if(cub->ea)
			error_msg("Oops!Something Happens!\n");
		cub->ea = ft_substr(v,i,ft_strlen(v)-(i+1));
		//file_existance(open(cub->ea,O_RDONLY),cub->ea);
		//free(v);
		cub->count++;
	}
	else if(check_WE(v))
	{
		i=check_WE(v);
		if(cub->we)
			error_msg("Oops!Something Happens!\n");
		cub->we = ft_substr(v,i,ft_strlen(v)-(i+1));
		//file_existance(open(cub->we,O_RDONLY),cub->we);
		//free(v);
		cub->count++;
	}
	else if(check_C(v))
	{
		i=check_C(v);
		if(cub->c)
			error_msg("Oops!Something Happens!\n");
		cub->c = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else if(check_F(v))
	{
		i=check_F(v);
		if(cub->f)
			error_msg("Oops!Something Happens!\n");
		cub->f = ft_substr(v,i,ft_strlen(v));
		//free(v);
		cub->count++;
	}
	else
		error_msg("Oops!Something Happens!\n");
	
}
void file_existance(int fd,char *s)
{
	if(fd==-1)
	{
		printf("s = %s\n",s);
		free(s);
		close(fd);
		error_msg("Oops!This Path Not Found!\n");
	}
}
char	**read_map(char *map,t_cub *cub)
{
	int		fd;
	char	*line;
	char	*v;
	char	**split;
	int		i;
	int e = 0;

	split = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	v = NULL;
	i = 0;
	//TAKE TEXTURES;
	while (line)
	{
		if(check_empty_space(line))
		{	
			free(line);
			line = get_next_line(fd);
			continue;
		}
		fill_textures(cub,line);
		if(cub->count==6)
			break;
		line = get_next_line(fd);
	}
	//TAKE MAP;
	line = get_next_line(fd);
	while(line)
	{
		if(check_empty_space(line))
		{	
			free(line);
			line = get_next_line(fd);
			continue;
		}
		break;
	}
	while(line)
	{
		e = 0;
		e = skip_space(line);
		if(line[e]=='\n')
			error_msg("Oops!Empty Line in Map!\n");
		if(line[e]!='1')
			error_msg("Oops!Map Has An Error!\n");
		v = ft_strjoin(v,line);
		free(line);
		line = get_next_line(fd);
	}
	empty_file(v);
	i = ft_strlen(v);
	empty_line(v[i - 1]);
	split = ft_split(v, '\n');
	free(v);
	close (fd);
	return (split);
}
