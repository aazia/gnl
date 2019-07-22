#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"

/*
** 4 lines with 8 chars without Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			a;
	int			b;
	int			c;
	int			d;

	a = 0;
	b= 0;
	c = 0;
	d = 0;
	filename = "tests/gnl7_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				{
					a++;
				}
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				b++;
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
				c++;
			if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			{
				printf("checked def");
				d++;
			}
			count_lines++;
			printf("in test: line : %s\n", line);
			if (count_lines > 5)
				break ;
		}
		close(fd);
		printf("ending line : %s\n", line);
		if (count_lines != 4)
		{
			printf("-> should have returned '1' four times instead of %d time(s)\n", count_lines);
			printf("error: %s, %d\n", line, ret);
		}
		if (a > 0 || b > 0 || c > 0 || d > 0)
		{
			printf("-> errors: %d %d %d %d, should have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n", a, b, c, d);
		}
		if (count_lines == 4 && a == 0 && b == 0 && c == 0 && d == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
