#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define PERSON_INFO_MAX_SIZE 1000

//typedef enum{
//	M,						//MALE = 0
//	F,						//FEMALE = 1
//	N						//UNKNOWN = 2
//}Gender;
typedef struct PersonInfo{          //单个联系人信息结构体
	char name[1024];
	char gender[10];
	int age;
	char phone[1024];
	char adder[1024];
}PersonInfo;
typedef struct AddressBook{         //电话本结构体
	//PersonInfo infos[PERSON_INFO_MAX_SIZE];
	PersonInfo* infos;
	int capacity;         //容量,infos指针指向的动态数组的长度(元素个数)
	int size;             //[0, size)范围是数组的有效元素区间
}AddressBook;

AddressBook g_address_book;

void Init(AddressBook* addr_book){
	assert(addr_book != NULL);
	//对 addre_book 初始化
	addr_book->size = 0;
	//由于size控制了结构体数组中有效元素的区间范围,只要将size设为0,无论数组中存的是什么都是没有意义的,不太需要把数组元素设为某些特定值
	addr_book->capacity = PERSON_INFO_MAX_SIZE;
	addr_book->infos = (PersonInfo*)malloc(addr_book->capacity * sizeof(PersonInfo));
}
//void Realloc(AddressBook* addr_book){
//	assert(addr_book != NULL);
//	//1.扩大capacity的取值
//	//此处每次扩容扩多少,这样的策划完全有我们定制
//	addr_book->capacity *= 2;
//	//2.申请一个更大的内存
//	PersonInfo* old_infos = addr_book->infos;
//	addr_book->infos = (PersonInfo*)malloc(addr_book->capacity * sizeof(PersonInfo));
//	//3.把原有的内存中的数据复制到开辟的新内存  
//	int i = 0;
//	for (; i < addr_book->size; ++i){
//		addr_book->infos[i] = old_infos[i];
//	}
//	//4.释放原有内存
//	free(old_infos);
//}
void Realloc(AddressBook* addr_book){
	assert(addr_book != NULL);
	addr_book->capacity *= 2;
  addr_book->infos = (PersonInfo*)realloc(addr_book->infos, addr_book->capacity);
}
void AddPresonInfo(AddressBook* addr_book){     //-----新增-----
	assert(addr_book != NULL);
	if (addr_book->size >= addr_book->capacity){
		//printf("当前通信录已满,插入失败!\n");
		//return;
		printf("当前通信录已满,进行扩容!\n");
		Realloc(addr_book);
	}
	printf("插入一个联系人!\n");
	//每次都把新的联系人添加到有效数组的最后一个元素上
	PersonInfo* p = &addr_book->infos[addr_book->size];
	//此处不能取一个结构体变量 PersonInfo p = addr_book->infos[addr_book->size];
	//只能取结构体指针 PersonInfo* p = &addr_book->infos[addr_book->size];
	//如果取的是结构体变量,该变量相当于数组中对应元素的副本,即拷贝
	//此时修改结构体变量只是对副本进行修改,没有影响到原来的数组
	printf("请输入联系人姓名: ");
	scanf("%s", p->name);
	//如果之前不用p简化代码,此处要写成 scanf("%s",addr_book->infos[addr_book->size].name);
	printf("请输入联系人性别('男','女','未知'): ");
	scanf("%s", p->gender);
	while (strcmp("男", p->gender) != 0 && strcmp("女", p->gender) != 0 && strcmp("未知", p->gender) != 0){
		printf("性别输入错误,请重新输入:");
		scanf("%s", p->gender);
	}
	printf("请输入该联系人年龄: ");
	scanf("%d", &p->age);
	while (p->age < 0 || p->age > 300){
		printf("年龄输入不规范,请重新输入:");
		scanf("%d", &p->age);
	}
	printf("请输入该联系人电话: ");
	scanf("%s", p->phone);
	printf("请输入联系人住址: ");
	scanf("%s", p->adder);
	++addr_book->size;            //新增完成后,需要更新 size
	printf("插入联系人成功!\n");
}
void DelPresonInfo(AddressBook* addr_book){     //-----删除-----
	assert(addr_book != NULL);
	printf("请输入要删除的联系人序号: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size){          //对输入进行验证
		printf("您输入的序号有误! 删除失败!\n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	printf("请确认您要删除的联系人: [%d] %s (确认删除请输入'Y'): ", id, p->name);   //确认操作
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") != 0){
		printf("删除操作已经取消!\n");
		return;
	}
	PersonInfo* from = &addr_book->infos[addr_book->size - 1];
	PersonInfo* to = p;
	*to = *from;        //用最后一个联系人的信息覆盖要删除的联系人的位置
	--addr_book->size;  //并把存储个数减一
	printf("删除成功!\n");
}
void ModifyPresonInfo(AddressBook* addr_book){      //-----修改-----
	assert(addr_book != NULL);
	printf("请输入需要修改的联系人序号: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size){          //对输入进行验证
		printf("您输入的序号有误! 修改失败!\n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	char input[1024] = { 0 };
	printf("请输入修改姓名(若不需要修改姓名请输入'#'): ");
	scanf("%s", input);
	if (strcmp(input, "#") != 0){
		strcpy(p->name, input);
	}
	printf("请输入修改性别(若不需要修改性别请输入'#'): ");
	scanf("%s", input);
	if (strcmp(input, "#") != 0){
		while (strcmp("男", input) != 0 && strcmp("女", input) != 0 && strcmp("未知", input) != 0){
			printf("性别输入错误,请重新输入:");
			scanf("%s", input);
		}
		strcpy(p->gender, input);
	}
	printf("请输入修改年龄(若不需要修改年龄请输入'-1'): ");
	scanf("%d", &p->age);
	if (p->age != -1){
		while (p->age < 0 || p->age > 300){
			printf("年龄输入不规范,请重新输入:");
			scanf("%d", &p->age);
		}
	}
	printf("请输入修改电话(若不需要修改电话请输入'#'): ");
	scanf("%s", input);
	if (strcmp(input, "#") != 0){
		strcpy(p->phone, input);
	}
	printf("请输入修改住址(若不需要修改姓名请输入'#'): ");
	scanf("%s", input);
	if (strcmp(input, "#") != 0){
		strcpy(p->adder, input);
	}
	printf("修改成功!\n");
}
void FindPresonInfo(AddressBook* addr_book){        //-----查找-----
	assert(addr_book != NULL);
	printf("请输入需要查找的联系人姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	int i = 0, count = 0;
	for (; i < addr_book->size; ++i){
		PersonInfo* p = &addr_book->infos[i];
		if (strcmp(name, p->name) == 0){
			printf("[%d] %s\t%s\t%d岁\t%s\t%s\n", i, p->name, p->gender, p->age, p->phone, p->adder);
			//break;   姓名是有可能重复的,尽量把匹配到的都找到
			++count;
		}
	}
	if (count == 0){
		printf("没有找到该联系人!\n");
		return;
	}
	else{
		printf("共查找到 %d 个联系人!\n", count);
	}
	printf("查找完毕!\n");
}
void PrintAllPresonInfo(AddressBook* addr_book){    //-----显示全部-----
	assert(addr_book != NULL);
	printf("显示所有联系人如下:\n");
	int i = 0;
	for (; i < addr_book->size; ++i){
		PersonInfo* p = &addr_book->infos[i];
		printf("[%d] %s\t%s\t%d岁\t%s\t%s\n", i, p->name, p->gender, p->age, p->phone, p->adder);
	}
	printf("共显示了 %d 个联系人的信息!\n", addr_book->size);
}
void SortPresonInfo(AddressBook* addr_book){        //-----排序-----
	assert(addr_book != NULL);
	int i = 0, j = 0;
	for (; i < addr_book->size - 1; ++i){
		PersonInfo* p = &addr_book->infos[i];
		for (j = i + 1; j < addr_book->size; ++j){
			PersonInfo* q = &addr_book->infos[j];
			if (strcmp(p->name, q->name) > 0){
				PersonInfo x;
				x = *p;
				*p = *q;
				*q = x;
			}
		}
	}
	printf("所有联系人排序成功!\n");
	PrintAllPresonInfo(addr_book);
}
void ClearPresonInfo(AddressBook* addr_book){       //-----清除全部-----
	assert(addr_book != NULL);
	printf("您确认要清空所有联系人吗？(输入'Y'确认)：\n");
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") != 0){
		printf("清除操作已经取消!\n");
		return;
	}
	addr_book->size = 0;
	printf("成功清除所有联系人!\n");
}
void ReadPersonInfo(AddressBook* addr_book){
  FILE* fp = fopen("./addr_book.txt", "r");
  if(fp == NULL){
    perror("fopen");
    return;
  }

  PersonInfo* p = &addr_book->infos[0];
  char str[4000] = {0};
  fgets(str, 4000, fp);
  char* pch;
  pch = strtok(str, "\t");
  int i = 0;
  while(pch != NULL){
    if(i == 0)
      strcpy(p->name, pch);
    if(i == 1)
      strcpy(p->gender, pch);
    if(i == 2)
      sscanf(pch, "%d", &p->age);
    if(i == 3)
      strcpy(p->phone, pch);
    if(i == 4)
      strcpy(p->adder, pch);
    pch = strtok(NULL, "\t");
    ++i;
  }

  fclose(fp);

  PrintAllPresonInfo(addr_book);    
}
void SavePersonInfo(AddressBook* addr_book){
  FILE* fp = fopen("./addr_book.txt", "w");
  if(fp == NULL){
    perror("fopen");
    return;
  }

  int i = 0;
  for(; i < addr_book->size; ++i){
    PersonInfo* p = &addr_book->infos[i];
    //fwrite(p->name, 1, 1024, fp);
    fputs(p->name, fp);    
    fputs("\t", fp);    
    //fwrite(p->gender, 1, 10, fp);
    fputs(p->gender, fp);    
    fputs("\t", fp);    
    char str[1024] = {0};
    sprintf(str, "%d", p->age);
    fputs(str, fp);
    fputs("\t", fp);    
    //fwrite(p->phone, 1, 1024, fp);
    fputs(p->phone, fp);    
    fputs("\t", fp);    
    //fwrite(p->adder, 1, 1024, fp);
    fputs(p->adder, fp);    
    //fwrite("\n", 1, 1, fp);
    fputs("\n", fp);    
  }
  
  fclose(fp);
}

int Menu(){
	printf("=====================\n");
	printf("1.新增\n");
	printf("2.删除\n");
	printf("3.修改\n");
	printf("4.查找\n");
	printf("5.排序\n");
	printf("6.显示全部\n");
	printf("7.清除全部\n");
	printf("0.退出\n");
	printf("=====================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main(){
	Init(&g_address_book);              //对通讯录进行初始化
  ReadPersonInfo(&g_address_book);
	typedef void(*pfunc_t)(AddressBook*);
	pfunc_t table[] = {                 //函数指针数组
		AddPresonInfo,
		DelPresonInfo,
		ModifyPresonInfo,
		FindPresonInfo,
		SortPresonInfo,
		PrintAllPresonInfo,
		ClearPresonInfo
	};
	int c = (int)(sizeof(table) / sizeof(table[0]));     //计算表元素个数,也就是可选择个数
	//无符号数太危险,尽量往有符号转,sizeof返回值为 unsigned int,我们把它转为 int
	while (1){
		int choice = Menu();
		if (choice < 0 || choice > c){
			printf("您的输入有误!\n");
			continue;
		}
		if (choice == 0){
			printf("编辑退出!goodbye!\n");
			break;
		}
		table[choice - 1](&g_address_book);     //通过表驱动调用相应函数
	}
  SavePersonInfo(&g_address_book);
	return 0;
}
