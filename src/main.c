/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "math.h"
#include "stdio.h"
#include "usart2_comm.h"
#include "gpio_led.h"

// Macro to use CCM (Core Coupled Memory) in STM32F4
#define CCM_RAM __attribute__((section(".ccmram")))

#define TASK1_STACK_SIZE 128
#define TASK2_STACK_SIZE 128

StackType_t printTask1_Stack[TASK1_STACK_SIZE] CCM_RAM; // Put task stack in CCM
StackType_t printTask2_Stack[TASK2_STACK_SIZE] CCM_RAM; // Put task stack in CCM

StaticTask_t Task1Buff CCM_RAM;  // Put TCB in CCM
StaticTask_t Task2Buff CCM_RAM;  // Put TCB in CCM

void vTask1_print(void* p)
{

	while (1)
	{
		USART_TX_string("Task1...\r\n");
		vTaskDelay(1000);
	}

	vTaskDelete(NULL);
}

void vTask2_print(void* p)
{
	while (1)
	{
		USART_TX_string("Task2.\r\n");
		toggle_leds();
		vTaskDelay(2000);
	}
	vTaskDelete(NULL);
}

int main(void)
{

	SystemInit();

	init_USART2();
	init_led_gpios();

	// Create a task
	// Stack and TCB are placed in CCM of STM32F4
	// The CCM block is connected directly to the core, which leads to zero wait states
	xTaskCreateStatic(vTask1_print, "task1_print", TASK1_STACK_SIZE, NULL, 1,
			printTask1_Stack, &Task1Buff);
	xTaskCreateStatic(vTask2_print, "task2_print", TASK2_STACK_SIZE, NULL, 5,
			printTask2_Stack, &Task2Buff);

	USART_TX_string("Task main\r\n");

	vTaskStartScheduler();  // should never return

	while (1)
	{

	}
}

void vApplicationTickHook(void)
{
}

/* vApplicationMallocFailedHook() will only be called if
 configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
 function that will get called if a call to pvPortMalloc() fails.
 pvPortMalloc() is called internally by the kernel whenever a task, queue,
 timer or semaphore is created.  It is also called by various parts of the
 demo application.  If heap_1.c or heap_2.c are used, then the size of the
 heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
 FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
 to query the size of free heap space that remains (although it does not
 provide information on how the remaining heap might be fragmented). */
void vApplicationMallocFailedHook(void)
{
	taskDISABLE_INTERRUPTS();
	for (;;)
		;
}

/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
 to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
 task.  It is essential that code added to this hook function never attempts
 to block in any way (for example, call xQueueReceive() with a block time
 specified, or call vTaskDelay()).  If the application makes use of the
 vTaskDelete() API function (as this demo application does) then it is also
 important that vApplicationIdleHook() is permitted to return to its calling
 function, because it is the responsibility of the idle task to clean up
 memory allocated by the kernel to any task that has since been deleted. */
void vApplicationIdleHook(void)
{
}

void vApplicationStackOverflowHook(xTaskHandle pxTask, signed char *pcTaskName)
{
	(void) pcTaskName;
	(void) pxTask;
	/* Run time stack overflow checking is performed if
	 configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	 function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for (;;)
		;
}

StaticTask_t xIdleTaskTCB CCM_RAM;
StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE] CCM_RAM;

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
 implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
 used by the Idle task. */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
		StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
	/* Pass out a pointer to the StaticTask_t structure in which the Idle task's
	 state will be stored. */
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

	/* Pass out the array that will be used as the Idle task's stack. */
	*ppxIdleTaskStackBuffer = uxIdleTaskStack;

	/* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
	 Note that, as the array is necessarily of type StackType_t,
	 configMINIMAL_STACK_SIZE is specified in words, not bytes. */
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

static StaticTask_t xTimerTaskTCB CCM_RAM;
static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH] CCM_RAM;

/* configUSE_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
 application must provide an implementation of vApplicationGetTimerTaskMemory()
 to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
		StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
	*ppxTimerTaskStackBuffer = uxTimerTaskStack;
	*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

