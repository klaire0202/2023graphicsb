#include <GL/glut.h>
float angle=0;
void myCube()
{
    glPushMatrix();///簡化程式
        glScalef(0.5,0.2,0.2);///調整大小
        glutSolidCube(1);///正方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///白色
    glutSolidCube(1);///身體

    glPushMatrix();
        glTranslatef(0.5,0.5,0);///放在右上角
        glRotatef(angle,0,0,1);///轉它
        glTranslatef(0.25,0,0);///往右移動0.25讓關節在正中心
        glColor3f(0,1,0);///綠色
        myCube();///改函數
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,0.5,0);///放在左上角
        glRotatef(angle,0,0,1);///轉它
        glTranslatef(0.25,0,0);///往右移動0.25讓關節在正中心
        glColor3f(0,1,0);///綠色
        myCube();///改函數
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
