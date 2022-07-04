#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winuser.h> 
#include <windows.h>


void gotoxy(int column, int line);

COORD coord = { 0, 0 };

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu();
void transiction();
void timer();
void clockPointer();
void hidecursor();
int diagram();
void autoMenu();
void cursor();
int message(int msg);


int main(void) {

    //Set terminal window size
    SMALL_RECT windowSize = {0,0, 38, 35};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

    //Hide terminal scrollbars
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);

    //Fixed window  size
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    hidecursor();
    menu();

    return 0;
}


void transiction() {
    for(int i = 10; i > 0; i--){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t Be ready!" );
        Sleep(100);
        system("cls");
        Sleep(100);
    }
}
void menu(){
    
    char option;
    system("cls");
    printf("\n  ----------- POMODORO-CLI ------------\n");
    diagram(2);
    printf("\n\n\n            Choose an option:\n\n\n");
    printf("\t       [f] Focus\n");
    printf("\t       [b] Break\n");
    printf("\t       [r] Rest\n");
    printf("\t       [c] Config\n");
    printf("\t       [h] About\n\n");
    printf("\t       [q] Quit\n\n");
    
    cursor();
    option = getchar();

    //scanf("%c", &option);
    
    if (option == 'q'){system("cls"); exit(0);}
    if (option != 'f' && option != 'b' && option != 'r' && option != 'c' && option != 'h') {
        fflush(stdin);//Limpar entrada
        menu();
    } 
    switch (option) {
        case 'f':
            fflush(stdin);
            system("cls");
            transiction();
            timer(1);
            break;
        case 'b':
            fflush(stdin);
            system("cls");
            transiction();
            timer(2);
            break;
        case 'r':
            fflush(stdin);
            system("cls");
            transiction();
            timer(3);
            break;
        case 'c':
            fflush(stdin);
            system("cls");
            printf("Nothing here...");
            break;
        case 'h':
            fflush(stdin);
            system("cls");
            printf("Nothing here...");
            break;
        default:
            break;
    }
    
}
void timer(int option) {

    /// Focus mode ///////////////////////////////////////////// 
    int min=25, sec=0, i=0;   
    if (option == 1) {
        do{
            system("cls");//limpa a tela
            printf("\n\n\n\t         In focus!\n\n\n");
            diagram(1);
            if (min < 10) {
                if (sec < 10) {
                    printf("\n\n\t           0%d:0%d\n\n",min,sec);
                }else {
                    printf("\n\n\t           0%d:%d\n\n",min,sec);
                }
            }else {
                if (sec < 10) {
                    printf("\n\n\t           %d:0%d\n\n",min,sec);
                }else {
                    printf("\n\n\t           %d:%d\n\n",min,sec);
                }
            }
            message(1);
            if (sec == 0) {
                sec = 60;
                min--;
            }
            Sleep(1000);
            sec--;

            if (min == 0 && sec == 0) autoMenu();
            
        }while (i == 0);

    }
    /// Break mode ///////////////////////////////////////////// 
    else if (option == 2){
    int min=5, sec=0, i=0; 
        do {
            system("cls");//limpa a tela
            printf("\n\n\n\t        Break time!\n\n\n");
            diagram(1);
            if (sec < 10) {
                printf("\n\n\t           0%d:0%d\n\n",min,sec);
            } else {
                printf("\n\n\t           0%d:%d\n\n",min,sec);
            }
            message(2);
            /// timer ////////////////////////////
            if (sec == 0) {
                sec = 60;
                min--;
            }
                Sleep(1000);
                sec--;
            ////////////////////////////////////
            if (min == 0 && sec == 0) {
                autoMenu();
            }
            
        }while (i==0);

    }
    /// Rest mode ///////////////////////////////////////////// 
    else if (option == 3) {
        int min = 15; sec = 0; 

        for( ; ; ) {

            system("cls");
            printf("\n\n\n\t       Time to rest!\n\n\n");
            diagram(1);
            // Minute below of 10!
            if ( min < 10) {
                //if second be lower than 10...
                if (sec < 10){// Second Lower!
                    printf("\n\n\t           0%d:0%d\n\n",min,sec);
                }else {// Second not lower!
                    printf("\n\n\t           0%d:%d\n\n",min,sec);
                }
            // Minute above of 10!
            }else {
                if(sec < 10){
                    printf("\n\n\t           %d:0%d\n\n",min,sec);
                } else {
                    printf("\n\n\t           %d:%d\n\n",min,sec);
                }
            }
            message(3);
            //timer
            if (sec == 0) {
                sec = 60;
                min--;
            }
                Sleep(1000);
                sec--;
            if (min == 0 && sec == 0) {
                autoMenu();
            }
            
        }

    }
    
    
}
void hidecursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int diagram(int option) {
    if (option == 1) {
        printf("                 _.-'''-._              \n");
        printf("            _.-''         ''-._         \n");
        printf("           '-.               .-'        \n");
        printf("           '-_'-._       _.-'.-'        \n");
        printf("            ||T+._'-._.-'_.-'|          \n");
        printf("            ||:   '-.:..-' :||          \n");
        printf("            || .     ||  .  ||          \n");
        printf("            ||  .    || .   ||          \n");
        printf("            ||   ';.:||'    ||          \n");
        printf("            ||    '::||     ||          \n");
        printf("            ||      )||     ||          \n");
        printf("            ||     ':||     ||          \n");
        printf("            ||   .' :||.    ||          \n");
        printf("            ||  ' . :||.'   ||          \n");
        printf("            ||.'-  .:|| -'._||          \n");
        printf("          .-'': .::::||:. : ''-.        \n");
        printf("          :'-.'::::::||::'  .-':        \n");
        printf("           '-.'-._'--:'  .-'.-'         \n");
        printf("              '-._'-._.-'.-'            \n");
        printf("                  '-.|.-'               \n");
    }
    if (option == 2){

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
        printf("\n\n\n\t         \n");
        printf("\t       ,,");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
        printf("m");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  
        printf(" ,");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  
        printf(",");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("m");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  
        printf(",,   \n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
        printf("\t     ,,,,,,");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
        printf("@@");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
        printf(" ,,,,,   \n");
        printf("\t    ,,,,,");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
        printf("m");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
        printf(",,,,");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
        printf("m");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
        printf(",,,,, \n");
        printf("\t    ,,,,,,,,,,,,,,,,\n");
        printf("\t    ,,,,,,,,,,,,,,,,\n");
        printf("\t     ,,,,,,,,,,,,,, \n");
        printf("\t       ,,,,,,,,,,     \n");
        
        SetConsoleTextAttribute(hConsole, saved_attributes);
    
    }
    return 0;
}
void autoMenu() {
    system("cls");
    
    for (int count = 0; count <= 5; count++){
        printf("\n\n\n\t         Time's Up!\n\n\n");
        diagram(1);
        printf("\n\n\t           00:00\n\n");
        Sleep(250); 
        system("cls");
        Sleep(250); 
        system("cls");
    }
    //loop for...
    char msg[24] = "Returning to menu";
    char point [5] = "";
    for (int count = 0; count < 4 ; count++){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t     %s%s\n\n", msg, point);
        Sleep(1000);
        system("cls");
        point[count]='.';
         
    }
    return menu();
}
void cursor() {
    
    printf("\n\t       > ");
           
    
}
int message(int msg) {

    if (msg == 1) {
        printf("\n\n    \"It is during our darkest moments\n        that we must focus to see\n\t       the light.\"\t");
    }
    if (msg == 2) {
       printf("\n\n        \"I am calm while the storm\n           is raging around me.\"");    
    }
    if (msg == 3) {
        printf("\n\n\t    \"If you get tired.\n        Learn to rest not to quit.\"");
    }
    return(0);
}
void clockPointer(){
    char clock[8]= {'\x7c', '\x2f', '\x2d', '\x5c', '\x7c', '\x2f', '\x2d', '\x5c'};
    for (int i = 0 ; i < 7 ; i++ ){
        printf("\n\n\t\t%c\n", clock[i]);
        Sleep(100);
        system("cls");
    }
}









