#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This struct is used to keep track and update the lifeline system
//There are 2 askHosts and 2 50/50s available when a game starts
struct lifeLine{
  int askHost;
  int fiftyFifty;
};
  
//Receives question number, a file pointer, and struct pointer, and returns
//either 'T' for True (Correct), 'F' for False (Incorrect), or 'W' if the user wants
//to talk away with their current winnings.
char askQuestion(int questionNum, FILE *fptr, struct lifeLine *lifeptr){

  //char arrays declared to read lines from file input
  char questions[200];
  char correctAnswer[100];
  char userChoice;

  //These arrays are used for the 50/50 lifeline, depending on the correct answer,
  //a random element of the corresponding array is chosen.
  char correctA[3] = {'B','C','D'};
  char correctB[3] = {'A', 'C', 'D'};
  char correctC[3] = {'A', 'B', 'D'};
  char correctD[3] = {'A', 'B', 'C'};

  //Searches through the file until '-' is found, it separates
  //the difficulties of questions in the file on a scale of 1-15
  while(*fgets(questions,100,fptr) != '-'){
    continue;
  }

  //For each difficulty in questions.txt, there are 5 questions of that difficulty. There are 75 total questions.
  //randNum is declared here to be used in the for loop after which chooses a question.
  int randNum = (rand() % 5) * 6;
  //randomOption one and two are used so the output of 50/50 lifeline is more random.
  int randomOptionOne = (rand() % 5) * 6;
  int randomOptionTwo = (rand() % 3);

  //reads lines a certain amount of times depending on the randNum
  //different randNums means different questions get asked each time
  for (int i=0; i<randNum; i++){
    fgets(questions,200, fptr);
  }

  //prints out question to user, as well as each option A, B, C, D.
  fgets(questions, 200, fptr);
  printf("%d. ", questionNum);
  printf("%s", questions);
  
  fgets(questions, 200, fptr);
  printf("%s", questions);

  fgets(questions, 200, fptr);
  printf("%s", questions);

  fgets(questions, 200, fptr);
  printf("%s", questions);

  fgets(questions, 200, fptr);
  printf("%s", questions);

  //reads the correct answer character from file
  fgets(correctAnswer, 100, fptr);

  //this loop, while mostly not used, is so that the user can answer after using a 50/50 lifeline
  int askAgain = 1;
  while(askAgain == 1){

    //recieves input from user
    printf("Your answer: ");
    scanf(" %c", &userChoice);

    //If user tries to use lifeline ask Host when none remain
    while (userChoice == 'H' && lifeptr->askHost == 0){
      printf("No host lifelines remaining!\n");
      printf("Your answer: ");
      scanf(" %c", &userChoice);
    }

    //If user tries to use lifeline 50/50 when none remain
    while (userChoice == 'F' && lifeptr->fiftyFifty == 0){
      printf("No 50/50 lifelines remaining!\n");
      printf("Your answer: ");
      scanf(" %c", &userChoice);
    }

    //Depending on the user's input, many different things can happen.
    //A, B, C, or D will be compared against the correct answer, and 'T' or 'F' will be returned accordingly
    //W will cause 'W' to be returned, meaning the player wishes to walk away with their current winnings
    //H means the player wants to ask the host for the answer, which will reveal it and return 'T'
    //F is for 50/50, a message stating the correct answer and one other option will be revealed
    switch (userChoice){
    case 'A':
    case 'a':
      if (*correctAnswer == 'A'){
	printf("Correct!\n");
	return 'T';
      }
      else{
	printf("Incorrect..\n");
	return 'F';
      }
      break;
    case 'B':
    case 'b':
      if (*correctAnswer == 'B'){
	printf("Correct!\n");
	return 'T';
      }
      else{
	printf("Incorrect..\n");
	return 'F';
      }
      break;
    case 'C':
    case 'c':
      if (*correctAnswer == 'C'){
	printf("Correct!\n");
	return 'T';
      }
      else{
	printf("Incorrect..\n");
	return 'F';
      }
      break;
    case 'D':
    case 'd':
      if (*correctAnswer == 'D'){
	printf("Correct!\n");
	return 'T';
      }
      else{
	printf("Incorrect..\n");
	return 'F';
      }
      break;
    case 'H':
    case 'h':
      printf("The host says... the correct answer is %c!\n", *correctAnswer);
      lifeptr->askHost -= 1;
      return 'T';
    case 'W':
    case 'w':
      return 'W';
    case 'F':
    case 'f':
      if (*correctAnswer == 'A' && randomOptionOne <= 6){
	printf("The correct answer is either %c or %c\n", *correctAnswer, correctA[randomOptionTwo]);
      }
      else if(*correctAnswer == 'A' && randomOptionOne > 6){
	printf("The correct answer is either %c or %c\n", correctA[randomOptionTwo], *correctAnswer);
      }
      if (*correctAnswer == 'B' && randomOptionOne <= 6){
	printf("The correct answer is either %c or %c\n", *correctAnswer, correctB[randomOptionTwo]);
      }
      else if(*correctAnswer == 'B' && randomOptionOne > 6){
	printf("The correct answer is either %c or %c\n", correctB[randomOptionTwo], *correctAnswer);
      }
      if (*correctAnswer == 'C' && randomOptionOne <= 6){
	printf("The correct answer is either %c or %c\n", *correctAnswer, correctC[randomOptionTwo]);
      }
      else if(*correctAnswer == 'C' && randomOptionOne > 6){
	printf("The correct answer is either %c or %c\n", correctC[randomOptionTwo], *correctAnswer);
      }
      if (*correctAnswer == 'D' && randomOptionOne <= 6){
	printf("The correct answer is either %c or %c\n", *correctAnswer, correctD[randomOptionTwo]);
      }
      else if(*correctAnswer == 'D' && randomOptionOne > 6){
	printf("The correct answer is either %c or %c\n", correctD[randomOptionTwo], *correctAnswer);
      }
      if (lifeptr->fiftyFifty != 0){
	lifeptr->fiftyFifty -= 1;
      }
    default:
      break;
    }
    if(askAgain != 1){
      printf("Incorrect..\n");
      return 'F';
    }
  }
  return 'F';
}

