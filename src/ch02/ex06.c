#include<stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {
    if (num == 1) {
        printf ("원반%d를 %c -> %c 이동 \n", num, from, to);
    } else {
        HanoiTowerMove(num-1, from, to, by);
        printf ("원반%d를 %c -> %c 이동 \n", num, from, to);
        HanoiTowerMove(num-1, by, from, to);
    }
}

int main() {
    int num = 4;
    char from = 'A', by='B', to='C';

    HanoiTowerMove(num, from, by, to);
    return 0;
}