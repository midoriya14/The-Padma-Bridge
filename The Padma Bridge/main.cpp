#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI          3.141516
#include<math.h>

GLint x=2;

GLint r=1;

GLfloat sx = 0.0f;
GLfloat sy = 0.0f;


GLfloat typositionCar = 0.0f;
GLfloat tyspeedCar = 0.1f;

GLfloat txpositionCar = 0.0f;
GLfloat txspeedCar = 0.1f;

GLfloat position = 0.0f;
GLfloat speed = 0.01f;

GLfloat typosition = 0.0f;
GLfloat tyspeed = 0.1f;

GLfloat txposition = 0.0f;
GLfloat txspeed = 0.1f;

GLfloat cloudposition = 0.0f;
GLfloat cloudspeed = 0.01f;
GLfloat cloudtposition = 0.0f;

GLfloat sunposition = 0.0f;
GLfloat sunspeed = 0.001f;


GLfloat xrain = 10.0f;
GLfloat yrain = 10.0f;


GLboolean sunlight = true;
GLboolean skylight = true;

void CC(float x, float y, float ra, int r, int g, int b) {


	int i;

    GLfloat p1 = x; GLfloat q1 = y; GLfloat r1 = ra;

    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (r,g,b);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();

    //glFlush();  // Render now

}


void update(int value) {

    if(position >2.5)
        position = 0.0f;


    if(position < 0)
        position = 1.5f;


        position += speed;

    if(txposition > 2.5){
        txposition = -0.3f;
        typosition = -0.063f;
    }
    txposition = txposition + 0.1f;
    typosition = typosition + 0.021f;



    if(cloudposition < -2.0){
        cloudposition = 2.0f;
    }
    cloudposition = cloudposition - cloudspeed;

    if(cloudtposition < -3.0){
        cloudtposition = 0.0f;

    }
    cloudtposition = cloudtposition - cloudspeed;

    if(sunposition < -0.4){
        sunposition = 0.2f;
        x = x + 1;
        if(x%2==0){
            sunlight = true;
        }
        else{
            sunlight = false;
        }
    }
    sunposition = sunposition - sunspeed;

    if(txpositionCar > 2.5){
        txpositionCar = -0.3f;
        typositionCar = -0.063f;
    }
    txpositionCar = txpositionCar + 0.01f;
    typositionCar = typositionCar + 0.0021f;


    if(r == 2){
        if(xrain > 0.1f){
            xrain = -0.2f;
            yrain = -0.5f;
        }
        xrain = xrain + 0.05f;
        yrain = yrain - 0.05f;
    }

    else{

        xrain = 10.0f;
        yrain = 10.0f;

    }


    if( sx < -1.5 ){
        sx = 0;
        sy = 0;
    }
    else{
        if(sx > -0.3){
            sx = sx - 0.01f;
            sy = sy + 0.003f;
        }
        else{
            sx = sx - 0.01;
            sy = sy + 0.01;
        }
    }




glutPostRedisplay();



glutTimerFunc(100, update, 0);
}

void shipboat(){
    glPushMatrix();
    glTranslatef(sx,sy, 0.0f);

    if(sx > -0.3){
        glBegin(GL_QUADS);
            glColor3ub (255, 0, 0);
            glVertex2f(0.1f, -0.95f);
            glVertex2f( 0.30f, -0.95f);
            glVertex2f( 0.32f,  -0.93f);
            glVertex2f( 0.08f,  -0.93f);

            glColor3ub (0, 0, 0);
            glVertex2f(0.08f, -0.93f);
            glVertex2f( 0.32f, -0.93f);
            glVertex2f( 0.37f,  -0.87f);
            glVertex2f( 0.03f,  -0.87f);

            glColor3ub (255, 0, 0);
            glVertex2f(0.08f, -0.87f);
            glVertex2f( 0.32f, -0.87f);
            glVertex2f( 0.32f,  -0.84f);
            glVertex2f( 0.08f,  -0.84f);

            glColor3ub (255, 0, 0);
            glVertex2f(0.1f, -0.84f);
            glVertex2f( 0.3f, -0.84f);
            glVertex2f( 0.3f,  -0.81f);
            glVertex2f( 0.1f,  -0.81f);

            glColor3ub (255, 255, 255);
            glVertex2f(0.13f, -0.81f);
            glVertex2f( 0.27f, -0.81f);
            glVertex2f( 0.27f,  -0.79f);
            glVertex2f( 0.13f,  -0.79f);
        glEnd();
    }

    else{
        glBegin(GL_QUADS);
            glColor3ub (255, 0, 0);
            glVertex2f(0.1f, -0.93f);
            glVertex2f( 0.30f, -0.97f);
            glVertex2f( 0.32f,  -0.95f);
            glVertex2f( 0.08f,  -0.91f);

            glColor3ub (0, 0, 0);
            glVertex2f(0.08f, -0.91f);
            glVertex2f( 0.32f, -0.95f);
            glVertex2f( 0.37f,  -0.89f);
            glVertex2f( 0.03f,  -0.85f);

            glColor3ub (255, 0, 0);
            glVertex2f(0.08f, -0.85f);
            glVertex2f( 0.32f, -0.89f);
            glVertex2f( 0.32f,  -0.86f);
            glVertex2f( 0.08f,  -0.82f);

            glColor3ub (255, 0, 0);
            glVertex2f(0.1f, -0.82f);
            glVertex2f( 0.3f, -0.86f);
            glVertex2f( 0.3f,  -0.83f);
            glVertex2f( 0.1f,  -0.79f);

            glColor3ub (255, 255, 255);
            glVertex2f(0.13f, -0.79f);
            glVertex2f( 0.27f, -0.83f);
            glVertex2f( 0.27f,  -0.81f);
            glVertex2f( 0.13f,  -0.77f);
        glEnd();

    }


    glPopMatrix();
}


