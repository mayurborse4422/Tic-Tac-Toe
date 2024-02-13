#include<stdio.h>
#include<stdlib.h>

char a[3][3];
char syst;
char player;
char player1='X';
char player2='O';
char name[20];

//Printing multiplayer matrix
void cout(){
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player (X) - System (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[0][0],a[0][1],a[0][2]);
	printf("__|_|__\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[1][0],a[1][1],a[1][2]);
	printf("__|_|__\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[2][0],a[2][1],a[2][2]);
	printf("     |     |     \n");	
}

//printing singleplayer matrix
void cout2(){
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player 1 (X) - Player 2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[0][0],a[0][1],a[0][2]);
	printf("__|_|__\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[1][0],a[1][1],a[1][2]);
	printf("__|_|__\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[2][0],a[2][1],a[2][2]);
	printf("     |     |     \n");	
}

//Making a new matrix
void initialize(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=' ';
        }
    }
    cout();
}

//input by user
int input(){
    while(1){
        int b,c;
        scanf("%d",&b);
        scanf("%d",&c);
        if((b>=1 && b<=3) && (c>=1 && c<=3) && (a[b-1][c-1]==' ')){
            return b*10+c;
        }
        else{
            printf("Invalid Move !!\n");
        }
    }
}


//Makes multiplayer game area
void initialize2(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=' ';
        }
    }
    cout2();
}

//For checking winnning condition
int checkwin(){
    for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[i][j]==player){
                c++;
            }
            else if(a[i][j]==syst){
                d++;
            }
        }
        if(c==3){
            cout();
            printf("Congratulations,You Win!!\n");
            //return 1;
            FILE* ptr=fopen("halloffame.txt","a");
            fputs(name,ptr);
            fprintf(ptr, "\n");
            fclose(ptr);
            exit(0);
        }
        else if(d==3){
            cout();
            printf("Better Luck Next Time!!\n");
            //return 1;
            exit(0);
        }
    }
    for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[j][i]==player){
                c++;
            }
            else if(a[j][i]==syst){
                d++;
            }
        }
        if(c==3){
            cout();
            printf("Congratulations,You Win!!\n");
            FILE* ptr=fopen("halloffame.txt","a");
            fputs(name,ptr);
            fprintf(ptr, "\n");
            fclose(ptr);
            //return 1;
            exit(0);
        }
        else if(d==3){
            cout();
            printf("Better Luck Next Time!!\n");
            //return 1;
            exit(0);
        }
    }
    if(a[0][0]==player){
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
            cout();
            printf("Congratulations,You Win!!\n");
            FILE* ptr=fopen("halloffame.txt","a");
            fputs(name,ptr);
            fprintf(ptr, "\n");
            fclose(ptr);
            //return 1;
            exit(0);
        }
    }
    else if(a[0][0]==syst){
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
            cout();
            printf("Better Luck Next Time!!\n");
            //return 1;
            exit(0);
        }
    }
    if(a[0][2]==player){
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0]){
            cout();
            printf("Congratulations,You Win!!\n");
            FILE* ptr=fopen("halloffame.txt","a");
            fputs(name,ptr);
            fprintf(ptr, "\n");
            fclose(ptr);
            //return 1;
            exit(0);
        }
    }
    else if(a[0][2]==syst){
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0]){
            cout();
            printf("Better Luck Next Time!!\n");
            //return 1;
            exit(0);
        }
    }
    return 0;
}

