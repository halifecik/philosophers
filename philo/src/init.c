#include "philo.h"

int	ft_initialize_data(t_data *data, int argc, char **argv)
{
	data->amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->stop = 0;
	data->start_time = ft_current_time();
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->data_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (1);
	return (0);
}

int	ft_initialize_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->amount);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->amount)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_initialize_philos(t_philo **philos, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->amount);
	if (!*philos)
		return (1);
	i = 0;
	while (i < data->amount)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eating = 0;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = data->start_time;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % data->amount;
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
