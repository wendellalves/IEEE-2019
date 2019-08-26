#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Arduino.h"
#include "Motor.hpp"
#include "Sensor.hpp"

class Robot {
   private:
    Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};
    Sensor sensorFL, sensorFR, sensorBL, sensorBR;

   public:
    Robot();
    ~Robot();

    void stop();
    void forward(unsigned long int goal);
    // void forward(unsigned char vel);
    void forward();

    void backward(unsigned long int goal);
    // void backward(unsigned char vel);
    void backward();

    void sidewaysRight(unsigned long int goal);
    // void sidewaysRight(unsigned char vel);
    void sidewaysRight();

    void sidewaysLeft(unsigned long int goal);
    // void sidewaysLeft(unsigned char vel);
    void sidewaysLeft();

    void rotateLeft(unsigned long int goal);
    // void rotateLeft(unsigned char vel);
    void rotateLeft();

    void rotateRight(unsigned long int goal);
    // void rotateRight(unsigned char vel);
    void rotateRight();
    void followLine();

    void moveRightForward(unsigned long int goal);
    void moveRightBackward(unsigned long int goal);
    void moveLeftForward(unsigned long int goal);
    void moveLeftBackward(unsigned long int goal);

    void findBlackLine();
    void alignBetweenContainers();
};

#endif  // ROBOT_HPP