void car(){


    glPushMatrix();
    //glTranslatef(-position,0.0f,0.0f);
    glTranslatef(-txpositionCar,-typositionCar,0.0f);
    glBegin(GL_POLYGON);
        glColor3ub(100, 149, 237); // Car left
        glVertex2f(0.71f, 0.39f);
        glVertex2f(0.89f, 0.39f);
        glVertex2f(0.91f, 0.420f);
        glVertex2f(0.91f, 0.470f);
        glVertex2f(0.885f, 0.510f);
        glVertex2f(0.79f, 0.510f);
        glVertex2f(0.76f, 0.460f);
        glVertex2f(0.71f, 0.460f);
        glVertex2f(0.7f, 0.450f);
        glVertex2f(0.7f, 0.4f);
        glEnd();

        glBegin(GL_QUADS);
    glColor3ub(248, 248, 255); // Window 1st
    glVertex2f(0.769f, -0.24f+0.7f); // x, y
    glVertex2f(0.82f, -0.24f+0.7f); // x, y
    glVertex2f(0.82f, -0.2f+0.7f); // x, y
    glVertex2f(0.7909f, -0.2f+0.7f); // x, y

    glColor3ub(248, 248, 255); // Window 2nd
    glVertex2f(0.84f, -0.24f+0.7f); // x, y
    glVertex2f(0.89f, -0.24f+0.7f); // x, y
    glVertex2f(0.869f, -0.2f+0.7f); // x, y
    glVertex2f(0.84f, -0.2f+0.7f); // x, y
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); //
        glVertex2f(0.805f, -0.25f+0.7f);    // Car line
        glVertex2f(0.82f, -0.25f+0.7f);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); //
        glVertex2f(0.885f, -0.25f+0.7f);    // Car line
        glVertex2f(0.87f, -0.25f+0.7f);
        glEnd();

         glLineWidth(1.5);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // Right  car Dhoya
        glVertex2f(0.91f, -0.297f+0.7f);
        glVertex2f(0.93f, -0.297f+0.7f);

        glVertex2f(0.917f, -0.312f+0.7f);
        glVertex2f(0.937f, -0.312f+0.7f);

        glVertex2f(0.91f, -0.326f+0.7f);
        glVertex2f(0.93f, -0.326f+0.7f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
        glVertex2f(0.7f, -0.27f+0.7f); // x, y
        glVertex2f(0.7f, -0.26f+0.7f); // x, y
        glVertex2f(0.695f, -0.26f+0.7f); // x, y
        glVertex2f(0.695f, -0.27f+0.7f); // x, y
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
        glVertex2f(0.7f, -0.29f+0.7f); // x, y
        glVertex2f(0.7f, -0.28f+0.7f); // x, y
        glVertex2f(0.695f, -0.28f+0.7f); // x, y
        glVertex2f(0.695f, -0.29f+0.7f); // x, y
        glEnd();

        CC(0.75,-0.31+0.7f,0.03, 0,0,0);  // Front wheel Car
        CC(0.75,-0.31+0.7f,0.015, 255,255,255);

        CC(0.85,-0.31+0.7f,0.03, 0,0,0);  // Back wheel Car
        CC(0.85,-0.31+0.7f,0.015, 255,255,255);
        glPopMatrix();

        glPushMatrix();
    //glTranslatef(position,0.0f,0.0f);
    glTranslatef(txpositionCar, typositionCar, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); //  Truck
    glVertex2f(-0.92f, -0.06f); // x, y
    glVertex2f(-0.8f, -0.06f); // x, y
    glVertex2f(-0.8f, -0.01f); // x, y
    glVertex2f(-0.92f, -0.01f); // x, y
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f); // Truck 1 left
    glVertex2f(-0.8f, -0.06f);
    glVertex2f(-0.7f, -0.06f);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.74f, 0.06f);
    glVertex2f(-0.8f, 0.06f);
    glEnd();

    CC(-0.86,-0.06,0.03, 0,0,0); // Front wheel track
    CC(-0.86,-0.06,0.015, 255,255,255);

    CC(-0.75,-0.06,0.03, 0,0,0); // Back wheel Track
    CC(-0.75,-0.06,0.015, 255,255,255);

    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);  //  Truck middle white
    glVertex2f(-0.78f, -0.35f+.35f); // x, y
    glVertex2f(-0.725f, -0.35f+.35f); // x, y
    glVertex2f(-0.75f, -0.31f+.35f); // x, y
    glVertex2f(-0.78f, -0.31f+.35f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Truck Load space
    glVertex2f(-0.8f, -0.36f+.35f); // x, y
    glVertex2f(-0.8f, -0.26f+.35f); // x, y
    glVertex2f(-0.92f, -0.26f+.35f); // x, y
    glVertex2f(-0.92f, -0.36f+.35f); // x, y
    glEnd();



    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // left Truck Dhoya
    glVertex2f(-0.93f, -0.393f+.35f);
    glVertex2f(-0.95f, -0.393f+.35f);

    glVertex2f(-0.94f, -0.407f+.35f);
    glVertex2f(-0.96f, -0.407f+.35f);

    glVertex2f(-0.93f, -0.419f+.35f);
    glVertex2f(-0.95f, -0.419f+.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck Light
    glVertex2f(-0.7f, -0.39f+.35f);
    glVertex2f(-0.7f, -0.37f+.35f);
    glVertex2f(-0.696f, -0.37f+.35f);
    glVertex2f(-0.696f, -0.39f+.35f);
    glEnd();
    glPopMatrix();



    //truck 2

    glPushMatrix();
    //glTranslatef(position,0.0f,0.0f);
    glTranslatef(txpositionCar, typositionCar, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); //  Truck
    glVertex2f(-0.32f, -0.06f); // x, y
    glVertex2f(-0.2f, -0.06f); // x, y
    glVertex2f(-0.2f, -0.01f); // x, y
    glVertex2f(-0.32f, -0.01f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load left box
    glVertex2f(-.305f,0.02f); // x, y
    glVertex2f(-.305f, -0.01f); // x, y
    glVertex2f(-.25f, -0.01f); // x, y
    glVertex2f(-.25f, 0.02f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load right box
    glVertex2f(-.246f,0.02f); // x, y
    glVertex2f(-.246f, -0.01f); // x, y
    glVertex2f(-.21f, -0.01f); // x, y
    glVertex2f(-.21f, 0.02f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); //  Truck Load middle box
    glVertex2f(-.29f,0.05f); // x, y
    glVertex2f(-.29f, 0.02f); // x, y
    glVertex2f(-.23f, 0.02f); // x, y
    glVertex2f(-.23f, 0.05f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); //  Truck Load upper middle box
    glVertex2f(-.276f,0.06f); // x, y
    glVertex2f(-.276f, 0.05f); // x, y
    glVertex2f(-.24f, 0.05f); // x, y
    glVertex2f(-.24f, 0.06f); // x, y
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f); // Truck 1 left
    glVertex2f(-0.8f+0.6f, -0.06f);
    glVertex2f(-0.7f+0.6f, -0.06f);
    glVertex2f(-0.7f+0.6f, 0.0f);
    glVertex2f(-0.74f+0.6f, 0.06f);
    glVertex2f(-0.8f+0.6f, 0.06f);
    glEnd();

    CC(-0.86+0.6f,-0.06,0.03, 0,0,0); // Front wheel track
    CC(-0.86+0.6f,-0.06,0.015, 255,255,255);

    CC(-0.75+0.6f,-0.06,0.03, 0,0,0); // Back wheel Track
    CC(-0.75+0.6f,-0.06,0.015, 255,255,255);

    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);  //  Truck middle white
    glVertex2f(-0.78f+0.6f, -0.35f+.35f); // x, y
    glVertex2f(-0.725f+0.6f, -0.35f+.35f); // x, y
    glVertex2f(-0.75f+0.6f, -0.31f+.35f); // x, y
    glVertex2f(-0.78f+0.6f, -0.31f+.35f); // x, y
    glEnd();

    /*glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load left box
    glVertex2f(-.305f,0.3f); // x, y
    glVertex2f(-.305f, 0.1f); // x, y
    glVertex2f(-.25f, 0.1f); // x, y
    glVertex2f(-.25f, 0.3f); // x, y
    glEnd();*/



    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // left Truck Dhoya
    glVertex2f(-0.93f+0.6f, -0.393f+.35f);
    glVertex2f(-0.95f+0.6f, -0.393f+.35f);

    glVertex2f(-0.94f+0.6f, -0.407f+.35f);
    glVertex2f(-0.96f+0.6f, -0.407f+.35f);

    glVertex2f(-0.93f+0.6f, -0.419f+.35f);
    glVertex2f(-0.95f+0.6f, -0.419f+.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck Light
    glVertex2f(-0.7f+0.6f, -0.39f+.35f);
    glVertex2f(-0.7f+0.6f, -0.37f+.35f);
    glVertex2f(-0.696f+0.6f, -0.37f+.35f);
    glVertex2f(-0.696f+0.6f, -0.39f+.35f);
    glEnd();
    glPopMatrix();




    ////////////////////

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck Load space
    glVertex2f(0.29f,-0.02f);
    glVertex2f(0.29f,-0.055f);
    glVertex2f(0.46f,-0.055f);
    glVertex2f(0.46f,-0.02f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // Truck Load
    glVertex2f(0.29f,-0.02f);
    glVertex2f(0.44f,-0.02f);
    glVertex2f(0.44f,0.085f);
    glVertex2f(0.29f,0.085f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.0f); // Truck Head
    glVertex2f(0.45f,-0.055f);
    glVertex2f(0.5f,-0.055f);
    glVertex2f(.5f,0.0f);
    glVertex2f(.482f,0.04f);
    glVertex2f(0.45,0.04f);
    glEnd();


    //head triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.45f,0.067f);
    glVertex2f(.45f,0.04f);
    glVertex2f(.467f,0.04f);
    glEnd();




    //door handle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.46f,-0.011f);
    glVertex2f(0.46f,-0.015f);
    glVertex2f(0.472f,-0.015f);
    glVertex2f(0.472f,-0.011f);
    glEnd();

    //head light
    glBegin(GL_QUADS);
    glColor3ub(255, 140, 0);
    glVertex2f(0.49f,-0.011f);
    glVertex2f(0.49f,-0.025f);
    glVertex2f(0.5f,-0.025f);
    glVertex2f(0.5f,-0.011f);
    glEnd();




    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck front glass
    glVertex2f(0.486f,0.03f);
    glVertex2f(0.46f,0.03f);
    glVertex2f(0.46f,0.015f);
    glVertex2f(0.5f,0.00f);
    glEnd();

    //rear wheel
    CC(.32f,-0.055f,0.023f,0,0,0);
    CC(.32f,-0.055f,0.011f,255,255,255);

    //middle wheel
    CC(.40f,-0.055f,0.023f,0,0,0);
    CC(.40f,-0.055f,0.011f,255,255,255);

    //front wheel
    CC(.47f,-0.055f,0.023f,0,0,0);
    CC(.47f,-0.055f,0.011f,255,255,255);




    glPopMatrix();



    glPushMatrix();
    //Reverse truck

    //head
    glBegin(GL_POLYGON);
    glColor3ub(84 ,255 ,159); // Truck Head
    glVertex2f(-0.3f,0.47f);
    glVertex2f(-0.36f,0.469f);
    glVertex2f(-.359,0.412f);
    glVertex2f(-.348f,0.4f);
    glVertex2f(-0.3,0.4f);
    glEnd();

    //head light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck Load
    glVertex2f(-0.36f,0.47f);
    glVertex2f(-0.3599f,0.45f);
    glVertex2f(-0.34f,0.45f);
    glVertex2f(-0.335f,0.47f);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3ub(84 ,255 ,159); // Truck Head
    glVertex2f(-0.3f,0.47f);
    glVertex2f(-0.3f,0.4f);
    glVertex2f(-.2,0.4f);
    glVertex2f(-.2,0.52f);
    glVertex2f(-.28f,0.52f);
    glEnd();





    //window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2723f,0.51f);
    glVertex2f(-0.29f,0.47f);
    glVertex2f(-.21,0.47f);
    glVertex2f(-.21,0.51f);
    glEnd();




    //handle 1
    glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.267f,0.46f);    // x, y
	glVertex2f(-0.25f, 0.46f);    // x, y
	glEnd();

	//handle 1
    glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.227f,0.46f);    // x, y
	glVertex2f(-0.21f, 0.46f);    // x, y
	glEnd();

    //window partition
    glBegin(GL_QUADS);
    glColor3ub(84 ,255 ,159);
    glVertex2f(-0.25f,0.51f);
    glVertex2f(-0.25f,0.47f);

    glVertex2f(-.243,0.47f);
    glVertex2f(-.243,0.51f);

    glEnd();




    //back
    glBegin(GL_QUADS);
    glColor3ub(84 ,255 ,159); // Truck Load
    glVertex2f(-0.2f,0.46f);
    glVertex2f(-0.2f,0.4f);
    glVertex2f(-0.07f,0.4f);
    glVertex2f(-0.07f,0.46f);
    glEnd();

    //tail light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Truck Load
    glVertex2f(-0.08f,0.44f);
    glVertex2f(-0.08f,0.42f);
    glVertex2f(-0.07f,0.42f);
    glVertex2f(-0.07f,0.44f);


    glEnd();

    //ground line
    glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-.355,0.409f);    // x, y
	glVertex2f(-0.07f, 0.409f);    // x, y
	glEnd();


	//middle line big
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.2f,0.409f);    // x, y
	glVertex2f(-0.2f, 0.46f);    // x, y
	glEnd();

	//middle line
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.24f,0.409f);    // x, y
	glVertex2f(-0.24, 0.43f);    // x, y
	glEnd();

	//back body line
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.2f,0.45f);    // x, y
	glVertex2f(-0.07, 0.45f);    // x, y
	glEnd();


    //wheel front
    CC(-.29f,0.4f,0.03f,0,0,0);
    CC(-.29f,0.4f,0.015f,255,255,255);

    //wheel rear
    CC(-.13f,0.4f,0.03f,0,0,0);
    CC(-.13f,0.4f,0.015f,255,255,255);

    glPopMatrix();


    glPushMatrix();

    //passenger hiace

    //main body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3f,0.5f);
    glVertex2f(0.3f,0.38f);
    glVertex2f(0.5f, 0.38f);
    glVertex2f(0.5f,0.5f);
    glEnd();

    //upper deck
    //stand 1

    glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.345f,0.5f);    // x, y
	glVertex2f(0.345f,0.516f);    // x, y
	glEnd();

    //stand 2
    glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.455f,0.5f);    // x, y
	glVertex2f(0.455f,0.516f);    // x, y
	glEnd();

	//upper stand
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.33f,0.515f);    // x, y
	glVertex2f(0.469f,0.515f);    // x, y
	glEnd();


    //back quads
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f, 0.38f);
    glVertex2f(0.51f,0.39f);
    glVertex2f(0.51f,0.49f);
    glVertex2f(0.5f,0.5f);
    glEnd();


    /* //head
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); // Truck Head
    glVertex2f(0.3f,0.5f);
    glVertex2f(0.28f,0.43f);
    glVertex2f(.23f,0.415f);
    glVertex2f(.23f,0.39f);
    glVertex2f(.24,0.38f);
    glVertex2f(.3,0.38f);
    glEnd();
    */

    //head1
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3f,0.5f);
    glVertex2f(0.28f,0.45f);
    glVertex2f(0.28f,0.38f);
    glVertex2f(0.3f,0.38f);
    glEnd();

    //head 2
    glBegin(GL_POLYGON);
    glVertex2f(0.28f,0.45f);
    glVertex2f(.23f,0.415f);
    glVertex2f(.23f,0.387f);
    glVertex2f(.24,0.38f);
    glVertex2f(.28,0.38f);
    glEnd();


    //headlight
    glBegin(GL_QUADS);
    glColor3ub(255, 140, 0);
    glVertex2f(0.23f,0.415f);
    glVertex2f(0.23f,0.395f);
    glVertex2f(0.245f,0.395f);
    glVertex2f(0.245f,0.424f);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.309f,0.49f);
    glVertex2f(0.29f,0.45f);
    glVertex2f(0.5f, 0.45f);
    glVertex2f(.5f,0.49f);
    glEnd();

    //windows portion
    //portion 1
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.3065f,0.45f);    // x, y
	glVertex2f(0.3065f,0.49f);    // x, y
	glEnd();

	//portion 2
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.36f,0.45f);    // x, y
	glVertex2f(0.36f,0.49f);    // x, y
	glEnd();

	//portion 3
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.42f,0.45f);    // x, y
	glVertex2f(0.42f,0.49f);    // x, y
	glEnd();

	//portion 4
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(0.48f,0.45f);    // x, y
	glVertex2f(0.48f,0.49f);    // x, y
	glEnd();

	//hadnle 1

	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.33f,0.44f);    // x, y
	glVertex2f(0.35f,0.44f);    // x, y
	glEnd();


	//hadnle 2

	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.395f,0.44f);    // x, y
	glVertex2f(0.415f,0.44f);    // x, y
	glEnd();

    //lower line
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(.23f,0.39f);    // x, y
	glVertex2f(0.51f,0.39f);    // x, y
	glEnd();

	//middle line right
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(.325f,0.39f);    // x, y
	glVertex2f(0.325f,0.43f);    // x, y
	glEnd();

	//middle line left
	glLineWidth(0.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(.408f,0.39f);    // x, y
	glVertex2f(0.408f,0.43f);    // x, y
	glEnd();

	//wheel front
    CC(.45f,0.38f,0.03f,0,0,0);
    CC(.45f,0.38f,0.015f,255,255,255);

    //front rear
    CC(.28f,0.38f,0.03f,0,0,0);
    CC(.28f,0.38f,0.015f,255,255,255);

    //tail light red
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.5f, 0.45f);
    glVertex2f(0.5f,0.43f);
    glVertex2f(0.51f,0.43f);
    glVertex2f(0.51f,0.45f);
    glEnd();

    //tail light orange
    glBegin(GL_QUADS);
    glColor3ub(255, 140, 0);
    glVertex2f(0.5f, 0.43f);
    glVertex2f(0.5f,0.41f);
    glVertex2f(0.51f,0.41f);
    glVertex2f(0.51f,0.43f);
    glEnd();

    //CC(-.7f,-.5f,0.5,1.0f,0.0f,0.0f);










    glPopMatrix();





}


