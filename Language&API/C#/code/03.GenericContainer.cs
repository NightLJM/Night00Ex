// using System;
// using System.Collections.Generic;

// namespace GenericContainerTest
// {
//     public class Point : IComparable<Point>
//     {
//         public int x;
//         public int y;
//         public Point()
//         {
//             x = 0;
//             y = 0;
//             Console.WriteLine("Construct without parm !");
//         }
//         public Point(int _x, int _y)
//         {
//             x = _x;
//             y = _y;
//             Console.WriteLine("Construct with two parm !");
//         }
//         public Point(Point p)
//         {
//             x = p.x;
//             y = p.y;
//             Console.WriteLine("Copy COnstruct");
//         }

//         public override string ToString()
//         {
//             return "(" + x.ToString() + ", " + y.ToString() + ")";
//         }

//         public int CompareTo(Point? p)
//         {
//             bool bLittle = (p == null) ? false : 
//                     ((x == p.x) ? y < p.y : x < p.x);
//             return bLittle ? -1 : 1;
//         }
//     }

//     public class PointComparer : IComparer<Point>
//     {
//         public int Compare(Point? x, Point? y)
//         {
//             int ret = (x == null) ? 1 : 
//                             (y == null) ? 1 : -1*x.CompareTo(y);
//             return ret;
//         }
//     }

//     public class ListTest
//     {
//         public static void printList<T>(List<T> l)
//         {
//             foreach (T t in l)
//             {
//                 Console.WriteLine(t);
//             } 
//         }

//         public static void testSort()
//         {
//             {   
//                 //1. List的sort
//                 List<Point> pointList = new List<Point>();
//                 pointList.Add(new Point(0, 0));
//                 pointList.Add(new Point(2, 2));
//                 pointList.Add(new Point(1, 1));
//                 pointList.Sort();
//                 printList<Point>(pointList);
//                 /*
//                     Construct with two parm !
//                     Construct with two parm !
//                     Construct with two parm !
//                     (0, 0)
//                     (1, 1)
//                     (2, 2)
//                 */
//                 pointList.Sort(new PointComparer());
//                 printList<Point>(pointList);
//                 /*
//                     Construct with two parm !
//                     Construct with two parm !
//                     Construct with two parm !
//                     (0, 0)
//                     (1, 1)
//                     (2, 2)
//                     (2, 2)
//                     (1, 1)
//                     (0, 0)
//                 */
//             }
//         }
//     }

//     public class MainClass
//     {
//         public static void Main(string[] args)
//         {
//             //1. List
//             ListTest.testSort();
//         }
//     }


// }
