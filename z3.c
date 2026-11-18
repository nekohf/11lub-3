#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct tovar
{
    char name[50];
    int day_proizv;
    int mesyac_proizv;
    int god_proizv;
    int srog_godnosti;
    float price;
    char seria[20];
};
typedef struct tovar TOVAR;
int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_CTYPE, "rus");

    TOVAR product;
    printf("--- Ввод данных о товаре ---\n");

    printf("Введите наименование (одним словом): ");
    scanf("%s", product.name);

    printf("Введите дату производства (день месяц год через пробел): ");
    scanf("%d %d %d", &product.day_proizv, &product.mesyac_proizv, &product.god_proizv);

    printf("Введите срок годности (в месяцах): ");
    scanf("%d", &product.srog_godnosti);

    printf("Введите цену: ");
    scanf("%f", &product.price);

    printf("Введите номер серии: ");
    scanf("%s", product.seria);

    int posl_day = product.day_proizv;
    int posl_mesyac = product.mesyac_proizv + product.srog_godnosti;
    int posl_god = product.god_proizv;

    posl_god += (posl_mesyac - 1) / 12;
    posl_mesyac = (posl_mesyac - 1) % 12 + 1;

    printf("\n--- Результат по заданию ---\n");
    printf("Наименование товара: %s\n", product.name);
    printf("Конечная дата применения (годен до): %02d.%02d.%d\n", posl_day, posl_mesyac, posl_god);
    return 0;
}
