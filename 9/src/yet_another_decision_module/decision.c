#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int make_decision(double *data, int n)
{
    int decision = 1;

    double m = mean(data, n);
    double sigma = sqrt(variance(data, n));
    double max_value = MaxSearch(data, n);
    double min_value = MinSearch(data, n);

    decision &= (max_value <= m + 3*sigma) &&
                (min_value >= m - 3*sigma) &&
                (m >= GOLDEN_RATIO);

    return decision;
}
