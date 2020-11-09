
## how to create thread, work with in/out values
		void* say_hello(void *arg)
		{
			int	i;
			int	*count;
			int	*ret;

			i = 5;
			count = (int *)arg;
			while (i--)
			{
				sleep(2);
				ft_putendl_fd("hello", STDOUT_FILENO);
				(*count)++;
			}
			ret = (int *)malloc(sizeof(int));
			ret = 10;
			return (ret);
		}

		void	say_bye(void)
		{
			int	i;

			i = 3;
			while (i--)
			{
				sleep(1);
				ft_putendl_fd("bye", STDOUT_FILENO);
			}
		}

		int	main(void)
		{
			pthread_t newthread;
			int				count;
			int				*ret;

			count = 0;
			pthread_create(&newthread, NULL, say_hello, &count);
			say_bye();
			pthread_join(newthread, (void *)&ret);

			ft_putstr_fd("count: ", STDOUT_FILENO);
			ft_putnbr_fd(count, STDOUT_FILENO);
			ft_putendl_fd("", STDOUT_FILENO);

			ft_putstr_fd("ret: ", STDOUT_FILENO);
			ft_putnbr_fd(*ret, STDOUT_FILENO);
			ft_putendl_fd("", STDOUT_FILENO);
			free(ret);
			return (0);
		}

## Creating multiple threads

		struct sum_struct
		{
			long long limit;
			long long answer;
		};

		void* sum(void *arg)
		{
			struct sum_struct *args_struct = (struct sum_struct *)arg;

			long long sum = 0;
			for (long long i = 0; i <= args_struct->limit; i++)
				sum += i;
			args_struct->answer = sum;
			return (NULL);
		}

		int main(int ac, char **av)
		{
			int					num_ac = ac - 1;
			struct sum_struct	args[num_ac];
			pthread_t			tid[num_ac];

			for (int i = 0; i < num_ac; i++)
			{
				args[i].limit = atoll(av[i + 1]);
				pthread_create(&tid[i], NULL, sum, &args[i]);
			}
			for (int i = 0; i < num_ac; i++)
			{
				pthread_join(tid[i], NULL);
				printf("For tid %d sum is %lld\n", (int)tid[i], args[i].answer);
			}
			return (0);
		}

## how to use mutex
		#include <stdio.h>
		#define NUM_LOOPS 20000000
		long long sum = 0;
		pthread_mutex_t mutex;

		void* counting_thread(void *arg)
		{
			int offset = *(int *)arg;
			for (int i = 0; i < NUM_LOOPS; i++)
			{
				pthread_mutex_lock(&mutex);
				sum += offset;
				pthread_mutex_unlock(&mutex);
			}
			return (NULL);
		}

		int main(void)
		{
			pthread_mutex_init(&mutex, NULL);

			pthread_t tid1;
			int offset1 = 1;
			pthread_create(&tid1, NULL, counting_thread, &offset1);

			pthread_t tid2;
			int offset2 = -1;
			pthread_create(&tid2, NULL, counting_thread, &offset2);

			pthread_join(tid1, NULL);
			pthread_join(tid2, NULL);

			pthread_mutex_destroy(&mutex);

			printf("sum = %lld\n", sum);
			return (0);
		}
