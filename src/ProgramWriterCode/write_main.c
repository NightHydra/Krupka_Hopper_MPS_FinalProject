#include "init.h"
#include "spi_flash_interface.h"
#include "SamplePrograms/Simple_test/ApplicationMain.h"


uint8_t read_buf[256] = {0};

//#define ERASE
#define WRITE
#define READx

extern uint32_t _appbegin;
extern uint32_t _append;





uint8_t copyfunc[200];

int main(void){

	Sys_Init();

	// Read the README in the base directory of this project.
	spi_flash_interface_initialize_SPI();

	//spi_flash_interface_validate_chip();

	/**
	memcpy(func, inc-1, 1000);
	uint8_t x = 0;

	void (*myFunc)(uint8_t * );
	myFunc = (void (*)(uint8_t * )) (func-1);
	*/

	uint8_t x = 0;

	//memcpy(copyfunc, (uint8_t *)(appFrame-1), 200);


	uint32_t app_begin_location = (uint32_t)(&_appbegin);
	uint32_t app_end_section = (uint32_t)(&_append);

	uint32_t prog_size = app_end_section - app_begin_location;

	//inc(&x);

	// If we conveniently make sure to copy the previous function then everything
	//     works out alright

	spi_flash_write_func_memory(0x00, prog_size, (uint8_t*) app_begin_location,
			0, (appFrame-1) - app_begin_location);


	printf("WROTE FUNCTION\r\n");

	while(1)
	{

	}
}
