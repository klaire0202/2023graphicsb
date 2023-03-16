#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glColor3f(1,0,0);///紅色
    glPushMatrix();
        glRotatef(angle,0,0,1);///改成z軸
        glTranslatef(0.8,0,0);///移到右邊
        glutSolidTeapot(0.3);
    glPopMatrix();

    glColor3f(0,1,0);///綠色
    glPushMatrix();
        glTranslatef(0.8,0,0);///移到右邊
        glRotatef(angle*1.5,0,0,1);///改成z軸
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05");

    glutDisplayFunc(display);
    glutIdleFunc(display);///重畫畫面

    glutMainLoop();
}
