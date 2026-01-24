#include "util_unit.h"
#include <stdlib.h>

int dummy(void) { return 1; }

int main(void) {
  t_unit_test *testlist;

  load_test(&testlist, "hi", &dummy);
}

t_unit_test *getTestAt(t_unit_test *head, size_t target_idx) {
  /* we loop over instead of shifting the pointer to make sure we don't skip
   * unexisting tests and end up in unallocated/invalid memory */
  for (size_t j = 0; (j < target_idx) && head; j++, head = head->next)
    ;
  return head;
}

size_t countTests(t_unit_test *head) {
  size_t j = 0;
  for (; head; j++, head = head->next)
    ;
  return j;
}

/**
 * @brief util function to get last test of the chain
 */
t_unit_test *getLast(t_unit_test *head) {
  for (; head; head = head->next)
    ;
  return head;
}

/**
 * @brief util function to allocate a new test
 */
t_unit_test *alloc_test(const char *title, int (*test_func)(void)) {
  t_unit_test *p = malloc(sizeof(t_unit_test));
  p->title = ft_strdup(title);
  p->func = test_func;
  p->next = NULL;
  return p;
}

size_t load_test(t_unit_test **head_ptr, const char *title,
                 int (*test_func)(void)) {
  if (!head_ptr)
    return -1;
  if (!*head_ptr) { // initial
    t_unit_test *p = alloc_test(title, test_func);
    if (!p)
      return -1;
    *head_ptr = p;
    return 0;
  }

  t_unit_test *last = getLast(*head_ptr);
  last->next = alloc_test(title, test_func);
  if (!last->next)
    return -1;
  return 0;
}

void clear_tests(t_unit_test **head_ptr) {
  for (t_unit_test *head = *head_ptr; head;) {
    t_unit_test *next = head = head->next;
    head->next = NULL;
    free(head->title);
    head->title = NULL;
    head->func = NULL;
    head = next;
  }
}
