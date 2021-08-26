#ifndef MIX_COLOR_SHADER_H
#define MIX_COLOR_SHADER_H

namespace MixColorShader{
	struct Varying{
		vec4 position;
		vec3 color;
	};
	Varying operator*(float t, Varying V){
		return {t*V.position, t*V.color};
	}
	Varying operator+(Varying U, Varying V){
		return {U.position + V.position, U.color + V.color};
	}

	mat4 M;
	vec3 pmin, pmax;
	std::array<Color, 8> C;
	
	template<typename Vertex>
	void vertexShader(Vertex in, Varying& out){
		vec4 pos = getPosition(in);
		out.position = M*pos;
		float dx = (pos.x-pmin.x)/(pmax.x - pmin.x);
		float dy = (pos.y-pmin.y)/(pmax.y - pmin.y);
		float dz = (pos.z-pmin.z)/(pmax.z - pmin.z);
		Color C1 = bilerp(dx, dz, C[0], C[1], C[2], C[3]);
		Color C2 = bilerp(dx, dz, C[4], C[5], C[6], C[7]);
		out.color = toVec3(lerp(dy, C1, C2));
	}

	void fragmentShader(Varying V, Color& FragColor){
		FragColor = toColor(V.color);
	}
}

#endif
