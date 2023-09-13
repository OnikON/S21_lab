#include <stdio.h>
#include <string.h>

int main(void){
	int input=0;
	char str;
	int num = 0;
	int out = -5;
	while(1){
		str = getchar();
		if (str == '=') break;
		if(str != '\n') {input = input*10 + str-48;
		//printf("%d\n",input);
		}
		else
		{
			
			if(input == -5){
				out = input;
			}
			if(input == -3){
				out = input;
			}
			if(input != -5 && input != -3){
				if(out == -3) num = num - input;
				if(out == -5) num = num + input;
			}
			input = 0;
		}
		

	}
	printf("%d \n",num);
	return 0;
}

