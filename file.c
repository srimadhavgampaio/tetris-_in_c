#include<ncurses.h>
#include<string.h>//dont need to specify for gcc cause its just a header not a library
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
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
    /*#define WIDTH 30
    #define HEIGHT 10
    int startx = 0;
    int starty = 0;
    char * choices[] = {
        "choice 1",
        "choice 2",
        "choice 3",
        "choice 4"
        "exit",
    };
    int nchoices = sizeof(choices)/ sizeof(char*);
    void print_menue(WINDOW *menue_win,int hightlight);
    int main() {
        WINDOW *menue_win;
        int highlight = 1;
        int choice = 0;
        int c;
        initscr();
        clear();
        noecho();
        cbreak(); //line buffereing disabled
        startx = (80-WIDTH)/2;
        starty = (24-HEIGHT)/2;
        menue_win = newwin(HEIGHT,WIDTH,starty,startx);
        keypad(menue_win,true);
        mvprintw(0,0,"use arrow keys to go up and down,press enter to select a choice");
        refresh();
        print_menue(menue_win,highlight);
        while (1) {
            c = wgetch(menue_win);
            switch(c) {
                case KEY_UP:
                    if (highlight == 1)
                        highlight = nchoices;
                    else
                        --highlight;
                    break;
                case KEY_DOWN:
                    if (highlight == nchoices)
                        highlight = 1;
                    else
                        ++highlight;
                    break;
                case 10:
                    choice = highlight;
                    break;
                default:
                    mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                    refresh();
                    break;
            }
            print_menue(menue_win, highlight);
            if(choice != 0)	/* User did a choice come out of the infinite loop #1#
                break;
        }
        mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
        clrtoeol();
        refresh();
        endwin();
        return 0;
    }
void print_menue(WINDOW *menue_win, int highlight)
    {
        int x, y, i;

        x = 2;
        y = 2;
        box(menue_win, 0, 0);
        for(i = 0; i < nchoices; i++)
        {	if(highlight == i + 1) /* High light the present choice #1#
        {	wattron(menue_win, A_REVERSE);
            mvwprintw(menue_win, y, x, "%s", choices[i]);
            wattroff(menue_win, A_REVERSE);
        }
            else
                mvwprintw(menue_win, y, x, "%s", choices[i]);
            y++;
        }
        wrefresh(menue_win);
    }*/
/*#define width 12
#define height 22
int startx = 0;
int starty = 0;
char * piece = "*";
void printp(WINDOW*board,int posx,int posy);
bool fits(int posx,int posy);
int main() {
    WINDOW * board;
    int posx = 1;
    int posy = 1;
    int c;
    initscr();
    clear();
    noecho();
    cbreak();
    startx = (80 - width)/2;
    starty = (24 - height)/2;
    board = newwin(height,width,starty,startx);
    keypad(board,TRUE);
    mvprintw(0,0,"use arrow keys to move the blcok around use enter to quit");
    refresh();
    printp(board,posx,posy);
    while (1) {
        int flag = 0;
        c = wgetch(board);
        switch (c) {
            case KEY_UP:
                posy--;
                if (fits(posx,posy)) {
                    mvprintw(25,0,"out of bound");
                    refresh();
                    posy++;
                }
                break;
            case KEY_DOWN:
                posy++;
                if (fits(posx,posy)) {
                    mvprintw(25,0,"out of bound");
                    refresh();
                    posy--;
                }
                break;
            case KEY_LEFT:
                posx --;
                if (fits(posx,posy)) {
                    mvprintw(25,0,"out of bound");
                    refresh();
                    posx++;
                }
                break;
            case KEY_RIGHT:
                posx ++;
                if (fits(posx,posy)) {
                    mvprintw(25,0,"out of bound");
                    refresh();
                    posx--;
                }
                break;
            case 10:
                flag ++;
                break;
            default:
                mvprintw(24,0,"character that you pressed is wrong dumbass");
                refresh();
                break;
        }
        printp(board,posx,posy);
        if (flag !=0)
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}
void printp(WINDOW*board,int posx,int posy) {
    werase(board);
    box(board,0,0);
    mvwprintw(board,posy,posx,"%s",piece);
}
bool fits(int posx,int posy) {
    if (posx == 0 || posx == 10)
        return 1;
    if (posy == 0 || posy == 20)
        return 1;
    return 0;
}*/
#define width 12
#define height 22

int startx = 0;
int starty = 0;
char *piece = "*";

void printp(WINDOW *board, int posx, int posy);
bool fits(int posx, int posy);

int main() {
    WINDOW *board;
    int posx = 1;
    int posy = 1;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    startx = (80 - width) / 2;
    starty = (24 - height) / 2;
    board = newwin(height, width, starty, startx);
    keypad(board, TRUE);
    mvprintw(0, 0, "use arrow keys to move the block around, enter to quit");
    refresh();
    printp(board, posx, posy);

    while (1) {
        int flag = 0;
        c = wgetch(board);
        switch (c) {
            case KEY_UP:
                if (fits(posx, posy - 1))
                    posy--;
                break;
            case KEY_DOWN:
                if (fits(posx, posy + 1))
                    posy++;
                break;
            case KEY_LEFT:
                if (fits(posx - 1, posy))
                    posx--;
                break;
            case KEY_RIGHT:
                if (fits(posx + 1, posy))
                    posx++;
                break;
            case 10:
                flag++;
                break;
            default:
                break;
        }
        printp(board, posx, posy);
        if (flag != 0)
            break;
    }
    endwin();
    return 0;
}

void printp(WINDOW *board, int posx, int posy) {
    werase(board);
    box(board, 0, 0);
    mvwprintw(board, posy, posx, "%s", piece);
    wrefresh(board);
}

bool fits(int posx, int posy) {
    return posx >= 1 && posx <= width - 2 &&
           posy >= 1 && posy <= height - 2;
}