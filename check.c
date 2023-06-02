
int ft_check_doupple(char **str, int n)
{
    int i;
    int key;
    
    key = 0;
    i = 0;
    while(str[i])
    {
        if(str[i] == n)
            key++;
        i++;
    }
    if(key == 1)
        return (0);
    else
        return (1);
}

void check_args(int ac, char **av)
{
    int i;
    char **test;

    if(ac == 2)
        test = ft_split(av[1], ' ');
    else if (ac > 2)
    {
        i = 1;
        test = av;
    }
    while (test[i])
    {
        int j;
        j = ft_atoi(test[i]);
        if(!ft_isnum(j))
            return_error("check your args, it have to be a number\n");
        else if (ft_check_doupple(test, test[i]) == 1)
            return_error("check your args, it contains doupple numbers\n");
        
    }
    


}