#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void motion(int x,int y)
{
    glLoadIdentity();
    float eyeX = (x-150)/150.0, eyeY = (150-y)/150.0;
    gluLookAt(eyeX,eyeY,1,   0,0,0,   0,1,0);
    glutPostRedisplay();
}
void reshape(int w, int h)
{///Week15-3
    float ar = w / (float)h;
    glViewport(0, 0, w, h);///Week15-3

    glMatrixMode(GL_PROJECTION);///Week15-3
    glLoadIdentity();///Week15-3
    gluPerspective(60,ar,0.01,1000);///Week15-3

    glMatrixMode(GL_MODELVIEW);///Week15-3
    glLoadIdentity();///Week15-3
    gluLookAt(0,0,1,   0,0,0,   0,1,0);///Week15-3
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week15-3");

    glutReshapeFunc(reshape);///Week15-3
    glutMotionFunc(motion);///Week15-3
    glutDisplayFunc(display);

    glutMainLoop();
}
