#include<stdio.h>
#include<GL/glut.h>
float view[3]={0,0,100};
GLfloat v[8][3]={{-200,200,200},{200,200,200},{200,-200,200},{-200,-200,200},{-200,200,-200},{200,200,-200},{200,-200,-200},{-200,-200,-200}};
void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-500,500,-500,500,-500,2000);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void cube(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d){
glBegin(GL_POLYGON);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glVertex3fv(d);
glEnd();
}
void display(){
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glRotatef(a,1,1,1);

glColor3f(0.1,0.1,0.6);
cube(v[0],v[1],v[2],v[3]);

glColor3f(0.6,0.1,0.1);
cube(v[4],v[5],v[6],v[7]);

glColor3f(0.6,0.1,0.6);
cube(v[0],v[4],v[7],v[3]);

glColor3f(1,0.1,0.6);
cube(v[0],v[1],v[5],v[4]);

glColor3f(0.6,0.1,0.6);
cube(v[1],v[5],v[6],v[2]);

glColor3f(0.2,0.1,0.2);
cube(v[2],v[3],v[7],v[6]);

glFlush();
}
void keys(unsigned char k,int x,int y){
if(k=='x')view[0]+=10;
}
void main(int argc,char **argv){
glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("Lab 3");
init();
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutKeyboardFunc(keys);
glutMainLoop();
}
