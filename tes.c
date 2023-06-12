
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



static int	count_c(char const *s, char c);
static char	**put_array(char **my_array, int counter, char const *s, char c);
static char	*get_str(char const *s, char c);


typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
}					t_list;




char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


static char	*get_str(char const *s, char c)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	while (*s == c)
		s++;
	tmp = ft_strchr(s, c);
	if (!tmp)
		len = ft_strlen(s);
	else
		len = tmp - s;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
static char	**put_array(char **my_array, int counter, char const *s, char c)
{
	int		i;
	size_t	z;
	char	*tmp;

	i = -1;
	while (++i < counter)
	{
		tmp = get_str(s, c);
		my_array[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (!my_array[i])
			return (NULL);
		z = -1;
		while (++z < ft_strlen(tmp))
			my_array[i][z] = tmp[z];
		my_array[i][z] = '\0';
		if (!(i == counter - 1))
		{
			while (*s == c)
				s++;
			s += ft_strlen(tmp) + 1;
		}
		free(tmp);
	}
	my_array[i] = NULL;
	return (my_array);
}




char	**ft_split(const char *s, char c)
{
	char	**my_array;
	int		counter;

	if (!s)
		return (NULL);
	counter = count_c(s, c);
	my_array = malloc(sizeof(char *) * (counter + 1));
	if (!my_array)
		return (NULL);
	my_array = put_array(my_array, counter, s, c);
	return (my_array);
}

int	count_c(char const *s, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[z])
	{
		if (s[z] == c && s[z + 1] != c && s[z + 1] != '\0')
			i++;
		if (s[z] != c && i == 0)
			i++;
		z++;
	}
	return (i);
}



t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while(tmp->next)
	{
		tmp = tmp->next;
		if(tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_lstsize(t_list *lst)
{
	size_t i;
	t_list *tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *) malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = content;
	new->index = -1;
	new -> next = NULL;
	return (new);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if(*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_number(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i++])
		if (!ft_isdigit(n[i]))
			return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int sign = 1;
	long result = 0;
	int i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_stack(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

static void swap(t_list **stack)
{
    t_list *tmp;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void    sa(t_list **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_list **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}
static void revers_rotate(t_list **stack)
{
    t_list *tmp;
    t_list *bottom;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    bottom = ft_lstlast(*stack);
    while((*stack)->next->next)
        *stack = (*stack)->next;
    bottom->next = tmp;
    (*stack)->next = NULL;
    *stack = bottom;
    //ft_lstadd_front(stack, tmp);

}

void    rra(t_list **stack_a)
{
    revers_rotate(stack_a);
    write(1, "rra\n", 3);
}

void    rrb(t_list **stack_b)
{
    revers_rotate(stack_b);
    write(1, "rrb\n", 3);
}


void    rrr(t_list **stack_a, t_list **stack_b)
{
    revers_rotate(stack_a);
    revers_rotate(stack_b);
    write(1, "rrr\n", 3);
}

// void    pa(t_list **stack_a, t_list **stack_b)
// {
//     t_list *tmp;

//     if(!(*stack_b))
//         return ;
//     tmp = (*stack_b)->next;
//     (*stack_b)->next = *stack_a;
//     *stack_a = *stack_b;
// 	*stack_b = tmp;
//     write(1, "pa\n", 3);
// }

void pa(t_list **stack_a, t_list **stack_b)
{
    if (!(*stack_b))
        return;

    t_list *tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, tmp);
    
    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if(!(*stack_a))
        return ;
    tmp = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
	*stack_a = tmp;
    write(1, "pb\n", 3);
}
static void rotate(t_list **stack)
{
    t_list *tmp;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    printf("stack->value = %d\n\n", (*stack)->value);
    printf("tmp = *stack\n");
    printf("tmp->value = %d\n", tmp->value);
    *stack = (*stack)->next;
    ft_lstadd_back(stack, tmp);
}

void    ra(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}


void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}


void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void return_error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(0);
}


int	ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				p_m;

	i = 0;
	p_m = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		p_m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0 && p_m == -1 && nb)
			return (0);
		if (nb < 0 && p_m == 1)
			return (-1);
		i++;
	}
	return (nb * p_m);
}

