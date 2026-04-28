#include <stdio.h>
#include <stdbool.h>

bool askQuestion(int questionNum, FILE *fptr){

  char questionsEasy[100];
  char correctAnswer[100];
  char userChoice;
  
  fgets(questionsEasy, 100, fptr);
  printf("%d. ", questionNum);
  printf("%s", questionsEasy);
  
  fgets(questionsEasy, 100, fptr);
  printf("A: %s", questionsEasy);

  fgets(questionsEasy, 100, fptr);
  printf("B: %s", questionsEasy);

  fgets(questionsEasy, 100, fptr);
  printf("C: %s", questionsEasy);

  fgets(questionsEasy, 100, fptr);
  printf("D: %s", questionsEasy);

  fgets(correctAnswer, 100, fptr);

  printf("Your answer: ");
  scanf("%c", &userChoice);
  
  switch (userChoice){
  case 'A':
  case 'a':
    if (*correctAnswer == 'A'){
      printf("Correct!\n");
      return true;
    }
    else{
      printf("Incorrect..\n");
      return false;
    }
    break;
  case 'B':
  case 'b':
    if (*correctAnswer == 'B'){
      printf("Correct!\n");
      return true;
    }
    else{
      printf("Incorrect..\n");
      return false;
    }
    break;
  case 'C':
  case 'c':
    if (*correctAnswer == 'C'){
      printf("Correct!\n");
      return true;
    }
    else{
      printf("Incorrect..\n");
      return false;
    }
    break;
  case 'D':
  case 'd':
    if (*correctAnswer == 'D'){
      printf("Correct!\n");
      return true;
    }
    else{
      printf("Incorrect..\n");
      return false;
    }
    break;
  default:
    break;
}
  return true;
}

int main(){

  for(int i=0;i<70;i++){
    printf("-");
  }
  printf("\n");

  printf("WELCOME TO..... WHO WANTS TO BE A MILLIONAIRE??\n");
  printf("In this game, YOU have the chance to become a millionaire.\n");

  printf("Let's Begin!\n");

  FILE *fptr;

  fptr = fopen("questionsEasy.txt", "r");
  
  //possibly simplify with function
  char questionsEasy[100];
  char correctAnswer[100];
  char userChoice;

  (askQuestion(1, fptr));

  //check for Q2 for second questions...
  while(*(fgets(questionsEasy,100,fptr)) != '2'){
    continue;
  }

  fgets(questionsEasy, 100, fptr);
  printf("2. ");
  printf("%s", questionsEasy);

  

  fclose(fptr);

  


  
  return 0;
}
