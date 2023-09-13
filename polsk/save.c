if (tmpL->flag == 0) {
    if (tmpL->value == '.') {
        flag = -1;
    } else {
        if (flag == 1) {
            if (tmpL->value == '.') {
                flag = -1;
            } else {
                double num = (tmpL->value - '0');
                tmpL = tmpL->r;
            }
        }
    }
    if (flag == -1) {
    }
}