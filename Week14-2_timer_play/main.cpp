#include <GL/glut.h>
float angle = 0;///step01-1
void timer(int t)
{
    glutTimerFunc(33,timer,t+1);///step01-1
    angle += 3;///角度+0度
    glutPostRedisplay();///step01-1 重畫畫面
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);///step01-2
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);///step01-1
        glutSolidTeapot(0.3);
    glPopMatrix();///step01-1
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14");

    glutKeyboardFunc(keyboard);///step01-2
    ///glutTimerFunc(500,timer,0);///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}
