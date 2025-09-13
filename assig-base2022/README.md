# Computer Graphics Mini Project - Vehicle Animation

**Course:** KXC354 - Computer Graphics & Animation  
**Assignment:** Mini Project - Composite Objects with Animation  
**Author:** Student  
**Date:** December 2024

## Project Overview

This project implements two composite 3D objects (vehicles) using C++ and OpenGL with complex hierarchical structures and animations. The project demonstrates advanced computer graphics concepts including:

- Composite object design with parent-child relationships
- Multiple independent animation systems
- Texture mapping and transparency
- 3D geometric primitives (cubes, spheres, cylinders, torus)
- Advanced geometry (extrusion and sweep objects)
- Lighting and camera systems

## Composite Objects

### Composite1: Car
A detailed car model with the following **15 child components**:

#### Components:
1. **Body** (cube) - Main car chassis
2. **Hood** (cube) - Front hood section  
3. **Roof** (cube) - Car roof
4. **Wheel1** (torus) - Front left wheel
5. **Wheel2** (torus) - Front right wheel
6. **Wheel3** (torus) - Rear left wheel
7. **Wheel4** (torus) - Rear right wheel
8. **Axle1** (cylinder) - Front axle
9. **Axle2** (cylinder) - Rear axle
10. **Door1** (cube) - Left door
11. **Door2** (cube) - Right door
12. **Headlight1** (sphere) - Left headlight
13. **Headlight2** (sphere) - Right headlight
14. **Windshield** (extrusion) - Front windshield glass
15. **Exhaust** (sweep) - Exhaust pipe

#### Independent Animations:
- **Wheel Spinning:** All four wheels rotate continuously
- **Door Opening:** Both doors open and close in oscillating motion
- **Circular Movement:** Entire car moves in a circular path

### Composite2: Airplane
A detailed airplane model with the following **15 child components**:

#### Components:
1. **Fuselage** (cylinder) - Main airplane body
2. **Wing1** (cube) - Left wing
3. **Wing2** (cube) - Right wing
4. **TailWing** (cube) - Horizontal stabilizer
5. **VerticalTail** (cube) - Vertical stabilizer
6. **Propeller** (cylinder) - Propeller hub
7. **PropBlade1** (cube) - Propeller blade 1
8. **PropBlade2** (cube) - Propeller blade 2
9. **PropBlade3** (cube) - Propeller blade 3
10. **LandingGear1** (cylinder) - Left landing gear strut
11. **LandingGear2** (cylinder) - Right landing gear strut
12. **Wheel5** (sphere) - Left landing gear wheel
13. **Wheel6** (sphere) - Right landing gear wheel
14. **Cockpit** (extrusion) - Cockpit canopy
15. **Exhaust2** (sweep) - Engine exhaust

#### Independent Animations:
- **Propeller Spinning:** 3-blade propeller rotates at high speed
- **Landing Gear Retraction:** Landing gear extends and retracts
- **Flight Pattern:** Airplane flies in figure-8 pattern with banking

## Technical Requirements Compliance

### ✅ Composite Objects (50% requirement)
- **Two separate class-based composite objects:** `Composite1` (Car) and `Composite2` (Airplane)
- **8+ child objects each:** Car has 15 components, Airplane has 15 components
- **Geometry variety:** Uses cube, cylinder, torus, sphere, extrusion, and sweep primitives
- **Animation methods:** Each composite has 3 independent animation methods
- **Hide/Show methods:** Properly implemented for all child objects

### ✅ Advanced Features
- **Two extrusions:** Windshield (car) and Cockpit (airplane)  
- **Two sweeps:** Exhaust pipes for both vehicles
- **Textured objects:** Multiple textured components
- **Transparent objects:** Windshield and cockpit canopy with alpha blending
- **Real recognizable objects:** Realistic car and airplane models

### ✅ Animation System
- **Independent animations:** 6 total animation methods (3 per composite)
- **Class-only animation:** All animations called through composite class methods
- **No direct manipulation:** Child objects only animated through parent methods

## File Structure

```
assig-base2022/
├── objects-student/
│   ├── Composite1.h          # Car class header
│   ├── Composite1.cpp        # Car class implementation
│   ├── Composite2.h          # Airplane class header
│   └── Composite2.cpp        # Airplane class implementation
├── basicsource/
│   └── scene.cpp            # Updated scene with composite integration
├── resources/
│   ├── windshield_profile.txt
│   ├── windshield_path.txt
│   ├── cockpit_profile.txt  
│   ├── cockpit_path.txt
│   ├── exhaust_profile.txt
│   └── boxtex.jpg           # Texture file
└── README.md                # This documentation
```

## Hierarchical Structure Diagrams

### Car (Composite1) Hierarchy:
```
Car (Composite1)
└── Body (cube) - Main parent
    ├── Hood (cube)
    ├── Roof (cube)  
    ├── Wheel1 (torus) - Animatable
    ├── Wheel2 (torus) - Animatable
    ├── Wheel3 (torus) - Animatable
    ├── Wheel4 (torus) - Animatable
    ├── Axle1 (cylinder)
    ├── Axle2 (cylinder)
    ├── Door1 (cube) - Animatable
    ├── Door2 (cube) - Animatable
    ├── Headlight1 (sphere)
    ├── Headlight2 (sphere)
    ├── Windshield (extrusion) - Transparent
    └── Exhaust (sweep)
```

