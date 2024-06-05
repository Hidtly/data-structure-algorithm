/*现在，我们用大炮来打蚊子：蚊子分布在一个M×N格的二维平面上，每只蚊子占据一格。向该平面的任意位置发射炮弹，炮弹的杀伤范围如下示意：
  O
 OXO
  O
其中，X为炮弹落点中心，O为紧靠中心的四个有杀伤力的格子范围。若蚊子被炮弹命中（位于X格），一击毙命，若仅被杀伤（位于O格），则损失一半的生命力。也就是说，一次命中或者两次杀伤均可消灭蚊子。现在给出蚊子的分布情况以及连续k发炮弹的落点，给出每炮消灭的蚊子数。

输入格式:
第一行为两个不超过20的正整数M和N，中间空一格，表示二维平面有M行、N列。

接下来M行，每行有N个0或者#字符，其中#表示所在格子有蚊子。

接下来一行，包含一个不超过400的正整数k，表示发射炮弹的数量。

最后k行，每行包括一发炮弹的整数坐标x和y（0≤x<M，0≤y<N），之间用一个空格间隔。

输出格式:
对应输入的k发炮弹，输出共有k行，第i行即第i发炮弹消灭的蚊子数。

输入样例:
5 6
00#00#
000###
00#000
000000
00#000
2
1 2
1 4
输出样例:
0
2
*/

#include "stdio.h"
#include "stdlib.h"

int board[20][20];
int M, N;


int bang(int x, int y, int kill) {
    if ( (x >= 0 && x < M) && ( y >= 0 && y < N) && board[x][y] > 0) {
        board[x][y] -= kill;
        if (board[x][y] <= 0)
            return 1;
        else
            return 0;
    }
    else {
        return 0;
    }
}
int main(void)
{
    scanf("%d%d", &M, &N);
    getchar();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = getchar() == '0' ? 0 : 2; //0：没有蚊子  2：有蚊子 
        }
        getchar();
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x, y;                   //炮弹位置坐标
        scanf("%d%d", &x, &y);
        int count;                  // 计数
        count = 0;
        count += bang(x, y, 2);
        count += bang(x - 1, y, 1);
        count += bang(x + 1, y, 1);
        count += bang(x, y - 1, 1);
        count += bang(x, y + 1, 1);
        printf("%d\n", count);
    }
    return 0;

}