void rain(){
    glPushMatrix();

    glTranslatef( xrain,yrain,0.0f);

    glBegin(GL_LINES);

    glVertex2f(-.85,1.9);glVertex2f(-.8,1.8);
    glVertex2f(-.55,1.9);glVertex2f(-.5,1.8);
    glVertex2f(-.25,1.9);glVertex2f(-.2,1.8);
            glVertex2f(.05,1.9);glVertex2f(.1,1.8);
            glVertex2f(.35,1.9);glVertex2f(.4,1.8);
            glVertex2f(.65,1.9);glVertex2f(.7,1.8);
            glVertex2f(.95,1.9);glVertex2f(1.0,1.8);

     glVertex2f(-1.0,1.6);glVertex2f(-.95,1.5);
    glVertex2f(-.7,1.6);glVertex2f(-.65,1.5);
    glVertex2f(-.4,1.6);glVertex2f(-.35,1.5);
    glVertex2f(-.1,1.6);glVertex2f(-.05,1.5);
            glVertex2f(.2,1.6);glVertex2f(.25,1.5);
            glVertex2f(.5,1.6);glVertex2f(.55,1.5);
            glVertex2f(.8,1.6);glVertex2f(.85,1.5);


    glVertex2f(-.85,1.3);glVertex2f(-.8,1.2);
    glVertex2f(-.55,1.3);glVertex2f(-.5,1.2);
    glVertex2f(-.25,1.3);glVertex2f(-.2,1.2);
             glVertex2f(.05,1.3);glVertex2f(.1,1.2);
            glVertex2f(.35,1.3);glVertex2f(.4,1.2);
            glVertex2f(.65,1.3);glVertex2f(.7,1.2);
            glVertex2f(.95,1.3);glVertex2f(1.0,1.2);

    glVertex2f(-1.0,1.0);glVertex2f(-.95,.9);
    glVertex2f(-.7,1.0);glVertex2f(-.65,0.9);
    glVertex2f(-.4,1.0);glVertex2f(-.35,0.9);
    glVertex2f(-.1,1.0);glVertex2f(-.05,0.9);
                 glVertex2f(.2,1.0);glVertex2f(.25,.9);
                 glVertex2f(.5,1.0);glVertex2f(.55,0.9);
                 glVertex2f(.8,1.0);glVertex2f(.85,0.9);



    glVertex2f(-.85,.7);glVertex2f(-.8,.6);
    glVertex2f(-.55,.7);glVertex2f(-.5,0.6);
    glVertex2f(-.25,.7);glVertex2f(-.2,0.6);
              glVertex2f(.05,.7);glVertex2f(.1,.6);
            glVertex2f(.35,.7);glVertex2f(.4,.6);
            glVertex2f(.65,.7);glVertex2f(.7,.6);
            glVertex2f(.95,.7);glVertex2f(1.0,.6);

    glVertex2f(-1.0,.4);glVertex2f(-.95,.3);
    glVertex2f(-.7,.4);glVertex2f(-.65,0.3);
    glVertex2f(-.4,.4);glVertex2f(-.35,0.3);
    glVertex2f(-.1,.4);glVertex2f(-.05,0.3);
                 glVertex2f(.2,.4);glVertex2f(.25,.3);
                 glVertex2f(.5,.4);glVertex2f(.55,0.3);
                 glVertex2f(.8,.40);glVertex2f(.85,0.3);

    glVertex2f(-.85,.1);glVertex2f(-.8,0.0);
    glVertex2f(-.55,.1);glVertex2f(-.5,0.0);
    glVertex2f(-.25,.1);glVertex2f(-.2,0.0);
              glVertex2f(.05,.1);glVertex2f(.1,.0);
            glVertex2f(.35,.1);glVertex2f(.4,.0);
            glVertex2f(.65,.1);glVertex2f(.7,.0);
            glVertex2f(.95,.1);glVertex2f(1.0,.0);


    glVertex2f(-1.0,-.2);glVertex2f(-.95,-.3);
    glVertex2f(-.7,-.2);glVertex2f(-.65,-0.3);
    glVertex2f(-.4,-.2);glVertex2f(-.35,-0.3);
    glVertex2f(-.1,-.2);glVertex2f(-.05,-0.3);
                 glVertex2f(.2,-.2);glVertex2f(.25,-.3);
                 glVertex2f(.5,-.2);glVertex2f(.55,-.3);
                 glVertex2f(.8,-.2);glVertex2f(.85,-.3);

    glVertex2f(-.85,-.5);glVertex2f(-.8,-.6);
    glVertex2f(-.55,-.5);glVertex2f(-.5,-.6);
    glVertex2f(-.25,-.5);glVertex2f(-.2,-.6);
              glVertex2f(.05,-.5);glVertex2f(.1,-.6);
            glVertex2f(.35,-.5);glVertex2f(.4,-.6);
            glVertex2f(.65,-.5);glVertex2f(.7,-.6);
            glVertex2f(.95,-.5);glVertex2f(1.0,-.6);

    glVertex2f(-1.0,-.8);glVertex2f(-.95,-.9);
    glVertex2f(-.7,-.8);glVertex2f(-.65,-0.9);
    glVertex2f(-.4,-.8);glVertex2f(-.35,-0.9);
    glVertex2f(-.1,-.8);glVertex2f(-.05,-0.9);
                 glVertex2f(.2,-.8);glVertex2f(.25,-.9);
                 glVertex2f(.5,-.8);glVertex2f(.55,-.9);
                 glVertex2f(.8,-.8);glVertex2f(.85,-.9);

    glVertex2f(-.85,-1.1);glVertex2f(-.8,-1.2);
    glVertex2f(-.55,-1.1);glVertex2f(-.5,-1.2);
    glVertex2f(-.25,-1.1);glVertex2f(-.2,-1.2);
              glVertex2f(.05,-1.1);glVertex2f(.1,-1.2);
            glVertex2f(.35,-1.1);glVertex2f(.4,-1.2);
            glVertex2f(.65,-1.1);glVertex2f(.7,-1.2);
            glVertex2f(.95,-1.1);glVertex2f(1.0,-1.2);

    glVertex2f(-1.0,-1.4);glVertex2f(-.95,-1.5);
    glVertex2f(-.7,-1.4);glVertex2f(-.65,-1.5);
    glVertex2f(-.4,-1.4);glVertex2f(-.35,-1.5);
    glVertex2f(-.1,-1.4);glVertex2f(-.05,-1.5);
                 glVertex2f(.2,-1.4);glVertex2f(.25,-1.5);
                 glVertex2f(.5,-1.4);glVertex2f(.55,-1.5);
                 glVertex2f(.8,-1.4);glVertex2f(.85,-1.5);


        glEnd();
        glPopMatrix();
        }



