#ifdef POINT_H
#define POINT_H

class point
{
private:
    float X;
    float Y;

public:
    point();
    point(float x, float y);
    void set_x(float x);
    void set_y(float y);
    float get_x() const;
    float get_y() const;
    void display() const;
    float distance(const point &p) const;

};

#endif
