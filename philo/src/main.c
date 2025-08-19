#include "philo.h"

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_argument(int ac, char **av)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (!ft_is_number(av[i]) || ft_atoi(av[i]) <= 0)
			{
				printf(MAGENTA);
				printf("Invalid Argument: Use positive integers only!");
				printf(RESET);
				return (1);
			}
			i++;
		}
		return (0);
	}
	printf(MAGENTA);
	printf("Usage: %s number_of_philosophers", av[0]);
	printf(" time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]");
	printf(RESET);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (ft_check_argument(ac, av))
		return (1);
	if (ft_initialize_data(&data, ac, av))
		return (1);
	if (ft_initialize_forks(&data))
		return (1);
	if (ft_initialize_philos(&philos, &data))
	{
		ft_clean(philos, &data);
		return (1);
	}
	if (ft_start_simulation(philos, &data))
	{
		ft_clean(philos, &data);
		return (1);
	}
	ft_clean(philos, &data);
	return (0);
}
