#include<stdio.h>
#include<GL/glut.h>
int theta;
void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void fixed(){
glLoadIdentity();
glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(-200,-90);
glVertex2f(-410,-310);
glVertex2f(-90,-310);
glEnd();
glColor3f(0.9,0.1,0.7);
glBegin(GL_TRIANGLES);
glVertex2f(-200,-100);
glVertex2f(-400,-300);
glVertex2f(-100,-300);
glEnd();

glTranslatef(-200,-100,0);
glRotatef(theta,0,0,1);
glTranslatef(200,100,0);
glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(-200,-90);
glVertex2f(-410,-310);
glVertex2f(-90,-310);
glEnd();
glColor3f(0.9,0.1,0.7);
glBegin(GL_TRIANGLES);
glVertex2f(-200,-100);
glVertex2f(-400,-300);
glVertex2f(-100,-300);
glEnd();

}
void orgin(){
glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(90,90);
glVertex2f(200,310);
glVertex2f(310,90);
glEnd();
glColor3f(0.9,0.1,0.7);
glBegin(GL_TRIANGLES);
glVertex2f(100,100);
glVertex2f(200,300);
glVertex2f(300,100);
glEnd();

glRotatef(theta,0,0,1);
glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(90,90);
glVertex2f(200,310);
glVertex2f(310,90);
glEnd();
glColor3f(0.9,0.1,0.7);
glBegin(GL_TRIANGLES);
glVertex2f(100,100);
glVertex2f(200,300);
glVertex2f(300,100);
glEnd();
}
void display(){
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT);
orgin();
fixed();
glFlush();
}
void main(int argc,char **argv){
glutInit(&argc,argv);
printf("Enter the angle: ");
scanf("%d",&theta);
glutInitWindowSize(500,500);
glutInitWindowPosition(-10,10);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("Lab 2");
init();
glutDisplayFunc(display);
glutMainLoop();
}