### Airplane (Composite2) Hierarchy:
```  
Airplane (Composite2)
└── Fuselage (cylinder) - Main parent
    ├── Wing1 (cube)
    ├── Wing2 (cube)
    ├── TailWing (cube)
    ├── VerticalTail (cube)
    ├── Propeller (cylinder) - Animatable
    │   ├── PropBlade1 (cube)
    │   ├── PropBlade2 (cube)
    │   └── PropBlade3 (cube)
    ├── LandingGear1 (cylinder) - Animatable
    │   └── Wheel5 (sphere)
    ├── LandingGear2 (cylinder) - Animatable
    │   └── Wheel6 (sphere)
    ├── Cockpit (extrusion) - Transparent
    └── Exhaust2 (sweep)
```

## Animation Timeline

| Time | Event |
|------|-------|
| 0s | Both vehicles appear, propeller starts spinning, wheels start rotating |
| 1s | Airplane begins flight pattern |
| 2s | Car doors begin opening/closing |
| 3s | Airplane landing gear begins retracting/extending |
| 5s | Car begins circular movement |
| 10s | Camera starts rotating around scene |
| 20s | Car hidden (airplane showcase) |
| 25s | Airplane hidden (car showcase) |
| 30s | Both vehicles visible again |
| 45s | Animation ends |

## Installation and Running Instructions

### Prerequisites:
- Visual Studio 2019 or later
- OpenGL libraries (included in project)
- GLEW library (included)
- SOIL library for texture loading (included)

### Setup Steps:

1. **Extract Project Files:**
   ```bash
   # Extract to desired directory
   unzip mini-project.zip
   cd assig-base2022
   ```

2. **Open in Visual Studio:**
   - Open `assig2.sln` in Visual Studio
   - Ensure Release configuration is selected
   - Build solution (F7)

3. **Add Resource Files:**
   - Create `resources/` folder in project directory
   - Copy texture files (`boxtex.jpg`) to `resources/`
   - Copy profile files to `resources/`:
     - `windshield_profile.txt`
     - `windshield_path.txt`
     - `cockpit_profile.txt`
     - `cockpit_path.txt`
     - `exhaust_profile.txt`

4. **Run Application:**
   - Press F5 to run in debug mode
   - Or run the executable directly from `build/` folder

### Controls:
- **'a'** - Start animation
- **'p'** - Pause/unpause animation
- **'f'** - Toggle fullscreen
- **'w'** - Toggle wireframe mode
- **'t'** - Toggle text display
- **'q'** - Quit application
- **Mouse** - Navigate camera (click and drag)

## Code Architecture

### Composite Design Pattern
Both composite classes inherit from `object3d` and implement the composite pattern:

```cpp
class Composite1 : public object3d {
private:
    // Child object pointers
    cube* body;
    torus* wheel1;
    // ... other components
    
public:
    // Required methods
    virtual void hide();
    virtual void show(); 
    
    // Animation methods
    void animateWheelsSpin(float deltaTime);
    void animateDoorsOpen(float deltaTime);
    void animateCarMovement(float deltaTime);
};
```

### Animation System
Each composite object manages its own animations through dedicated methods:

```cpp
// Called from scene.cpp animateForNextFrame()
if (car) {
    car->animateWheelsSpin(deltaTime);
    car->animateDoorsOpen(deltaTime);
    car->animateCarMovement(deltaTime);
}
```

### Parent-Child Relationships
All child objects are properly parented for hierarchical transformations:

```cpp
// Example: Wheel attached to car body
wheel1->setParent(body);
wheel1->setPosition(2.5, -1.2, -2.3); // Relative to parent
```

## Features Demonstrated

### Graphics Techniques:
- **Hierarchical Modeling:** Complex parent-child relationships
- **Texture Mapping:** Applied to multiple objects  
- **Transparency:** Alpha blending for glass surfaces
- **Lighting:** Multiple light sources with different colors
- **Camera Animation:** Dynamic camera movement
- **Geometric Primitives:** Cubes, spheres, cylinders, tori
- **Advanced Geometry:** Extrusion and sweep objects

### Programming Concepts:
- **Object-Oriented Design:** Clean class hierarchy
- **Composite Pattern:** Complex objects from simple components  
- **Encapsulation:** Private animation state management
- **Polymorphism:** Virtual methods for hide/show
- **Memory Management:** Proper constructor/destructor implementation

## Troubleshooting

### Common Issues:

1. **Missing Texture Files:**
   - Ensure `boxtex.jpg` is in `resources/` folder
   - Check file permissions

2. **Profile Files Not Found:**
   - Verify all `.txt` profile files are in `resources/`
   - Check file encoding (should be ASCII/UTF-8)

3. **Compilation Errors:**
   - Ensure all header files are included
   - Check that objects-student folder is in include path
   - Verify Visual Studio platform toolset is set correctly

4. **Animation Not Working:**
   - Press 'a' to start animation
   - Check that `animateForNextFrame()` is being called
   - Verify delta time calculations

### Performance Notes:
- The project is optimized for smooth 60 FPS rendering
- Complex animations may affect performance on older systems
- Use wireframe mode ('w') for performance debugging

## Future Enhancements

Potential improvements that could be added:
- **Sound Effects:** Engine sounds, door sounds
- **Particle Systems:** Exhaust smoke, dust clouds
- **Physics:** Collision detection, realistic movement
- **Additional Vehicles:** Motorcycle, helicopter, boat
- **Environment:** Buildings, roads, runway
- **Interactive Controls:** User-controlled vehicles

## Conclusion

This project successfully demonstrates advanced computer graphics programming with complex composite objects, hierarchical modeling, and sophisticated animation systems. The implementation meets all assignment requirements while showcasing clean code architecture and engaging visual presentation.

The two vehicles (car and airplane) provide distinct examples of how composite objects can be used to create realistic, animated 3D models with independent, coordinated animations that bring the scene to life.