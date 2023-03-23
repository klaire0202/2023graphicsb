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

    glutSolidSphere(0.01,30,30);///瞴いみ翴把σ

    glPushMatrix();///も
        glTranslatef(0.25,0,0);///(3)硂︽玥琌璶∕﹚本柑
        glRotatef(angle,0,0,1);///(2)
        glTranslatef(0.25,0,0);///(1)
        myCube();///も▂
        glPushMatrix();
            glTranslatef(0.25,0,0);///(3)硂︽玥琌璶∕﹚本柑
            glRotatef(angle,0,0,1);///(2)
            glTranslatef(0.25,0,0);///(1)
            myCube();///も▂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///オも
        glTranslatef(-0.25,0,0);///(3)硂︽玥琌璶∕﹚本柑
        glRotatef(angle,0,0,1);///(2)
        glTranslatef(-0.25,0,0);///(1)
        myCube();///も▂
        glPushMatrix();
            glTranslatef(-0.25,0,0);///(3)硂︽玥琌璶∕﹚本柑
            glRotatef(angle,0,0,1);///(2)
            glTranslatef(-0.25,0,0);///(1)
            myCube();///も▂
        glPopMatrix();
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
    glutIdleFunc(display);///礶礶

    glutMainLoop();
}
