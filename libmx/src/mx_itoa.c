#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int len = 0;
    bool flag = false;
    int start = 0;

    if (number == 0) {
        return "0";
    }
    else if (number == -214748364) {
        return "-214748364";
    }
    
    if (number < 0) {
        number *= -1;
        flag = true;
        start++;
    }

    int temp = number;
    while (temp > 1) {
        temp /= 10;
        len++;
    }
    
    char *num_str = mx_strnew(4 * (len + start));

    if (flag) {
        num_str[0] = '-';
    }

    for (int i = len - 1 + start; i >= start; i--) {
        num_str[i] = number % 10 + '0';
        number /= 10;
    }

    return num_str;
}
