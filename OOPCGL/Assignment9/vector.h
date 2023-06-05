#ifndef VECTOR_H
#define VECTOR_H

class Matrix{
public:
    float matrix[2][2];

    void set(int i, int j, float element){
        matrix[i][j] = element;
    }
};

class Vertex{
public:
    float x = 0.0;
    float y = 0.0;

    Vertex(float x, float y){
        this->x = x;
        this->y = y;
    }

    Vertex operator +(Vertex other){
        return Vertex(x+other.x, y+other.y);
    }

    friend Vertex operator *(Vertex vector, Matrix matrix){
        float x = (vector.x * matrix.matrix[0][0]) + (vector.y * matrix.matrix[0][1]);
        float y = (vector.x * matrix.matrix[1][0]) + (vector.y * matrix.matrix[1][1]);
        return Vertex(x, y);
    }
};

#endif // VECTOR_H
