#include <stdio.h>

void Drink(long long money){
  long long drink_bottle = money;             //喝了多少瓶
  long long empty_bottle = drink_bottle;      //空瓶数量
  while(empty_bottle > 1){
    long long e_bottle = empty_bottle/2;      //空瓶可兑换几瓶汽水
    long long bottle_1 = empty_bottle%2;      //兑换后剩余的奇数瓶
    drink_bottle += e_bottle;
    empty_bottle = e_bottle + bottle_1;
  }
  printf("用 %lld 元钱,可以喝到 %lld 瓶汽水!\n",money,drink_bottle);
}



int main(){
  long long money = 0;
  printf("你给多少钱?\n");
  scanf("%lld",&money);
  Drink(money);
  return 0;
}
