#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0,Z=0; ///使用global變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2f(-0.61,0.27);
    glVertex2f(-0.36,0.41);
    glVertex2f(-0.07,0.41);
    glVertex2f(0.41,0.33);
    glVertex2f(0.47,0.05);
    glVertex2f(0.47,-0.13);
    glVertex2f(0.17,-0.33);
    glVertex2f(-0.02,-0.37);
    glVertex2f(-0.19,-0.37);
    glVertex2f(-0.53,-0.31);
    glVertex2f(-0.68,-0.17);
    glVertex2f(-0.67,-0.01);
    glVertex2f(-0.64,0.20);
    glEnd();

    glutSwapBuffers();
}

void mouse(int button,int state,int x,int y)
{
    X = (x-150)/150.0;
    Y =-(y-150)/150.0;
    if(state==GLUT_DOWN)printf("   glVertex2f(%.2f,%.2f);\n",X,Y);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutMouseFunc(mouse);
    glutDisplayFunc(display);

    glutMainLoop();
}
