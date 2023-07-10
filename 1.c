#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
int x1,x2,y11,y2;
void plot(int x,int y){
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
void brensen(){
int x,dx,dy,y,xinc,yinc,pk;
dx=x2-x1;
dy=y2-y11;
x=x1;
y=y11;
plot(x1,y11);
if(dx>0)
xinc=1;
else
xinc=-1;
if(dy>0)
yinc=1;
else
yinc=-1;
if(fabs(dx)>fabs(dy)){
pk=2*fabs(dy)-fabs(dx);
for(int i=0;i<dx;i++){
if(pk>0){
pk=pk+2*fabs(dy)-2*fabs(dx);
y=y+yinc;
}
else{
pk=pk+2*fabs(dy);
y=y;
}
x=x+xinc;
plot(x,y);
}
}
else{
pk=2*fabs(dx)-fabs(dy);
for(int i=0;i<dy;i++){
if(pk>0){
pk=pk+2*fabs(dx)-2*fabs(dy);
x=x+xinc;
}
else{
pk=pk+2*fabs(dx);
x=x;
}
y=y+yinc;
plot(x,y);
}
}

}
void display(){
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
brensen();
glFlush();
}
void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void main(int argc,char **argv){
glutInit(&argc,argv);
printf("Enter the points");
scanf("%d %d %d %d",&x1,&y11,&x2,&y2);
glutInitWindowSize(-500,500);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutCreateWindow("lab 1");
init();
glutDisplayFunc(display);
glutMainLoop();
}
