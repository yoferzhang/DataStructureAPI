// linkstack.h
// 链式存储栈的API声明

#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;

// 创建栈
LinkStack* LinkStack_Create();

// 销毁栈
void LinkStack_Destroy(LinkStack* stack);

// 清空栈
void LinkStack_Clear(LinkStack* stack);

// 将item入栈
int LinkStack_Push(LinkStack* stack, void* item);

// 弹出栈顶元素
void* LinkStack_Pop(LinkStack* stack);

// 获取栈顶元素
void* LinkStack_Top(LinkStack* stack);

// 获取栈的大小
int LinkStack_Size(LinkStack* stack);

#endif //_MY_LINKSTACK_H_
