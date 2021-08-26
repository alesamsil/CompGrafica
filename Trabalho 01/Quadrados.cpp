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
    int N = 50,i=0; /// numero de quadrados  = 50

    double t = (2*M_PI/N); /// Separa��o para cada desenho de quantos "graus" v�o ocupar

    std::vector<vec2> P = { /// Ponto onde a tarefa manda o quadrado iniciar.
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

	vec2 v = {500, 500}; /// Ponto central da imagem que ser� 1000, 1000

    mat3 R= {   /// Matriz que ser� usada para rotacionar a cada desenho
        cos(t*i), -sin(t*i), 0.0,
        sin(t*i),  cos(t*i), 0.0,
        0.0,    0.0, 1.0
    };
    mat3 R2= {/// Matriz que ser� usada para rotacionar apenas o quadrado inicialmente em 45� graus antes de aplicar o restante
              /// Das opera��es e impress�es.
        cos(M_PI/4), -sin(M_PI/4), 0.0,
        sin(M_PI/4),  cos(M_PI/4), 0.0,
        0.0,    0.0, 1.0
    };
	mat3 T = { /// Matriz que ser� usada para centralizar de volta a imagem
		1.0, 0.0, v.x,
		0.0, 1.0, v.y,
		0.0, 0.0, 1.0
	};

	mat3 Ti = { /// Matriz que ser� usada para antes de rotacionar, uma vez q s� rodamos com o eixo 0,0 como centro at� aqui
		1.0, 0.0, -v.x,
		0.0, 1.0, -v.y,
		0.0, 0.0, 1.0
	};

	mat3 M = { /// Uma matriz de transla��o para arrumar um ultimo detalhe do desenho e se aproximar o m�ximo do exemplo dado
		1.0, 0.0, 370,
		0.0, 1.0, 370,
		0.0, 0.0, 1.0
	};
	mat3 Maumenta = { /// Matriz para aumentar o tamanho do quadrado
		15.0, 0.0, 0.0,
		0.0, 15.0, 0.0,
		0.0, 0.0, 1.0
	};

    LineLoop L{P.size()};

	Graphics2D G(1000, 1000);
	G.clear();
	P = R2 * P; /// Aqui separadamente do restante das opera��es, rotaciono o quadrado que j� esta centralizado no 0,0
                /// com seus pontos originais em 45�.
	for(i=0; i<N; i++){
        R = { /// Modifica��o da matriz de rota��o principal a cada itera��o.
            cos(t*i), -sin(t*i), 0.0,
            sin(t*i),  cos(t*i), 0.0,
              0.0,       0.0   , 1.0
        };
        G.draw((T*R*Ti*M*Maumenta)*P, L, blue);

	}
	G.savePNG("QuadradosFinal.png");
    return 0;
}
