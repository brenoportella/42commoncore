void    ft_bzero(void *s, unsigned int n);

void    ft_bzero(void *s, unsigned int n)
{
    unsigned char *ptr;
    unsigned int i;

    if (s == 0 || n <= 0)
    return;

    ptr = (unsigned char *)s; //converting the generic pointer to unsigned char
    i = 0;

    while(i < n)
    {
        ptr[i] = 0;
        i++;
    }

}
/*
#include <stdio.h>
#include <strings.h>
int main(void)
{
    char str[] = "breno";
    printf("%s \n", str);
    ft_bzero(str, 3);
    printf("%s \n", str);

}
*/