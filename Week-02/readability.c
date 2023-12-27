#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int main(void)
{   //Getting user iput.
    string txt = get_string("Text: ");

    //letters,words,sentences count to 0.
    int letters = 0;
    int words = 1;
    int sentences = 0;


    //index = 0, keep on going unles i < length of the string,one by one.
    for(int i = 0  , len = strlen(txt); i < len; i++)
    {
        //if its a letter.
        if(isalpha(txt[i])){

            letters++;
        }
        //if its a word.
        else if (txt[i] == ' '  ){

        words++;
    }
    //if its a sentence.
    else if (txt[i] == '!' || txt[i] == '.' || txt[i] == '?'){

        sentences++;
    }

  }
  //"Letters","words" and "sentences" represent a int, but we want a float.
  //so we can cast(convert datatype into another)
  float L = (float) letters / (float) words * 100;
  float S = (float) sentences / (float) words * 100;


  //Coleman-Liau index
  int index = round(0.0588 * L - 0.296 * S - 15.8);

  //Checks if index is less than 1
  if(index < 1){

    printf("Before Grade 1\n");

  }

 //Checks if index is greater than 16
  else if(index > 16){

     printf("Grade 16+\n");

  }

  //if 1 < index < 16 print grade %i
  else{

    printf("Grade %i\n" , index);

  }
}
