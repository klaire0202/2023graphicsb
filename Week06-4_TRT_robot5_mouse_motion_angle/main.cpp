#include <GL/glut.h>
float angle=0;
void myCube()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.01,30,30);///小球作為中心點參考

    glPushMatrix();///右手
        glTranslatef(0.25,0,0);///(3)這行則是要決定掛在哪裡
        glRotatef(angle,0,0,1);///(2)
        glTranslatef(0.25,0,0);///(1)
        myCube();///上手肘
        glPushMatrix();
            glTranslatef(0.25,0,0);///(3)這行則是要決定掛在哪裡
            glRotatef(angle,0,0,1);///(2)
            glTranslatef(0.25,0,0);///(1)
            myCube();///下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左手
        glTranslatef(-0.25,0,0);///(3)這行則是要決定掛在哪裡
        glRotatef(-angle,0,0,1);///(2)
        glTranslatef(-0.25,0,0);///(1)
        myCube();///上手肘
        glPushMatrix();
            glTranslatef(-0.25,0,0);///(3)這行則是要決定掛在哪裡
            glRotatef(-angle,0,0,1);///(2)
            glTranslatef(-0.25,0,0);///(1)
            myCube();///下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    ///angle++; ///把angle++註解掉
}
void motion(int x,int y) ///新增加的 mouse motion
{
    angle=x;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week06");

    glutMotionFunc(motion);///增加新的mouse motion
    glutDisplayFunc(display);
    glutIdleFunc(display);///重畫畫面

    glutMainLoop();
}
