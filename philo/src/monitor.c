#include "philo.h"

static int	ft_check_death(t_philo *philos, int index)
{
	long long	time;

	pthread_mutex_lock(&philos->data->meal_mutex);
	time = ft_current_time() - philos[index].last_meal_time;
	if (time >= philos->data->time_to_die && !philos[index].eating)
	{
		pthread_mutex_unlock(&philos->data->meal_mutex);
		pthread_mutex_lock(&philos->data->data_mutex);
		philos->data->stop = 1;
		pthread_mutex_unlock(&philos->data->data_mutex);
		time = ft_current_time() - philos->data->start_time;
		pthread_mutex_lock(&philos->data->print_mutex);
		printf("%lld %d died\n", time, philos[index].id);
		pthread_mutex_unlock(&philos->data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philos->data->meal_mutex);
	return (0);
}

static int	ft_check_meals(t_philo *philos)
{
	int	i;
	int	finished_eating;

	if (philos->data->must_eat == -1)
		return (0);
	finished_eating = 0;
	i = 0;
	while (i < philos->data->amount)
	{
		pthread_mutex_lock(&philos->data->meal_mutex);
		if (philos[i].meals_eaten >= philos->data->must_eat)
			finished_eating++;
		pthread_mutex_unlock(&philos->data->meal_mutex);
		i++;
	}
	if (finished_eating == philos->data->amount)
	{
		pthread_mutex_lock(&philos->data->data_mutex);
		philos->data->stop = 1;
		pthread_mutex_unlock(&philos->data->data_mutex);
		return (1);
	}
	return (0);
}

static int	ft_check_stop_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->data_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->data_mutex);
	return (0);
}

void	*ft_philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (1)
	{
		if (ft_check_stop_condition(philo))
			break ;
		ft_philo_eat(philo);
		if (ft_check_stop_condition(philo))
			break ;
		ft_philo_sleep(philo);
		if (ft_check_stop_condition(philo))
			break ;
		ft_philo_think(philo);
	}
	return (NULL);
}

void	*ft_monitor_routine(void *arg)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)arg;
	usleep(1000);
	while (1)
	{
		if (ft_check_meals(philos))
			return (NULL);
		i = 0;
		while (i < philos->data->amount)
		{
			if (ft_check_death(philos, i))
				return (NULL);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
