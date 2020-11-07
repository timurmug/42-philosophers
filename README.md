
## how to create thread, work with in/out values
		void \*say_hello(void *arg)
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
			return (0);
		}
