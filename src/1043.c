#include <stdio.h>

#include <memory.h>

#pragma warning(disable:4996)

 

int main() {

    int n, m, stack[1000], top = 0, check[100], know[100], k, part_c[100], party[100][100], p = 0;

    scanf("%d %d %d", &n, &m, &k);

    

    memset(know, 0, sizeof(know));

    memset(check, 0, sizeof(check));

    memset(part_c, 0, sizeof(part_c));

    

    for (int i = 0; i < k; i++) {

        scanf("%d", &stack[top++]);

        know[stack[top - 1]] = 1;

    }

    for (int i = 0; i < m; i++) {

        scanf("%d", &party[i][0]);

        for (int j = 1; j <= party[i][0]; j++) {

            scanf("%d", &party[i][j]);

        }

    }

    for (int i = 0;;i++) {

        if (top == 0) break;

        int num = stack[--top];

        for (int j = 0; j < m; j++) {

            if (part_c[j]) continue;

            for (int t = 1; t <= party[j][0]; t++) {

                if (party[j][t] == num) {

                    ++p; part_c[j] = 1;

                    for (int c = 1; c <= party[j][0]; c++) {

                        if (know[party[j][c]]) continue;

                        know[party[j][c]] = 1;

                        stack[top++] = party[j][c];

                    }

                    break;

                }

            }

        }

    }

    

    printf("%d\n", m - p);

    return 0;

}