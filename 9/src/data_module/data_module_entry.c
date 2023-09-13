#include <stdio.h>
#include <stdlib.h>

#include "data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"

int main(void)
{
    double *data;
    int n;
    
    //Don`t forget to allocate memory !

    input(&data, &n);

    if (normalization(data, n))
        output(data, n);
    else {
        free(data);
        printf("ERROR");
        return 1;
    }

    free(data);
    return 0;
}
