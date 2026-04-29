#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Reads questions.txt and outputs question to user, returns true if user
//is correct.
bool askQuestion(int questionNum, FILE *fptr){

  char questions[100];
  char correctAnswer[100];
  char userChoice;
  int counter;

  int randNum = (rand() % 3) + 1;
  if (randNum == 1){
    counter = 1;
  }
  else if (randNum == 2){
    counter = 7;
  }
  else if (randNum == 3){
    counter = 13;
  }
   

  //for (int i=0; i<counter; i++){
  //fgets(questions, 100, fptr);
  //}

  fgets(questions, 100, fptr);
  fgets(questions, 100, fptr);
  printf("%d. ", questionNum);
  printf("%s", questions);
  
  fgets(questions, 100, fptr);
  printf("%s", questions);

  fgets(questions, 100, fptr);
  printf("%s", questions);

  fgets(questions, 100, fptr);
  printf("%s", questions);

  fgets(questions, 100, fptr);
  printf("%s", questions);

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

  srand(time(NULL));

  for(int i=0;i<70;i++){
    printf("-");
  }
  printf("\n");

  printf("WELCOME TO..... WHO WANTS TO BE A MILLIONAIRE??\n");
  printf("In this game, YOU have the chance to become a millionaire.\n");

  printf("Let's Begin!\n");

  FILE *fptr;

  fptr = fopen("questions.txt", "r");
  
  //Array sizes might need to be changed for longer questions
  char questions[100];
  char correctAnswer[100];
  char userChoice;

  (askQuestion(1, fptr));

  //check for Q2 for second questions...
  while(*(fgets(questions,100,fptr)) != '2'){
    continue;
  }

  fgets(questions, 100, fptr);
  printf("2. ");
  printf("%s", questions);
  //Next step is to iterate through all 75 questions to make sure they work
  //use function for that

  

  fclose(fptr);

  


  
  return 0;
}
