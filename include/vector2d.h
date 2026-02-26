#ifndef vector2d_H
#define vector2d_H

#include <cmath>
#include <iostream>

/** Clase de vectores en 2D */
class vector2d
{
    private:

    /**
     Coordenada en x */

    float m_x;

    /** Coordenada en y */
    
    float m_y;

    public:

    /**
    Constructor
    Coordenada en x
    Coordenada en y
     */
    vector2d() : m_x{0}, m_y{0} {}    
    vector2d(float x, float y): m_x{x}, m_y{y}{}

    /**Operación de suma de vectores
     @param v el otro vector a ser sumado 
     @returns vector2d es la suma de los vectores */

     vector2d operator+(const vector2d& v)
     {
        return vector2d(m_x+v.m_x,m_y+v.m_y);
     }

     /**Copia del vector actual
     @returns vector2d copia del vector */

     vector2d clone()
     {
        return vector2d(m_x,m_y);
     }

     /**Calcula la normal, distancia o magnitud del vetor
      */

      float distancia()
      {
        return std::sqrt(m_x*m_x + m_y*m_y);
      }

      /** Operación de escalar por un vetor */
       vector2d& operator*(float s)
        {
            m_x = m_x*s;
            m_y = m_y*s;
            return *this;
        }
vector2d lerp(const vector2d& v, float t) const  // agregar const al final
{
    float nuevo_x = (1-t)*m_x + t*v.m_x;
    float nuevo_y = (1-t)*m_y + t*v.m_y;
    return vector2d(nuevo_x, nuevo_y);
}

        /**Compara dos vectores */
         bool equals(const vector2d& v)
        {
            float epsilon = 0.00001f;
            bool x1 = m_x<=v.m_x+epsilon && m_x>= v.m_x-epsilon;
            bool y1 = m_y<=v.m_y+epsilon && m_y>= v.m_y-epsilon;

            return x1 && y1;
        }
        
        /**Regresa un vector normalizado */

        vector2d normalize()
        {
            return vector2d(m_x/distancia(),m_y/distancia());
        }

        /**Asiga nuevos valores de coordenadas */

         void set(float x, float y)
        {
            m_x = x;
            m_y = y;
        } 

        /** Resta de dos vectores*/

         vector2d operator-(const vector2d& v)
        {
            return vector2d(m_x-v.m_x,m_y-v.m_y);
        }

        /**Asigna ceros a las coordenadas */
        void zero()
        {
            m_x = 0.f;
            m_y = 0.f;
        }

        float getX(){
            return m_x;
        }

        float getY(){
            return m_y;
        }

        /**Imprime el objeto */
        friend std::ostream& operator<<(std::ostream& os,const vector2d& v) {
            os << "(" << v.m_x << ", " << v.m_y<<")";
            return os;
        }
};

#endif