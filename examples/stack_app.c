
#include "stack_app.h"

#include <ctype.h>
#include <math.h>
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

static bool basic_calculation(int operand_left, int operand_right,
                              char operator, int * result) {

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

bool init_inffix_by_str(char *str, int length, listack *inffix_stk) {

  int data;
  static int digit_cnt;
  static int digit_val;
  static bool in_operand;

  if (!init_listack(inffix_stk)) {
    return false;
  }

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

  return true;
}

// priority 1: +-, priority 2: */, priority 3: (){}[]
// will pop out all operators in operator_stk which have equal or higher
// priority than current operator in inffix_stk
bool convert_inffix_to_suffix(listack *inffix_stk, listack *suffix_stk) {
  listack operand_stk, operator_stk;
  int data;

  init_listack(suffix_stk);
  init_listack(&operand_stk);
  init_listack(&operator_stk);

  while (!listack_is_empty(*inffix_stk)) {
    listack_pop(inffix_stk, &data); // get elem from inffix

    switch (data_type_in_expression(data)) {

    case 0: { // operand
      listack_push(suffix_stk, data);
    } break;

    case 1: { //+-
      int pre_operator;
      if (listack_get_top(&operator_stk, &pre_operator)) {
        switch (data_type_in_expression(pre_operator)) {
        case 0:
          printf("error\r\n");
          break;
        // if the operator in operator_stk has higher or equal priority than
        // current operator, put operator from operator_stk to suffix_stk, and
        // push current operator into operator_stk
        case 1: // fall thru
        case 2: {
          listack_pop(&operator_stk, &pre_operator);
          listack_push(suffix_stk, pre_operator);
          listack_push(&operator_stk, data);
        } break;
        case 3: //[({
        {
          // listack_push(&operator_stk, data);
        } break;
        case 4: // fall thru
        default:
          printf("error\r\n");
          break;
        }
      } else {
        listack_push(&operator_stk, data);
      }
    } break;

    case 2: { //*/
      int pre_operator;
      if (listack_get_top(&operator_stk, &pre_operator)) {
        switch (data_type_in_expression(pre_operator)) {
        case 0:
          printf("error\r\n");
          break;
        // if the operator in operator_stk has higher priority than current
        // operator, put operator from operator_stk to suffix_stk, and push
        // current operator into operator_stk
        case 1: {
          listack_push(&operator_stk, data);
        } break;
        case 2: {
          listack_pop(&operator_stk, &pre_operator);
          listack_push(suffix_stk, pre_operator);
          listack_push(&operator_stk, data);
        } break;
        case 3: //[({
        {
          // listack_push(&operator_stk, data);
        } break;
        case 4: // fall thru
        default:
          printf("error\r\n");
          break;
        }
      } else {
        listack_push(&operator_stk, data);
      }
    } break;
    case 3:
    case 4: {

    } break;
    default:
      printf("unexpect char found\r\n");
      break;
    }
  }

  while (!listack_is_empty(operator_stk)) {
    // push operators if any remains
    listack_pop(&operator_stk, &data);
    listack_push(suffix_stk, data);
  }

  return true;
}

bool suffix_stk_caculation(listack suffix_stk, int *result) {
  listack s;
  init_listack(&s);
  listack_reverse(&suffix_stk);
  printf("reversed: ");
  show_stack_content(suffix_stk);

  int data;
  while (!listack_is_empty(suffix_stk)) {
    listack_pop(&suffix_stk, &data);

    switch (data_type_in_expression(data)) {

    case 0: { // operand
      listack_push(&s, data);
    } break;
    case 1:
    case 2: {
      int operand_left, operand_right, r;
      listack_pop(&s, &operand_right);
      listack_pop(&s, &operand_left);
      basic_calculation(operand_left - '0', operand_right - '0', data, &r);
      // printf("cal:%d \r\n", r);
      listack_push(&s, r + '0');
    } break;
    case 3: {

    } break;
    case 4: {

    } break;
    }
  }

  if (listack_pop(&s, result)) {
    return true;
  } else {
    return false;
  }
}

void basic_cal_example(void) {

  char input_str[100] = {0};
  printf("please input a string\r\n");
  scanf("%s", input_str);
  printf("GET(%d):%s\r\n", (int)strlen(input_str), input_str);

  listack inffix_stk, suffix_stk;

  init_inffix_by_str(input_str, strlen(input_str), &inffix_stk);
  printf("orginal: ");
  show_stack_content(inffix_stk);

  listack_reverse(&inffix_stk);
  printf("reversed: ");
  show_stack_content(inffix_stk);

  convert_inffix_to_suffix(&inffix_stk, &suffix_stk);
  printf("suffix: ");
  show_stack_content(suffix_stk);

  int result;
  suffix_stk_caculation(suffix_stk, &result);
  printf("[RESULT]%c\r\n", result);
}
