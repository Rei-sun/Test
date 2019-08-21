#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdarg.h>
#include<string.h>

#define MAINSIZE 511
#define SUBSIZE 127
#define D1SIZE 40
#define D2SIZE 20

void format_output(char *string, char *fmt, ...) {
	va_list arg;
	va_start(arg, fmt);
	vsprintf(string, fmt, arg);
	va_end(arg);
}

void join_string(char *str1,const char *str2) {
	strcat(str1, str2);
}

int main() {
	char str[MAINSIZE] = {'\0'}, sub[SUBSIZE] = {'\0'};
	char table[D2SIZE][D1SIZE] = {'\0'};
	int i, j, k=0;

	for (i = 0; i < 11;i++) {
		for (j = 0; j < 10;j++) {
			if (i == 0) {
				char f[] = "%2d ";
				format_output(sub, f, j);
				join_string(str, sub);
				//printf("%2d ", j);
			}else if (i == 1) {
				char f[] = "%s";
				format_output(sub, f, "---");
				join_string(str, sub);
				//printf("---");
			}else {
				if (j == 0) {
					char f[] = "%2d|";
					format_output(sub, f, k);
					join_string(str, sub);
					//printf("%2d|", k);
				}
				else {
					char f[] = "%2d ";
					format_output(sub, f, k*j);
					join_string(str, sub);
					//printf("%2d ", k*j);
				}
			}
		}
		k++;
		char f[] = "%s";
		format_output(sub, f, "\n");
		join_string(str, sub);
		//printf("\n");
		if (i == 1) k = 1;
	}
	j = 0;
	k = 0;
	// strをtableに改行コードで分ける
	for (i = 0; i < MAINSIZE;i++) {
		table[j][k] = str[i];
		k++;
		if (str[i] == '\n') {
			j++;
			k = 0;
		}
	}
	// tableから一文字ずつ出力
	for (i = 0; i < D2SIZE;i++) {
		for (j = 0; j < D1SIZE; j++) {
			printf("%c", table[i][j]);
			if (table[i][j] == '\n') break;
		}
		if (table[i][j] == '\0') break;
	}
}
