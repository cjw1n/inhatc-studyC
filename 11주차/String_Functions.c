#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20] = "Apple";
    char str2[20] = "Banana";

    strcpy(str1, str2);

    printf("%d %d",
           (int)strlen(str1),
           strcmp(str1, str2));

    return 0;
}

// 코드 실행 결과로 올바른 것은?
// 1. 5 0
// 2. 6 0
// 3. 6 1
// 4. 5 -1

// 답 : 2
