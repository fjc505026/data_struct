

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

#include "listack.h"
#include <string.h>

bool bracket_check(char *str, int length) {
  listack stk;
  init_listack(&stk);
  // top_element can't use char.cast will across memeory boundary
  int top_element = '\0';
  {}

  for (int i = 0; i < length; i++) {
    printf("char:%c,index:%d\r\n", str[i], i);

    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      listack_push(&stk, str[i]);
    } else {

      if (listack_is_empty(stk))
        return false;

      listack_pop(&stk, (int *)&top_element);
      // printf("[debug]char:%c,index:%d\r\n", str[i], i);
      if (str[i] == ')' && top_element != '(')
        return false;
      if (str[i] == ']' && top_element != '[')
        return false;
      if (str[i] == '}' && top_element != '{')
        return false;
    }
  }

  return listack_is_empty(stk);
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

// seperated by space
// bool parse_suffix_expression(char *str, int length){
// }
#include <ctype.h>
#include <math.h>

static bool basic_calculation(float operand_left, float operand_right,
                              char operator, float * result) {

  switch (operator) {
  case '+': {
    *result = operand_left + operand_right;
  } break;
  case '-': {
    *result = operand_left - operand_right;
  } break;

  case '*': {
    *result = operand_left * operand_right;
  } break;

  case '/': {
    *result = operand_left / operand_right;
  } break;

  default:
    printf("unexpect operator %c\n", operator);
    return false;
  }
  return true;
}

// priority 1: +-, priority 2: */, priority 3: (){}[]
// only detect a operator has priority =< previous operator (at the top of the
// operator stack), we can caclulate

/*@brief  check data type in in expression
 *@param a input char
 *@return -1: out of range
 *         0:operand
 *         1:+-
 *         2:* \/
 *         3:[({
 *         4:])}
 */

static int data_type_in_expression(char ch) {

  if (isdigit(ch)) {
    return 0;
  } else if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '{' || ch == '[' || ch == '(') {
    return 3;
  } else if (ch == '}' || ch == ']' || ch == ')') {
    return 4;
  }

  return -1;
}

listack *init_inffix_by_str(char *str, int length) {

  int data;
  static int digit_cnt;
  static int digit_val;
  static bool in_operand;

  listack *inffix_stk;
  init_listack(inffix_stk);
  for (int i = 0; i < length; i++) {

    int type = data_type_in_expression(str[i]);
    switch (type) {
    case 0: {
      digit_val += (str[i] - '0') * pow(10, digit_cnt++);
      in_operand = true;
    } break;
    case 1:
    case 2:
    case 3:
    case 4: {
      if (in_operand) {
        in_operand = false;
        listack_push(inffix_stk, digit_val + '0');
        digit_val = 0;
        digit_cnt = 0;
      }
      listack_push(inffix_stk, str[i]);
    } break;
    default:
      printf("unexpect char found\r\n");
      break;
    }
    if (i == length - 1 && type == 0) {
      listack_push(inffix_stk, digit_val + '0');
    }
  }

  return inffix_stk;
}

//能算就先压
bool convert_inffix_to_suffix(char *str, int length) {

  listack operand_stk, operator_stk, suffix_stk;
  init_listack(&suffix_stk);
  init_listack(&operand_stk);
  init_listack(&operator_stk);

  int data;
  static int digit_cnt;
  static int digit_val;

  for (int i = 0; i < length; i++) {

    if (isdigit(str[i])) {
      digit_val += (str[i] - '0') * 10 * digit_cnt++;
      listack_push(&operand_stk, str[i]);

    } else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      // priority 3 operator
      listack_push(&operator_stk, str[i]);
    } else if (str[i] == ')' || str[i] == '[' || str[i] == '}') {

    } else if (str[i] == '+' || str[i] == '-') {
      // priority 1 operator
      if (listack_get_top(&operator_stk, &data)) {
        if (data == '+' || data == '-' || data == '*' || data == '/') {
          // we can calculate previous steps
          int operand_right, operand_left, operator, result;
          listack_pop(&operand_stk, &operand_right);
          listack_pop(&operand_stk, &operand_left);
          listack_pop(&operator_stk, &operator);
          if (basic_calculation(operand_left,
                                operand_right, operator, & result)) {
            listack_push(&operand_stk, result);
          }
        } else if (data == '(' || data == '[' || data == '{') {
          listack_push(&operator_stk, data);
        } else {
          printf("unexpected operator\r\n");
        }
      } else {
        listack_push(&operator_stk, data);
      }

    } else if (str[i] == '*' || str[i] == '/') {
      // priority 2 operator
      if (listack_get_top(&operator_stk, &data)) {
        if (data == '*' || data == '/') {
          // we can calculate previous steps
          int operand_right, operand_left, operator, result;
          listack_pop(&operand_stk, &operand_right);
          listack_pop(&operand_stk, &operand_left);
          listack_pop(&operator_stk, &operator);
          if (basic_calculation(operand_left,
                                operand_right, operator, & result)) {
            listack_push(&operand_stk, result);
          }
        } else if (data == '+' || data == '-') {
          listack_push(&operator_stk, data);
        } else if (data == '(' || data == '[' || data == '{') {
          listack_push(&operator_stk, data);
        } else {
          printf("unexpected operator\r\n");
        }
      } else {
        listack_push(&operator_stk, data);
      }
    } else {
      printf("unexpect char found\r\n");
      return false;
    }
  }
}

int main() {
  // list_example();
  // stack_example();

  char input_str[100] = {0};
  printf("please input a string\r\n");
  scanf("%s", input_str);
  printf("GET(%d):%s\r\n", (int)strlen(input_str), input_str);

  listack *inffix_stk = init_inffix_by_str(input_str, strlen(input_str));
  show_stack_content(*inffix_stk);

  return 0;
}
///