#include "include/Sort.h"
bool compareincreasingPerimeter(Shape * shape1,Shape * shape2)
{
    return shape1->perimeter() < shape2->perimeter();
}
bool comparedecreasingPerimeter(Shape * shape1,Shape * shape2)
{
    return shape1->perimeter() > shape2->perimeter();
}
bool compareincreasingArea(Shape * shape1,Shape * shape2)
{
    return shape1->area() < shape2->area();
}
bool comparedecreasingArea(Shape * shape1,Shape * shape2)
{
    return shape1->area() > shape2->area();
}
bool compareincreasingCompactness(Shape * shape1,Shape * shape2)
{
    return shape1->compactness() < shape2->compactness();
}
void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList)
{
	shapeList->sort(compareincreasingPerimeter);
	return;
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
	shapeList->sort(comparedecreasingPerimeter);
	return;
}

void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort(compareincreasingArea);
	return;
}

void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
	shapeList->sort(comparedecreasingArea);
	return;
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
	shapeList->sort(compareincreasingCompactness);
	return;
}
