#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
float v[20][2];
int n;
void edgedetect(float x1, float y1, float x2, float y2, int *le, int *re)
{
float mx,x,temp;
int i;
if((y2-y1)<0)
{
temp=y1;
y1=y2;
y2=temp;
temp=x1;
x1=x2;
x2=temp;
}
if((y2-y1)!=0)
mx=(x2-x1)/(y2-y1);
else
mx=x2-x1;
x=x1;
for(i=y1;i<=y2;i++)
{
if(x<(float)le[i])
le[i]=(int)x;
if(x>(float)re[i])
re[i]=(int)x;
x+=mx;
}
}
void draw_pixel(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}
void scanfill(float v[20][2])
{
int le[500],re[500];
int j,i;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
for(i=0;i<n-1;i++)
{
edgedetect(v[i][0],v[i][1],v[i+1][0],v[i+1][1],le,re);
}
edgedetect(v[i][0],v[i][1],v[0][0],v[0][1],le,re);
for(j=0;j<500;j++)
{
if(le[j]<=re[j])
for(i=(int)le[j];i<=(int)re[j];i++)
draw_pixel(i,j);
}
}
void init()
{
glClearColor(1.0,1.0,1.0,1.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glColor3f(1.0,0.0,0.0);
}
void display()
{
int i;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
for(i=0;i<n;i++)
{
glVertex2f(v[i][0],v[i][1]);
}
glEnd();
scanfill(v);
//glFlush();
}
void menu(int id)
{
if (id == 1)
glClearColor(1, 0.5, 0, 0);
if (id==2)
glClearColor(0, 1, 1, 0);
if (id==3)
glColor3f(0, 0, 1);
if (id==4)
glColor3f(1, 1, 0);
glutPostRedisplay();
}
void main(int argc, char **argv)
{
int i;
printf("Enter the number of verices of Polygon\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter values for vertex %d:",i+1);
scanf("%f%f",&v[i][0],&v[i][1]);
}
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(10,10);
glutInitWindowSize(500,500);
glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
init();
glutDisplayFunc(display);
int bgcolor=glutCreateMenu(menu);
glutAddMenuEntry("orange",1);
glutAddMenuEntry("cyan",2);
int fillcolor=glutCreateMenu(menu);
glutAddMenuEntry("blue",3);
glutAddMenuEntry("yellow",4);
glutCreateMenu(menu);
glutAddSubMenu("Background",bgcolor);
glutAddSubMenu("Fill color",fillcolor);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}
