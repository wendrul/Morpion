#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int	tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	read_file(int fd, char **s)
{
	ssize_t bytes;
	ssize_t size;
	char buf[4096];
	
	if ((fd = open(REPLIES_PATH, O_RDONLY)) == -1)
		return (-1);
	while ((bytes = read(fd, buf, 4096)))
		size += bytes 
	close(fd);
	if ((fd = open(REPLIES_PATH, O_RDONLY)) == -1)
		return (-1);
	if (!(*s = (char*)malloc(sizeof(char) * (size + 1))))
		return (-1);
	read(fd, *s, size);
	s[size] = '\0';
	return (0);
}

char	*get_text(char *category)
{
	int fd;
	char *rawtext;
	char *aux_tab;
	int i;

	if (read_file(fd, &rawtext) != -1)
		return ("FAILED TO OPEN FILE (lol ca marche pas verifie que lines.txt existe gros con)\n");
	if (!(aux_tab = ft_split(rawtext, "=><")))
		return ("FAILED (really malloc?)\n");
	free(rawtext);
	i = 0;
	while (strcmp(aux_tab[2 * i], category))
	{
		free(aux_tab[2 * i]);
		if(!aux_tab[2 * i + 1] || aux_tab[2 * (i + 1)])
			break ;
		free(aux_tab[2 * i + 1]);
	}
	if (aux_tab[2*i + 1] && !(rawtext = ft_split(aux_tab[2 * i + 1], "=><")))
		return ("FAILED (really malloc?) or file badly formatted or bad code(yeah yo me entiendo)\n");
	i = 2 * i - 1;
	while (aux_tab[++i])
		free(aux_tab[i]);
	i = rand() % (tab_size(raw_text) - 1);
	
}






















