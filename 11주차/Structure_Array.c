#include <stdio.h>

struct Student {
    int id;
    int score;
};

int main()
{
    struct Student students[2] = {
        {101, 80},
        {102, 90}
    };

    students[0].score += 10;

    printf("%d %d",
           students[0].score,
           students[1].score);

    return 0;
}

// 코드 실행 결과로 올바른 것은?
// 1. 80 90
// 2. 90 90
// 3. 80 100
// 4. 90 100

// 답 : 2
