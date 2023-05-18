#include <GL/glut.h>
float angle= 0, oldAngle = 0, newAngle = 0;///step02-2 宣告 新角度 舊角度
float oldX = 0;///step02-2 舊的x座標
void timer(int t)
{
    if(t<100) glutTimerFunc(33,timer,t+1);///step02-2
    float alpha = t/100.0;///step02-2 所以 alpha 0.0~1.0 之間
    angle = alpha*newAngle + (1-alpha)*oldAngle;///step02-2
    glutPostRedisplay();///step01-1 重畫畫面
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);///step01-2
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle = angle;///step02-2
    if(state==GLUT_UP) newAngle = angle;///step02-2
    oldX = x;///step02-2
    glutPostRedisplay();///step02-2
}
void motion(int x,int y)
{
    angle += x-oldX;///step02-2
    oldX = x;///step02-2
    glutPostRedisplay();///step02-2 更新畫面
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

    glutMouseFunc(mouse);///step02-2
    glutMotionFunc(motion);///step02-2
    glutKeyboardFunc(keyboard);///step01-2
    ///glutTimerFunc(500,timer,0);///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}
