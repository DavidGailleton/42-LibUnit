#ifndef UTIL_UNIT_H
#define UTIL_UNIT_H

#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief singular unit test def
 */
typedef struct s_unit_test {
  char *title;
  int (*func)(void);
  struct s_unit_test *next;
} t_unit_test;

/**
 * @brief finds a test at index
 *
 * @return test or NULL
 */
t_unit_test *get_test_at(t_unit_test *head, size_t target_idx);

/**
 * @brief count tests
 *
 * @return size_t test count
 */
size_t count_tests(t_unit_test *head);

/**
 * @brief adds a new test
 * @brief alternatively, if the passed head is empty, replace it with the
 * initial test
 *
 * @param head_ptr pointer to the head of the tests list
 * @param title name of the test
 * @param test_func function to execute the test
 *
 * @return -1 on error, 0 on success
 */
size_t load_test(t_unit_test **head_ptr, const char *title,
                 int (*test_func)(void));

/**
 * @brief clears the tests memory
 */
void clear_tests(t_unit_test **head_ptr);

#endif // !UTIL_UNIT_H
