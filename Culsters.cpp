#include "point.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


class point
{
private:
    float X;
    float Y;

public:
    point()
    {
        X = 0;
        Y = 0;
    }
    point(float x, float y)
    {
        X = x;
        Y = y;
    }
    void set_x(float x)
    {
        X = x;
    }
    void set_y(float y)
    {
        Y = y;
    }
    float get_x() const
    {
        return X;
    }
    float get_y() const
    {
        return Y;
    }
    void display() const
    {
        cout << "(" << X << ", " << Y << ")";
    }
    float distance(const point &p) const
    {
        float dx = X - p.X;
        float dy = Y - p.Y;
        float D = sqrt(pow(dx, 2) + pow(dy, 2));

        return D;
    }

};


point center(point *C, int n) // a function that determins the center of the given cluster by calculating the average of x and y and returns a point
{
    float sum_of_X = 0; // sum for x and y to be able to calculate the avarage later
    float sum_of_Y = 0;

    for (int i = 0; i < n; i++) // it goes through the array and adds x together and y together
    {
        sum_of_X += C[i].get_x();
        sum_of_Y += C[i].get_y();
    }

    float ave_of_X = sum_of_X / n; // here i calculate the average of x and y
    float ave_of_Y = sum_of_Y / n;

    point cluster_center(ave_of_X, ave_of_Y); // makes a new cluster_center of type point  with the center we found

    return cluster_center;
}

int closest_cluster(point *A, point *B, int n, point p) // determins which cluster is closer to the point given p
{
    point center_A = center(A, n);           // compute the center of cluster A and B
    point center_B = center(B, n);           
    float distance_A = p.distance(center_A); // compute distance between p and center of A and the cluster of B
    float distance_B = p.distance(center_B); 
    if (distance_A < distance_B)             
        return 0;                            
    else                                     
        return 1;                           
}

int main()
{
    srand(time(NULL)); // seed random number generator

                        // create clusters A and B
    const int n = 200; // number of points in each cluster
    point A[n];
    point B[n]; // creates arrays of points

    for (int i = 0; i < n; i++) // to set each point in every array to a random number from the range mentioned in the question
    {
        A[i].set_x(rand() % 21 + 70); // generate x-coordinate in [70, 90]
        A[i].set_y(rand() % 21 + 70); // generate y-coordinate in [70, 90]
        B[i].set_x(rand() % 21 + 20); // generate x-coordinate in [20, 40]
        B[i].set_y(rand() % 21 + 20); // generate y-coordinate in [20, 40]
    }

                        // create array of points p
    const int m = 20; // number of points
    point p[m];       // array of points

    for (int i = 0; i < m; i++)
    {
        p[i].set_x(rand() % 96 + 5); // generate x-coordinate between [5, 100]
        p[i].set_y(rand() % 96 + 5); // generate y-coordinate between [5, 100]
    }

    // classify points in p
    for (int i = 0; i < m; i++)
    {
        int cluster = closest_cluster(A, B, n, p[i]); // determine closest cluster
        int counter = i + 1;

        if (cluster == 0)
        {
            cout << "Point " << counter << ": ";
            p[i].display();
            cout << " is closer to cluster A\n\n";
        }
        else
        {
            cout << "Point " << counter << ": ";
            p[i].display();
            cout << " is closer to cluster B\n\n";
        }
    }

    return 0;
}
