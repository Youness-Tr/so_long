#include <stdio.h>

typedef struct test
 {
    int x;
    int y;
}   t_var;


t_var mlxini(void)
{
    t_var data;
    data.y = 13;
    data.x = 88;
    return(data);
}

#include <stdlib.h>

int main()
{
    //void;
    t_var data;

    void* mlx = mlxini();
   //data = malloc (sizeof(t_var));
    //x(data);
   //data = y(data);

    printf("%d", data.x);
}