//Calculates system's winning cases
int checkthree(){
    for(int i=0;i<3;i++){
        int c=0;
        for(int j=0;j<3;j++){
            if(a[i][j]==syst){
                c++;
            }
        }
        if(c==2){
            for(int j=0;j<3;j++){
                if(a[i][j]==' '){
                    a[i][j]=syst;
                }
            }
            cout();
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        int c=0;
        for(int j=0;j<3;j++){
            if(a[j][i]==syst){
                c++;
            }
        }
        if(c==2){
            for(int j=0;j<3;j++){
                if(a[j][i]==' '){
                    a[j][i]=syst;
                }
            }
            cout();
            return 1;
        }
    }
    int c=0;
    for(int i=0;i<3;i++){
        if(a[i][i]==syst)c++;
    }
    if(c==2){
        for(int j=0;j<3;j++){
            if(a[j][j]==' '){
                a[j][j]=syst;
            }
        }
        cout();
        return 1;
    }
    c=0;
    for(int i=0;i<3;i++){
        if(a[i][2-i]==syst)c++;
    }
    if(c==2){
        for(int j=0;j<3;j++){
            if(a[j][2-j]==' '){
                a[j][2-j]=syst;
            }
        }
        cout();
        return 1;
    }
    return 0;
}

//Prevents player from winning
int checktwo(){
    for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[i][j]=='X'){
                c++;
            }
            else if(a[i][j]=='O'){
                d++;
            }
        }
        if(c==2 && d==0){
            for(int j=0;j<3;j++){
                if(a[i][j]==' '){
                    a[i][j]='O';
                }
            }
            cout();
            return 1;
        }
        else if(d==2 && c==0){
            for(int j=0;j<3;j++){
                if(a[i][j]==' '){
                    a[i][j]='X';
                }
            }
            cout();
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[j][i]=='X'){
                c++;
            }
            else if(a[j][i]=='O'){
                d++;
            }
        }
        if(c==2 && d==0){
            for(int j=0;j<3;j++){
                if(a[j][i]==' '){
                    a[j][i]='O';
                }
            }
            cout();
            return 1;
        }
        else if(d==2 && c==0){
            for(int j=0;j<3;j++){
                if(a[j][i]==' '){
                    a[j][i]='X';
                }
            }
            cout();
            return 1;
        }
    }
    int c=0,d=0;
    for(int i=0;i<3;i++){
        if(a[i][i]=='X')c++;
        else if(a[i][i]=='O')d++;
    }
    if(c==2 && d==0){
        for(int j=0;j<3;j++){
            if(a[j][j]==' '){
                a[j][j]='O';
            }
        }
        cout();
        return 1;
    }
    else if(d==2 && c==0){
        for(int j=0;j<3;j++){
            if(a[j][j]==' '){
                a[j][j]='X';
            }
        }
        cout();
        return 1;
    }
    c=0,d=0;
    for(int i=0;i<3;i++){
        if(a[i][2-i]=='X')c++;
        else if(a[i][2-i]=='O')d++;
    }
    if(c==2 && d==0){
        for(int j=0;j<3;j++){
            if(a[j][2-j]==' '){
                a[j][2-j]='O';
            }
        }
        cout();
        return 1;
    }
    else if(d==2 && c==0){
        for(int j=0;j<3;j++){
            if(a[j][2-j]==' '){
                a[j][2-j]='X';
            }
        }
        cout();
        return 1;
    }
    return 0;
}

