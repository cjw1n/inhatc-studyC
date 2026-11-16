#include <stdio.h>

union Number {
    int num;
    char ch;
};

int main()
{
    union Number data;

    data.ch = 'A';
    printf("%c ", data.ch);

    data.num = 100;
    printf("%d", data.num);

    return 0;
}

// 코드 실행 결과로 올바른 것은?
// 1. A 100
// 2. A A
// 3. 100 A
// 4. 100 100

// 답 : 1
