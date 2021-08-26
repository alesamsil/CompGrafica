#include "colors.inc"
camera{
 location <4, 2, -25>
 look_at <0, 0, 0>
 angle 36
}
light_source{ <500, 500, -1000> White }
background { color White }


union{
    ///Parte de Baixo --------------------------------------------------------------------------
        box{-1 ,1 scale <0.65,0.65,0.65> rotate <0,45,0>} 
        cylinder{ <0, 0, 1.5> , <0, 0, -1.5>, 0.4  rotate <0,45,0>}
        // Perna esquerda  
        cylinder{ <0, 0, 2> , <0, 0, 0>, 0.3 translate <0,-1.7,0> rotate <90,45,0>}//Perna
        sphere{0, 1.5 translate <0,0.1,-4.7>scale <0.35,0.35,0.35> rotate <0,45,0>}//ligação
        sphere{0, 1.5 translate <0.5,-6.5,-4.5>scale <1,0.35,0.35> rotate <0,45,0>}//pé  
        
        // Perna Direita 
        cylinder{ <0, 0, 2> , <0, 0, 0>, 0.3 translate <0,+1.7,0> rotate <90,45,0>}//Perna
        sphere{0, 1.5 translate <0,0.1,+4.7>scale <0.35,0.35,0.35> rotate <0,45,0>}//ligação
        sphere{0, 1.5 translate <0.5,-6.5,+5.1>scale <1,0.35,0.35> rotate <0,45,0>}//pé
    ///-----------------------------------------------------------------------------------------
    
    ///Parte de Cima ---------------------------------------------------------------------------
    
         
         cylinder{ <0, 0, 2.3> , <0, 0, 0.5>, 0.45 translate <0,3.5,-2.6> rotate <-45,45,0>}//braço esquerdo
         sphere{0, 1.5 translate <0,5.5,-4.8>scale <0.46,0.46,0.46> rotate <0,45,0>}//Ombro esquerdo 
         difference{//mão esquerda
            cylinder{ <0, 0, 2.3> , <0, 0, 1.0>, 0.4 translate <0,-2.5,-5.1> rotate <45,45,0>}
            cylinder{ <0, 0, 2.4> , <0, 0, 0.8>, 0.28 translate <0,-2.65,-5.1> rotate <45,45,0>}
         }
         
         
         cylinder{ <0, 0, 2.3> , <0, 0, -0.5>, 0.5 translate <-1.8,4.6,1.8> rotate <45,45,0>}//braço direito
         sphere{0, 1.5 translate <0,5.5,+4.8>scale <0.46,0.46,0.46> rotate <0,45,0>}//Ombro direito 
         difference{//mão direita
            cylinder{ <0, 0, 2.3> , <0, 0, 0.8>, 0.6 translate <-1.7,-4.7,3.1> rotate <-45,45,0>}
            cylinder{ <0, 0, 2.3> , <0, 0, 0.8>, 0.3 translate <-1.7,-4.9,3.1> rotate <-45,45,0>}
         }
     ///-----------------------------------------------------------------------------------------
    /// Tronco
        cylinder{ <0, 2, 0> , <0, 0, 0>, 0.58}
        torus {
            1, 0.5         
            rotate -0*x      
            pigment {Green} 
            translate<0,1.3,0>
        }
        intersection{
            sphere{0,5}
            box{-1, 1 scale <0.65,0.65,3> rotate <0,45,0> translate <0,2.5,0>}
        }
    /// Cabeça
        sphere{0,1.2 translate <0,4.2,0>}
   

           
    
    pigment{Green}
}


