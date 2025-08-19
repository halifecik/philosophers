#include "philo.h"

static int	ft_philo_take_fork(t_philo *philo)
{
	if (philo->data->amount == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_print_message("has taken a fork", philo, philo->id);
		ft_usleep(philo->data->time_to_die + 1000);
		return (0);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_print_message("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_print_message("has taken a fork", philo, philo->id);
	}
	return (1);
}

void	ft_philo_eat(t_philo *philo)
{
	if (!ft_philo_take_fork(philo))
		return ;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->eating = 1;
	philo->last_meal_time = ft_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_print_message("is eating", philo, philo->id);
	ft_usleep_check_stop(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void	ft_philo_think(t_philo *philo)
{
	ft_print_message("is thinking", philo, philo->id);
	if (philo->data->amount > 1)
		ft_usleep(1);
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_print_message("is sleeping", philo, philo->id);
	ft_usleep_check_stop(philo->data->time_to_sleep, philo->data);
}
