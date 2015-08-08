#pragma once 

#include <glm/glm.hpp>
#include <deque>
#include <stack>
#include <vector>
#include "../core/Scene.h"

using namespace glm;

namespace raytracer 
{
	class SceneBuilder
	{
		Camera *camera;
		vector<Primitive*> primitives;
		vector<Light*> lights;

		Attenuation attenuation;
		bool isAttenuationSet = false;
		stack<mat4> transformStack;
		bool isAnyTrsnform = false;
		
		string outputFile;

	public:
		Color bgColor;
		int recursionDepth = 3;
		int fragmentsPerPixel = 2;
		short bitsPerPixel = 24;

		Scene*		buildScene();
		void		setupCamera(int width, int heght, float fovXDeg, vec3 lookFrom, vec3 lookTo, vec3 up);

		void		addPrimitive(Primitive* primitive);
		void		addLight(Light* light);
		void		setAttenuation(float constant, float linear, float quad);

		void		setOutputFile(string pathAndName);

		void		addTransform(const mat4& transform);
		void		pushTransform();
		void		popTransform();

					SceneBuilder(int approxPrimitivesCnt = 20, int approxLightCnt = 5);
	};
}