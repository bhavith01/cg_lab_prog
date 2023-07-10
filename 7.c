#include<stdio.h>
#include<GL/glut.h>
int n;
GLfloat v[4][3]={{0.0,0.0,0.5},{-0.5,-0.5,-0.5},{0.5,-0.5,-0.5},{0,0.5,-0.5}};

void init(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1,1,-1,1,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void tri(GLfloat *a,GLfloat *b,GLfloat *c){
glBegin(GL_TRIANGLES);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d){
glColor3f(1,0,0);
tri(a,b,c);
glColor3f(0,1,0);
tri(a,d,b);
glColor3f(0,0,1);
tri(b,c,d);
glColor3f(0.6,0.5,0);
tri(a,d,c);
}
void divtetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int n){
GLfloat m[6][3];
if(n>0){
for(int i=0;i<3;i++){
m[0][i]=(a[i]+b[i])/2;
m[1][i]=(a[i]+c[i])/2;
m[2][i]=(b[i]+c[i])/2;
m[3][i]=(a[i]+d[i])/2;
m[4][i]=(b[i]+d[i])/2;
m[5][i]=(c[i]+d[i])/2;
}
divtetra(a,m[0],m[1],m[3],n-1);
divtetra(m[0],b,m[2],m[4],n-1);
divtetra(m[1],m[2],c,m[5],n-1);
divtetra(m[3],m[4],m[5],d,n-1);
}
else{
tetra(a,b,c,d);
}
}
void display(){
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
divtetra(v[0],v[1],v[2],v[3],n);
glFlush();
}
void main(int argc,char **argv){
printf("Enter the n:  ");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitWindowSize(900,900);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
glutCreateWindow("tetra");
init();
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}