int main(){
  //srand used to improve uniqueness of each game
  srand(time(NULL));
  //The moneyAmount array is used to update the current winnings after each correct answer
  int moneyAmount[15] = {0, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 250000, 500000};

  //Initializing lifeline struct to have 2 of each
  struct lifeLine life = {2,2};
  //Created struct pointer so the struct can be changed from inside the function
  struct lifeLine *lifeptr;
  lifeptr = &life;

  //Game introduction
  for(int i=0;i<110;i++){
    printf("-");
  }
  printf("\n");

  printf("WELCOME TO..... WHO WANTS TO BE A MILLIONAIRE??\n");
  printf("\n");
  printf("In this game, YOU have the chance to become a millionaire.\n");
  printf("Enter A B C D for your answer, F for 50/50, H to ask host, or W to walk away with current winnings!\n");
  printf("There are checkpoints at $1000 and $32000, good luck!\n");

  //file pointer declared
  FILE *fptr;

  //file questions.txt opened for reading
  fptr = fopen("questions.txt", "r");

  //result stores the return character from the function askQuestion
  char result;

  //iterates 15 times, once for each question
  for(int i=1; i<=15; i++){
    for(int i=0;i<110;i++){
      printf("-");
    }
    printf("\n");
    printf("$%d QUESTION | Current Winnings: $%d | (F) 50/50: %d | (H) Ask Host: %d | (W) Walk away with current winnings \n", moneyAmount[i], moneyAmount[i-1], lifeptr->fiftyFifty, lifeptr->askHost);
    for(int i=0;i<110;i++){
    printf("-");
    }
    printf("\n");

    //function is called to ask question corresponding to i
    result = askQuestion(i, fptr, lifeptr);
    //If user answers incorrectly
    if (result == 'F'){
      //check for checkpoints
      if(i >10){
	printf("You won $32000!\n");
	fclose(fptr);
	return 0;
      }
      else if(i > 5){
	printf("You won $1000!\n");
	fclose(fptr);
	return 0;
      }
      printf("You lose!\n");
      fclose(fptr);
      return 0;
    }
    //if user wants to walk away
    if (result == 'W'){
       printf("You won $%d!\n", moneyAmount[i-1]);
       fclose(fptr);
       return 0;
    }
  }
  //If all 15 questions are answered correctly
  printf("YOU WON A MILLION DOLLARS!!!!!!\n");
  fclose(fptr);
  return 0;
}
