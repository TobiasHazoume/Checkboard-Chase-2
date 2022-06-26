#pragma once
#include<iostream>
//vector with 2 conponents and its a float. NOTE THIS IS A MATH VECTOR
//he declared and defined his methods that wierd but ok
struct Vector2f
{
    //a contructor for if we want to makes a vector w/ no initial parameters
    Vector2f()
    :x(0.0f),y(0.0f)
    {}

    // a contructor for if you have values in mind that you want
    // to initialize for your Vector
    Vector2f(float p_x, float p_y)
    :x(p_x),y(p_y)
    {}

    //its usefull print stuff so you can debug your vectors
    //this is essential for game programming!
    void print(){
        std::cout <<x <<", " << y << std::endl;
    }
    float x,y;
};
 
