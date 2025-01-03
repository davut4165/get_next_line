#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include"ft_get_next_line.h"
#include<stdlib.h>
int main()
{
    char    *line;
    int fd;
    
    fd = open("sas.txt",O_RDONLY);
    // line = ft_get_next_line(fd);
    // printf("%s",line);
    // line = ft_get_next_line(fd);
    // printf("%s",line);
    // line = ft_get_next_line(fd);
    // printf("%s",line);
    while((line = ft_get_next_line(fd)))
    {
        printf("%s",line);
        free(line);
    }
}
