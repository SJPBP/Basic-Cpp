#ifndef LAB__3_CIRCLE_H
#define LAB__3_CIRCLE_H

class Circle
{
    private:
        double Radius;
        double Pi;

    public:
        Circle();
        Circle(double);
        void setRadius(double);
        double getArea() const;
        double getDiameter() const;
        double getCircumference() const;
        double getRadius() const
        { return Radius; }

};


#endif //LAB__3_CIRCLE_H
