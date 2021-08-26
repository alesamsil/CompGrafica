#include <bits/stdc++.h>
#include <complex>
#include "Image.h"
#include "rasterization.h"
#include "Graphics2D.h"
#include "Primitives.h"
#include "vec.h"
#include "bezier.h"
#include "matrix.h"

using namespace std;


int main(){

    /// BORBOLETA---------------------------------------------------------------------------

    int N = 12,i=0; /// numero de repeticoes N = 12

    double t = (2*M_PI/N); /// Separação para cada desenho de quantos "graus" vão ocupar

    vector<vec2> P = loadCurve("borboleta.txt");
    vector<vec2> Q = sample_cubic_bezier_spline(P, 30);

	vec2 v = {500, 500}; /// Ponto central da imagem que será 1000, 1000

    mat3 R= { /// Matriz que será usada para rotacionar
        cos(t*i), -sin(t*i), 0.0,
        sin(t*i),  cos(t*i), 0.0,
        0.0,       0.0   , 1.0
    };
	mat3 T = { /// Matriz que será usada para centralizar de volta a imagem
		1.0, 0.0, v.x,
		0.0, 1.0, v.y,
		0.0, 0.0, 1.0
	};

	mat3 Ti = { /// Matriz que será usada para antes de rotacionar, uma vez q só rodamos com o eixo 0,0 como centro até aqui
		1.0, 0.0, -v.x,
		0.0, 1.0, -v.y,
		0.0, 0.0, 1.0
	};

	mat3 M = { /// Uma matriz de translação para arrumar um ultimo detalhe do desenho e se aproximar o máximo do exemplo dado
               /// Ela basicamente como é aplicada depois da Ti ela aumenta o raio em relação ao 0,0 que é mantida quando aplicamos
               /// o T e colocamos o "novo centro" como v;
		1.0, 0.0, 140,
		0.0, 1.0, 140,
		0.0, 0.0, 1.0
	};


    LineStrip L{Q.size()};

	Graphics2D G(1000, 1000);
	G.clear();
	G.draw((T*R*M*Ti)*Q, L, red); /// Fazemos o primeiro desenho fora do for pra desenhar a vermelha
	for(i=1; i<N; i++){
        R = {
            cos(t*i), -sin(t*i), 0.0,
            sin(t*i),  cos(t*i), 0.0,
              0.0,       0.0   , 1.0
        };
        /// O restante vamos recalculando a mtriz de rotação apenas e usando o mesmo processo, porém com cores azuis.
        G.draw((T*R*M*Ti)*Q, L, blue);
	}

	G.savePNG("borboletasFinal.png");

    return 0;
}
