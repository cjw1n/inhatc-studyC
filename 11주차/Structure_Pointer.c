#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main()
{
    struct Point point = {10, 20};
    struct Point *p = &point;

    p->x = p->y + 5;

    printf("%d %d", point.x, point.y);

    return 0;
}

// 코드 실행 결과로 올바른 것은?
// 1. 10 20
// 2. 20 10
// 3. 25 20
// 4. 15 20

// 답 : 3
