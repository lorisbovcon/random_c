#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LINE_BLACK           "\e[38;2;0;0;0m"
#define LINE_BEGINNING_COLOR "\x1b[36m"
#define LINE_STATUS          "\x1b[33m"
#define LINE_TIPP            "\x1b[32m"
#define LINE_ERROR           "\x1b[31m"
#define LINE_COLOR_RESET     "\x1b[0m"

FILE *file;
const char HELP_TEXT[256] = "Usage:\n  h-help,\n  q-quit,\n  r-random(usage: r-xy-numper of people in class, x-class number, y-class letter, example: r-2b-26 gets a random person from 2.b with 26 members),\n  n-no(useage: n-2b removes the last entery from 2b),\n", FILE_NAME[16] = "USED_NUMS.txt", LINE_BEGINNING[32] = "RANDOM_NUMBER_GENERATOR> ", ERROR1[24] = "Error-1: Unknown mode!\n";
char input[8], file_line[8], class[16][32][8], chr[2], line[8], to_file[16], temp[8];
int headings[12] = { 0 }, used_numbers[32], num_of_people, rn_unref = 0, refined, klas, class_num;

int math();
int check_whicht_class();
int num_of_class();
int check_nums();
void add_to_file();
void rm_last();
void add_to_class();
void check_file();
void analise_file();
void put_file();
void final_rand(int num_of_people);
void random_my_func(int num_of_people);

int main(){
  while(1){
    printf(LINE_BEGINNING_COLOR "%s" LINE_COLOR_RESET, LINE_BEGINNING);
    scanf("%s", &input);
      switch(input[0]){
        case 'q':
          return 0;
          break;
        case 'h':
          printf("%s\n", &HELP_TEXT);
          break;
        case 'r':
          math();
          break;
        case 'n':
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

int math(){
  check_file();
  printf("%d\n", rn_unref);
}

void check_file(){
  if(!(file = fopen(FILE_NAME, "r"))){
    file = fopen(FILE_NAME, "w");
    strncat(line, &input[1], 6);
    strncat(line, "\n", 2);
    fprintf(file, line);
    fclose(file);
    check_file();
  }
  else{
    fclose(file);
    put_file();
    if(num_of_class() == 1 && input[4] != '-'){
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
    final_rand(num_of_people);
    add_to_class();
    add_to_file();
  }
}

void put_file(){
  file = fopen(FILE_NAME, "r");
  int i = 0;
  int x = -1;
  while(fscanf(file, "%s", file_line) == 1){
    if(file_line[0] == '-'){
      ++x;
      i = 0;
      int h;
      for(h = 0; h < 8; ++h)
        class[x][i][h] = file_line[h];
    }
    else{
      int h;
      for(h = 0; h < 4; ++h)
        class[x][i][h] = file_line[h];
    }
    ++i;
  }
}

void random_my_func(int num_of_people){
  srand(time(NULL));
  rn_unref = ((rand() % num_of_people) + 1);
}

int check_whicht_class(){
  int i;
  for(i = 0; i < 16; ++i){
    if(input[2] == class[i][0][1] && (input[3] == class[i][0][2] || input[3] == class[i][0][3])){
      return i;
    }
  }
  int j = 0;
  for(j = 0; class[j][0][0] == '-'; ++j){}
  strncat(class[j][0], &input[1], 6);
  return j;
}

int check_nums(){
  int i;
  for(i = 1; i <= num_of_people + 1; ++i){
    if(atoi(&class[klas][i][0]) == rn_unref){
      return 1;
    }
  }
  return 0;
}

void final_rand(int num_of_people){
  while((check_nums() != 0)){
    if(rn_unref < num_of_people)
      ++rn_unref;
    else
      rn_unref = 1;
  }
}

void add_to_class(){
  int i;
  for(i = 0; class[klas][i][0] != '\0'; ++i){}
  sprintf(class[klas][i], "%d", rn_unref);
}

void add_to_file(){
  file = fopen(FILE_NAME, "w");
  int kls, prs, j;
  for(kls = 0; kls < 16; ++kls){
    for(prs = 0; prs < 32; ++prs){
      if(class[kls][prs][0] == '\0' && class[kls + 1][0][0] == '\0'){
        fclose(file);
        return;
      }
      for(j = 0; j < 8; ++j)
        to_file[j] = class[kls][prs][j];
      strncat(to_file, "\n", 2);
      fprintf(file, "%s", to_file);
    }
  }
  fclose(file);
}

void rm_last(){
  if(num_of_class() == 1 && input[1] != '-'){
    int in;
    for(in = 0; in < 7; ++in)
      input[in + 1] = class[0][0][in];
  }
	put_file();
	klas = check_whicht_class();
	int i;
	for(i = 0; class[klas][i][0] != '\0'; ++i){}
  class[klas][i - 1][0] = '\0';
  class[klas][i - 1][1] = '\0';
	add_to_file();
}

int num_of_class(){
	int i;
	for(i = 0; i < 15; ++i){
		if(class[i][0][0] != '-'){
			return i;
		}
	}
}
