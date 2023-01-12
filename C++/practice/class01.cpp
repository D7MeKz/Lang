#include<iostream>
#include<cmath>

class Point{
    int x, y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int pos_x, int pos_y){
        x = pos_x;
        y = pos_y;
    }
    
    int GetX(){
        return x;
    }

    int GetY(){
        return y; 
    }
};

class Geometry{
    Point* point_array[100];
    int num_points;

public:
    Geometry(){
        num_points = 0;
    }

    void AddPoint(Point &point) {
        point_array[num_points++] = new Point(point.GetX(), point.GetY());
    }

    void PrintDistance();
};

void Geometry::PrintDistance(){
    int len_x;
    int len_y;
    for(int first = 0 ; first < num_points-1 ; first++){
        for(int second = first+1 ; second < num_points; second++){
            len_x = std::abs(point_array[first]->GetX() - point_array[second]->GetX());
            len_y = std::abs(point_array[first]->GetY() - point_array[second]->GetY());
            std::cout << "Length: " << sqrt(pow(len_x,2)+pow(len_y,2))<<std::endl;
        }
        
    }
}

int main(){
    Point point1(1,1);
    Point point2(2,2);
    Geometry geom;
    geom.AddPoint(point1);
    geom.AddPoint(point2);
    geom.PrintDistance();
}