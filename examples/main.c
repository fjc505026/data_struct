#include "stack_app.h"

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

int main() {
  // list_example();
  // stack_example();
  basic_cal_example();

  return 0;
}
