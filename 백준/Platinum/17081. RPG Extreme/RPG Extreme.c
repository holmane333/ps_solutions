#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

typedef enum pendant {
	HR = 0,
	RE,
	CO,
	EX,
	DX,
	HU,
	CU
} pendant;

int n, m, mcnt, bcnt, ix, iy;
char map[200][200], dir[10000];
char mname[200][200][15], bname[200][200][5];
int mstat[200][200][6], bstat[200][200], pen, pencnt;
int maxhp, hp, ad, df, lv, maxexp, exp, w, a;

void printres(int turn, int c, int x, int y) {
	for (int i = 1; i <= n; ++i) printf("%s\n", map[i] + 1);
	printf("Passed Turns : %d\n", turn);
	printf("LV : %d\n", lv);
	printf("HP : %d/%d\n", hp, maxhp);
	printf("ATT : %d+%d\n", ad, w);
	printf("DEF : %d+%d\n", df, a);
	printf("EXP : %d/%d\n", exp, maxexp);
	if (c == 1) printf("YOU WIN!\n");
	else if (c == 2) 
		if (map[x][y] == '^') printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..\n");
		else printf("YOU HAVE BEEN KILLED BY %s..\n", mname[x][y]);
	else printf("Press any key to continue.\n");
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", map[i] + 1);
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] == '&' || map[i][j] == 'M') ++mcnt;
			else if (map[i][j] == 'B') ++bcnt;
			else if (map[i][j] == '@') {
				ix = i;
				iy = j;
				map[i][j] = '.';
			}
		}
	}
	scanf("%s", dir + 1);
	for (int i = 1; i <= mcnt; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%s", mname[x][y]);
		scanf("%d %d %d %d", &mstat[x][y][1], &mstat[x][y][2], &mstat[x][y][3], &mstat[x][y][4]);
	}
	for (int i = 1; i <= bcnt; ++i) {
		int x, y;
		char name[5];
		scanf("%d %d", &x, &y);
		scanf("%s", bname[x][y]);
		if (bname[x][y][0] == 'O') {
			scanf("%s", name);
			if (name[0] == 'H' && name[1] == 'R') bstat[x][y] = 0;
			if (name[0] == 'R' && name[1] == 'E') bstat[x][y] = 1;
			if (name[0] == 'C' && name[1] == 'O') bstat[x][y] = 2;
			if (name[0] == 'E' && name[1] == 'X') bstat[x][y] = 3;
			if (name[0] == 'D' && name[1] == 'X') bstat[x][y] = 4;
			if (name[0] == 'H' && name[1] == 'U') bstat[x][y] = 5;
			if (name[0] == 'C' && name[1] == 'U') bstat[x][y] = 6;
		}
		else scanf("%d", &bstat[x][y]);
	}

	int x = ix, y = iy, dirlen = strlen(dir + 1);
	maxhp = 20, hp = 20, ad = 2, df = 2, lv = 1, maxexp = 5 * lv, exp = 0, w = 0, a = 0;
	
	for (int i = 1; i <= dirlen; ++i) {
		int dx, dy;
		if (dir[i] == 'R') {
			dx = x;
			dy = y + 1;
		}
		else if (dir[i] == 'L') {
			dx = x;
			dy = y - 1;
		}
		else if (dir[i] == 'U') {
			dx = x - 1;
			dy = y;
		}
		else {
			dx = x + 1;
			dy = y;
		}
		if (dx <= 0 || dx > n || dy <= 0 || dy > m) {
			if (map[x][y] == '^') {
				if (pen & (1 << DX)) hp -= 1;
				else hp -= 5;
				if (hp <= 0) {
					if (pen & (1 << RE)) {
						hp = maxhp;
						x = ix;
						y = iy;
						pen &= ~(1 << RE);
						--pencnt;
						continue;
					}
					hp = 0;
					printres(i, 2, x, y);
					return 0;
				}
			}
		}
		else if (map[dx][dy] == '.') {
			if (map[x][y] != '^') map[x][y] = '.';
			x = dx;
			y = dy;
		}

		else if (map[dx][dy] == '&') {
			if (map[x][y] != '^') map[x][y] = '.';
			int mw = mstat[dx][dy][1];
			int ma = mstat[dx][dy][2];
			int mh = mstat[dx][dy][3];
			int me = mstat[dx][dy][4];

			int noww = ad + w;
			int nowa = df + a;
			if (pen & (1 << CO)) {
				if (pen & (1 << DX)) noww *= 3;
				else noww *= 2;
			}

			mh -= max(1, noww - ma);
			if (mh <= 0) {
				if (pen & (1 << HR)) hp = min(hp + 3, maxhp);
				if (pen & (1 << EX)) exp += me * 6 / 5;
				else exp += me;
				if (exp >= maxexp) {
					exp = 0;
					++lv;
					maxexp += 5;
					maxhp += 5;
					hp = maxhp;
					ad += 2;
					df += 2;
				}
				
				if (map[x][y] != '^') map[x][y] = '.';
				x = dx;
				y = dy;
				map[x][y] = '.';
				continue;
			}
			hp -= max(1, mw - nowa);
			if (hp <= 0) {
				if (pen & (1 << RE)) {
					hp = maxhp;
					x = ix;
					y = iy;
					pen &= ~(1 << RE);
					--pencnt;
					continue;
				}
				hp = 0;
				printres(i, 2, dx, dy);
				return 0;
			}

			if (pen & (1 << CO)) {
				if (pen & (1 << DX)) noww /= 3;
				else noww /= 2;
			}

			int t = mh / max(1, noww - ma) + (mh % max(1, noww - ma) > 0 ? 1 : 0);

			hp -= (t - 1) * max(1, mw - nowa);
			if (hp <= 0) {
				if (pen & (1 << RE)) {
					hp = maxhp;
					x = ix;
					y = iy;
					pen &= ~(1 << RE);
					--pencnt;
					continue;
				}
				hp = 0;
				printres(i, 2, dx, dy);
				return 0;
			}
			if (pen & (1 << HR)) hp = min(hp + 3, maxhp);
			if (pen & (1 << EX)) exp += me * 6 / 5;
			else exp += me;
			if (exp >= maxexp) {
				exp = 0;
				++lv;
				maxexp += 5;
				maxhp += 5;
				hp = maxhp;
				ad += 2;
				df += 2;
			}
			if (map[x][y] != '^') map[x][y] = '.';
			x = dx;
			y = dy;
			map[x][y] = '.';
		}
		else if (map[dx][dy] == 'M') {
			if (map[x][y] != '^') map[x][y] = '.';
			int mw = mstat[dx][dy][1];
			int ma = mstat[dx][dy][2];
			int mh = mstat[dx][dy][3];
			int me = mstat[dx][dy][4];

			int noww = ad + w;
			int nowa = df + a;
			if (pen & (1 << CO)) {
				if (pen & (1 << DX)) noww *= 3;
				else noww *= 2;
			}
			if (pen & (1 << HU)) {
				mw = 0;
				hp = maxhp;
			}

			mh -= max(1, noww - ma);
			if (mh <= 0) {
				map[dx][dy] = '@';
				if (pen & (1 << HR)) hp = min(hp + 3, maxhp);
				if (pen & (1 << EX)) exp += me * 6 / 5;
				else exp += me;
				if (exp >= maxexp) {
					exp = 0;
					++lv;
					maxexp += 5;
					maxhp += 5;
					hp = maxhp;
					ad += 2;
					df += 2;
				}
				printres(i, 1, dx, dy);
				return 0;
			}
			if (!(pen & (1 << HU))) hp -= max(1, mw - nowa);
			if (hp <= 0) {
				if (pen & (1 << RE)) {
					hp = maxhp;
					x = ix;
					y = iy;
					pen &= ~(1 << RE);
					--pencnt;
					continue;
				}
				hp = 0;
				printres(i, 2, dx, dy);
				return 0;
			}

			if (pen & (1 << CO)) {
				if (pen & (1 << DX)) noww /= 3;
				else noww /= 2;
			}
			
			mw = mstat[dx][dy][1];

			int t = mh / max(1, noww - ma) + (mh % max(1, noww - ma) > 0 ? 1 : 0);
			
			hp -= (t - 1) * max(1, mw - nowa);
			if (hp <= 0) {
				if (pen & (1 << RE)) {
					hp = maxhp;
					x = ix;
					y = iy;
					pen &= ~(1 << RE);
					--pencnt;
					continue;
				}
				hp = 0;
				printres(i, 2, dx, dy);
				return 0;
			}
			else {
				if (map[x][y] != '^') map[x][y] = '.';
				map[dx][dy] = '@';
				if (pen & (1 << HR)) hp = min(hp + 3, maxhp);
				if (pen & (1 << EX)) exp += me * 6 / 5;
				else exp += me;
				if (exp >= maxexp) {
					exp = 0;
					++lv;
					maxexp += 5;
					maxhp += 5;
					hp = maxhp;
					ad += 2;
					df += 2;
				}
				printres(i, 1, dx, dy);
				return 0;
			}
		}
		else if (map[dx][dy] == 'B') {
			if (bname[dx][dy][0] == 'O') {
				if (!(pen & (1 << bstat[dx][dy])) && pencnt <= 3) {
					pen |= 1 << bstat[dx][dy];
					++pencnt;
				}
			}
			else if (bname[dx][dy][0] == 'W') {
				w = bstat[dx][dy];
			}
			else {
				a = bstat[dx][dy];
			}
			if (map[x][y] != '^') map[x][y] = '.';
			x = dx;
			y = dy;
			map[x][y] = '.';
		}
		else if (map[dx][dy] == '^') {
			if (map[x][y] != '^') map[x][y] = '.';
			x = dx;
			y = dy;
			if (pen & (1 << DX)) hp -= 1;
			else hp -= 5;
			if (hp <= 0) {
				if (pen & (1 << RE)) {
					hp = maxhp;
					x = ix;
					y = iy;
					pen &= ~(1 << RE);
					--pencnt;
					continue;
				}
				hp = 0;
				printres(i, 2, x, y);
				return 0;
			}
		}
		else {
			if (map[x][y] == '^') {
				if (pen & (1 << DX)) hp -= 1;
				else hp -= 5;
				if (hp <= 0) {
					if (pen & (1 << RE)) {
						hp = maxhp;
						x = ix;
						y = iy;
						pen &= ~(1 << RE);
						--pencnt;
						continue;
					}
					hp = 0;
					printres(i, 2, x, y);
					return 0;
				}
			}
		}
	}
	map[x][y] = '@';
	printres(dirlen, 3, 1, 1);

	return 0;
}
