#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <deque>
#include <stack>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "../geometry/Primitive.h"
#include "../geometry/Triangle.h"
#include "../geometry/Sphere.h"
#include "../core/Scene.h"

using namespace glm;
using namespace std;

namespace raytracer {

    class Parser {
    public:
        static
        Scene*          createSceneFromFile(const char* fileName);

    private:
        static
        bool            readVals(stringstream &s, const int numvals, float* values);
    };

}

#endif