void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_LUMINANCE);
    glutSwapBuffers();



    //Background Sky
    glPushMatrix();

        glBegin(GL_QUADS);
        glColor3ub (135, 206, 250);

    if(sunlight){
        glBegin(GL_QUADS);
        glColor3ub (135, 206, 250);
        glVertex2f(-1.0f, 0.5f);
        glVertex2f( 1.0f, 0.5f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( -1.0f,  1.0f);
        glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3ub (26, 26, 26);
        glVertex2f(-1.0f, 0.5f);
        glVertex2f( 1.0f, 0.5f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( -1.0f,  1.0f);
        glEnd();
    }

    glPopMatrix();



    //sun
    glPushMatrix();
    glTranslatef(0.0f, sunposition, 0.0f);
    if(sunlight)
        CC(-0.85,0.85,0.08,255,255,0);
    else
        CC(0.85,0.85,0.05,255,255,255);
    glPopMatrix();


    //Cloud
    glPushMatrix();
    glTranslatef(cloudposition, 0.0f, 0.0f);

    if(sunlight){
        CC(0.85,0.85,0.1,255,255,255);
        CC(0.75,0.85,0.06,255,255,255);
        CC(0.95,0.85,0.06,255,255,255);


        CC(0.0,0.75,0.1,255,255,255);
        CC(-0.1,0.75,0.06,255,255,255);
        CC(0.1,0.75,0.06,255,255,255);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cloudtposition, 0.0f, 0.0f);
        CC(1.75,0.85,0.1,255,255,255);
        CC(1.65,0.85,0.06,255,255,255);
        CC(1.85,0.85,0.06,255,255,255);


        CC(1.16,0.75,0.1,255,255,255);
        CC(1.06,0.75,0.06,255,255,255);
        CC(1.26,0.75,0.06,255,255,255);
    }
    else{
        CC(0.85,0.85,0.1,122 ,122 ,122);
        CC(0.75,0.85,0.06,122 ,122 ,122);
        CC(0.95,0.85,0.06,122 ,122 ,122);


        CC(0.0,0.75,0.1,122 ,122 ,122);
        CC(-0.1,0.75,0.06,122 ,122 ,122);
        CC(0.1,0.75,0.06,122 ,122 ,122);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cloudtposition, 0.0f, 0.0f);
        CC(1.75,0.85,0.1,122 ,122 ,122);
        CC(1.65,0.85,0.06,122 ,122 ,122);
        CC(1.85,0.85,0.06,122 ,122 ,122);


        CC(1.16,0.75,0.1,122 ,122 ,122);
        CC(1.06,0.75,0.06,122 ,122 ,122);
        CC(1.26,0.75,0.06,122 ,122 ,122);
    }

    glPopMatrix();


    //Background River
    glPushMatrix();

    if(sunlight){
        glBegin(GL_QUADS);
        glColor3ub (0, 138, 216);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  0.5f);
        glVertex2f( -1.0f, 0.5f);
        glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3ub (0, 0, 139);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  0.5f);
        glVertex2f( -1.0f, 0.5f);
        glEnd();
    }
    glPopMatrix();


    //Background Green
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3ub (139, 117 ,0);
    glVertex2f(1.0f, -0.38f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(0.70f, -0.32f);
    glVertex2f(0.78f, -0.38f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (139 ,69, 19);
    glVertex2f(0.78f, -0.38f);
    glVertex2f(0.70f, -0.32f);
    glVertex2f(0.68f, -0.34f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub (139, 117 ,0);
    glVertex2f(1.0f, -0.63f);
    glVertex2f(1.0f, -0.38f);
    glVertex2f(0.78f, -0.38f);
    glVertex2f(0.52f, -0.55f);
    glVertex2f(0.59f, -0.63f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (139 ,69, 19);
    glVertex2f(0.59f, -0.63f);
    glVertex2f(0.52f, -0.55f);
    glVertex2f(0.50f, -0.57f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (139, 117 ,0);
    glVertex2f(1.0f, -0.83f);
    glVertex2f(1.0f, -0.63f);
    glVertex2f(0.59f, -0.63f);
    glVertex2f(0.40f, -0.76f);
    glVertex2f(0.44f, -0.83f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (139 ,69, 19);
    glVertex2f(0.44f, -0.83f);
    glVertex2f(0.40f, -0.76f);
    glVertex2f(0.38f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (139, 117 ,0);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.83f);
    glVertex2f(0.44f, -0.83f);
    glVertex2f(0.35f, -0.96f);
    glVertex2f(0.38f, -1.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (139 ,69, 19);
    glVertex2f(0.38f, -1.0f);
    glVertex2f(0.35f, -0.96f);
    glVertex2f(0.34f, -0.98f);
    glEnd();
    glPopMatrix();




    //House
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3ub (158, 158, 158);
    glVertex2f(0.80f, -0.85f);
    glVertex2f( 0.92f, -0.83f);
    glVertex2f( 0.92f,  -0.74f);
    glVertex2f( 0.80f, -0.75f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub (218, 165, 32);
    glVertex2f( 0.80f, -0.75f);
    glVertex2f( 0.92f,  -0.74f);
    glVertex2f( 0.87f,  -0.70f);
    glVertex2f( 0.73f,  -0.69f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (158, 158, 158);
    glVertex2f(0.80f, -0.85f);
    glVertex2f( 0.80f, -0.75f);
    glVertex2f( 0.745f,  -0.70f);
    glVertex2f( 0.71f,  -0.73f);
    glVertex2f( 0.71f,  -0.80f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub (139 ,69, 19);
    glVertex2f( 0.71f,  -0.73f);
    glVertex2f( 0.745f,  -0.70f);
    glVertex2f( 0.73f,  -0.69f);
    glVertex2f( 0.69f,  -0.73f);
    glEnd();

    //Door
    glBegin(GL_QUADS);
    glColor3ub (139 ,69, 19);
    glVertex2f(0.85f, -0.844f);
    glVertex2f( 0.88f, -0.837f);
    glVertex2f( 0.88f,  -0.780f);
    glVertex2f( 0.85f, -0.787f);
    glEnd();
    //window
    glBegin(GL_POLYGON);
    glColor3ub (139 ,69, 19);
    glVertex2f( 0.74f,  -0.79f);
    glVertex2f(0.77f, -0.80f);
    glVertex2f(0.77f, -0.77f);
    glVertex2f(0.74f, -0.76f);
    glEnd();
    glPopMatrix();




    //Tree - 1
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3ub (205 ,133, 63);
    glVertex2f(0.45f, -0.96f);
    glVertex2f(0.48f, -0.96f);
    glVertex2f(0.47f, -0.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (0 ,255, 0);
    glVertex2f(0.47f, -0.62f);
    glVertex2f(0.47f, -0.65f);
    glVertex2f(0.35f, -0.6f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (0 ,255, 0);
    glVertex2f(0.47f, -0.64f);
    glVertex2f(0.47f, -0.68f);
    glVertex2f(0.35f, -0.7f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (0 ,255, 0);
    glVertex2f(0.45f, -0.62f);
    glVertex2f(0.49f, -0.62f);
    glVertex2f(0.42f, -0.45f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub (0 ,255, 0);
    glVertex2f(0.45f, -0.62f);
    glVertex2f(0.49f, -0.62f);
    glVertex2f(0.52f, -0.45f);

    glVertex2f(0.45f, -0.62f);
    glVertex2f(0.49f, -0.62f);
    glVertex2f(0.6f, -0.45f);

    glVertex2f(0.47f, -0.62f);
    glVertex2f(0.47f, -0.65f);
    glVertex2f(0.60f, -0.6f);

    glVertex2f(0.47f, -0.64f);
    glVertex2f(0.47f, -0.68f);
    glVertex2f(0.58f, -0.7f);
    glEnd();
    glPopMatrix();





    //Tree - 2
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3ub (205 ,133, 63);
    glVertex2f(0.45f, -0.96f);
    glVertex2f(0.42f, -0.96f);
    glVertex2f(0.33f, -0.60f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub (0 ,255, 0);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.25f, -0.76f);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.45f, -0.78f);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.25f, -0.65f);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.45f, -0.70f);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.43f, -0.60f);

    glVertex2f(0.36f, -0.70f);
    glVertex2f(0.37f, -0.74f);
    glVertex2f(0.28f, -0.62f);

    glVertex2f(0.35f, -0.70f);
    glVertex2f(0.37f, -0.70f);
    glVertex2f(0.37f, -0.60f);

    glVertex2f(0.35f, -0.70f);
    glVertex2f(0.37f, -0.70f);
    glVertex2f(0.33f, -0.60f);
    glEnd();
    glPopMatrix();


    shipboat();


/*
    //Boat
    glPushMatrix();
    glTranslatef(-position,position, 0.0f);


        glBegin(GL_QUADS); // boat 1.1
           glColor3f(0.0f, 0.0f, 0.0f);
           glVertex2f(0.1f,  -0.9f);
           glVertex2f(0.13f, -0.9f);
           glVertex2f(0.05f, -0.80f);
           glVertex2f(0.02f, -0.80f);
        glEnd();

        glBegin(GL_QUADS); // boat 1.2
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.02f, -0.80f);
            glVertex2f(0.05f, -0.80f);
            glVertex2f(0.10f, -0.70f);
            glVertex2f(0.07f, -0.70f);

        glEnd();

    glPopMatrix();

*/
    //Ship
    glPushMatrix();
    glTranslatef(position, 0.0f, 0.0f);
       glBegin(GL_QUADS);

          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(-1.4f, 0.35f);
          glVertex2f( -1.2f, 0.35f);
          glVertex2f( -1.10f,  0.45f);
          glVertex2f(-1.5f,  0.45f);

       glEnd();

       glBegin(GL_QUADS);
          glColor3f(1.0f, 0.2f, 0.0f);
          glVertex2f(-1.45f, 0.45f);
          glVertex2f( -1.15f, 0.45f);
          glVertex2f( -1.15f,  0.48f);
          glVertex2f(-1.45f,  0.48f);

       glEnd();

       glBegin(GL_QUADS);
          glColor3f(1.0f, 0.2f, 0.0f);
          glVertex2f(-1.40f, 0.48f);
          glVertex2f( -1.20f, 0.48f);
          glVertex2f( -1.20f,  0.51f);
          glVertex2f(-1.40f,  0.51f);

       glEnd();

       glLineWidth(7);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.2f, 0.0f);


    glVertex2f(-1.35f, 0.51f);
    glVertex2f(-1.35f, 0.55f);

    glVertex2f(-1.30f, 0.51f);
    glVertex2f(-1.30f, 0.55f);

    glVertex2f(-1.25f, 0.51f);
    glVertex2f(-1.25f, 0.55f);

    glEnd();

    CC(-1.36, 0.556, 0.01, 255, 255, 255);
    CC(-1.31, 0.556, 0.01, 255, 255, 255);
    CC(-1.26, 0.556, 0.01, 255, 255, 255);


    glPopMatrix();


    //Road
    glBegin(GL_QUADS);
    glColor3ub (0 ,0 ,0);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f( 1.0f, 0.2f);
    glVertex2f( 1.0f,  0.5f);
    glVertex2f( -1.0f, 0.1f);
    glEnd();


    //Road divider
    glBegin(GL_QUADS);
    glColor3ub (255 ,255 ,255);
    glVertex2f(-1.0f, -0.051f);
    glVertex2f( 1.0f, 0.349f);
    glVertex2f( 1.0f,  0.351f);
    glVertex2f( -1.0f, -0.049f);
    glEnd();

    //Pillar - 1 begin
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3ub (205, 197, 191);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.80f, -1.0f);
    glVertex2f(-0.80f, -0.55f);
    glVertex2f(-0.6f, -0.45f);
    glVertex2f(-1.0f, -0.53f);

    glEnd();

    //Pillar - 1.1
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(-0.80f, -1.0f);
    glVertex2f(-0.75f, -0.95f);
    glVertex2f(-0.75f, -0.70f);
    glVertex2f(-0.80f, -0.70f);
    glEnd();

    //Pillar - 1.2
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(-0.75f, -0.70f);
    glVertex2f(-0.80f, -0.70f);
    glVertex2f(-0.57f,-0.40f);
    glVertex2f(-0.53f,-0.40f);
    glEnd();

    glPopMatrix();

    //Pillar - 2 begin
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3ub (205, 197, 191);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.2f, -0.35f);
    glVertex2f(0.3f, -0.25f);
    glVertex2f(0.0f, -0.32f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub (205, 197, 191);

    glVertex2f(-0.1f,-0.34f);
    glVertex2f(0.0f, -0.43f);
    glVertex2f(0.0f, -0.32f);
    glEnd();

    //Pillar - 2.1
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(0.2f,-0.7f);
    glVertex2f(0.25f, -0.65f);
    glVertex2f(0.25f, -0.4f);
    glVertex2f(0.2f, -0.4f);
    glEnd();

    //Pillar - 2.2
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(0.25f, -0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.3f,-0.25f);
    glVertex2f(0.38f, -0.20f);
    glEnd();

    glPopMatrix();

    //Pillar - 3 begin
    glPushMatrix();

    //Pillar - 3.1
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(0.90f, -0.45f);
    glVertex2f(0.95f, -0.40f);
    glVertex2f(0.95f, -0.20f);
    glVertex2f(0.90f, -0.20f);
    glEnd();

    //Pillar - 3.2
    glBegin(GL_QUADS);
    glColor3ub (180, 160, 170);
    glVertex2f(0.90f, -0.20f);
    glVertex2f(0.95f, -0.20f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(0.95f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (205, 197, 191);
    glVertex2f(0.75f, -0.45f);
    glVertex2f(0.90f, -0.45f);
    glVertex2f(0.90f, -0.20f);
    glVertex2f(0.95f, -0.113f);
    glVertex2f(0.75f, -0.155f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub (205, 197, 191);
    glVertex2f(0.7f,-0.168f);
    glVertex2f(0.75f, -0.22f);
    glVertex2f(0.75f, -0.155f);
    glEnd();
    glPopMatrix();


    //Bridge Span back side
    glPushMatrix();

    //1
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f(-0.875f, -0.20f);
    glVertex2f( -0.775f, -0.40f);
    glVertex2f( -0.725f,  -0.40f);
    glVertex2f( -0.825f, -0.19f);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f(-0.625f, -0.145f);
    glVertex2f( -0.525f, -0.35f);
    glVertex2f( -0.475f,  -0.35f);
    glVertex2f( -0.575f, -0.155f);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f(-0.375f, -0.09f);
    glVertex2f( -0.275f, -0.30f);
    glVertex2f( -0.225f,  -0.30f);
    glVertex2f( -0.325f, -0.09f);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f(-0.125f, -0.05f);
    glVertex2f( -0.025f, -0.25f);
    glVertex2f( 0.025f,  -0.25f);
    glVertex2f( -0.075f, -0.05f);
    glEnd();

    //5
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.125f, 0.01f);
    glVertex2f( 0.225f, -0.20f);
    glVertex2f( 0.275f,  -0.20f);
    glVertex2f( 0.175f, 0.01f);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.375f, 0.04f);
    glVertex2f( 0.475f, -0.15f);
    glVertex2f( 0.525f, -0.14f);
    glVertex2f( 0.425f, 0.045f);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.625f, 0.095f);
    glVertex2f( 0.725f, -0.09f);
    glVertex2f( 0.775f,  -0.09f);
    glVertex2f( 0.675f, 0.095f);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.875f, 0.15f);
    glVertex2f( 0.975f, -0.03f);
    glVertex2f( 1.025f,  -0.03f);
    glVertex2f( 0.925f, 0.15f);
    glEnd();

    glPopMatrix();

    //Bridge Span - //Bridge Span back side 2

    glPushMatrix();

    //1
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( -0.975f,  -0.45f);
    glVertex2f( -0.925f, -0.45f);
    glVertex2f( -0.875f, -0.20f);
    glVertex2f( -0.925f, -0.20f);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( -0.725f,  -0.40f);
    glVertex2f( -0.675f, -0.40f);
    glVertex2f(-0.625f, -0.15f);
    glVertex2f( -0.675f, -0.15f);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f(-0.475f,  -0.35f);
    glVertex2f( -0.425f, -0.35f);
    glVertex2f( -0.375f,  -0.10f);
    glVertex2f( -0.425f, -0.10f);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( -0.225f,  -0.30f);
    glVertex2f( -0.175f, -0.29f);
    glVertex2f( -0.125f, -0.05f);
    glVertex2f( -0.175f, -0.05f);
    glEnd();

    //5
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.025f, -0.23f);
    glVertex2f( 0.20f-0.125, -0.23f);
    glVertex2f( 0.25f-0.125, 0.0f);
    glVertex2f( 0.20f-0.125, 0.0f);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.40f-0.125, -0.195f);
    glVertex2f( 0.45f-0.125, -0.185f);
    glVertex2f( 0.50f-0.125, 0.05f);
    glVertex2f( 0.45f-0.125, 0.05f);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.65f-0.125, -0.140f);
    glVertex2f( 0.70f-0.125, -0.130f);
    glVertex2f( 0.75f-0.125, 0.10f);
    glVertex2f( 0.70f-0.125, 0.10f);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub (160, 200, 220);
    glVertex2f( 0.90f-0.125, -0.085f);
    glVertex2f( 0.95f-0.125, -0.075f);
    glVertex2f( 1.0f-0.125, 0.15f);
    glVertex2f( 0.95f-0.125, 0.15f);
    glEnd();

    glPopMatrix();


    //Train viaduct
    glBegin(GL_QUADS);
    glColor3ub (230, 230, 230);
    glVertex2f(-1.0f, -0.47f);
    glVertex2f( 1.0f, -0.04f);
    glVertex2f( 1.0f,  -0.01f);
    glVertex2f( -1.0f, -0.44f);
    glEnd();

    //train
    glPushMatrix();
    glTranslatef(txposition, typosition, 0.0f);

    //Engine
    //back quad
    glBegin(GL_QUADS);
    glColor3ub (255, 165, 0);
    glVertex2f(-0.1f, -0.29f);
    glVertex2f( 0.1f, -0.25f);
    glVertex2f( 0.1f,  -0.1f);
    glVertex2f( -0.14f, -0.16f);
    glEnd();
    //front quad 1.1
    glBegin(GL_QUADS);
    glColor3ub (255, 165, 0);
    glVertex2f(0.1f, -0.25f);
    glVertex2f( 0.2f, -0.22f);
    glVertex2f( 0.2f,  -0.145f);
    glVertex2f( 0.10f, -0.10f);
    glEnd();
    //front quad 1.2
    glBegin(GL_TRIANGLES);
    glColor3ub (255, 165, 0);
    glVertex2f(0.2f, -0.22f);
    glVertex2f( 0.23f, -0.16f);
    glVertex2f( 0.2f,  -0.15f);
    glEnd();

    //Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.08f, -0.272f);
    glVertex2f(0.2f, -0.2f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, -0.16f);
    glVertex2f(-0.091f, -0.272f);
    glEnd();

    //window black
    glBegin(GL_QUADS);
    glColor3ub (0, 0, 0);
    glVertex2f(-0.1f, -0.217f);
    glVertex2f( 0.09f,  -0.165f);
    glVertex2f( 0.08f, -0.127f);
    glVertex2f(-0.11f, -0.172f);
    glEnd();

    //windows white
    glLineWidth(13);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.085f, -0.186f);
    glVertex2f(-0.065f, -0.179f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.045f, -0.176f);
    glVertex2f(-0.025f, -0.169f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.005f, -0.166f);
    glVertex2f(0.015f, -0.159f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.035f, -0.156f);
    glVertex2f(0.055f, -0.149f);
    glEnd();

    //front glass
    glBegin(GL_QUADS);
    glColor3ub (255, 255, 255);
    glVertex2f(0.12f, -0.162f);
    glVertex2f( 0.2f, -0.15f);
    glVertex2f( 0.125f,  -0.122f);
    glVertex2f( 0.11f, -0.123f);
    glEnd();


    //Compartment-1
    glBegin(GL_QUADS);
    glColor3ub (255, 165, 0);
    glVertex2f(-0.41f, -0.4f);
    glVertex2f( -0.13f, -0.3f);
    glVertex2f(-0.16f,  -0.165f);
    glVertex2f( -0.43f, -0.22f);
    glEnd();

    //Compartment 1 window black
    glBegin(GL_QUADS);
    glColor3ub (0, 0, 0);
    glVertex2f(-0.4f, -0.24f);
    glVertex2f( -0.39f,  -0.29f);
    glVertex2f( -0.17f, -0.24f);
    glVertex2f(-0.19f, -0.19f);
    glEnd();





    //Compartment-2
    glBegin(GL_QUADS);
    glColor3ub (255, 165, 0);
    glVertex2f(-0.71f, -0.45f);
    glVertex2f( -0.437f, -0.4f);
    glVertex2f(-0.457f,  -0.232f);
    glVertex2f( -0.73f, -0.291f);
    glEnd();

    //Compartment 2 window black
    glBegin(GL_QUADS);
    glColor3ub (0, 0, 0);
    glVertex2f(-0.71f, -0.32f);
    glVertex2f( -0.7f,  -0.368f);
    glVertex2f( -0.47f, -0.315f);
    glVertex2f(-0.49f, -0.265f);
    glEnd();






    glPopMatrix();


    //Bridge Span front side
    glPushMatrix();

    //1
    glBegin(GL_QUADS);

    glColor3ub (198, 226, 255);
    glVertex2f(-1.0f, -0.22f);
    glVertex2f( -0.9f, -0.48f);
    glVertex2f( -0.85f,  -0.47f);
    glVertex2f( -0.95f, -0.211f);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f(-0.75f, -0.17f);
    glVertex2f( -0.65f, -0.425f);
    glVertex2f( -0.60f,  -0.415f);
    glVertex2f( -0.70f, -0.165f);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f(-0.5f, -0.12f);
    glVertex2f( -0.4f, -0.370f);
    glVertex2f( -0.35f,  -0.360f);
    glVertex2f( -0.45f, -0.119f);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f(-0.25f, -0.07f);
    glVertex2f( -0.15f, -0.315f);
    glVertex2f( -0.10f,  -0.305f);
    glVertex2f( -0.20f, -0.065f);
    glEnd();

    //5
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.00f, -0.02f);
    glVertex2f( 0.10f, -0.260f);
    glVertex2f( 0.15f,  -0.250f);
    glVertex2f( 0.05f, -0.015f);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.25f, 0.03f);
    glVertex2f( 0.35f, -0.205f);
    glVertex2f( 0.40f,  -0.195f);
    glVertex2f( 0.30f, 0.035f);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.50f, 0.08f);
    glVertex2f( 0.60f, -0.150f);
    glVertex2f( 0.65f,  -0.140f);
    glVertex2f( 0.55f, 0.085f);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.75f, 0.13f);
    glVertex2f( 0.85f, -0.095f);
    glVertex2f( 0.90f,  -0.085f);
    glVertex2f( 0.80f, 0.136f);
    glEnd();

    glPopMatrix();


    //Bridge Span - //Bridge Span front side 2
    glPushMatrix();

    //1
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);

    glVertex2f( -0.85f,  -0.47f);
    glVertex2f( -0.80f, -0.46f);
    glVertex2f( -0.75f, -0.17f);
    glVertex2f( -0.80f, -0.180f);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( -0.60f,  -0.415f);
    glVertex2f( -0.55f, -0.408f);
    glVertex2f(-0.5f, -0.12f);
    glVertex2f( -0.55f, -0.13f);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f(-0.35f,  -0.360f);
    glVertex2f( -0.30f, -0.350f);
    glVertex2f( -0.25f,  -0.07f);
    glVertex2f( -0.30f, -0.08f);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( -0.10f,  -0.305f);
    glVertex2f( -0.05f, -0.295f);
    glVertex2f( 0.00f, -0.02f);
    glVertex2f( -0.05f, -0.03f);
    glEnd();

    //5
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.15f,  -0.250f);
    glVertex2f( 0.20f, -0.240f);
    glVertex2f( 0.25f, 0.03f);
    glVertex2f( 0.20f, 0.02f);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.40f,  -0.195f);
    glVertex2f( 0.45f,  -0.185f);
    glVertex2f( 0.50f, 0.08f);
    glVertex2f( 0.45f, 0.07f);
    glEnd();
    //7
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.65f,  -0.140f);
    glVertex2f( 0.70f, -0.130f);
    glVertex2f( 0.75f, 0.13f);
    glVertex2f( 0.70f, 0.12f);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub (198, 226, 255);
    glVertex2f( 0.90f,  -0.085f);
    glVertex2f( 0.95f, -0.075f);
    glVertex2f( 1.0f, 0.18f);
    glVertex2f( 0.95f, 0.17f);
    glEnd();

    glPopMatrix();


    //Lamp post
    glPushMatrix();

    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub (198, 226, 255);
    //lamp1 upper
    glVertex2f(-0.8f, 0.50f);
    glVertex2f(-0.8f, 0.15f);

    glVertex2f(-0.8f, 0.50f);
    glVertex2f(-0.75f, 0.50f);

    //Lamp2 upper
    glVertex2f(-0.4f, 0.58f);
    glVertex2f(-0.4f, 0.23f);

    glVertex2f(-0.4f, 0.58f);
    glVertex2f(-0.35f, 0.58f);

    //Lamp3 upper
    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.33f);

    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.05f, 0.65f);

    //Lamp4 upper
    glVertex2f(0.4f, 0.73f);
    glVertex2f(0.4, 0.40f);

    glVertex2f(0.4, 0.73f);
    glVertex2f(0.45f, 0.73f);

    //Lamp5 upper
    glVertex2f(0.8f, 0.80f);
    glVertex2f(0.8, 0.49f);

    glVertex2f(0.8, 0.80f);
    glVertex2f(0.85f, 0.80f);


    //Lamp1 lower
    glVertex2f(-0.6f, 0.14f);
    glVertex2f(-0.6, -0.14f);

    glVertex2f(-0.6, 0.14f);
    glVertex2f(-0.65f, 0.14f);

    //Lamp2 lower
    glVertex2f(-0.2f, 0.22f);
    glVertex2f(-0.2, -0.06f);

    glVertex2f(-0.2, 0.22f);
    glVertex2f(-0.25f, 0.22f);

    //Lamp3 lower
    glVertex2f(0.2f, 0.32f);
    glVertex2f(0.2, 0.02f);

    glVertex2f(0.2, 0.32f);
    glVertex2f(0.15f, 0.32f);

    //Lamp4 lower
    glVertex2f(0.6f, 0.40f);
    glVertex2f(0.6, 0.1f);

    glVertex2f(0.6, 0.40f);
    glVertex2f(0.55f, 0.40f);

    glEnd();



    if(sunlight){
        glPushMatrix();
        glLineWidth(8);
        //Bulb upper
        glBegin(GL_LINES);
        glColor3ub (198, 226, 255);
        glVertex2f(-0.78f, 0.50f);
        glVertex2f(-0.75f, 0.50f);
        glVertex2f(-0.38f, 0.58f);
        glVertex2f(-0.35f, 0.58f);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(0.05f, 0.65f);
        glVertex2f(0.42, 0.73f);
        glVertex2f(0.45f, 0.73f);
        glVertex2f(0.82, 0.80f);
        glVertex2f(0.85f, 0.80f);
        //Bulb lower
        glVertex2f(-0.62, 0.14f);
        glVertex2f(-0.65f, 0.14f);
        glVertex2f(-0.22, 0.22f);
        glVertex2f(-0.25f, 0.22f);
        glVertex2f(0.18, 0.32f);
        glVertex2f(0.15f, 0.32f);
        glVertex2f(0.58, 0.40f);
        glVertex2f(0.55f, 0.40f);
        glEnd();
        glPopMatrix();
    }

    else{
        glPushMatrix();
        glLineWidth(8);
        //Bulb upper
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.78f, 0.50f);
        glVertex2f(-0.75f, 0.50f);
        glVertex2f(-0.38f, 0.58f);
        glVertex2f(-0.35f, 0.58f);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(0.05f, 0.65f);
        glVertex2f(0.42, 0.73f);
        glVertex2f(0.45f, 0.73f);
        glVertex2f(0.82, 0.80f);
        glVertex2f(0.85f, 0.80f);
        //Bulb lower
        glVertex2f(-0.62, 0.14f);
        glVertex2f(-0.65f, 0.14f);
        glVertex2f(-0.22, 0.22f);
        glVertex2f(-0.25f, 0.22f);
        glVertex2f(0.18, 0.32f);
        glVertex2f(0.15f, 0.32f);
        glVertex2f(0.58, 0.40f);
        glVertex2f(0.55f, 0.40f);
        glEnd();
        glPopMatrix();
    }



 glPushMatrix();
    //Bridge viaduct upper
    glBegin(GL_QUADS);
    glColor3ub (255, 255, 255);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f( 1.0f, 0.5f);
    glVertex2f( 1.0f,  0.55f);
    glVertex2f( -1.0f, 0.15f);

    glVertex2f(-1.0f, -0.24f);
    glVertex2f( 1.0f, 0.16f);
    glVertex2f( 1.0f,  0.2f);
    glVertex2f( -1.0f, -0.2f);
    glEnd();
        glPopMatrix();

        glPushMatrix();
    //Lower deck viaduct
    glBegin(GL_QUADS);
    glColor3ub (230, 230, 230);
    glVertex2f(-1.0f, -0.54f);
    glVertex2f( 1.0f, -0.11f);
    glVertex2f( 1.0f,  -0.05f);
    glVertex2f( -1.0f, -0.48f);
    glEnd();
        glPopMatrix();
    rain();

    car();



    glFlush();
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 0.1f;
    }
    glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
            r = 2;
            break;
        case 's':
            r = 1;
            break;


        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1680,1080);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Translation Animation");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutSwapBuffers();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
   return 0;
}

