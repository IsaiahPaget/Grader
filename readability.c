#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

    //get text from user
    string text = get_string("text: ");
    printf("text: %s\n", text);


    int words = 1;
    int sentences = 0;
    int letters = 0;
    for ( int i = 0; i < strlen(text); i++)
    {
        //number of letters in text
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        letters ++;
        //number of sentences
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        sentences ++;
        //words
        if(text[i] == ' ')
            words ++;
    }
    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);



    //get grade
    float L = (float)letters / ((float)words) *100;
    float S = (float)sentences / ((float)words) *100;

    float calc = (0.0588 * L - 0.296 * S - 15.8);
    int x = round(calc);

    if (x < 16 && x > 0)
        printf("Grade %i\n", x);
    else if (x <= 0)
        printf("Before Grade 1\n");
    else
        printf("Grade 16+\n");
}