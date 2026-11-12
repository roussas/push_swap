long	ft_atol(const char *nptr)
{
	int     i;
	long	k;
	int     sign;

	i = 0;
	k = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = 10 * k + nptr[i] - '0';
		i++;
	}
	return (k * sign);
}