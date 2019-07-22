#include "get_next_line.h"

int	ft_checkline(char **str, char **line, int fd, int ret)
{
	char 	*tmp;
	int	i;

	i = 0;
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
		return (0);
	printf("\n\nstr in checkline : %s", *str);
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
	{
		i++;	
	}
	if ((*str)[i] == '\n')
	{	
		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = ft_strdup(tmp);
		printf("\nstr after tmp : %s", *str);
		if ((*str)[0] == '\0')
		{
			printf("\n\nhelo\n\\n");
			*line = ft_strdup(*str);
			ft_strdel(str);
		}
	}
	else
	{
		printf("checkline: else");
		ft_strdel(str);
	}
	printf("\nline after checkline : %s, str : %s\n", *line, str[fd]);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*buffer;
	int		nbread;
	char		*tmpstr;
	if (!line || fd < 0 || fd >= 1025 || (read(fd, str[fd], 0) < 0) || \
		!((buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	while ((nbread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nbread] = '\0';

		if (str[fd] == NULL)
		{
			printf("\n\nstrdup buffer\n\n");
			str[fd] = ft_strdup(buffer);	
		}
		else
		{
			tmpstr = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(tmpstr);
		}
		if (ft_strchr(str[fd], '\n'))
			break;

	}
	printf("\nnew line : %s\n", *line);
	
	return (ft_checkline(&str[fd], line, fd, nbread));
}
