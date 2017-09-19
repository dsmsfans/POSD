#ifndef UTSORT_H
#define URSORT_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter)
{
    Circle cir(2, 7, 11,"C1");//69.08
	Rectangle rect(3, 8, 12, 21,"R1");//66
	Triangle tri({1, 1}, {3, 1}, {3, 4},"T1");//8.6

	std::list<Shape *> shapes;
	shapes.push_back(&cir);
	shapes.push_back(&rect);
	shapes.push_back(&tri);

	Sort::sortByIncreasingPerimeter(&shapes);
//	for(std::list<Shape *>::iterator itr = shapes.begin(); itr != shapes.end(); itr++)
//	{
//		std::cout << (*itr)->getShapeName() << " ";
//	}
    ASSERT_EQ(shapes.front(),&tri);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&rect);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&cir);
    shapes.pop_front();
}

TEST (Sort, sortByDecreasingPerimeter)
{
    Circle cir(2, 7, 11,"C1");//69.08
	Rectangle rect(3, 8, 12, 21,"R1");//66
	Triangle tri({1, 1}, {3, 1}, {3, 4},"T1");//8.6

	std::list<Shape *> shapes;
	shapes.push_back(&cir);
	shapes.push_back(&rect);
	shapes.push_back(&tri);

	Sort::sortByDecreasingPerimeter(&shapes);
//	for(std::list<Shape *>::iterator itr = shapes.begin(); itr != shapes.end(); itr++)
//	{
//		std::cout << (*itr)->getShapeName() << " ";
//	}
    ASSERT_EQ(shapes.front(),&cir);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&rect);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&tri);
    shapes.pop_front();
}

TEST (Sort, sortByIncreasingArea)
{
    Circle cir(2, 7, 11,"C1");//379.94
	Rectangle rect(3, 8, 12, 21,"R1");//252
	Triangle tri({1, 1}, {3, 1}, {3, 4},"T1");//3

	std::list<Shape *> shapes;
	shapes.push_back(&cir);
	shapes.push_back(&rect);
	shapes.push_back(&tri);

	Sort::sortByIncreasingArea(&shapes);
//	for(std::list<Shape *>::iterator itr = shapes.begin(); itr != shapes.end(); itr++)
//	{
//		std::cout << (*itr)->getShapeName() << " ";
//	}
    ASSERT_EQ(shapes.front(),&tri);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&rect);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&cir);
    shapes.pop_front();
}

TEST (Sort, sortByDecreasingArea)
{
    Circle cir(2, 7, 11,"C1");//69.08
	Rectangle rect(3, 8, 12, 21,"R1");//66
	Triangle tri({1, 1}, {3, 1}, {3, 4},"T1");//8.6

	std::list<Shape *> shapes;
	shapes.push_back(&cir);
	shapes.push_back(&rect);
	shapes.push_back(&tri);

	Sort::sortByDecreasingArea(&shapes);
//	for(std::list<Shape *>::iterator itr = shapes.begin(); itr != shapes.end(); itr++)
//	{
//		std::cout << (*itr)->getShapeName() << " ";
//	}
    ASSERT_EQ(shapes.front(),&cir);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&rect);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&tri);
    shapes.pop_front();
}

TEST (Sort, sortByIncreasingCompactness)
{
    Circle cir(2, 7, 11,"C1");//5.5
	Rectangle rect(3, 8, 12, 21,"R1");//3.93
	Triangle tri({1, 1}, {3, 1}, {3, 4},"T1");//0.34

	std::list<Shape *> shapes;
	shapes.push_back(&cir);
	shapes.push_back(&rect);
	shapes.push_back(&tri);

	Sort::sortByIncreasingCompactness(&shapes);
//	for(std::list<Shape *>::iterator itr = shapes.begin(); itr != shapes.end(); itr++)
//	{
//		std::cout << (*itr)->getShapeName() << " ";
//	}
    ASSERT_EQ(shapes.front(),&tri);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&rect);
    shapes.pop_front();
    ASSERT_EQ(shapes.front(),&cir);
    shapes.pop_front();
}

#endif
