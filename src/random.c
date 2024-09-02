#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

#define LINE_BEGINNING_COLOR "\x1b[36m"
#define LINE_ERROR           "\x1b[31m"
#define LINE_COLOR_RESET     "\x1b[0m"

FILE *file;
const char HELP_TEXT[256] = "usage:\n  h-help,\n  q-quit,\n  r-random(usage: r-xy-numper of people in class, x-class number, y-class letter, example: r-2b-26 gets a random person from 2.b with 26 members),\n  n-no(useage: n-2b removes the last entery from 2b),\n", file_name[16] = "USED_NUMS.txt", LINE_BEGINING[32] = "random_number_generator> ", ERROR1[8]="a";
char input[8], file_line[8], class[16][32][8], chr[2], line[8], to_file[16], temp[8];
int used_numbers[32], num_of_people, check_num, num_of_clas, refined, klas, class_num;

int main(){
  while(1){
    printf(LINE_BEGINNING_COLOR "%s" LINE_COLOR_RESET, LINE_BEGINNING);
    scanf("%s", &input);
      switch(input[0]){
        case 'q':
          return 0;
          break;
        case 'h':
          printf("%s\n", HELP_TEXT);
          break;
        case 'r':
          check_file();
          put_file();
          num_of_clas = num_of_class();
          if(num_of_clas == 1 && input[4] != '-'){
    	      int in;
    	      for(in = 0; in < 7; ++in)
    		      input[in + 1] = class[0][0][in];
          }
          klas = check_whicht_class();
          int nums;
          for(nums = 1; nums < 32; ++nums)
            if(atoi(class[klas][nums]) != 0)
              used_numbers[nums - 1] = atoi(&class[klas][nums][0]);
          fclose(file);
          if(atoi(&input[5]) != 0)
            num_of_people = atoi(&input[5]);
          else
          num_of_people = atoi(&class[klas][0][4]);
          if(atoi(&class[klas][num_of_people][0]) < num_of_people && atoi(&class[klas][num_of_people][0]) > 0){
            int z;
            for(z = 0; z < 8; ++z)
      	      temp[z] = class[klas][num_of_people +2][z];
            int lokal_klas;
            int lokal_usr;
            for(lokal_klas = 2; lokal_klas < 32; ++lokal_klas)
              for(lokal_usr = 0; lokal_usr < 8; ++lokal_usr)
                class[klas][lokal_klas][lokal_usr] = '\0';
            sprintf(class[klas][1], "%d", rn_unref);
          }
          random_my_func(num_of_people);
          check_num = check_nums();
          final_rand(num_of_people);
          add_to_class();
          add_to_file();
          printf("%d\n", rn_unref);
          break;
        case 'n':
          klas = check_whicht_class();
          num_of_clas = num_of_class();
	        put_file();
        	rm_last();
        	break;
        default:
          printf(LINE_ERROR "%s" LINE_COLOR_RESET, ERROR1);
          printf("%s", HELP_TEXT);
          return -1;
          break;
      }
  }
  return 0;
}
