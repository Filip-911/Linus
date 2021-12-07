#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  typedef enum state_t {MENU, WRITE,READ,TERMINATE} state_t;
  state_t state = MENU;
  FILE *fw, *fr;
  char* write_s;
  size_t num_of_bytes;
  

  while(1)
    {
    switch(state)
      {
      case MENU:
	puts("\nMENU:");
	puts("1 - Write to FIFO");
	puts("2 - Read from FIFO");
	puts("3 - Terminate");
	  scanf("%u", &state);
	
	break;
	
      case WRITE:
	puts("How many bytes do you want to write down ?");
	scanf("%zu",&num_of_bytes);
	num_of_bytes = num_of_bytes * 11;
	
	write_s = (char*) malloc(num_of_bytes);
	//write_s[num_of_bytes - 1] = '\0';
	puts("Here: ");
	scanf("%s", write_s);
	printf("%s", write_s);
	
	fw = fopen("/dev/fifo", "a");
	if(fw == NULL)
	{
	  printf("Opening /dev/fifo error\n");
	  return -1;
	}
	
	fprintf(fw,"%s", write_s);
	
	if(fclose(fw))
	  {
	    printf("Closing /dev/fifo error\n");
	    return -1;
	  }
	free(write_s);
	
	state = MENU;
	break;
	  
      case READ:
	
	break;
      case TERMINATE:

	break;
      }
    }

  return 0;
}
