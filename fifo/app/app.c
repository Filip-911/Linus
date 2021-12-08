#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  typedef enum state_t {MENU, WRITE,READ,TERMINATE} state_t;
  state_t state = MENU;
  FILE *fw, *fr;
  char* str;
  unsigned char i=0;
  size_t num_of_bytes;
  int read_size = 1;
  char c;
  

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
	
	str = (char*) malloc(num_of_bytes * sizeof(char));
	str[num_of_bytes - 1] = '\0';
	puts("Here: ");
	scanf("%s", str); //getline propadne ?
	  printf("%s\n", str);
	
	fw = fopen("/dev/fifo", "w");
	if(fw == NULL)
	{
	  printf("Opening /dev/fifo error\n");
	  return -1;
	}
	
	fprintf(fw,"%s", str);
	
	if(fclose(fw))
	  {
	    printf("Closing /dev/fifo error\n");
	    return -1;
	  }
	free(str);
	
	state = MENU;
      break;
	  
      case READ:
	puts("How many bytes do you want to read ?");
	scanf("%zu",  &num_of_bytes);
	
	fr = fopen("/dev/fifo", "w");
	if(fr == NULL)
	  {
	    puts("Error while writing n");
	    return -1;
	  }
	
	fprintf(fr,"num=%zu\n",num_of_bytes);
	//printf("num_of_bytes: %d", num_of_bytes);

	if(fclose(fr))
	  {
	    printf("Closing /dev/fifo error\n");
	    return -1;
	  }
	
	num_of_bytes = num_of_bytes * 24;
	
	fr = fopen("/dev/fifo", "r");
	if(fr == NULL)
	  {
	    puts("Error while opening /dev/fifo");
	    return -1;
	  }
	str = (char*) calloc(num_of_bytes, sizeof(char));
	str [num_of_bytes - 1] = '\0';
	//TODO
	getdelim(&str, &num_of_bytes, ';', fr);
	printf("%s", str);
	//
	if(fclose(fr))
	  {
	    printf("Closing /dev/fifo error\n");
	    return -1;
	  }
	
	free (str);
	state = MENU;
      break;

      case TERMINATE:
	return 0;
	break;
      }
    }

  return 0;
}
