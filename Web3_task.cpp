#include<iostream>
#include <cmath>
using namespace std;

class Car {
private:
    int x_;
    int y_;
    int z_;
    int vel_x_;
    int vel_y_;
    int vel_z_;

public:
    Car(int x, int y, int z, int vel_x, int vel_y, int vel_z) : x_(x), y_(y), z_(z), vel_x_(vel_x), vel_y_(vel_y), vel_z_(vel_z){}

    bool detect_collision(const Car& other) const {
        double distance = sqrt((x_ - other.x_)*(x_ - other.x_) + (y_ - other.y_)*(y_ - other.y_) + (z_ - other.z_)*(z_ - other.z_));
        if (distance==0) {
            return true;
        }
        else {
            return false;
        }
    }

    void time_to_collision(const Car& other) const {
        int rel_vel_x = vel_x_ - other.vel_x_;
        int rel_vel_y = vel_y_ - other.vel_y_;
        int rel_vel_z = vel_z_ - other.vel_z_;
        int rel_x = other.x_ - x_;
        int rel_y = other.y_ - y_;
        int rel_z = other.z_ - z_;

        int a = (rel_vel_x * rel_vel_x) + (rel_vel_y * rel_vel_y) + (rel_vel_z * rel_vel_z);
        int b = 2 * (rel_vel_x * rel_x + rel_vel_y * rel_y + rel_vel_z * rel_z);
        int c = (rel_x * rel_x) + (rel_y * rel_y) + (rel_z * rel_z);

        if (a == 0) {
            cout<<INFINITY<<endl;
        }
        else {
            double D = b*b - 4*a*c;
            if (D < 0) {
                cout<<INFINITY<<endl;
            }
            else {
                double t1 = abs(-b + sqrt(D)) / (2*a);
                double t2 = abs(-b - sqrt(D)) / (2*a);
                cout<<max(t1, t2)<<endl;
            }
        }
    }

    void accelerate(double speed_increment) {
        vel_x_ += speed_increment;
        vel_y_ += speed_increment;
        vel_z_ += speed_increment;
    }

    void brake(double speed_decrement) {
        vel_x_ -= speed_decrement;
        vel_y_ -= speed_decrement;
        vel_z_ -= speed_decrement;
    }

    void move() {
        x_ += vel_x_;
        y_ += vel_y_;
        z_ += vel_z_;
    }
};

int main(){
    Car car_1(2, 2, 2, 1, 1, 1);
    Car car_2(0, 0, 0, 2, 2, 2);
    car_1.accelerate(1);
    car_2.move();
    car_1.brake(1);
    car_1.detect_collision(car_2);

    if(car_1.detect_collision(car_2)){
        cout<<"Collided"<<endl;
    }
    else{
        cout<<"Not Collided"<<endl;
    }

    car_1.time_to_collision(car_2);

    return 0;
}
