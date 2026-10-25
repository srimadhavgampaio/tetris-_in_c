#include<ncurses.h>
#include<string.h>//dont need to specify for gcc cause its just a header not a library
#include<stdlib.h>
#include<stdio.h>
int main(int argc , char* argv[]) {
    // argc hods the lines and arg v holds the string
    /*int ch = 121;
    noecho();
    initscr();
    //addch(ch|A_BOLD|A_UNDERLINE);
    printw("hello world");
    refresh();
    getch();
    endwin();*/
    /*char msg[] = "just a string";
    int row ,col;
    initscr();
    getmaxyx(stdscr,row,col);
    mvprintw(row/2,(col-strlen(msg))/2,"%s",msg);
    mvprintw(row-2,0,"this screen has %d rows and %d columns\n",row,col);
    printw("try resizing your window and then run this program again");
    refresh();
    getch();
    endwin();*/
    /*char msg[] = "something yoo";
    char str[80];
    int row,col;
    initscr();
    getmaxyx(stdscr,row,col);//gets max rows and coloumns
    mvprintw(row/2,(col-strlen(str))/2,"%s",str);
    getstr(str);
    mvprintw(LINES-2,0,"you enteredd:%s",str);
    //lines is the total no of rows and cols is the total number of coloumsn
    getch();
    endwin();*/
    /*int ch, prev, row,col;
    prev = EOF;
    FILE *fp;
    int y,x;
    if (argc !=2) {
        printf("usage %s <a c file name>/n",argv[0]);
        exit(1);
    }
    fp = fopen(argv[1],"r");
    if (fp == NULL) {
        perror("cannont open input file");
        exit(1);
    }
    initscr();
    getmaxyx(stdscr,row,col);
    while (ch = fgetc(fp) != EOF){
        getyx(stdscr,y,x);
        if (y == (row-1)) {
            printw("press and key");
            getch();
            clear();
            move(0,0);
        }
        if (prev == '/'&&ch == '*') {
            attron(A_BOLD);
            getyx(stdscr,y,x);
            move(y,x-1);
            printw("%c%c",'/',ch);
        }
        else
            printw("%c",ch);
        refresh();
        if (prev == '*' && ch == '/')
            attroff(A_BOLD);
        prev = ch;
}
    endwin();
    fclose(fp);*/
    /*int ch;
    initscr();
    noecho();
    ch = getch();
    printw("%c",ch);
    refresh();
    getch();
    endwin();*/
    /*int ch;
    initscr();
    noecho();
    keypad(stdscr,TRUE);
    refresh();
    while (ch != 'q') {
        ch = getch();
        if (ch == KEY_LEFT)
            printw("left arrow is pressed \n");
    }
    endwin();*/
    

}