#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

/* colors */
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

typedef struct s_data
{
	int				amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	meal_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_eaten;
	long long		last_meal_time;
	int				left_fork;
	int				right_fork;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

/* init.c */
int	ft_initialize_data(t_data *data, int argc, char **argv);
int	ft_initialize_forks(t_data *data);
int	ft_initialize_philos(t_philo **philos, t_data *data);

/* utils.c */
int		ft_atoi(const char *str);
long long	ft_current_time(void);
int		ft_usleep(useconds_t time);
int		ft_usleep_check_stop(useconds_t time, t_data *data);
void		ft_print_message(char *str, t_philo *philo, int id);

/* actions.c */
void		ft_philo_eat(t_philo *philo);
void		ft_philo_think(t_philo *philo);
void		ft_philo_sleep(t_philo *philo);

/* simulation.c */
int		ft_start_simulation(t_philo *philos, t_data *data);

/* monitor.c */
void		*ft_philo_routine(void *philosopher);
void		*ft_monitor_routine(void *arg);

/* clean.c */
void		ft_clean(t_philo *philos, t_data *data);

#endif
