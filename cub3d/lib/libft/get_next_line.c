
#include "libft.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	character;
	int		i;
	int		rd;

	i = 0;
	rd = 1;
	character = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(100000);
	while (rd > 0)
	{
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
