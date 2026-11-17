# 11주차 퀴즈 (2회차) — 구조체와 함수 (ex3.c / ex4.c / ex5.c)

아래 소스 코드를 참고하여 문제를 푸세요.

### ex3.c

```c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

Point makePoint(int x, int y) {
    Point p = {x, y};
    return p;
}

Point movePoint(Point p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
    return p;
}

int main(void) {
    Point a = makePoint(1, 2);
    Point b = movePoint(a, 3, 4);

    printf("a : (%d, %d)\n", a.x, a.y);
    printf("b : (%d, %d)\n", b.x, b.y);
    return 0;
}
```

### ex4.c

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int score;
} Student;

void addBonus(Student list[], int n) {
    for (int i = 0; i < n; i++) {
        list[i].score += 10;
    }
}

int main(void) {
    Student s[3] = {{"Kim", 70}, {"Lee", 85}, {"Park", 90}};

    addBonus(s, 3);
    printf("%d %d %d\n", s[0].score, s[1].score, s[2].score);
    return 0;
}
```

### ex5.c

```c
#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

struct Event {
    char title[30];
    struct Date date;
};

int main(void) {
    struct Event e = {"Exam", {2026, 12, 20}};
    struct Event *ep = &e;

    /* (A) 이 위치에서 ep를 이용해 year 값 2026을 출력하려고 한다. */
    return 0;
}
```

---

## 문제 1

`ex3.c`를 실행했을 때 출력 결과로 알맞은 것은?

```
① a : (1, 2)
   b : (1, 2)

② a : (4, 6)
   b : (4, 6)

③ a : (1, 2)
   b : (4, 6)

④ a : (4, 6)
   b : (1, 2)
```

---

## 문제 2

`ex4.c`를 실행했을 때 출력 결과로 알맞은 것은?

```
① 80 95 100

② 70 85 90

③ 80 85 90

④ 컴파일 오류가 발생한다.
```

---

## 문제 3

`ex4.c`의 `addBonus()` 함수가 `main()`에 있는 배열 `s`의 점수를 실제로 바꿀 수 있는 이유로 가장 알맞은 것은?

```
① 구조체를 typedef로 정의하면 함수에 항상 참조로 전달되기 때문이다.

② 반복문 안에서는 매개변수의 복사가 일어나지 않기 때문이다.

③ list[i].score += 10; 은 전역 변수를 수정하는 문장이기 때문이다.

④ 배열은 첫 번째 원소의 주소로 전달되어, list가 원본 배열의 원소를 가리키기 때문이다.
```

---

## 문제 4

`ex5.c`의 (A) 위치에서 `ep`를 이용해 `year` 값인 2026을 출력하려고 한다.
`printf("%d\n", ____);` 의 빈칸에 들어갈 올바른 표현은?

```
① ep.date.year

② ep->date.year

③ ep->date->year

④ (*ep)->date.year
```

---

## 문제 5

다음 코드에 대한 설명으로 옳은 것은?

```c
struct Person a = {"Moon", 25};
struct Person b;

b = a;
b.age = 30;
strcpy(b.name, "Yun");
```

```
① b = a; 는 a의 모든 멤버(name 배열 포함)를 b로 복사하므로,
   이후 b를 수정해도 a의 값은 그대로 유지된다.

② 구조체 변수끼리는 = 로 대입할 수 없으므로 컴파일 오류가 발생한다.

③ b = a; 이후 a.name과 b.name은 같은 메모리를 공유하므로,
   strcpy(b.name, "Yun"); 을 하면 a.name도 "Yun"이 된다.

④ a == b 로 두 구조체의 모든 멤버가 같은지 한 번에 비교할 수 있다.
```

---

# 정답 및 해설

| 문제 | 정답 |
| :--: | :--: |
|  1   |  ③   |
|  2   |  ①   |
|  3   |  ④   |
|  4   |  ②   |
|  5   |  ①   |

**1번** `movePoint()`는 `a`의 복사본 `p`를 수정해서 반환하고, 그 반환값이 `b`에 저장된다. 원본 `a`는 바뀌지 않으므로 `a`는 (1, 2), `b`는 (4, 6)이다.

**2번** `addBonus()`가 배열의 각 원소 점수에 10을 더한다. 따라서 70→80, 85→95, 90→100이 되어 `80 95 100`이 출력된다.

**3번** 배열을 함수 인자로 넘기면 첫 번째 원소의 주소가 전달된다. `Student list[]`는 `Student *list`와 같은 의미이므로, 함수 안의 변경이 원본 배열에 반영된다.

**4번** `ep`는 포인터이므로 `ep->date`로 멤버에 접근한다. `date`는 포인터가 아닌 구조체 멤버이므로 그다음에는 `.year`를 쓴다. `(*ep).date.year`도 같은 의미이다.

**5번** 같은 타입의 구조체 변수끼리 `=`로 대입하면 배열 멤버를 포함한 모든 멤버가 복사된다. 복사된 뒤에는 서로 독립이므로 `b`를 바꿔도 `a`는 그대로이다(`a`는 "Moon", 25 유지). 구조체는 `==`로 비교할 수 없다.
