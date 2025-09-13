// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// scene.cpp



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "constants.h"			// system-wide constants
#include "utility.h"			// general utility functions
#include "light.h"
#include "camera.h"
#include "texture.h"
#include "scene.h"
#include "snd.h"
#include "skybox.h"
#include "fog.h"
#include "viewfrustum.h"


// #includes for geometry
#include "sweep.h"
#include "extrusion.h"
#include "cube.h"
#include "sphere.h"
#include "torus.h"
#include "terrain.h"
#include "billboard.h"
#include "plane.h"
#include "tsphere.h"
#include "cylinder.h"
#include "disc.h"

// Include our composite objects
#include "Composite1.h"  // Car
#include "Composite2.h"  // Airplane

// -----------------------------------------------------------------------------------------
// global variables
// -----------------------------------------------------------------------------------------
extern ProgramMode		gProgramMode;							// initially, we're not animating

extern cameraClass		gCamera;								// the camera
extern object3d			*gSky;									// the global skybox
extern fog				*gFog;									// the global fog
extern viewfrustum		*gViewFrustum;							// the global view frustum object
extern float			gCurrentFrameTime;						// the time that the current animation frame was started

extern vector<object3d*> gShapeVector;
typedef vector<object3d*>::iterator shapeVectorIterator;






// -----------------------------------------------------------------------------------------
// variables that represent 3D objects being used in the animation
// -----------------------------------------------------------------------------------------
// these are really global variables, but you shouldn't need to access them from anywere
// except in this file 
// -----------------------------------------------------------------------------------------

// pointer of shapes defined here

// Composite objects - our main vehicles
Composite1 *car;        // Car composite object
Composite2 *airplane;   // Airplane composite object

// Environment objects
plane *ground;          // Ground plane
texture *groundTexture; // Ground texture


// some lights
light *ambient, *light0, *light1, *light2;



// -----------------------------------------------------------------------------------------
// constructScene
// -----------------------------------------------------------------------------------------
// This function constructs the objects required for the animation.  It is only called once
// when the program is first run.
// Use this to create child objects and bind them to their parents.
// -----------------------------------------------------------------------------------------

void constructScene()
{
	// create the lights first
	ambient = new light(GL_LIGHT_MODEL_AMBIENT);
	light0 = new light(GL_LIGHT0);
	light1 = new light(GL_LIGHT1);
    
    // Create ground plane for reference
    groundTexture = new texture("boxtex.jpg");
    ground = new plane();
    ground->setTexture(groundTexture);
    ground->setPosition(0, -2, 0);
    ground->setScale(50.0); // Large ground plane
    ground->setRotation('x', -90); // Horizontal
    ground->setColour(0.3, 0.8, 0.3, 1.0); // Green ground
    
	// Create our composite objects
    car = new Composite1();      // Create the car
    airplane = new Composite2(); // Create the airplane
    
    // Position them initially
    car->setPosition(-10, 0, 0);      // Car starts on left
    airplane->setPosition(10, 8, 0);  // Airplane starts on right, in air
}




// -----------------------------------------------------------------------------------------
// resetScene
// -----------------------------------------------------------------------------------------
// This function is called whenever the animation is restarted.  Use it to reset objects
// to their starting position or size, or to reset any aspects of the objects that
// might have been altered during an animation sequence.
// -----------------------------------------------------------------------------------------

void resetScene()
{
	// initialise the camera
	gCamera.setPosition(0, 15, 25);  // Higher up to see both vehicles
	gCamera.setTarget(0, 3, 0);      // Look at center, slightly up
    
	ambient->setColour(0.4, 0.4, 0.4, 1.0); // Slightly brighter ambient
    
	light0->turnOn();
	light0->setPosition(-20, 20, 10);
	light0->setColour(1.0, 1.0, 0.9, 1.0);  // Warm sunlight
	light0->setSpecularColour(1.0, 1.0, 0.9, 1.0);
	light0->makePositional();
	light0->setLinearAttenuation(0.05);
	
	light1->turnOn();
	light1->setPosition(20, 15, -10);
	light1->setColour(0.8, 0.8, 1.0, 1.0);  // Cool fill light
	light1->setSpecularColour(0.8, 0.8, 1.0, 1.0);
	light1->makePositional();
	light1->setLinearAttenuation(0.05);
    
	// Reset composite objects to their starting positions and animations
    if (car) {
        car->setPosition(-10, 0, 0);
        car->resetAnimations();
        car->show(); // Make sure car is visible
    }
    
    if (airplane) {
        airplane->setPosition(10, 8, 0);
        airplane->resetAnimations();
        airplane->show(); // Make sure airplane is visible
    }
}




// -----------------------------------------------------------------------------------------
// animateForNextFrame
// -----------------------------------------------------------------------------------------
// This function is called to animate objects ready for the next frame
// -----------------------------------------------------------------------------------------


void animateForNextFrame(float time, long frame)
{
    // Calculate delta time for smooth animation
    static float lastTime = 0.0f;
    float deltaTime = time - lastTime;
    lastTime = time;
    
    // Animate the car if it exists
    if (car) {
        // Always animate wheels spinning
        car->animateWheelsSpin(deltaTime);
        
        // Animate doors opening/closing (starts at 2 seconds)
        if (time >= 2.0f) {
            car->animateDoorsOpen(deltaTime);
        }
        
        // Animate car movement in circle (starts at 5 seconds)
        if (time >= 5.0f) {
            car->animateCarMovement(deltaTime);
        }
    }
    
    // Animate the airplane if it exists  
    if (airplane) {
        // Always animate propeller spinning
        airplane->animatePropellerSpin(deltaTime);
        
        // Animate landing gear retraction (starts at 3 seconds)
        if (time >= 3.0f) {
            airplane->animateLandingGearRetract(deltaTime);
        }
        
        // Animate flight pattern (starts at 1 second)
        if (time >= 1.0f) {
            airplane->animateFlightPattern(deltaTime);
        }
    }
    
    // Camera movement for better viewing
    if (time >= 10.0f) {
        // Slowly rotate camera around the scene
        float cameraAngle = (time - 10.0f) * 15.0f; // 15 degrees per second
        float cameraDistance = 30.0f;
        float cameraX = cameraDistance * sin_d(cameraAngle);
        float cameraZ = cameraDistance * cos_d(cameraAngle);
        gCamera.setPosition(cameraX, 18, cameraZ);
        gCamera.setTarget(0, 5, 0);
    }
    
    // Toggle object visibility for demonstration (optional)
    if (time >= 20.0f && time < 25.0f) {
        // Hide car to showcase airplane only
        if (car) car->hide();
    }
    else if (time >= 25.0f && time < 30.0f) {
        // Hide airplane to showcase car only  
        if (car) car->show();
        if (airplane) airplane->hide();
    }
    else {
        // Show both objects
        if (car) car->show();
        if (airplane) airplane->show();
    }

	// eventually stop the animation
	if (time >= 45)
		gProgramMode = kpmFinished;
}

