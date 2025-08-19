#include "philo.h"

void	ft_clean(t_philo *philos, t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->amount)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->data_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	if (philos)
		free(philos);
}
