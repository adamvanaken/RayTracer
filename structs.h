#include "transformations.h"

#define SOLID 1
#define CHECKERED 2

#define SPHERE 1
// class Mesh{
//   public:
//     Mesh();

    
// };

class Camera{
public:
    Camera(Vec3 e, Vec3 c, Vec3 up);
    Vec3 origin;
    Vec3 x;
    Vec3 y;
    Vec3 z;
};

class Ray{
public:
    Ray(Vec3 ori, Vec3 dir);
    Vec3 origin;
    Vec3 direction;
};

class Sphere{
  public:
    Sphere();
    Sphere(Vec3 c, float r);
    Vec3 center;
    float radius;
};

class Object{
public:
    Object();
    Object(Sphere s, int col, int f, int n);
    Sphere sphere;
    int color;
    int finish;
    int numTrans;
    int type;
    bool Collide(Ray r, float &t);
    Vec3 normal(Vec3 point);
};

class Finish{
public:
    Finish();
    Finish(float am, float dif, float spec, float shin, float refl, float trans, float ior);
    float ambiance;
    float diffuse;
    float specular;
    float shininess;
    float reflect;
    float transmission;
    float refraction;
};

class Pigment{
public:
    Pigment();
    Pigment(int t, Vec3 col1, Vec3 col2, float s);
    int type;
    Vec3 color;
    Vec3 color2;
    float scale;

    Vec3 GetColor(Vec3 point);
};

class Light{
public:
    Light();
    Light(Vec3 pos, Vec3 inten, Vec3 atten);
    Vec3 position;
    Vec3 intensity;
    Vec3 attenuation;
};