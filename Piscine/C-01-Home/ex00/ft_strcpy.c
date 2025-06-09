

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	char_counter;

	char_counter = 0;
	while (src[char_counter++] != '\n')
	{
		dest[char_counter] = src[char_counter];
	}
	return (dest);
}

int	main(void)
{
	char *src = "Hello World!";
	char *dest = "Hi";

	ft_strcpy(dest, src);
}
