#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
char* word;
word = document[n-1][m-1][k-1];
return word;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
char** sentence;
sentence = document[m-1][k-1];
return sentence;
}

char*** kth_paragraph(char**** document, int k) {
    char*** paragraph;
    paragraph = document[k-1];
    return paragraph;
}

char**** get_document(char* text) {
    char**** doc = malloc(sizeof(char ****));
    doc[0] = malloc(sizeof(char ***));
    doc[0][0] = malloc(sizeof(char**));
    doc[0][0][0] = malloc(sizeof(char*));
    
    int i =0;
    int word_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;
    while (*text)
    {
        if(*text == '\n')
        {
            // paragraph
            sentence_count = 0;
            word_count = 0;
            i =0;
            paragraph_count++;
           doc = realloc(doc,(paragraph_count + 1) * sizeof(char****));
           doc[paragraph_count] = malloc(sizeof(char***));
           doc[paragraph_count][sentence_count] =malloc(sizeof(char**));
           doc[paragraph_count][sentence_count][word_count] = malloc(sizeof(char*));
           
        }
        else if (*text == '.') {
           // new sentence
            word_count = 0;
            i = 0;
            sentence_count++;
            doc[paragraph_count]= realloc(doc[paragraph_count] , (sentence_count + 1) * sizeof(char**));
            doc[paragraph_count][sentence_count] = malloc(sizeof(char**));
            
            doc[paragraph_count][sentence_count][word_count] = malloc(sizeof(char*));
        }
        else if (*text == ' ') {
            // new word
            i = 0;
            word_count++;
            doc[paragraph_count][sentence_count] = realloc(doc[paragraph_count][sentence_count] , (word_count+1)* sizeof(char*));
            doc[paragraph_count][sentence_count][word_count] = malloc(sizeof(char*));
        }
        else {
            // new character
            i++;
            doc[paragraph_count][sentence_count][word_count] = realloc( doc[paragraph_count][sentence_count][word_count] , (i+1) * sizeof(char));
            doc[paragraph_count][sentence_count][word_count][i-1] =*text; 
            doc[paragraph_count][sentence_count][word_count][i] ='\0'; 
        }
        text++;
        
    }
    return doc;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}