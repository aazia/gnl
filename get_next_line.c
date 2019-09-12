#include "get_next_line.h"

// large line 3 missing characters:(
// et 04 of moulitest
int	ft_checkline(char **str, char **line, int ret, char **buffer)
{
	char 	*tmp;
	int	i;
	// option a: is last line
	// option b: is not last line

	// case 1: str is empty
	// case 2: str contains a \n with characters on either side => 2 lines
	// case 3: str contains a \n and no characters after it => exactly 1 line
	i = 0;
	if (ret < 0)
		return (-1);
	if (ret == 0 && *str == NULL)
	{
		return (0);
	}
	while ((*str)[i] != '\n' && ((*str)[i] != '\0'))
		i++;	
	*line = ft_strsub(*str, 0, i);
	tmp = ft_strdup(&((*str)[i + 1]));
	free(*str);
	*str = ft_strdup(tmp);
//	free(tmp) fixes 7_3 when c-out;
	if (ret == 0)
	{
		if (((*str)[i] == '\n') || ((*str)[i] == '\0' && *line[0] != '\0') || *line[0])
		{
			return (1);
		}
		i = 0;
	//	free(*str); fixes test24 when c-out
		return (0);
	}
	free(*buffer);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*buffer;
	int		ret;
	char		*tmpstr;
	if (!line || fd < 0 || fd >= 1025 || (read(fd, str[fd], 0) < 0) || \
		!((buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);	
		else
		{
			tmpstr = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(tmpstr);
			free(tmpstr);
		}
		if (ft_strchr(str[fd], '\n'))
			break;
	}
	return (ft_checkline(&str[fd], line, ret, &buffer));
}
