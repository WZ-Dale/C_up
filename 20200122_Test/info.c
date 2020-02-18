#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define PERSON_INFO_MAX_SIZE 200

typedef struct PersonInfo{
  char name[1024];
  char phone[1024];
} PersonInfo;

typedef struct AddressBook{
  PersonInfo infos[PERSON_INFO_MAX_SIZE];
  int size;   // [0, size) 范围是数组的有效元素区间
} AddressBook;

AddressBook g_address_book;

void Init(AddressBook* addr_book){
  assert(addr_book != NULL);
  // 对 addr_book 进行初始化
  // 由于size控制了结构体数组中有效元素的区间范围，只要将其设为0,
  // 无论数组中存的是什么都没有意义的，不需要将每个元素都设为特定值
  addr_book->size = 0;

}

void AddPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);
  if(addr_book->size >= PERSON_INFO_MAX_SIZE){
    printf("当前通讯录已满，插入失败！\n");
    return;
  }
  // 每次都把这个新的联系人放到有效数组的最后一个元素上
  PersonInfo* p = &addr_book->infos[addr_book->size];
  printf("请输入联系人姓名：");
  scanf("%s", p->name);
  printf("请输入联系人手机号：");
  scanf("%s", p->phone);
  ++addr_book->size;
  printf("插入联系人成功！\n");
}

void DelPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);
  printf("请输入要删除的联系人序号：");
  int id = 0;
  scanf("%d", &id);
  if(id < 0 || id >= addr_book->size){
    printf("您输入的序号有误，删除失败！\n");
    return;
  }
  PersonInfo* p = &addr_book->infos[id];
  printf("您确定要删除联系人：[%d] %s,确认请输入Y：", id, p->name);
  char cmd[1024] = {0};
  scanf("%s", cmd);
  if(strcmp(cmd, "Y") != 0){
    printf("删除操作已经取消！\n");
    return;
  }
  PersonInfo* from = &addr_book->infos[addr_book->size - 1];
  PersonInfo* to = p;
  *to = *from;
  --addr_book->size;
  printf("删除成功！\n");
}

void ModifyPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);
  printf("请输入需要修改的联系人序号：");
  int id = 0;
  scanf("%d", &id);
  if(id < 0 || id >= addr_book->size){
    printf("您输入的序号有误，修改失败！\n");
    return;
  }
  PersonInfo* p = &addr_book->infos[id];
  char input[1024] ={0};
  printf("请输入要修改的姓名：");
  scanf("%s", input);
  if(strcmp(input, "#") != 0){
    strcpy(p->name, input);    
  }
  printf("请输入要修改的手机号：");
  scanf("%s", input);
  if(strcmp(input, "#") != 0){
    strcpy(p->phone, input);    
  }
  printf("修改成功！\n");
}

void FindPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);

}

void SortPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);

}

void PrintAllPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);
  printf("共有%d个联系人：\n", addr_book->size);
  int i = 0;
  for(; i < addr_book->size; ++i){
    PersonInfo* p = &addr_book->infos[i];
    printf("[%d] %s\t%s\n", i, p->name, p->phone);
  }
}

void ClearAllPersonInfo(AddressBook* addr_book){
  assert(addr_book != NULL);
  printf("确认要清空所有联系人？是请输入Y：");
  char cmd[1024] = {0};
  scanf("%s", cmd);
  if(strcmp(cmd, "Y") != 0){
    printf("删除操作已经取消！\n");
    return;
  }
  addr_book->size = 0;
  printf("已删除所有联系人！\n");
}

int Menu(){
  printf("====================\n");
  printf("1. 新增\n");
  printf("2. 删除\n");
  printf("3. 修改\n");
  printf("4. 查找\n");
  printf("5. 排序\n");
  printf("6. 显示全部\n");
  printf("7. 清空全部\n");
  printf("0. 退出\n");
  printf("====================\n");
  printf("请输入您的选择：");
  int choice = 0;
  scanf("%d", &choice);
  return choice;
}

int main(){
  // 1. 对通讯录进行初始化
  Init(&g_address_book);
  typedef void (*pfunc_t)(AddressBook*);
  pfunc_t table[] = {
    AddPersonInfo,
    DelPersonInfo,
    ModifyPersonInfo,
    FindPersonInfo,
    SortPersonInfo,
    PrintAllPersonInfo,
    ClearAllPersonInfo,
  };
  while(1){
    int choice = Menu();
    if(choice < 0 || choice > (int)(sizeof(table) / sizeof(table[0]))){
      printf("您的输入有误！\n");
      continue;
    }
    if(choice == 0){
      printf("退出！\n");
      break;
    }
    table[choice - 1](&g_address_book);
  }
  return 0;
}
