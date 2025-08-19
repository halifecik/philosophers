#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		ret = ret * 10 + (str[i++] - 48);
	return (ret * sign);
}

long long	ft_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep_check_stop(useconds_t time, t_data *data)
{
	long long	start;

	start = ft_current_time();
	while ((ft_current_time() - start) < time)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->data_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->data_mutex);
		usleep(100);
	}
	return (0);
}

int	ft_usleep(useconds_t time)
{
	long long	start;

	start = ft_current_time();
	while ((ft_current_time() - start) < time)
		usleep(100);
	return (0);
}

void	ft_print_message(char *str, t_philo *philo, int id)
{
	long long	time;

	pthread_mutex_lock(&philo->data->data_mutex);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->data_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->data_mutex);
	time = ft_current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lld %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
