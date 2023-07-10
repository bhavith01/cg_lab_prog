#include<GL/glut.h>
void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100,100,-100,100,-100,100);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void display(){
glClearColor(0.5,0.5,0.1,0);
glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

GLfloat abient1[]={0,1,1,1};
GLfloat diffuse1[]={1,0.5,1,1};
GLfloat specular1[]={0.5,0.5,1,1};
GLfloat shininess1[]={25};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,abient1);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse1);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular1);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess1);

GLfloat col1[]={0.5,0.5,0.5,0};
GLfloat pos1[]={25,50,50,0};
glLightfv(GL_LIGHT0,GL_DIFFUSE,col1);
glLightfv(GL_LIGHT0,GL_POSITION,pos1);

glPushMatrix();
glTranslatef(0,30,0);
glRotatef(35,1,0.5,0);
//glScalef(1.5,1.5,0.1);
glutSolidTeapot(10);
glPopMatrix();

GLfloat abient[]={0,1,1,1};
GLfloat diffuse[]={1,1,0,1};
GLfloat specular[]={1,1,0,1};
GLfloat shininess[]={25};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,abient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess);

GLfloat col[]={0.5,0.5,0.5,0};
GLfloat pos[]={25,50,50,0};
glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
glLightfv(GL_LIGHT0,GL_POSITION,pos);
//top
glPushMatrix();
glTranslatef(0,20,0);
glRotatef(-80,1,0.5,0.8);
glScalef(1.5,1.5,0.1);
glutSolidCube(50);
glPopMatrix();

//legs
glPushMatrix();
glTranslatef(-45,-10,-5);
glRotatef(45,0,1,0);
glScalef(0.4,5.5,0.4);
glutSolidCube(10);
glPopMatrix();

glPushMatrix();
glTranslatef(45,-5,-10);
glRotatef(45,0,1,0);
glScalef(0.4,5.5,0.4);
glutSolidCube(10);
glPopMatrix();
glPushMatrix();
glTranslatef(-10,-25,5);
glRotatef(45,0,1,0);
glScalef(0.4,5.5,0.4);
glutSolidCube(10);
glPopMatrix();
glPushMatrix();
glTranslatef(10,5,-35);
glRotatef(45,0,1,0);
glScalef(0.4,5.5,0.4);
glutSolidCube(10);
glPopMatrix();

glFlush();
}
void main(int argc,char **argv){
glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
glutCreateWindow("tea pot");
init();
glutDisplayFunc(display);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glutMainLoop();

}
