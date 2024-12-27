#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = 0;
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_strdup(const char *s1)
{
	char	*tmp_str;
	size_t	i;

	i = 0;
	tmp_str = (char *) malloc ((ft_strlen (s1) + 1) * sizeof(char));
	if (tmp_str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		tmp_str[i] = s1[i];
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}

int		main(void)
{
	int		fd;
	int		r = 1;
	char	*buff;
	char 	*str = NULL;
	char	*temp;
	int 	i = 0;
	int		res = 0;
	int		xcount = 0;

	fd = open ("everybody_codes_e2024_q01_p3.txt", O_RDONLY);
	if (fd < 0)
		return (printf ("Error loading file"), 1);
	buff = malloc ((1000 + 1) * sizeof(char));
	if (!buff)
		return (1);
	while (r > 0)
	{
		r = read (fd, buff, 1000);
		if (r < 0)
			return (printf ("Error reading file"), 1);
		buff[r] = '\0';
		if (!str)
			str = ft_strdup ("");
		temp = str;
		str = ft_strjoin (str, buff);
		free (temp);
	}
	free (buff);
	while (str[i] != '\0')
	{
		if (str[i] == 'B')
			res += 1;
		else if (str[i] == 'C')
			res += 3;
		else if (str[i] == 'D')
			res += 5;
		else if (str[i] == 'x')
			xcount++;
		if ((i + 1) % 3 == 0)
		{
			if (xcount == 0)
				res += 6;
			else if (xcount == 1)
				res += 2;
			xcount = 0;
		}
		i++;
	}
	printf ("In part 3, we will need %i potions to win the battle.\n", res);
	free (str);
	return (0);
}