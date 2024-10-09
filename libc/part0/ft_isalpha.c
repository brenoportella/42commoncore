int ft_isalpha(int c);

int ft_isalpha(int c)
{
    if((c >= 97 && c <= 122) || (c >= 41 && c <= 90))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}