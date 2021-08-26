#ifndef SIMPLE_SHADER_H
#define SIMPLE_SHADER_H

#include "matrix.h"
#include "Color.h"
#include "VertexUtils.h"

namespace SimpleShader{
	struct Varying{
		vec4 position;
	};
	Varying operator*(float t, Varying V){
		return {t*V.position};
	}

	Varying operator+(Varying U, Varying V){
		return {U.position + V.position};
	}

	mat4 M;
	Color C;

	template<class Vertex>
	void vertexShader(Vertex in, Varying& out){
		out.position = M*getPosition(in);
	}

	void fragmentShader(Varying, Color& fragColor){
		fragColor = C;
	}
}

#endif
