#include<GL/glut.h>
int counter=1;
GLfloat grid1[4][4][3]={{{-300,225,0},{-250,225,0},{-50,225,0},{50,225,0}},
						{{-300,250,0},{-250,250,0},{-50,250,0},{50,250,0}},
						{{-300,275,0},{-250,275,0},{-50,275,0},{50,275,0}},
						{{-300,300,0},{-250,300,0},{-50,300,0},{50,300,0}}};
GLfloat grid2[4][4][3]={{{-300,150,0},{-250,150,0},{-50,150,0},{50,150,0}},
						{{-300,175,0},{-250,175,0},{-50,175,0},{50,175,0}},
						{{-300,200,0},{-250,200,0},{-50,200,0},{50,200,0}},
						{{-300,225,0},{-250,225,0},{-50,225,0},{50,225,0}}};
GLfloat grid3[4][4][3]={{{-300,75,0},{-250,75,0},{-50,75,0},{40,75,0}},
						{{-300,100,0},{-250,100,0},{-50,100,0},{50,100,0}},
						{{-300,125,0},{-250,125,0},{-50,125,0},{50,125,0}},
						{{-300,150,0},{-250,150,0},{-50,150,0},{50,150,0}}};
void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-500,500,-500,500,-500,500);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glEnable(GL_MAP2_VERTEX_3);
}
void timer(int value){
for(int i=0;i<4;i++){
if(counter==1){
grid1[i][1][1]+=5;
grid2[i][1][1]+=5;
grid3[i][1][1]+=5;
grid1[i][2][1]-=5;
grid2[i][2][1]-=5;
grid3[i][2][1]-=5;
}
else if(counter==0){
grid1[i][1][1]-=5;
grid2[i][1][1]-=5;
grid3[i][1][1]-=5;
grid1[i][2][1]+=5;
grid2[i][2][1]+=5;
grid3[i][2][1]+=5;
}
}
if(grid3[0][1][1]==125)
counter=0;
if(grid3[0][1][1]==0)
counter=1;

glutTimerFunc(10,timer,20);
glutPostRedisplay();
}
void menu(int id){
if(id==1)
glClearColor(1,0,0,0);
if(id==2)
glClearColor(0.5,0.5,0,0);
if(id==3)
glClearColor(0.5,0.5,0.5,0);

glutPostRedisplay();
}
void drawflag()
{
glMapGrid2f(20,0,1,20,0,1);
glEvalMesh2(GL_FILL,0,20,0,20);
}
void display(){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3f(0,0.5,0.5);
glLineWidth(25);
glBegin(GL_LINES);
glVertex2f(-300,-300);
glVertex2f(-300,315);
glEnd();

glBegin(GL_QUADS);
glColor3f(1,0.5,0);
glVertex2f(-350,-300);
glVertex2f(-250,-300);
glVertex2f(-250,-340);
glVertex2f(-350,-340);

glColor3f(1,1,1);
glVertex2f(-370,-340);
glVertex2f(-230,-340);
glVertex2f(-230,-380);
glVertex2f(-370,-380);

glColor3f(0,1,0);
glVertex2f(-390,-380);
glVertex2f(-210,-380);
glVertex2f(-210,-420);
glVertex2f(-390,-420);
glEnd();

glLineWidth(1);
glColor3f(0,0,1);
glPushMatrix();
glTranslatef(-130,186,0);
glutWireSphere(32,24,2);
glPopMatrix();

glColor3f(1,0.5,0);
glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,4*3,4,&grid1[0][0][0]);
drawflag();

glColor3f(1,1,1);
glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,4*3,4,&grid2[0][0][0]);
drawflag();

glColor3f(0,1,0);
glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,4*3,4,&grid3[0][0][0]);
drawflag();
glFlush();
}
void main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DEPTH);
glutCreateWindow("sdhasd");
init();
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutCreateMenu(menu);
glutAddMenuEntry("Red",1);
glutAddMenuEntry("Yellow",2);
glutAddMenuEntry("clay",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutTimerFunc(10,timer,20);
glutMainLoop();
}
