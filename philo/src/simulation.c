#include "philo.h"

static void	ft_init_meals(t_philo *philos, t_data *data, long long start_time)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		pthread_mutex_lock(&data->meal_mutex);
		philos[i].last_meal_time = start_time;
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
}

static int	ft_launch_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		if (pthread_create(&philos[i].thread, NULL,
				&ft_philo_routine, &philos[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_join_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_start_simulation(t_philo *philos, t_data *data)
{
	pthread_t	monitor_thread;
	long long	start_time;

	start_time = ft_current_time();
	ft_init_meals(philos, data, start_time);
	if (ft_launch_threads(philos, data))
		return (1);
	if (pthread_create(&monitor_thread, NULL, &ft_monitor_routine, philos))
		return (1);
	if (pthread_join(monitor_thread, NULL))
		return (1);
	if (ft_join_threads(philos, data))
		return (1);
	return (0);
}
