#include "main.h"

extern SQW global_wrapper;

void rotl_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR) {}
void rotr_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR) {}
void stack_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	global_wrapper.SQ_flag = STACK_F;
}
void queue_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	global_wrapper.SQ_flag = QUEUE_F;
}