//Singleplayer Game
void tryfirst(){
    syst='O';
    player='X';
    int o=input();
    int r=o/10,c=o%10;
    a[r-1][c-1]='X';
    if(r-1==1 && c-1==1){
        a[0][0]='O';
        cout();
        int o1=input();
        int r1=o1/10,c1=o1%10;
        a[r1-1][c1-1]='X';
        if(r1-1==2 && c1-1==2){
            a[0][1]='O';
            cout();
        }
        else{
            checktwo();
        }
        int o2=input();
        int r2=o2/10,c2=o2%10;
        a[r2-1][c2-1]='X';
        checkwin();
        checkthree();
        checkwin();
        checktwo();
        int o3=input();
        int r3=o3/10,c3=o3%10;
        a[r3-1][c3-1]='X';
        checkwin();
        checkthree();
        checkwin();
        checktwo();
        int o4=input();
        int r4=o4/10,c4=o4%10;
        a[r4-1][c4-1]='X';
        cout();
        checkwin();
        checkthree();
        checkwin();
        checktwo();
        printf("GAME OVER !!!!\n");
        printf("The result is tie !");
    }
    else{
        a[1][1]='O';
        cout();
        if((r-1==1 && c-1==0) || (r-1==0 && c-1==1) || (r-1==1 && c-1==2) || (r-1==2 && c-1==1)){
            int o1=input();
            int r1=o1/10,c1=o1%10;
            a[r1-1][c1-1]=player;
            if(!checktwo()){
                if(a[0][1]==player && a[1][2]==player)a[0][2]=syst;
                else if(a[2][1]==player && a[1][2]==player)a[2][2]=syst;
                else if(a[2][1]==player && a[1][0]==player)a[2][0]=syst;
                else if(a[0][1]==player && a[1][0]==player)a[0][0]=syst;
                else if(a[0][0]==' ')a[0][0]=syst;
                else if(a[2][0]==' ')a[2][0]=syst;
                else if(a[0][2]==' ')a[0][2]=syst;
                cout();
            }
            checkwin();
            int o2=input();
            int r2=o2/10,c2=o2%10;
            a[r2-1][c2-1]=player;
            checkwin();
            checkthree();
            checkwin();
            if(!checktwo()){
                if(a[0][0]==' ')a[0][0]=syst;
                else if(a[2][0]==' ')a[2][0]=syst;
                else if(a[0][2]==' ')a[0][2]=syst;
                cout();
            }
            int o3=input();
            int r3=o3/10,c3=o3%10;
            a[r3-1][c3-1]=player;
            checkwin();
            checkthree();
            checkwin();
            checktwo();
            if(!checktwo()){
                if(a[0][0]==' ')a[0][0]=syst;
                else if(a[2][0]==' ')a[2][0]=syst;
                else if(a[0][2]==' ')a[0][2]=syst;
                cout();
            }
            int o4=input();
            int r4=o4/10,c4=o4%10;
            a[r4-1][c4-1]=player;
            checkwin();
            checkthree();
            checkwin();
            checktwo();
            printf("GAME OVER !!!!\n");
            printf("The result is tie !");
        }
        else{
            int o1=input();
            int r1=o1/10,c1=o1%10;
            a[r1-1][c1-1]=player;
            if((r1-1==1 && c1-1==0) || (r1-1==0 && c1-1==1) || (r1-1==1 && c1-1==2) || (r1-1==2 && c1-1==1)){
                if(!checktwo()){
                    if(a[0][0]==' ')a[0][0]=syst;
                    else if(a[2][0]==' ')a[0][2]=syst;
                    else if(a[0][2]==' ')a[2][0]=syst;
                    cout();
                }
                int o2=input();
                int r2=o2/10,c2=o2%10;
                a[r2-1][c2-1]=player;
                checkwin();
                checkthree();
                checkwin();
                checktwo();
                int o3=input();
                int r3=o3/10,c3=o3%10;
                a[r3-1][c3-1]=player;
                checkwin();
                checkthree();
                checkwin();
                int flag=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(a[i][j]==' '){a[i][j]=syst;flag=1;break;}
                        
                    }
                    if(flag==1)break;
                }
                cout();
                int o4=input();
                int r4=o4/10,c4=o4%10;
                a[r4-1][c4-1]=player;
                checkwin();
                checkthree();
                checkwin();
                checktwo();
                printf("GAME OVER !!!!\n");
                printf("The result is tie !");
            }
            else{
                if(!checktwo()){
                    if(a[0][1]==' ')a[0][1]=syst;
                    else if(a[1][0]==' ')a[1][0]=syst;
                    else if(a[1][2]==' ')a[1][2]=syst;
                    else if(a[2][1]==' ')a[2][1]=syst;
                    cout();
                }
                int o2=input();
                int r2=o2/10,c2=o2%10;
                a[r2-1][c2-1]=player;
                checkwin();
                checkthree();
                checkwin();
                if(!checktwo()){
                    if(a[0][1]==' ')a[0][1]=syst;
                    else if(a[1][0]==' ')a[1][0]=syst;
                    else if(a[1][2]==' ')a[1][2]=syst;
                    else if(a[2][1]==' ')a[2][1]=syst;
                    cout();
                }
                int o3=input();
                int r3=o3/10,c3=o3%10;
                a[r3-1][c3-1]=player;
                checkwin();
                checkthree();
                checkwin();
                checktwo();
                int o4=input();
                int r4=o4/10,c4=o4%10;
                a[r4-1][c4-1]=player;
                cout();
                checkwin();
                checkthree();
                checkwin();
                checktwo();
                printf("GAME OVER !!!!\n");
                printf("The result is tie !");
            }
        }

    }
}

