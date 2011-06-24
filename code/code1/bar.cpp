int x=n-1;
int y=m-1;
int index=n+m-1;

while(index>=0 && x>=0 && y>=0){
    if(a[x]>b[y]){
        a[index]=a[x];
        x--;
    }
    else{
        a[index]=b[y];
        y--;
    }
    index--;
}

///trial 1
//copy out remaining elements of b
//
//gave code and algo fast fast
//but forgot the last section
//and is struggling with it 
//why????
//
//


//almost after 10 minutes
//not necessary for a
//
//

char *path=findpath("PATH");
int l=strlen(path);
char ourpath[25][100];
int n=0;
int i=0;
while(i<l){
    if(path[i]!=';'){
        ourpath[n][j]=path[i];
        j++;
    }
    else{
        ourpath[n][j]='\0';
        n++;
        j=0;
    }
    i++;
}

