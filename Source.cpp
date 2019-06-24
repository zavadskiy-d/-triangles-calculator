/*
* @file practice.cpp
* @brief Учебная практика №1
* @autor Завадский Д.С. гр. 515Б
* @date 23.06.2019
*
* Произвольный треугольник по заданным парметрам.
*/
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#define INF -999999
//Нахождение параметров треугольника по трем сторонам
void three_sides(float, float, float, float[]);
//Нахождение параметров треугольника по одной стороне и двум углам
void side_two_corn(int, float[]);
//Нахождение параметров треугольника по двум сторонам и углу между ними
void two_sides_corn(int, float[]);
//Нахождение параметров треугольника по одной стороне и двум высотам
void side_two_h(int, float[]);
//Нахождение параметров треугольника по одной стороне и двум высотам (которые не падают на данную сторону)
void side_two_h_wrong(int, float[]);
//Нахождение параметров треугольника по двум сторонам и медиане
void two_s_med(int, float[]);
//Нахождение параметров треугольника по двум сторонам и медиане (которая не падает на данную сторону)
void two_s_med_wrong(int, float[]);
//Нахождение параметров треугольника по трем высотам
void three_h(float[]);
//Нахождение параметров треугольника по двум сторонам и площади
void two_sides_s(int, float[]);
//Нахождение параметров треугольника по трем медианам
void three_med(float[]);
//Вывод результатов расчета
void vivod(float[]);
//Нахождение параметров треугольника по двум сторонам и углу
void two_sides_corn_wrong(int indx7, float num[]);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int option[17], i;
	float a = INF, b = INF, c = INF, A = INF, B = INF, C = INF, ma = INF, mb = INF, mc = INF;
	float ha = INF, hb = INF, hc = INF, xa = INF, ya = INF, xb = INF, yb = INF, xc = INF, yc = INF, s = INF, p = INF, num[] = { INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF };
	printf("Меню\n1. Сторона а \n2. Сторона b\n3. Сторона с\n4. Угол А в градусах\n5. Угол В в градусах \n6. Угол С в градусах \n"
		"7. Медиана на сторону а \n8. Медиана на сторону b \n9. Медиана на сторону с\n"
		"10. Высота на сторону а \n11. Высота на сторону b \n12. Высота на сторону с \n13. Координаты вершины А \n"
		"14. Координаты вершины В \n15. Координаты вершины С \n16. Площадь треугольника S \n17. Полупериметр сторон треугольника р \n0. Выход\n"
		"Введите через пробел номера пунктов, которые хотите использовать (после окончания введите 0): \n");
	for (i = 0; i < 17; i++) {
		scanf("%d", &option[i]);
		if (option[i] == 0)
			break;
	}
	if (option[0] == 0) {
		return 0;
	}
	i = 0;
	system("cls");
	for (;;) {
		if (option[i] == 0)
			break;
		switch (option[i]){
		case 1: printf("Введите сторону а: "); scanf("%f", &a); num[1] = a; break;
		case 2: printf("Введите сторону b: "); scanf("%f", &b); num[2] = b; break;
		case 3: printf("Введите сторону с: "); scanf("%f", &c); num[3] = c; break;
		case 4: printf("Введите угол А в градусах: "); scanf("%f", &A); num[4] = A; break;
		case 5: printf("Введите угол В в градусах: "); scanf("%f", &B); num[5] = B; break;
		case 6: printf("Введите угол С в градусах: "); scanf("%f", &C); num[6] = C; break;
		case 7: printf("Введите медиану на сторону а: "); scanf("%f", &ma); num[7] = ma; break;
		case 8: printf("Введите медиану на сторону b: "); scanf("%f", &mb); num[8] = mb; break;
		case 9: printf("Введите медиану на сторону с: "); scanf("%f", &mc); num[9] = mc; break;
		case 10: printf("Введите высоту на сторону а: "); scanf("%f", &ha); num[10] = ha; break;
		case 11: printf("Введите высоту на сторону b: "); scanf("%f", &hb); num[11] = hb; break;
		case 12: printf("Введите высоту на сторону с: "); scanf("%f", &hc); num[12] = hc; break;
		case 13: printf("Введите координаты вершины А: "); scanf("%f %f", &xa, &ya); num[13] = xa; num[14] = ya; break;
		case 14: printf("Введите координаты вершины В: "); scanf("%f %f", &xb, &yb); num[15] = xb; num[16] = yb; break;
		case 15: printf("Введите координаты вершины С: "); scanf("%f %f", &xc, &yc); num[17] = xc; num[18] = yc; break;
		case 16: printf("Введите площадь треугольника S: "); scanf("%f", &s); break;
		case 17: printf("Введите полупериметр сторон треугольника р "); scanf("%f", &p); break;
		default: printf("Ошибка! Введен номер несуществующей опции\n"); system("pause"); return 0;
		}
		i++;
	}
	if (a > 0 && b > 0 && c > 0) {
		three_sides(a, b, c, num);
	}
	else if (a == INF || b == INF || c == INF) {
		if (s > 0){
			num[19] = s;
			if (a > 0 && b > 0){
				two_sides_s(3, num);
			}
			if (a > 0 && c > 0){
				two_sides_s(2, num);
			}
			if (c > 0 && b > 0){
				two_sides_s(1, num);
			}
		}
		if (p > 0){
			if (a > 0 && b > 0){
				c = 2 * p - a - b; three_sides(a, b, c, num);
			}
			if (a > 0 && c > 0){
				b = 2 * p - a - c; three_sides(a, b, c, num);
			}
			if (c > 0 && b > 0){
				a = 2 * p - b - c; three_sides(a, b, c, num);
			}
		}
		here:
		if (A > 0 && B > 0 && C > 0 && A + B + C == 180){
			num[1] = a; num[2] = b; num[3] = c; num[4] = A; num[5] = B; num[6] = C;
			if (a > 0){
				side_two_corn(1, num);
			}
			if (b > 0){
				side_two_corn(2, num);
			}
			if (c > 0){
				side_two_corn(3, num);
			}
		}
		if (A == INF || B == INF || C == INF) {
			if (C > 0 && B > 0) {
				A = 180 - C - B; goto here;
			}
			if (C > 0 && A > 0) {
				B = 180 - C - A; goto here;
			}
			if (A > 0 && B > 0) {
				C = 180 - A - B; goto here;
			}
			if (b > 0 && c > 0) {
				if (A > 0){
					two_sides_corn(1, num);
				}
				if (B > 0){
					two_sides_corn_wrong(1, num);
				}
				if (C > 0){
					two_sides_corn_wrong(1, num);
				}
				if (num[15] != INF && num[16] != INF && num[17] != INF && num[18] != INF && num[13] == INF && num[14] == INF){
					a = sqrt(pow(num[15] - num[17], 2) + pow(num[16] - num[18], 2));
					three_sides(a, b, c, num);
				}
				
			}
			if (a > 0 && c > 0) {
				if (A > 0){
					two_sides_corn_wrong(2, num);
				}
				if (B > 0){
					two_sides_corn(2, num);
				}
				if (C > 0){
					two_sides_corn_wrong(2, num);
				}
				if (num[15] == INF && num[16] == INF && num[17] != INF && num[18] != INF && num[13] != INF && num[14] != INF){
					b = sqrt(pow(num[13] - num[17], 2) + pow(num[14] - num[18], 2));
					three_sides(a, b, c, num);
				}
			}
			if (b > 0 && a > 0) {
				if (A > 0){
					two_sides_corn_wrong(3, num);
				}
				if (B > 0){
					two_sides_corn_wrong(3, num);
				}
				if (C > 0){
					two_sides_corn(3, num);
				}
				if (num[15] != INF && num[16] != INF && num[17] == INF && num[18] == INF && num[13] != INF && num[14] != INF){
					c = sqrt(pow(num[15] - num[13], 2) + pow(num[16] - num[14], 2));
					three_sides(a, b, c, num);
				}
			}
		}
		else {
			printf("Ошибка!\n"); system("pause"); return 0;
		}
		if (ha > 0 && hb > 0) {
			if (c > 0) {
				side_two_h(3, num);
			}
			if (a > 0) {
				side_two_h_wrong(1, num);
			}
			if (b > 0) {
				side_two_h_wrong(2, num);
			}
		}
		if (ha > 0 && hc > 0) {
			if (c > 0) {
				side_two_h_wrong(3, num);
			}
			if (a > 0) {
				side_two_h_wrong(1, num);
			}
			if (b > 0) {
				side_two_h(2, num);
			}
		}
		if (hb > 0 && hc > 0) {
			if (c > 0) {
				side_two_h_wrong(3, num);
			}
			if (a > 0) {
				side_two_h(1, num);
			}
			if (b > 0) {
				side_two_h_wrong(2, num);
			}
		}
		if (ma > 0 && mb > 0 && mc > 0){
			three_med(num);
		}
		if (ma > 0 || mb > 0 || mc > 0){
			if (a > 0 && b > 0) {
				if (ma > 0) {
					two_s_med_wrong(3, num);
				}
				if (mb > 0) {
					two_s_med_wrong(3, num);
				}
				if (mc > 0) {
					two_s_med(3, num);
				}
			}
			if (a > 0 && c > 0) {
				if (ma > 0) {
					two_s_med_wrong(2, num);
				}
				if (mb > 0) {
					two_s_med(2, num);
				}
				if (mc > 0) {
					two_s_med_wrong(2, num);
				}
			}
			if (b > 0 && c > 0) {
				if (ma > 0) {
					two_s_med(1, num);
				}
				if (mb > 0) {
					two_s_med_wrong(1, num);
				}
				if (mc > 0) {
					two_s_med_wrong(1, num);
				}
			}
		}
		if (ha > 0 && hb > 0 && hc > 0){
			num[10] = ha; num[11] = hb; num[12] = hc; three_h(num);
		}
		bool xy = true;
		for (int i = 13; i < 19; i++){
			if (num[i] == INF){
				xy = false; break;
			}
		}
		if (xy){
			a = sqrt(pow(num[17] - num[15], 2) + pow(num[18] - num[16], 2));
			b = sqrt(pow(num[13] - num[17], 2) + pow(num[14] - num[18], 2));
			c = sqrt(pow(num[13] - num[15], 2) + pow(num[14] - num[16], 2)); three_sides(a, b, c, num);
		}
	}
		printf("Ошибка!\n");
		system("pause");
	return 0;
}
void three_sides(float a, float b, float c, float num[])
{
	float A, B, C, ma, mb, mc, ha, hb, hc, s, p;
	if (a + b <= c || a + c <= b || c + b <= a) {
		printf("Невозможно образовать треугольник!\n");  system("pause"); exit(EXIT_FAILURE);
	}
	num[1] = a; num[2] = b; num[3] = c;
	if (num[7] == INF) {
		ma = (1.0 / 2)*(sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2))); num[7] = ma;
	}
	if (num[9] == INF) {
		mb = (1.0 / 2)*(sqrt(2 * pow(b, 2) + 2 * pow(a, 2) - pow(c, 2))); num[9] = mb;
	}
	if (num[8] == INF) {
		mc = sqrt(2 * pow(c, 2) + 2 * pow(a, 2) - pow(b, 2))/2; num[8] = mc;
	}
	if (num[20] == INF) {
		p = (1.0 / 2)*(a + b + c); num[20] = p;
	}
	if (num[10] == INF) {
		ha = (2 * sqrt(p * (p - a)*(p - b)*(p - c))) / a; num[10] = ha;
	}
	if (num[11] == INF) {
		hb = (2 * sqrt(p * (p - a)*(p - b)*(p - c))) / b; num[11] = hb;
	}
	if (num[12] == INF) {
		hc = (2 * sqrt(p * (p - a)*(p - b)*(p - c))) / c; num[12] = hc;
	}
	if (num[19] == INF) {
		s = sqrt(p*(p - a)*(p - b)*(p - c)); num[19] = s;
	}
	if (num[4] == INF) {
		A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b*c));
		num[4] = A; num[4] = num[4] * 180.0 / M_PI;
	}
	if (num[5] == INF) {
		B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a *c));
		num[5] = B; num[5] = num[5] * 180.0 / M_PI;
	}
	if (num[6] == INF) {
		C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b));
		num[6] = C; num[6] = num[6] * 180.0 / M_PI;
	}
	if (!(num[13] == num[15] && num[15] == num[17]) && !(num[14] == num[16] && num[16] == num[18])){
		if ((num[13] != INF && num[14] != INF) && (num[15] != INF && num[16] != INF)){
			c = sqrt(pow(num[13] - num[15], 2) + pow(num[14] - num[16], 2));
			if (c != num[3]){
				for (int i = 13; i < 19; i++){
					num[i] = INF;
				}
			}

		}
		if ((num[13] != INF && num[14] != INF) && (num[17] != INF && num[18] != INF)){
			b = sqrt(pow(num[13] - num[17], 2) + pow(num[14] - num[18], 2));
			if (b != num[2]){
				for (int i = 13; i < 19; i++){
					num[i] = INF;
				}
			}

		}
		if ((num[17] != INF && num[18] != INF) && (num[15] != INF && num[16] != INF)){
			a = sqrt(pow(num[17] - num[15], 2) + pow(num[18] - num[16], 2));
			if (a != num[1]){
				for (int i = 13; i < 19; i++){
					num[i] = INF;
				}
			}

		}
	}
	vivod(num);
}
void side_two_corn(int indx, float num[])
{
	
	switch (indx){
	case 2: num[5] = (num[5] * M_PI) / 180.0; num[4] = (num[4] * M_PI) / 180.0; num[6] = (num[6] * M_PI) / 180.0; num[1] = (num[2] * sin(num[4])) / (sin(num[5])); num[3] = (num[2] * sin(num[6])) / (sin(num[5])); num[5] = (num[5] * 180.0) / M_PI; num[4] = (num[4] * 180.0) / M_PI; num[6] = (num[6] * 180.0) / M_PI; break;
	case 1: num[5] = (num[5] * M_PI) / 180.0; num[4] = (num[4] * M_PI) / 180.0; num[6] = (num[6] * M_PI) / 180.0; num[2] = (num[1] * sin(num[5])) / (sin(num[4])); num[3] = (num[1] * sin(num[6])) / (sin(num[4])); num[5] = (num[5] * 180.0) / M_PI; num[4] = (num[4] * 180.0) / M_PI; num[6] = (num[6] * 180.0) / M_PI; break;
	case 3: num[5] = (num[5] * M_PI) / 180.0; num[4] = (num[4] * M_PI) / 180.0; num[6] = (num[6] * M_PI) / 180.0; num[2] = (num[3] * sin(num[5])) / (sin(num[6])); num[1] = (num[3] * sin(num[4])) / (sin(num[6])); num[5] = (num[5] * 180.0) / M_PI; num[4] = (num[4] * 180.0) / M_PI; num[6] = (num[6] * 180.0) / M_PI; break;
	}
	three_sides(num[1], num[2], num[3], num);
}
void two_sides_corn(int indx2, float num[])
{
	switch (indx2){
	case 1:num[4] = (num[4] * M_PI) / 180.0; num[1] = sqrt(pow(num[2], 2) + pow(num[3], 2) - 2 * num[2] * num[3] * cos(num[4])); num[4] = num[4] * 180.0 / M_PI; break;
	case 2:num[5] = (num[5] * M_PI) / 180.0; num[2] = sqrt(pow(num[1], 2) + pow(num[3], 2) - 2 * num[1] * num[3] * cos(num[5])); num[5] = num[5] * 180.0 / M_PI; break;
	case 3:num[6] = (num[6] * M_PI) / 180.0; num[3] = sqrt(pow(num[1], 2) + pow(num[2], 2) - 2 * num[1] * num[2] * cos(num[6])); num[6] = num[6] * 180.0 / M_PI; break;
	}
	three_sides(num[1], num[2], num[3], num);
}
void side_two_h(int indx3, float num[])
{
	switch (indx3){
	case 1: num[6] = asin(num[11] / num[1]); num[5] = asin(num[12] / num[1]); num[4] = 180 - num[5] - num[6]; break;
	case 2: num[4] = asin(num[10] / num[2]); num[6] = asin(num[12] / num[2]); num[5] = 180 - num[4] - num[6]; break;
	case 3: num[4] = asin(num[11] / num[3]); num[5] = asin(num[10] / num[3]); num[6] = 180 - num[5] - num[4]; break;
	}
	side_two_corn(indx3, num);
}
void side_two_h_wrong(int indx4, float num[])
{
	float ss;
	switch (indx4){
	case 1: if (num[11] > 0){
		ss = num[11] / num[1]; num[6] = asin(ss) * 180.0 / M_PI; num[2] = num[10] / ss; two_sides_corn(3, num);
	}
			else
	{
		ss = num[12] / num[1]; num[5] = asin(ss) * 180.0 / M_PI; num[3] = num[10] / ss; 
		two_sides_corn(2, num);
	}		break;
	case 2: if (num[10] > 0){
		ss = num[10] / num[2]; num[6] = asin(ss) * 180.0 / M_PI;
		num[1] = num[11] / ss; two_sides_corn(3, num);
	}
			else
	{
		ss = num[12] / num[2]; num[4] = asin(ss) * 180.0 / M_PI;
		num[3] = num[10] / ss; two_sides_corn(1, num);
	} break;
	case 3: if (num[10] > 0){
		ss = num[10] / num[3]; num[5] = asin(ss) * 180.0 / M_PI;
		num[3] = num[10] / ss; two_sides_corn(2, num);
	}
			else
	{
		ss = num[11] / num[3]; num[4] = asin(ss) * 180.0 / M_PI;
		num[2] = num[12] / ss; two_sides_corn(1, num);
	}break;
	}
}
void two_s_med(int indx5, float num[])
{
	switch (indx5){
	case 1: num[1] = sqrt(2 * pow(num[2], 2) + 2 * pow(num[3], 2) - pow(2 * num[7], 2)); three_sides(num[1], num[2], num[3], num); break;
	case 2:	num[2] = sqrt(2 * pow(num[1], 2) + 2 * pow(num[3], 2) - pow(2 * num[8], 2)); three_sides(num[1], num[2], num[3], num); break;
	case 3:	num[3] = sqrt(2 * pow(num[2], 2) + 2 * pow(num[1], 2) - pow(2 * num[9], 2)); three_sides(num[1], num[2], num[3], num); break;
	}
}
void two_s_med_wrong(int indx6, float num[])
{
	switch (indx6){
	case 1: if (num[8] > 0){
		num[1] = sqrt((pow(num[2], 2) + pow(2 * num[8], 2) - 2 * pow(num[3], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			else
	{
		num[1] = sqrt((pow(num[3], 2) + pow(2 * num[9], 2) - 2 * pow(num[2], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			break;
	case 2:	 if (num[7] > 0){
		num[2] = sqrt((pow(num[1], 2) + pow(2 * num[7], 2) - 2 * pow(num[3], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			else
	{
		num[2] = sqrt((pow(num[3], 2) + pow(2 * num[9], 2) - 2 * pow(num[1], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			break;
	case 3:	 if (num[7] > 0){
		num[3] = sqrt((pow(num[1], 2) + pow(2 * num[7], 2) - 2 * pow(num[2], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			else
	{
		num[3] = sqrt((pow(num[2], 2) + pow(2 * num[8], 2) - 2 * pow(num[1], 2)) / 2);  three_sides(num[1], num[2], num[3], num);
	}
			break;
	}
}
void three_med(float num[])
{
	num[1] = (2.0 / 3) * sqrt(2 * ((pow(num[8], 2) + pow(num[9], 2)) - pow(num[7], 2)));
	num[2] = (2.0 / 3) * sqrt(2 * ((pow(num[7], 2) + pow(num[9], 2)) - pow(num[8], 2)));
	num[3] = (2.0 / 3) * sqrt(2 * ((pow(num[7], 2) + pow(num[8], 2)) - pow(num[9], 2)));
	three_sides(num[1], num[2], num[3], num);
}
void vivod(float num[])
{
	printf(" a: %.3f\n", num[1]); printf(" b: %.3f\n", num[2]);
	printf(" c: %.3f\n", num[3]); printf(" A: %.3f\n", num[4]);
	printf(" B: %.3f\n", num[5]); printf(" C: %.3f\n", num[6]);
	printf(" ma: %f\n", num[7]); printf(" mb: %f\n", num[8]);
	printf(" mc: %f\n", num[9]); printf(" ha: %f\n", num[10]);
	printf(" hb: %f\n", num[11]); printf(" hc: %f\n", num[12]);
	if (num[13] != INF){
		printf(" xa: %f\n", num[13]);
	}
	if (num[14] != INF){
		printf(" ya: %f\n", num[14]);
	}
	if (num[15] != INF){
		printf(" xb: %f\n", num[15]);
	}
	if (num[16] != INF){
		printf(" yb: %f\n", num[16]);
	}
	if (num[17] != INF){
		printf(" xc: %f\n", num[17]);
	}
	if (num[18] != INF){
		printf(" yc: %f\n", num[18]);
	}
	printf(" S: %f\n", num[19]); printf(" p: %f\n", num[20]);
	system("pause"); exit(0);
}
void two_sides_s(int n, float num[])
{
	switch (n){
	case 1: num[11] = 2 * num[19] / num[2]; num[12] = 2 * num[19] / num[3]; side_two_h_wrong(2, num); break;
	case 2: num[10] = 2 * num[19] / num[1]; num[12] = 2 * num[19] / num[3]; side_two_h_wrong(3, num); break;
	case 3: num[11] = 2 * num[19] / num[2]; num[10] = 2 * num[19] / num[1]; side_two_h_wrong(1, num); break;
	}
}
void three_h(float num[])
{
	float s, a, b, c;
	s = pow(num[11] * num[10] * num[12], 2) / sqrt(2 * pow(num[11] * num[10] * num[12], 2)*(pow(num[10], 2) + pow(num[11], 2) + pow(num[12], 2)) - (pow(num[10], 4)*pow(num[11], 4) + pow(num[10], 4)*pow(num[12], 4) + pow(num[11], 4)*pow(num[12], 4)));
	a = 2 * s / num[10]; b = 2 * s / num[11]; c = 2 * s / num[12]; three_sides(a, b, c, num);
}
void two_sides_corn_wrong(int indx7, float num[])
{
	switch (indx7){
	case 1: if (num[5] > INF){
		num[5] = (num[5] * M_PI) / 180.0;
		num[6] = asin(num[3] * sin(num[5]) / num[2]) * 180.0 / M_PI;
		num[5] = num[5] * 180.0 / M_PI; num[4] = 180 - num[5] - num[6];
		two_sides_corn(1, num);
	}
			else
	{
		num[6] = (num[6] * M_PI) / 180.0;
		num[5] = asin(num[2] * sin(num[6]) / num[3]) * 180.0 / M_PI;
		num[6] = num[6] * 180.0 / M_PI; num[4] = 180 - num[5] - num[6];
		two_sides_corn(1, num);
	}

	case 2:  if (num[4] > INF){
		num[4] = (num[4] * M_PI) / 180.0;
		num[6] = asin(num[3] * sin(num[4]) / num[1]) * 180.0 / M_PI;
		num[4] = num[4] * 180.0 / M_PI; num[5] = 180 - num[4] - num[6];
		two_sides_corn(2, num);
	}
			 else
	{
		num[6] = (num[6] * M_PI) / 180.0;
		num[4] = asin(num[1] * sin(num[6]) / num[3]) * 180.0 / M_PI;
		num[6] = num[6] * 180.0 / M_PI; num[5] = 180 - num[4] - num[6];
		two_sides_corn(2, num);
	}
	case 3:  if (num[4] > INF){
		num[4] = (num[4] * M_PI) / 180.0;
		num[5] = asin(num[2] * sin(num[4]) / num[1]) * 180.0 / M_PI;
		num[4] = num[4] * 180.0 / M_PI; num[6] = 180 - num[5] - num[4];
		two_sides_corn(3, num);
	}
			 else
	{
		num[5] = (num[5] * M_PI) / 180.0;
		num[4] = asin(num[1] * sin(num[5]) / num[2]) * 180.0 / M_PI;
		num[5] = num[5] * 180.0 / M_PI; num[6] = 180 - num[5] - num[4];
		two_sides_corn(3, num);
	}
	}
}