int ft_check_doupple(char **str, int n)
{
    //printf("-----Check_doupple\n");
    int i;
    int key;
    
    key = 0;
    i = 0;
    while(str[i])
    {
        int num;
        num = ft_atoi(str[i]);
        if(num == n)
        {
            key++;
            if(key > 1)
                return (1);
        }
        i++;
    }
    return (0);
}

void check_args(int ac, char **av)
{
    printf("check_args\n");
    int i;
    char **test;

    if(ac == 2)
    {
        //printf("-TEST1\n");
        //printf("av[1] = %s\n", av[1]);
        i = 0;
        test = ft_split(av[1], ' ');
        //printf("pause\n");
        //for (size_t j = 0; test[j]; j++)
        //    printf("test = %s\n", test[j]);
        //printf("after for\n");
    }
    else if (ac > 2)
    {
        //printf("--TEST2\n");
        i = 1;
        test = av;
    }
    //printf("---TEST3\n");
    while (test[i])
    {
        //printf("---TEST6\n");
        if(ft_is_number(test[i]) == 0)
            return_error("check your args, it have to be a number\n");
        if(ft_atol(test[i]) >= 2147483647 || ft_atol(test[i]) < -2147483648)
            return_error("check your args, INT_MAX or -INT_MAX\n");
        if (ft_check_doupple(test, ft_atoi(test[i])) != 0)
            return_error("check your args, it contains doupple numbers\n");
        //write(1, "Hallo\n", 6);
        i++;
    }
    if(ac == 2)
        free(test);
}

int check_sorted(t_list **stack)
{
    t_list  *tmp;

    tmp = *stack;
    while(tmp && tmp->next)
    {
        if(tmp->value > tmp->next->value)
            return(0);
        tmp = tmp->next;
    }
    return (1);
}

void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> %d", list->value, list->flag);
        list = list->next;
    }
    printf("\n");
}

static void	init_stack(t_list **stack_a, int ac, char **av)
{
    printf("init\n");
	char	**str;
    //t_list *new;
    int hm;
	int		i;

    str = NULL;
	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		//printf("after split\n");
        // for (size_t j = 0; str[j]; j++)
        //     printf("test = %s\n", str[j]);
		while (str[i])
		{
            //new = ft_lstnew(ft_atoi(str[i]));
		    //printf("in while\n");
            hm = ft_atoi(str[i]);
            //printf("hm = %d\n", hm);
			ft_lstadd_back(stack_a, ft_lstnew(hm));
		    //printf("after list1\n");
            i++;
		}
		free(str);
	}
	else
	{
		//printf("elseeee\n");
		i = 1;
		while (i < ac)
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
		    //printf("after list2\n");
			i++;
		}
	}
}

int	main(int ac, char **av)
{
    printf("main\n");
	//char **arg_temp;
	t_list **stack_a;
	t_list **stack_b;
	if (ac < 2)
		return (1);
	check_args(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
	if(!stack_a || !stack_b)
	    return (0);
	init_stack(stack_a, ac, av);

	//printf("fertig\n");
    /*
    printf("stack a :\n");
    print_list(*stack_a);



    ra(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);
	//start_sort(stack_a, stack_b);
    sa(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);
    */


    sa(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);

    // ra(stack_a);
    // printf("stack a :\n");
    // print_list(*stack_a);

    ra(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);

	rra(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);

	rra(stack_a);
    printf("stack a :\n");
    print_list(*stack_a);


	pa(stack_a, stack_b);
    printf("stack a :\n");
    print_list(*stack_a);
	printf("\n\n");
	printf("stack b :\n");
    print_list(*stack_b);



	pb(stack_a, stack_b);
    printf("stack a :\n");
    print_list(*stack_a);
	printf("\n\n");
	printf("stack b :\n");
    print_list(*stack_b);


	pb(stack_a, stack_b);
    printf("stack a :\n");
    print_list(*stack_a);
	printf("\n\n");
	printf("stack b :\n");
    print_list(*stack_b);


	pa(stack_a, stack_b);
    printf("stack a :\n");
    print_list(*stack_a);
	printf("\n\n");
	printf("stack b :\n");
    print_list(*stack_b);
	return (0);
}