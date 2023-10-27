#include "date.h"
#include <stdio.h>

int is_valid_day(int day) {
    return day >= 1 && day <= 31;
}

int is_valid_month(int month) {
    return month >= 1 && month <= 12;
}

int is_valid_year(int year) {
    return year >= 1900 && year <= 2100;
}

int set_date(Date * d, int day, int month, int year) {
    if (!is_valid_day(day) || !is_valid_month(month) || !is_valid_year(year)) return 0;
    d->day = day;
    d->month = month;
    d->year = year;
    return 1;
}

void print_date(Date * d) {
    printf("%02d/%02d/%04d\n", d->day, d->month, d->year);
}
