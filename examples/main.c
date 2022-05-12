

#if 0
#include "sll_ex.h"
void list_example(void) {
  Linklist sll;

  int sll_len = 10;
  printf("program start!!!\r\n");

  init_sll_ex(&sll);

  for (int i = 0; i < sll_len; i++) {
    ElemType rnd_data = rand();
    printf("[%d]%d ", i, rnd_data);
    sll_ex_insert_next_node(sll, &rnd_data);
  }
  printf("\r\n");
  printf("original list: ");
  sll_ex_show(sll);

  sll_ex_reverse(&sll);
  printf("reversed list: ");
  sll_ex_show(sll);
}
#endif

#include "sqstack.h"
#include <string.h>

bool bracket_check(char *str, int length) {
  sqstack stk;
  init_sqstack(&stk);
  // top_element can't use char.cast will across memeory boundary
  int top_element = '\0';

  for (int i = 0; i < length; i++) {
    printf("char:%c,index:%d\r\n", str[i], i);

    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      sqstack_push(&stk, str[i]);
    } else {

      if (sqstack_is_empty(&stk))
        return false;

      sqstack_pop(&stk, (int *)&top_element);
      // printf("[debug]char:%c,index:%d\r\n", str[i], i);
      if (str[i] == ')' && top_element != '(')
        return false;
      if (str[i] == ']' && top_element != '[')
        return false;
      if (str[i] == '}' && top_element != '{')
        return false;
    }
  }

  return sqstack_is_empty(&stk);
}

void stack_example(void) {
  char input_str[100] = {0};
  printf("please input brackets string\r\n");
  scanf("%s", input_str);
  printf("GET(%d):%s\r\n", (int)strlen(input_str), input_str);

  if (bracket_check(input_str, (int)strlen(input_str))) {
    printf("matched!\r\n");
  } else {
    printf("not matched!\r\n");
  }
}

int main() {
  // list_example();
  stack_example();

  return 0;
}
