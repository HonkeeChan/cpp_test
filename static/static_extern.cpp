/*
static extern  变量一起使用的效果
*/

/*
static_extern.cpp:6:12: error: ‘i’ was declared ‘extern’ and later ‘static’ [-fpermissive]
 static int i;
            ^
static_extern.cpp:5:12: note: previous declaration of ‘i’
 extern int i;
*/
//extern int i;
//static int i;

/*  OK !!!*/
static int i;
extern int i;


int main(){
    return 0;
}