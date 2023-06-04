#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * hat = NULL;
GLMmodel * button = NULL;
GLMmodel * face = NULL;
GLMmodel * body = NULL;
GLMmodel * cloth = NULL;
GLMmodel * belt = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * jewelry1 = NULL, * jewelry2 = NULL;
GLMmodel * glove1 = NULL, * glove2 = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * pocket1 = NULL, * pocket2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
GLMmodel * shoe1 = NULL, * shoe2 = NULL;
GLMmodel * metal1 = NULL, * metal2 = NULL;

float teapotX = 0, teapotY = 0, oldX = 0, oldY = 0;
float angle[20] = {}, angle2[20] = {};///float  angle = 0, angle2 = 0;
float NewAngle[20] = {}, NewAngle2[20] = {};
float OldAngle[20] = {}, OldAngle2[20] = {};
int ID = 0;
FILE * fout = NULL;
FILE * fin = NULL;
void timer(int t)
{
    printf("現在timer(%d)\n", t);
    glutTimerFunc(20, timer, t+1); ///馬上設定下一個鬧鐘
    float alpha = (t%50) / 50.0; ///0.0 ~ 1.0

    if(t%50==0)
    {
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++)
        {
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );
        }
    }
    for(int i=0; i<20; i++)
    {
        angle[i] = NewAngle[i] * alpha + OldAngle[i] * (1-alpha);
        angle2[i] = NewAngle2[i] * alpha + OldAngle2[i] * (1-alpha);
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;
    if(key=='5') ID = 5;
    if(key=='6') ID = 6;
    if(key=='7') ID = 7;
    if(key=='8') ID = 8;
    if(key=='9') ID = 9;

    if(key=='s')
    { ///save存檔
        if(fout == NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++)
        {
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("寫了一行\n");
    }
    if(key=='r')
    { ///read讀檔
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++)
        {
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }
    if(key=='p')
    { ///play播放 也會動到檔案
        glutTimerFunc(0, timer, 0);
    }
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
void motion(int x, int y)
{
    teapotX += (x - oldX) / 150.0 * 10;
    teapotY += (oldY - y) / 150.0 * 10;
    angle[ID] += x - oldX;
    angle2[ID] += oldY - y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    printf("  glTranslatef( %.2f, %.2f, 0 ); \n", teapotX, teapotY );
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(1.6, 1.6, 1.6);
        glTranslatef(0, -0.5, 0);///往下一半
        glPushMatrix();
            glColor3f(0.9,0.6,0.7);
            glScalef(0.04, 0.04, 0.04);
            glRotatef(angle[0], 0, 1, 0);
            glmDraw(body, GLM_MATERIAL|GLM_TEXTURE);

            glPushMatrix();
                glColor3f(0.5,0.3,0.5);
                glmDraw(cloth, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();
            glPushMatrix();
                glColor3f(0.5,0.3,0.5);
                glmDraw(belt, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();///右手
                glColor3f(0.8,0.4,0.6);
                glTranslatef(-1.53,  18.07, 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef( 1.53, -18.07, 0 );
                glmDraw(arm1, GLM_MATERIAL|GLM_TEXTURE);
                glPushMatrix();
                    glColor3f(1,0.8,0.9);
                    glTranslatef(-2.27, 16.67, 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef( 2.27, -16.67, 0 );
                    glmDraw(hand1, GLM_MATERIAL|GLM_TEXTURE);
                    glPushMatrix();
                        glColor3f(0.5,0.3,0.6);
                        glmDraw(jewelry1, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                    glPushMatrix();
                        glColor3f(0.3,0.3,0.5);
                        glmDraw(glove1, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///左手
                glColor3f(0.8,0.4,0.6);
                glTranslatef(-1.53,  18.07, 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef( 1.53, -18.07, 0 );
                glmDraw(arm2, GLM_MATERIAL|GLM_TEXTURE);
                glPushMatrix();
                    glColor3f(1,0.8,0.9);
                    glTranslatef( 2.33, 16.60, 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef( -2.33, -16.60, 0 );
                    glmDraw(hand2, GLM_MATERIAL|GLM_TEXTURE);
                    glPushMatrix();
                        glColor3f(0.5,0.3,0.6);
                        glmDraw(jewelry2, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                    glPushMatrix();
                        glColor3f(0.3,0.3,0.5);
                        glmDraw(glove2, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///頭
                glColor3f(0.8,0.5,0.6);
                glTranslatef( 0.00, 19.07, 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef( 0.00, -19.07, 0 );
                glmDraw(head, GLM_MATERIAL|GLM_TEXTURE);
                    glPushMatrix();
                        glColor3f(1,0.8,0.9);
                        glmDraw(face, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                    glPushMatrix();
                        glColor3f(0.9,0.5,0.75);
                        glmDraw(hat, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
                    glPushMatrix();
                        glColor3f(0.5,0.3,0.5);
                        glmDraw(button, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();
            glPopMatrix();
            glPushMatrix();///右腳
                glPushMatrix();
                    glColor3f(0.3,0.2,0.4);
                    glTranslatef(-0.93,  14.87, 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef( 0.93, -14.87, 0 );
                    glmDraw(leg1, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glColor3f(0.9,0.7,0.9);
                        glmDraw(pocket1, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();

                    glPushMatrix();
                        glColor3f(0.4,0.2,0.5);
                        glTranslatef(-2.33,  6.33, 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef( 2.33, -6.33, 0 );
                        glmDraw(foot1, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glColor3f(0.9,0.7,0.9);
                            glmDraw(shoe1, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                        glPushMatrix();
                            glColor3f(1,0.95,0.2);
                            glmDraw(metal1, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///左腳
                glPushMatrix();
                    glColor3f(0.3,0.2,0.4);
                    glTranslatef(  0.87,  14.73, 0 );
                    glRotatef(angle[8], 0, 1, 0);
                    glRotatef(angle2[8], 1, 0, 0);
                    glTranslatef( -0.87, -14.73, 0 );
                    glmDraw(leg2, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glColor3f(0.9,0.7,0.9);
                        glmDraw(pocket2, GLM_MATERIAL|GLM_TEXTURE);
                    glPopMatrix();

                    glPushMatrix();
                        glColor3f(0.4,0.2,0.5);
                        glTranslatef(  2.33,  6.27, 0 );
                        glRotatef(angle[9], 0, 1, 0);
                        glRotatef(angle2[9], 1, 0, 0);
                        glTranslatef( -2.33, -6.27, 0 );
                        glmDraw(foot2, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glColor3f(0.9,0.7,0.9);
                            glmDraw(shoe2, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                        glPushMatrix();
                            glColor3f(1,0.95,0.2);
                            glmDraw(metal2, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();

        ///glColor3f(0,1,0);
        ///glutSolidTeapot( 0.005 );

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("10160056");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    hat = glmReadOBJ("model/hat.obj");
    button = glmReadOBJ("model/button.obj");
    face = glmReadOBJ("model/face.obj");
    body = glmReadOBJ("model/body.obj");
    cloth = glmReadOBJ("model/cloth.obj");
    belt = glmReadOBJ("model/belt.obj");
    arm1 = glmReadOBJ("model/armR.obj");
    arm2 = glmReadOBJ("model/armL.obj");
    hand1 = glmReadOBJ("model/handR.obj");
    hand2 = glmReadOBJ("model/handL.obj");
    jewelry1 = glmReadOBJ("model/jewelryR.obj");
    jewelry2 = glmReadOBJ("model/jewelryL.obj");
    glove1 = glmReadOBJ("model/gloveR.obj");
    glove2 = glmReadOBJ("model/gloveL.obj");
    leg1 = glmReadOBJ("model/legR.obj");
    leg2 = glmReadOBJ("model/legL.obj");
    pocket1 = glmReadOBJ("model/pocketR.obj");
    pocket2 = glmReadOBJ("model/pocketL.obj");
    foot1 = glmReadOBJ("model/footR.obj");
    foot2 = glmReadOBJ("model/footL.obj");
    shoe1 = glmReadOBJ("model/shoeR.obj");
    shoe2 = glmReadOBJ("model/shoeL.obj");
    metal1 = glmReadOBJ("model/metalR.obj");
    metal2 = glmReadOBJ("model/metalL.obj");

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