//Multiplayer Game
void trysecond(){
     int p=0;
     int i=0;
     while(i<9){
        int r,c;
        scanf("%d%d",&r,&c);
        if((r<1) || (r>3) || (c<1) || (c>3) || (a[r-1][c-1]!=' ')){
            printf("Invalid Move !!\n");
        }
        else{
        if(i%2==0){
        a[r-1][c-1]='X';
        cout2();
        }
        else{
            a[r-1][c-1]='O';
            cout2();
        }
        for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[i][j]==player1){
                c++;
            }
            else if(a[i][j]==player2){
                d++;
            }
        }
        if(c==3){
            cout2();
            printf("player 1 Wins!!\n");
            p++;
            exit(0);
        }
        else if(d==3){
            cout2();
            printf("player 2 Wins!!\n");
            p++;
            exit(0);
        }
    }
    for(int i=0;i<3;i++){
        int c=0,d=0;
        for(int j=0;j<3;j++){
            if(a[j][i]==player1){
                c++;
            }
            else if(a[j][i]==player2){
                d++;
            }
        }
        if(c==3){
            cout2();
            printf("player 1 Wins!!\n");
            p++;
            exit(0);
        }
        else if(d==3){
            cout2();
            printf("player 2 Wins!!\n");
            p++;
            exit(0);
        }
    }
    if(a[0][0]==player1){
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
            cout2();
            printf("player 1 Wins!!\n");
            p++;
            exit(0);
        }
    }
    else if(a[0][0]==player2){
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
            cout2();
            printf("player 2 win!!\n");
            p++;
            exit(0);
        }
    }
    if(a[0][2]==player1){
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0]){
            cout2();
            printf("player 1 Wins!!\n");
            p++;
            exit(0);
        }
    }
    else if(a[0][2]==player2){
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0]){
            cout2();
            printf("player 2 Wins!!\n");
            p++;
            exit(0);
        }
    }
    i++;
    }
    }
    if(p==0){
        cout2();
            printf("The game is tie\n");
            exit(0);
    }
}

int main(){
    system("color 0a");
    printf("\n\nWelcome to TIC-TAC-TOE\n");
    printf("\n");
    printf("-----------------------------\n");
    printf("\n");
    int entry;
    printf("1 : Singleplayer\n");
    printf("2 : Multiplayer\n");
    printf("3 : Hall of Fame\n");
    scanf("%d",&entry);
    if(entry==1){
        printf("Enter your name :\n");
        scanf("%s",name);
        printf("\n\n       Instructions...   \n\n");
        printf("1. To select a box in the grid enter the coordinate corresponding to the box with space\n");
        printf("2. The top-left box has a coordinate : 1 1\n");
        printf("3. Only enter numbers while selecting coordinates\n");
        initialize();
        tryfirst();
    }
    else if(entry==2){
        printf("\n\n       Instructions...   \n\n");
        printf("1. To select a box in the grid enter the coordinate corresponding to the box with space\n");
        printf("2. The top-left box has a coordinate : 1 1\n");
        printf("3. Only enter numbers while selecting coordinates\n");
        initialize2();
        trysecond();
    }
    else{
        FILE* ptr=fopen("halloffame.txt","r");
        char str[20];
        int c=1;
        printf("___________HALL OF FAME__________\n\n\n");
        while (fgets(str, 20, ptr) != NULL){
            printf("                                %d. %s                             \n",c,str);
            c++;
        }
        fclose(ptr);
    }
}