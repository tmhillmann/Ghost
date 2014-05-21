#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define WORDS 178693 
#define LENGTH 50 
  
char dict[WORDS][LENGTH]; 
int turn; 
int players; 
char word[LENGTH]; 
int playerturn(); 
int compturn(); 
int wincheck(); 
  
int main(void) 
{ 
    word[0]='\0'; 
    turn=1; 
    char filename[] = "dictionary.txt"; 
    FILE *fptr; 
    char  n; 
    int  i; 
    int  j; 
    int  k=0; 
    int  l=0; 
  
    fptr = fopen(filename,"r"); 
  
    i=0; 
    j=0; 
    while (fscanf(fptr,"%c",&n)!=EOF) 
    { 
        if (n!='\n' && n!='\0' && n!=EOF) 
        { 
            dict[i][j]=n; 
            j++; 
        } 
        else
        { 
            dict[i][j]='\0'; 
            i++; 
            j=0; 
        } 
    } 
    dict[i][j]='\0'; 
  
    fclose(fptr); 
  
    printf("Players: "); 
    scanf("%d",&players); 
    fflush(stdout); 
    fflush(stdin); 
    if (players==1) 
    { 
        int seed; 
        printf("Enter a Seed: "); 
        scanf("%d",&seed); 
        fflush(stdout); 
        fflush(stdin); 
        srand(seed); 
    } 
    printf("\n"); 
  
    while (k==0) 
    { 
        if (l==0) 
        { 
            l=playerturn(); 
        } 
        if (l==1) 
        { 
            l=compturn(); 
        } 
        if (l==5) 
        { 
            l=wincheck(); 
        } 
        if (l==10) 
        { 
            k=1; 
        } 
    } 
  
    return 0; 
} 
  
int playerturn() 
{ 
    fflush(stdout); 
    fflush(stdin); 
  
    char letter; 
  
    printf("It is Player %d's turn: %s",(turn+1)%2+1,word); 
  
    scanf("%c",&letter); 
    word[turn-1]=letter; 
    word[turn]='\0'; 
  
    return 5; 
} 
  
int wincheck() 
{ 
    int i; 
    int j; 
    int k; 
    int len; 
    int ghosttest=0; 
  
    len=strlen(word); 
  
    for (i=0;i<WORDS;i++) 
    { 
        j=strcmp(word,dict[i]); 
        k=memcmp(word,dict[i],len); 
        if (j==0 && turn % 2) 
        { 
            printf("\nPlayer 2 Wins\n"); 
            return 10; 
        } 
        if (j==0 && turn+1 % 2) 
        { 
            printf("\nPlayer 1 Wins\n"); 
            return 10; 
        } 
        if (k==0) 
        { 
            ghosttest++; 
        } 
    } 
    if (ghosttest==0) 
    { 
        printf("Ghost \n"); 
        if (turn % 2) 
        { 
            printf("\nPlayer 2 Wins\n"); 
        } 
        if ((turn+1) % 2) 
        { 
            printf("\nPlayer 1 Wins\n"); 
        } 
        return 10; 
    } 
    turn++; 
  
    if ((turn+1) %2 && players==1) 
    { 
        return 1; 
    } 
    if (turn%2) 
    { 
        return 0; 
    } 
    return 0; 
} 
  
int compturn() 
{ 
  
    char tempword[LENGTH]; 
    int templena; 
    int templenb; 
    int len; 
    int i; 
    int j; 
    int k; 
    int l; 
    int m; 
    int breakcheck; 
    int randomizer; 
  
    len=strlen(word); 
    randomizer=rand(); 
  
    printf("It is Player %d's turn: %s",(turn+1)%2+1,word); 
  
    i=randomizer; 
    breakcheck=0; 
    while (i<WORDS && breakcheck==0) 
    { 
        k=memcmp(word,dict[i],len); 
        if (k==0) 
        { 
            strcpy(tempword,dict[i]); 
            templena=strlen(tempword); 
            if (templena % 2) 
            { 
                l=0; 
                for (j=0;j<WORDS;j++) 
                { 
                    templenb=strlen(dict[j]); 
                    if(templenb>len && templenb+1 % 2 && templenb<templena) 
                    { 
                        m=memcmp(tempword,dict[j],templenb); 
                        if (m==0) 
                        { 
                            l++; 
                        } 
                    } 
                } 
                if (l==0) 
                { 
                    word[turn-1]=tempword[turn-1]; 
                    word[turn]='\0'; 
                    breakcheck=1; 
                } 
            } 
        } 
        i++; 
    } 
    i=0; 
    while (i<randomizer && breakcheck==0) 
    { 
        k=memcmp(word,dict[i],len); 
        if (k==0) 
        { 
            strcpy(tempword,dict[i]); 
            templena=strlen(tempword); 
            if (templena % 2) 
            { 
                l=0; 
                for (j=0;j<WORDS;j++) 
                { 
                    templenb=strlen(dict[j]); 
                    if(templenb>len && templenb+1 % 2 && templenb<templena) 
                    { 
                        m=memcmp(tempword,dict[j],templenb); 
                        if (m==0) 
                        { 
                            l++; 
                        } 
                    } 
                } 
                if (l==0) 
                { 
                    word[turn-1]=tempword[turn-1]; 
                    word[turn]='\0'; 
                    breakcheck=1; 
                } 
            } 
        } 
        i++; 
    } 
    i=randomizer; 
    while (i<WORDS && breakcheck==0) 
    { 
        k=memcmp(word,dict[i],len); 
        if (k==0) 
        { 
            strcpy(tempword,dict[i]); 
            word[turn-1]=tempword[turn-1]; 
            word[turn]='\0'; 
            breakcheck=1; 
        } 
        i++; 
    } 
    i=0; 
    while (i<randomizer && breakcheck==0) 
    { 
        k=memcmp(word,dict[i],len); 
        if (k==0) 
        { 
            strcpy(tempword,dict[i]); 
            word[turn-1]=tempword[turn-1]; 
            word[turn]='\0'; 
            breakcheck=1; 
        } 
        i++; 
    } 
    printf("%c\n",word[turn-1]); 
    return 5; 
} 
